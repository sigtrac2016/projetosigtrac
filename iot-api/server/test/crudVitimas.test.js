var expect  = require("chai").expect;
var request = require("request");
var apiServer = require("../app.js");
var baseURL = "http://localhost:8080/api";

describe("Hello world", function() {

    describe ("GET /api", function() {

        it("return status code 200", function(done) {
            request({
                url: baseURL,
                method: 'GET'
            }, function(error, response, body) {
                expect(response.statusCode).to.equal(200);
                done();
            });
        });

        it("return Hello World", function(done) {
            request({
                url: baseURL,
                method: 'GET'
            }, function(error, response, body) {
                expect(body).to.equal("Hello World. Oie.");
                done();
            });
        });

        it("post vitima", function(done) {
            request({
                url: baseURL,
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    alias: '001',
                	name: 'Teste 001',
                	timeCreated: '2016-09-16',
                	location: {
                		latitude: -23.0,
                		longitude: -45.0
                	},
                	deambulando: true,
                	respiracao: 100,
                	respiraViasAereas: true,
                	reenchimentoCapilar: 100,
                	pulsoRadial: true,
                	cumpreOrdens: false
                })
            }, function(error, response, body) {
                expect(response.statusCode).to.equal(200);
                done();
            });
        });

        it("get vitima especifica", function(done) {
            request({
                url: baseURL,
                method: 'GET',
                qs: {
                    alias: "001"
                }
            }, function(error, response, body) {
                expect(response.statusCode).to.equal(200);
                done();
            });
        });

        it("get vitima inexistente", function(done) {
            request({
                url: baseURL,
                method: 'GET',
                qs: {
                    alias: "999"
                }
            }, function(error, response, body) {
                expect(response.statusCode).to.equal(200);
                done();
            });
        });

    });

});
