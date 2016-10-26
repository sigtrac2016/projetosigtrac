/*
    Testes unitários para Scripts
*/
var assert = require('assert');
var util = require('./../web/script/util.js');
var sinon = require('sinon');

// Testes unitários para Scripts
describe('Scripts', function() {

    // Testes unitários para util.js
    describe('util.js', function() {
        it('Teste de cor do segmento', function() {
            assert.equal("blue", util.segmentoColor("police"));
            assert.equal("red", util.segmentoColor("health"));
            assert.equal("black", util.segmentoColor("fire"));
            assert.equal("green", util.segmentoColor("civil"));
            assert.equal("#aaa", util.segmentoColor("other"));
        });
        it('Teste get de parâmetro de URL', function() {
            global.window = { 'location': { 'search': '?segmento=police' } };
            assert.equal("police", util.getUrlParameter("segmento"));
        });
    });


});