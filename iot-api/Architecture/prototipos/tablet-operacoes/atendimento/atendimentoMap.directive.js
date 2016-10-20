'use strict';

angular.module('SigTrac')
    .filter('filterWithOr', function($filter) {
        var comparator = function(actual, expected) {
            if (angular.isUndefined(actual)) {
                return false;
            }
            if ((actual === null) || (expected === null)) {
                return actual === expected;
            }
            if ((angular.isObject(expected) && !angular.isArray(expected)) || (angular.isObject(actual) && !hasCustomToString(actual))) {
                return false;
            }
            console.log('ACTUAL EXPECTED')
            console.log(actual)
            console.log(expected)

            actual = angular.lowercase('' + actual);
            if (angular.isArray(expected)) {
                var match = false;
                expected.forEach(function(e) {
                    console.log('forEach')
                    console.log(e)
                    e = angular.lowercase('' + e);
                    if (actual.indexOf(e) !== -1) {
                        match = true;
                    }
                });
                return match;
            } else {
                expected = angular.lowercase('' + expected);
                return actual.indexOf(expected) !== -1;
            }
        };
        return function(array, expression) {
            return $filter('filter')(array, expression, comparator);
        };
    })
    .directive('atendimentoMap', function($compile) {
        return {
            controller: function($scope, $location, mapService, atendimentoControlsService, infoWindowService, atendimentosService, markersService) {
                if ($location.path() === '') {
                    $location.path('/');
                }

                $scope.location = $location;
                $scope.infow = infoWindowService;
                $scope.controls = atendimentoControlsService;

                this.registerInfoWindow = function(infoWindow) {
                    infoWindowService.registerInfoWindow(infoWindow);
                };

                this.registerMap = function(map) {
                    mapService.setMap(map);
                    $scope.atendimentos = atendimentosService;
                };

                $scope.$watch('location.path()', function(path) {
                    atendimentosService.filter = (path === '/bombeiros') ? {
                        tipo: 2
                    } : (path === '/paramedicos') ? {
                        tipo: 3
                    } : (path === '/vitimas') ? {
                        tipo: 4
                    } : null;
                });

                $scope.filterEquipe = function(item) {
                    return item.tipo === 2 || item.tipo === 3;
                }

                $scope.$watch('location.path() + atendimentos.nextId + atendimentos.remainingCount()', function() {
                    var i,
                        atendimentos = atendimentosService.filtered(),
                        map = mapService.getMap(),
                        atendimentoId,
                        marker,
                        markers = markersService.markers,
                        markerId,
                        uniqueAtendimentos = {};

                    function addMarkerByAtendimentoIndex(atendimentoIndex) {
                        var marker,
                            markerOptions,
                            atendimento = atendimentos[atendimentoIndex];
                        markerOptions = {
                            map: map,
                            title: atendimento.title,
                            icon: getMarkerIcon(atendimento.tipo),
                            position: new google.maps.LatLng(atendimento.lat, atendimento.lng, atendimento.radius)
                        };
                        marker = new google.maps.Marker(markerOptions);
                        var cityCircle = new google.maps.Circle({
                            strokeColor: atendimento.completed ? '#FF0000' : '#00FF0F',
                            strokeOpacity: 0.8,
                            strokeWeight: 2,
                            fillColor: atendimento.completed ? '#FF0000' : '#00FF0F',
                            fillOpacity: 0.15,
                            map: map,
                            center: {
                                lat: atendimento.lat,
                                lng: atendimento.lng
                            },
                            radius: atendimento.radius
                        });
                        marker.setValues({
                            id: atendimento.id,
                            atendimento: atendimento,
                            circle: cityCircle
                        });
                        markersService.markers.push(marker);

                        function markerClickCallback(scope, atendimentoId) {
                            return function() {
                                scope.$apply(function() {
                                    atendimentoControlsService.openInfoWindowByAtendimentoId(atendimentoId);
                                });
                            };
                        }

                        google.maps.event.addListener(marker, 'click', markerClickCallback($scope, atendimento.id));

                        function markerDblClickCallback(scope, atendimentoId) {
                            return function() {
                                scope.$apply(function() {
                                    atendimentoControlsService.editAtendimentoById(atendimentoId);
                                });
                            };
                        }

                        google.maps.event.addListener(marker, 'dblclick', markerDblClickCallback($scope, atendimento.id));
                    }
                    for (i = atendimentos.length - 1; i >= 0; i--) {
                        uniqueAtendimentos[atendimentos[i].id] = i;
                    }
                    for (i = markers.length - 1; i >= 0; i--) {
                        marker = markers[i];
                        markerId = marker.get("id");
                        if (uniqueAtendimentos[markerId] !== undefined) {
                            delete uniqueAtendimentos[markerId];
                        } else {
                            marker.get("circle").setMap(null);
                            marker.setMap(null);
                            markers.splice(i, 1);
                        }
                    }
                    for (atendimentoId in uniqueAtendimentos) {
                        if (uniqueAtendimentos.hasOwnProperty(atendimentoId)) {
                            addMarkerByAtendimentoIndex(uniqueAtendimentos[atendimentoId]);
                        }
                    }
                });
            },
            link: function(scope, elem, attrs, ctrl) {
                var mapOptions,
                    latitude = attrs.latitude,
                    longitude = attrs.longitude,
                    infoWindowTemplate,
                    infoWindowElem,
                    infoWindow,
                    atendimentosControlTemplate,
                    atendimentosControlElem,
                    editAtendimentoControlTemplate,
                    editAtendimentoControlElem,
                    editSearchControlTemplate,
                    editSearchControlElem,
                    searchAutocomplete,
                    mapStyles,
                    map;
                latitude = latitude && parseFloat(latitude, 10) || -23.2041321;
                longitude = longitude && parseFloat(longitude, 10) || -45.910916;
                infoWindowTemplate = document.getElementById('infoWindowTemplate').innerHTML.trim();
                infoWindowElem = $compile(infoWindowTemplate)(scope);
                infoWindow = new google.maps.InfoWindow({
                    content: infoWindowElem[0]
                });

                ctrl.registerInfoWindow(infoWindow);
                mapStyles = [{
                    featureType: 'all',
                }];

                mapOptions = {
                    zoom: 18,
                    disableDefaultUI: false,
                    center: new google.maps.LatLng(latitude, longitude),
                    mapTypeId: google.maps.MapTypeId.ROADMAP,
                    styles: mapStyles
                };

                google.maps.visualRefresh = true;
                map = new google.maps.Map(elem[0], mapOptions);
                ctrl.registerMap(map);

                atendimentosControlTemplate = document.getElementById('atendimentosControlTemplate').innerHTML.trim();
                atendimentosControlElem = $compile(atendimentosControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.TOP_LEFT].push(atendimentosControlElem[0]);

                editAtendimentoControlTemplate = document.getElementById('editAtendimentoControlTemplate').innerHTML.trim();
                editAtendimentoControlElem = $compile(editAtendimentoControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.RIGHT_BOTTOM].push(editAtendimentoControlElem[0]);

                editSearchControlTemplate = document.getElementById('editSearchControlTemplate').innerHTML.trim();
                editSearchControlElem = $compile(editSearchControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.TOP_CENTER].push(editSearchControlElem[0]);

                searchAutocomplete = new google.maps.places.Autocomplete(editSearchControlElem[0]);
                searchAutocomplete.addListener('place_changed', function() {
                    setPlace();
                });

                var setPlace = function() {
                    var place = searchAutocomplete.getPlace();
                    if (!place.geometry) return;
                    if (place.geometry.viewport) {
                        map.fitBounds(place.geometry.viewport);
                    } else {
                        map.setCenter(place.geometry.location);
                    }
                }
            }
        };
    });

function getMarkerIcon(tipo) {
    var prefix = 'googleMapMarkers/';
    var color;
    var file = '_Marker';
    var symbol;
    var suffix = '.png';

    if (tipo <= 4) {
        switch (tipo) {
            case 1:
                color = 'paleblue';
                symbol = 'A';
                break;
            case 2:
                color = 'yellow';
                symbol = 'B';
                break;
            case 3:
                color = 'orange';
                symbol = 'P';
                break;
            case 4:
                color = 'red';
                symbol = 'V';
                break;
        }
    } else {
        prefix = 'emoji/';
        color = '';
        file = '';
        symbol = '';

        switch (tipo) {
            case 5:
                file = '1f691';
                break;
            case 6:
                file = '1f692';
                break;
        }
    }

    return prefix + color + file + symbol + suffix;
}
