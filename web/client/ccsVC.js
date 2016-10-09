/*
===========================================================================
            Central de Comando e Controle - Controller AngularJS
===========================================================================
*/

var app = angular.module('ccs', []);
var segmento = getUrlParameter("segmento");

app.controller("ccsVC", function($scope, $http) {

    $.getJSON("/data/segmentos.json", function(data) {
        $scope.segmentos = data;
        $scope.segmentos.forEach(function(seg) {
            if (seg.url.indexOf(segmento) != -1)
                $scope.segmento = seg;
        });
        $(".navbar-inverse").css('background-color', $scope.segmento.navcolor);
        $scope.$apply();
    });
});