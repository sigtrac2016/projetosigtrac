'use strict';

var should = require('should');
var request = require('request');
var requestURL = require('url');

var apiServer = require('../app.js');

var baseURL = 'http://localhost:9092';
var baseAPI = '/api';
var vitimasAPI = '/api/vitimas';

describe('Vitimas', function() {

    describe ('API', function() {

        it('return status code 200', function(done) {
            request({
                url: requestURL.resolve(baseURL, baseAPI),
                method: 'GET'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        it('return Hello World', function(done) {
            request({
                url: requestURL.resolve(baseURL, baseAPI),
                method: 'GET'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                body.should.equal('Hello World. Oie.');
                done();
            });
        });

        it('post vitima', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI),
                method: 'POST',
                body: {
                    alias: '001',
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
                    cumpreOrdens: false
                },
                json: true
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        it('get vitima especifica', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI, '001'),
                method: 'GET'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        it('get vitima inexistente', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI, '999'),
                method: 'GET'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(404);
                done();
            });
        });

        it('delete vitima', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI, '100'),
                method: 'DELETE'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(200);
                done();
            });
        });

        it('delete vitima inexistente', function(done) {
            request({
                url: requestURL.resolve(baseURL, vitimasAPI, '999'),
                method: 'DELETE'
            }, function(error, response, body) {
                should.not.exist(error);
                should.exist(response);
                response.statusCode.should.equal(404);
                done();
            });
        });

    });

});
