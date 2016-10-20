'use strict';

angular.module('SigTrac')
    .directive('operacaoMap', function($compile) {
        return {
            controller: function($scope, $location, mapService, operacaoControlsService, infoWindowService, operacoesService, markersService) {
                if ($location.path() === '') {
                    $location.path('/');
                }

                $scope.location = $location;
                $scope.infow = infoWindowService;
                $scope.controls = operacaoControlsService;

                this.registerInfoWindow = function(infoWindow) {
                    infoWindowService.registerInfoWindow(infoWindow);
                };

                this.registerMap = function(map) {
                    mapService.setMap(map);
                    $scope.operacoes = operacoesService;
                };

                $scope.$watch('location.path()', function(path) {
                    operacoesService.filter = (path === '/active') ? {
                        completed: false
                    } : (path === '/completed') ? {
                        completed: true
                    } : null;
                });

                $scope.$watch('location.path() + operacoes.nextId + operacoes.remainingCount()', function() {
                    var i,
                        operacoes = operacoesService.filtered(),
                        map = mapService.getMap(),
                        operacaoId,
                        marker,
                        markers = markersService.markers,
                        markerId,
                        uniqueOperacoes = {};

                    function addMarkerByOperacaoIndex(operacaoIndex) {
                        var marker,
                            markerOptions,
                            operacao = operacoes[operacaoIndex];
                        markerOptions = {
                            map: map,
                            title: operacao.title,
                            icon: getMarkerIcon(operacao.tipo),
                            position: new google.maps.LatLng(operacao.lat, operacao.lng, operacao.radius)
                        };
                        marker = new google.maps.Marker(markerOptions);
                        var cityCircle = new google.maps.Circle({
                            strokeColor: operacao.completed ? '#FF0000' : '#00FF0F',
                            strokeOpacity: 0.8,
                            strokeWeight: 2,
                            fillColor: operacao.completed ? '#FF0000' : '#00FF0F',
                            fillOpacity: 0.15,
                            map: map,
                            center: {
                                lat: operacao.lat,
                                lng: operacao.lng
                            },
                            radius: operacao.radius
                        });
                        marker.setValues({
                            id: operacao.id,
                            operacao: operacao,
                            circle: cityCircle
                        });
                        markersService.markers.push(marker);

                        function markerClickCallback(scope, operacaoId) {
                            return function() {
                                scope.$apply(function() {
                                    operacaoControlsService.openInfoWindowByOperacaoId(operacaoId);
                                });
                            };
                        }

                        google.maps.event.addListener(marker, 'click', markerClickCallback($scope, operacao.id));

                        function markerDblClickCallback(scope, operacaoId) {
                            return function() {
                                scope.$apply(function() {
                                    operacaoControlsService.editOperacaoById(operacaoId);
                                });
                            };
                        }

                        google.maps.event.addListener(marker, 'dblclick', markerDblClickCallback($scope, operacao.id));
                    }
                    for (i = operacoes.length - 1; i >= 0; i--) {
                        uniqueOperacoes[operacoes[i].id] = i;
                    }
                    for (i = markers.length - 1; i >= 0; i--) {
                        marker = markers[i];
                        markerId = marker.get("id");
                        if (uniqueOperacoes[markerId] !== undefined) {
                            delete uniqueOperacoes[markerId];
                        } else {
                            marker.get("circle").setMap(null);
                            marker.setMap(null);
                            markers.splice(i, 1);
                        }
                    }
                    for (operacaoId in uniqueOperacoes) {
                        if (uniqueOperacoes.hasOwnProperty(operacaoId)) {
                            addMarkerByOperacaoIndex(uniqueOperacoes[operacaoId]);
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
                    operacoesControlTemplate,
                    operacoesControlElem,
                    editOperacaoControlTemplate,
                    editOperacaoControlElem,
                    editSearchControlTemplate,
                    editSearchControlElem,
                    searchAutocomplete,
                    mapStyles,
                    map;
                latitude = latitude && parseFloat(latitude, 10) || -23.26157050117577;
                longitude = longitude && parseFloat(longitude, 10) || -45.8938622586914;
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
                    zoom: 12,
                    disableDefaultUI: false,
                    center: new google.maps.LatLng(latitude, longitude),
                    mapTypeId: google.maps.MapTypeId.ROADMAP,
                    styles: mapStyles
                };

                google.maps.visualRefresh = true;
                map = new google.maps.Map(elem[0], mapOptions);
                ctrl.registerMap(map);

                operacoesControlTemplate = document.getElementById('operacoesControlTemplate').innerHTML.trim();
                operacoesControlElem = $compile(operacoesControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.TOP_LEFT].push(operacoesControlElem[0]);

                editOperacaoControlTemplate = document.getElementById('editOperacaoControlTemplate').innerHTML.trim();
                editOperacaoControlElem = $compile(editOperacaoControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.RIGHT_BOTTOM].push(editOperacaoControlElem[0]);

                editSearchControlTemplate = document.getElementById('editSearchControlTemplate').innerHTML.trim();
                editSearchControlElem = $compile(editSearchControlTemplate)(scope);
                map.controls[google.maps.ControlPosition.TOP_CENTER].push(editSearchControlElem[0]);

                searchAutocomplete = new google.maps.places.Autocomplete(editSearchControlElem[0]);
                searchAutocomplete.addListener('place_changed', function() {
                    setPlace();
                });

                var setPlace = function() {
                    var place = searchAutocomplete.getPlace();
                    if(!place.geometry) return;
                    if(place.geometry.viewport) {
                        map.fitBounds(place.geometry.viewport);
                    }
                    else {
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

    switch(tipo) {
        case 1:
            color = 'paleblue';
            symbol = 'A';
            break;
        case 2:
            color = 'green';
            symbol = 'V';
            break;
        case 3:
            color = 'orange';
            symbol = 'I';
            break;
        case 4:
            color = 'brown';
            symbol = 'D';
            break;
        default:
            color = 'yellow';
            symbol = 'Z';
    }

    return prefix + color + file + symbol + suffix;
}
