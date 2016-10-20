'use strict';

angular.module('SigTrac')
    .service('mapService', function() {
        var _map;
        this.setMap = function(map) {
            _map = map;
        };

        this.getMap = function() {
            if (_map) return _map;
            throw new Error("Mapa não definido");
        };

        this.getLatLng = function() {
            var center = _map.getCenter();
            return {
                lat: center.lat(),
                lng: center.lng()
            };
        };
    })
    .service('markersService', function() {
        this.markers = [];
        this.getMarkerById = function(id) {
            var marker, i;
            for (i = this.markers.length - 1; i >= 0; i--) {
                marker = this.markers[i];
                if (marker.get("id") === id) {
                    return marker;
                }
            }
            return false;
        };
    })
    .service('infoWindowService', function(mapService) {
        var _infoWindow;
        this.data = {};
        this.registerInfoWindow = function(infoWindowBuscaResgate) {
            _infoWindow = infoWindowBuscaResgate;
        };

        this.setData = function(id, title, desc, buscaResgateInicio, buscaResgateTermino, editMsg) {
            this.data.id = id;
            this.data.title = title;
            this.data.desc = desc;
            this.data.buscaResgateInicio = buscaResgateInicio;
            this.data.buscaResgateTermino = buscaResgateTermino;
            this.data.editMsg = editMsg;
        };

        this.open = function(marker) {
            _infoWindow.open(mapService.getMap(), marker);
        };

        this.close = function() {
            if (_infoWindow) {
                _infoWindow.close();
                this.data = {};
            }
        };
    });
