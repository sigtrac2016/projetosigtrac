'use strict';

angular.module('SigTrac')
    .value('NEW_RECORD_ID', -1)
    .controller('operacaoMapCtrl', function($scope, mapService, operacoesService, infoWindowService, operacaoControlsService, NEW_RECORD_ID) {
        var editPinImage,
            editMarker;
        $scope.editOperacao = {};

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
                scope.editOperacao.lat = pos.lat();
                scope.editOperacao.lng = pos.lng();
                if (!scope.$$phase) scope.$apply();
            };
        }

        google.maps.event.addListener(editMarker, 'drag', editMarkerDragCallback($scope, editMarker));

        function editMarkerDblClickCallback(scope) {
            return function() {
                scope.$apply(function() {
                    scope.submitOperacao();
                });
            };
        }

        google.maps.event.addListener(editMarker, 'dblclick', editMarkerDblClickCallback($scope));

        $scope.$watch('editOperacao.lat + editOperacao.lng', function(newValue, oldValue) {
            if (newValue !== oldValue) {
                var pos = editMarker.getPosition(),
                    latitude = pos.lat(),
                    longitude = pos.lng();
                if ($scope.editOperacao.lat !== latitude || $scope.editOperacao.lng !== longitude)
                    editMarker.setPosition(new google.maps.LatLng($scope.editOperacao.lat || 0, $scope.editOperacao.lng || 0));
            }
        });

        $scope.$watch('controls.editOperacao + controls.editOperacaoId', function() {
            var pos, operacao = operacaoControlsService.editOperacaoId !== NEW_RECORD_ID && operacoesService.getOperacaoById(operacaoControlsService.editOperacaoId);
            infoWindowService.close();
            if (operacaoControlsService.editOperacao) {
                if (operacao) {
                    $scope.editOperacao = {
                        id: operacao.id,
                        title: operacao.title,
                        desc: operacao.desc,
                        operacaoInicio: operacao.operacaoInicio,
                        operacaoTermino: operacao.operacaoTermino,
                        tipo: operacao.tipo,
                        lat: operacao.lat,
                        lng: operacao.lng,
                        radius: operacao.radius,
                        comp: operacao.completed,
                        saveMsg: "Atualizar",
                        cancelMsg: "Cancelar"
                    };
                } else {
                    pos = mapService.getLatLng();
                    $scope.editOperacao = {
                        id: NEW_RECORD_ID,
                        lat: pos.lat,
                        lng: pos.lng,
                        operacaoInicio: "",
                        operacaoTermino: "",
                        tipo: 0,
                        radius: 100,
                        saveMsg: "Salvar",
                        cancelMsg: "Cancelar"
                    };
                }
                editMarker.setMap(mapService.getMap());
            }
        });

        $scope.submitOperacao = function() {
            if ($scope.editOperacaoForm.$valid) {
                if ($scope.editOperacao.id === NEW_RECORD_ID)
                    addOperacao();
                else
                    editOperacao();
            }
        }

        $scope.resetCloseOperacaoForm = function() {
            editMarker.setMap(null);
            operacaoControlsService.editOperacao = false;
            operacaoControlsService.editOperacaoId = NEW_RECORD_ID;
            $scope.editOperacao = {};
        }

        function addOperacao() {
            operacoesService.addOperacao(
                $scope.editOperacao.title,
                $scope.editOperacao.desc,
                $scope.editOperacao.operacaoInicio,
                $scope.editOperacao.operacaoTermino,
                $scope.editOperacao.tipo,
                $scope.editOperacao.lat,
                $scope.editOperacao.lng,
                $scope.editOperacao.radius);
            $scope.resetCloseOperacaoForm();
        }

        function editOperacao() {
            operacoesService.updateOperacao(
                $scope.editOperacao.id,
                $scope.editOperacao.title,
                $scope.editOperacao.desc,
                $scope.editOperacao.operacaoInicio,
                $scope.editOperacao.operacaoTermino,
                $scope.editOperacao.tipo,
                $scope.editOperacao.lat,
                $scope.editOperacao.lng,
                $scope.editOperacao.radius,
                $scope.editOperacao.comp);
            $scope.resetCloseOperacaoForm();
        }
    });
