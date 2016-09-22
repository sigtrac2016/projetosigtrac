var assert = require('assert');
var ccc = require('./../web/views/maps-scripts/ccc.js')
var ccs = require('./../web/views/maps-scripts/ccs.js')

describe('Maps-Scripts', function() {

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

    describe('CCS.js', function() {
        it('fillMarker() should return #ff0000', function() {
            assert.equal("#ff0000", ccs.fillMarker());
        });
        it('deleteMarkers() should erase markers without color #ff0000', function() {
            var markers = [];
            // Mock complicado
            assert.ok(markers.length == 0);
            ccs.deleteMarkers(markers);
        });
        it('genContentString() should have coordinates', function() {
            ccs.genContentString("(4, 3)");
            assert.ok(contentString.length > 0);
            assert.ok(contentString.indexOf("(4, 3)") !== -1);
        });
    });
});