'use strict';

const should = require('should');
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

    describe ('API', function() {
        forEach([
            [1, true, 20, true, 2, true, true],
            [2, false, 40, false, 4, false, true],
            [3, false, 20, false, 2, false, false],
            [4, true, 40, true, 4, true, false],
            [5, true, 40, false, 2, true, false],
            [6, false, 20, true, 4, true, false],
            [7, true, 20, true, 4, false, false]
        ])
        .it('post experimento%d', (exp, deambulando, respiracao, respiraViasAereas, reenchimentoCapilar, pulsoRadial, cumpreOrdens) => {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI),
                method: 'POST',
                body: {
                    alias: 'experimento' + exp,
                    name: 'Teste 001',
                    timeCreated: '2016-09-16',
                    location: {
                        latitude: -23.0,
                        longitude: -45.0
                    },
                    deambulando: deambulando,
                    respiracao: respiracao,
                    respiraViasAereas: respiraViasAereas,
                    reenchimentoCapilar: reenchimentoCapilar,
                    pulsoRadial: pulsoRadial,
                    cumpreOrdens: cumpreOrdens
                },
                json: true
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        context('validar regras START', () => {
            forEach([
                [1, VERDE],
                [2, VERDE],
                [3, VERDE],
                [4, VERDE],
                [5, VERDE],
                [6, VERDE],
                [7, VERDE]
            ])
            .it('get experimento%d', (exp, status) => {
                request({
                    url: requestURL.resolve(baseURL, vitimasAPI + '/experimento' + exp),
                    method: 'GET'
                }, function(error, response, body) {
                    should.not.exist(error);
                    should.exist(response);
                    response.statusCode.should.equal(200);
                    should.exist(body);
                    var responseBody = JSON.parse(body);
                    'Roxo'.should.equal('Azul');
                    responseBody['status'].should.equal(status);
                });
            });
        });

    });

});
