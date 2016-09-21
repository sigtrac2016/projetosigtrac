'use strict';

const should = require('chai').should();
const request = require('request');
const requestURL = require('url');
const forEach = require('mocha-each');

const apiServer = require('../app.js');

const baseURL = 'http://localhost:8080';
const baseAPI = '/api';
const vitimasAPI = '/api/vitimas';

const VERDE = 'Verde';
const AMARELO = 'Amarelo';
const VERMELHO = 'Vermelho';
const PRETO = 'Preto';

describe('Vitimas', function() {

    describe ('API Pairwise', function() {
        var tests = [
            {exp: 1, deambulando: true, respiracao: 20, respiraViasAereas: true, reenchimentoCapilar: 2, pulsoRadial: true, cumpreOrdens: true},
            {exp: 2, deambulando: false, respiracao: 40, respiraViasAereas: false, reenchimentoCapilar: 4, pulsoRadial: false, cumpreOrdens: true},
            {exp: 3, deambulando: false, respiracao: 20, respiraViasAereas: false, reenchimentoCapilar: 2, pulsoRadial: false, cumpreOrdens: false},
            {exp: 4, deambulando: true, respiracao: 40, respiraViasAereas: true, reenchimentoCapilar: 4, pulsoRadial: true, cumpreOrdens: false},
            {exp: 5, deambulando: true, respiracao: 40, respiraViasAereas: false, reenchimentoCapilar: 2, pulsoRadial: true, cumpreOrdens: false},
            {exp: 6, deambulando: false, respiracao: 20, respiraViasAereas: true, reenchimentoCapilar: 4, pulsoRadial: true, cumpreOrdens: false},
            {exp: 7, deambulando: true, respiracao: 20, respiraViasAereas: true, reenchimentoCapilar: 4, pulsoRadial: false, cumpreOrdens: false}
        ];

        tests.forEach(function(data) {
            it('post experimento%d', function(done) {
                request({
                    url: requestURL.resolve(baseURL, vitimasAPI),
                    method: 'POST',
                    body: {
                        alias: 'experimento' + data.exp,
                        name: 'Teste 001',
                        timeCreated: '2016-09-16',
                        location: {
                            latitude: -23.0,
                            longitude: -45.0
                        },
                        deambulando: data.deambulando,
                        respiracao: data.respiracao,
                        respiraViasAereas: data.respiraViasAereas,
                        reenchimentoCapilar: data.reenchimentoCapilar,
                        pulsoRadial: data.pulsoRadial,
                        cumpreOrdens: data.cumpreOrdens
                    },
                    json: true
                }, function(error, response, body) {
                    should.not.exist(error);
                    should.exist(response);
                    response.statusCode.should.equal(200);
                    done();
                });
            });
        });

        context('Validação', () => {
            var tests = [
                {exp: 1, status: VERDE},
                {exp: 2, status: VERDE},
                {exp: 3, status: VERDE},
                {exp: 4, status: VERDE},
                {exp: 5, status: VERDE},
                {exp: 6, status: VERDE},
                {exp: 7, status: VERDE},
            ];

            tests.forEach(function(data) {
                it('get experimento%d', function(done) {
                    request({
                        url: requestURL.resolve(baseURL, vitimasAPI + '/experimento' + data.exp),
                        method: 'GET'
                    }, function(error, response, body) {
                        should.not.exist(error);
                        should.exist(response);
                        response.statusCode.should.equal(200);
                        should.exist(body);
                        var responseBody = JSON.parse(body);
                        console.log('Request: %s, expected: %s', responseBody['status'], data.status);
                        responseBody['status'].should.equal(data.status);
                        done();
                    });
                });
            });
        });

    });

});
