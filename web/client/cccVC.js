/*
===========================================================================
            Central de Comando e Controle - Controller AngularJS
===========================================================================
*/

var app = angular.module('ccc', []);
var segmento = "global";

app.controller("cccVC", function($scope, $http) {

    $.getJSON("/data/segmentos.json", function(data) {
        $scope.segmentos = data;
        $scope.$apply();
    });
});