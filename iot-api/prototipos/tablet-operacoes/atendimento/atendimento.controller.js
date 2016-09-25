'use strict';

angular.module('SigTrac')
    .value('NEW_RECORD_ID', -1)
    .controller('atendimentoMapCtrl', function($scope, mapService, atendimentosService, infoWindowService, atendimentoControlsService, NEW_RECORD_ID) {
        var editPinImage,
            editMarker;
        $scope.editAtendimento = {};

        editPinImage = new google.maps.MarkerImage("http://chart.apis.google.com/chart?chst=d_map_pin_letter&chld=%E2%80%A2|" + "55FF00",
            new google.maps.Size(21, 34),
            new google.maps.Point(0, 0),
            new google.maps.Point(10, 34));
        editMarker = new google.maps.Marker({
            title: "Arraste",
            draggable: true,
            clickable: false,
            icon: editPinImage,
            position: new google.maps.LatLng(0, 0)
        });

        function editMarkerDragCallback(scope, marker) {
            return function() {
                var pos = marker.getPosition();
                scope.editAtendimento.lat = pos.lat();
                scope.editAtendimento.lng = pos.lng();
                if (!scope.$$phase) scope.$apply();
            };
        }

        google.maps.event.addListener(editMarker, 'drag', editMarkerDragCallback($scope, editMarker));

        function editMarkerDblClickCallback(scope) {
            return function() {
                scope.$apply(function() {
                    scope.submitAtendimento();
                });
            };
        }

        google.maps.event.addListener(editMarker, 'dblclick', editMarkerDblClickCallback($scope));

        $scope.$watch('editAtendimento.lat + editAtendimento.lng', function(newValue, oldValue) {
            if (newValue !== oldValue) {
                var pos = editMarker.getPosition(),
                    latitude = pos.lat(),
                    longitude = pos.lng();
                if ($scope.editAtendimento.lat !== latitude || $scope.editAtendimento.lng !== longitude)
                    editMarker.setPosition(new google.maps.LatLng($scope.editAtendimento.lat || 0, $scope.editAtendimento.lng || 0));
            }
        });

        $scope.$watch('controls.editAtendimento + controls.editAtendimentoId', function() {
            var pos, atendimento = atendimentoControlsService.editAtendimentoId !== NEW_RECORD_ID && atendimentosService.getAtendimentoById(atendimentoControlsService.editAtendimentoId);
            infoWindowService.close();
            if (atendimentoControlsService.editAtendimento) {
                if (atendimento) {
                    $scope.editAtendimento = {
                        id: atendimento.id,
                        title: atendimento.title,
                        desc: atendimento.desc,
                        atendimentoInicio: atendimento.atendimentoInicio,
                        atendimentoTermino: atendimento.atendimentoTermino,
                        deambulando: atendimento.deambulando,
                        cumpreOrdens: atendimento.cumpreOrdens,
                        respiracaoViaAerea: atendimento.respiracaoViaAerea,
                        reenchimentoCapilar: atendimento.reenchimentoCapilar,
                        respiracao: atendimento.respiracao,
                        tipo: atendimento.tipo,
                        lat: atendimento.lat,
                        lng: atendimento.lng,
                        radius: atendimento.radius,
                        comp: atendimento.completed,
                        saveMsg: "Atualizar",
                        cancelMsg: "Cancelar"
                    };
                } else {
                    pos = mapService.getLatLng();
                    $scope.editAtendimento = {
                        id: NEW_RECORD_ID,
                        lat: pos.lat,
                        lng: pos.lng,
                        atendimentoInicio: "",
                        atendimentoTermino: "",
                        deambulando: true,
                        cumpreOrdens: true,
                        respiracaoViaAerea: true,
                        reenchimentoCapilar: 0,
                        respiracao: 0,
                        tipo: 0,
                        radius: 100,
                        saveMsg: "Salvar",
                        cancelMsg: "Cancelar"
                    };
                }
                editMarker.setMap(mapService.getMap());
            }
        });

        $scope.submitAtendimento = function() {
            if ($scope.editAtendimentoForm.$valid) {
                if ($scope.editAtendimento.id === NEW_RECORD_ID)
                    addAtendimento();
                else
                    editAtendimento();
            }
        }

        $scope.resetCloseAtendimentoForm = function() {
            editMarker.setMap(null);
            atendimentoControlsService.editAtendimento = false;
            atendimentoControlsService.editAtendimentoId = NEW_RECORD_ID;
            $scope.editAtendimento = {};
        }

        function addAtendimento() {
            atendimentosService.addAtendimento(
                $scope.editAtendimento.title,
                $scope.editAtendimento.desc,
                $scope.editAtendimento.atendimentoInicio,
                $scope.editAtendimento.atendimentoTermino,
                $scope.editAtendimento.deambulando,
                $scope.editAtendimento.cumpreOrdens,
                $scope.editAtendimento.respiracaoViaAerea,
                $scope.editAtendimento.reenchimentoCapilar,
                $scope.editAtendimento.respiracao,
                $scope.editAtendimento.tipo,
                $scope.editAtendimento.lat,
                $scope.editAtendimento.lng,
                $scope.editAtendimento.radius);
            $scope.resetCloseAtendimentoForm();
        }

        function editAtendimento() {
            atendimentosService.updateAtendimento(
                $scope.editAtendimento.id,
                $scope.editAtendimento.title,
                $scope.editAtendimento.desc,
                $scope.editAtendimento.atendimentoInicio,
                $scope.editAtendimento.atendimentoTermino,
                $scope.editAtendimento.deambulando,
                $scope.editAtendimento.cumpreOrdens,
                $scope.editAtendimento.respiracaoViaAerea,
                $scope.editAtendimento.reenchimentoCapilar,
                $scope.editAtendimento.respiracao,
                $scope.editAtendimento.tipo,
                $scope.editAtendimento.lat,
                $scope.editAtendimento.lng,
                $scope.editAtendimento.radius,
                $scope.editAtendimento.comp);
            $scope.resetCloseAtendimentoForm();
        }
    });
