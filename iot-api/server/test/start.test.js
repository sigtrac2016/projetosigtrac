'use strict';

var should = require('should');
var request = require('request');
var requestURL = require('url');

var apiServer = require('../app.js');

var baseURL = 'http://localhost:9092';
var baseAPI = '/api';
var vitimasAPI = '/api/vitimas';

const VERDE = 'Verde';
const AMARELO = 'Amarelo';
const VERMELHO = 'Vermelho';
const PRETO = 'Preto';

describe('Vitimas', function() {

    describe ('API', function() {

        it('post experimento01', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI),
                method: 'POST',
                body: {
                    alias: 'experimento01',
                    name: 'Teste 001',
                    timeCreated: '2016-09-16',
                    location: {
                        latitude: -23.0,
                        longitude: -45.0
                    },
                    deambulando: true,
                    respiracao: 20,
                    respiraViasAereas: true,
                    reenchimentoCapilar: 2,
                    pulsoRadial: true,
                    cumpreOrdens: true
                },
                json: true
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        it('get experimento01', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI + '/experimento01'),
                method: 'GET'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                should.exist(body);
                var responseBody = JSON.parse(body);
                responseBody['status'].should.equal(VERDE);
                done();
            });
        });

    });

});
