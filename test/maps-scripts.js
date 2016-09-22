/*
    Testes unitários para maps-scripts
*/
var assert = require('assert');
var ccc = require('./../web/views/maps-scripts/ccc.js');
var ccs = require('./../web/views/maps-scripts/ccs.js');
var sinon = require('sinon');

/* Criei uma classe de stub devido à propriedade dela */
// Stub para marcadores.
var StubMarker = function(color) {
    this.icon = {
        fillColor: color
    };
    this.map = new Object();

    this.setMap = function(map) {
        this.map = map;
    };
}

// Testes unitários para Maps-Scripts
describe('Maps-Scripts', function() {

    // Testes unitários para CCC.js
    describe('CCC.js', function() {
        it('fillMarker() should return #aaa', function() {
            assert.equal("#aaa", ccc.fillMarker());
        });
        it('genContentString() should have coordinates', function() {
            ccc.genContentString("(4, 3)");
            assert.ok(contentString.length > 0);
            assert.ok(contentString.indexOf("(4, 3)") !== -1);
        });
    });

    // Testes unitários para CCS.js
    describe('CCS.js', function() {
        it('fillMarker() should return #ff0000', function() {
            assert.equal("#ff0000", ccs.fillMarker());
        });
        it('deleteMarkers() should erase markers without color #ff0000', function() {
            // Given
            var stubMarker1 = new StubMarker("#ff0000");
            var stubMarker2 = new StubMarker("#000000");
            var markers = [stubMarker1, stubMarker2];

            var setMapSpy1 = sinon.spy(stubMarker1, 'setMap');
            var setMapSpy2 = sinon.spy(stubMarker2, 'setMap');
            // When
            ccs.deleteMarkers(markers);
            // Then
            assert.ok(markers.length == 2);
            assert.equal(0, setMapSpy1.callCount);
            assert.equal(1, setMapSpy2.callCount);
            assert.notEqual(null, stubMarker1.map);
            assert.equal(null, stubMarker2.map);

            setMapSpy1.restore();
            setMapSpy2.restore();
        });
        it('genContentString() should have coordinates', function() {
            ccs.genContentString("(4, 3)");
            assert.ok(contentString.length > 0);
            assert.ok(contentString.indexOf("(4, 3)") !== -1);
        });
    });
});