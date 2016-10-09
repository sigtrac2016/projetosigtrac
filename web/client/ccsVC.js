/*
===========================================================================
            Central de Comando e Controle - Controller AngularJS
===========================================================================
*/

var app = angular.module('ccs', []);
var segmento = "health";

app.controller("ccsVC", function($scope, $http) {

    // Replicação de segmentos no Painel de Legenda
    $scope.segmentos = [
        { name: 'POLICE DEPARTMENT', color: 'blue', icon: 'fa fa-map-marker', url: '/ccs' },
        { name: 'HEALTH CARE', color: 'red', icon: 'fa fa-map-marker', url: '/ccs' },
        { name: 'FIRE DEPARTMENT', color: 'black', icon: 'fa fa-map-marker', url: '/ccs' },
        { name: 'CIVIL DEFENSE', color: 'green', icon: 'fa fa-map-marker', url: '/ccs' },
        { name: 'Não designado', color: 'gray', icon: 'fa fa-map-marker', url: '' },
        { name: 'Sensor', color: 'red', icon: 'fa fa-heartbeat', url: '' }
    ];

});