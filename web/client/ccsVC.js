/*
===========================================================================
            Central de Comando e Controle - Controller AngularJS
===========================================================================
*/

var app = angular.module('ccs', []);

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

function genContentString(coor) {
    contentString = '<div id="content">' +
        '<h1 >Alerta de Incêndio</h1>' +
        '<div>' +
        '<p><b>Horário de ocorrência: </b> 13:30h</p>' +
        '<p><b>Coordenadas: </b>' + coor + '</p>' +
        '<p><a href="http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg">Fotos do alerta</a></p> ' +
        '<hr>' +
        '<h4>Comandos:</h4>' +
        '<button class="btn btn-warning" onclick="deleteMarker()">Alerta falso</button> ' +
        '<button class="btn btn-default" onclick="deleteMarker()">Alerta de Reforços</button>' +
        '<button class="btn btn-danger" onclick="deleteMarker()">Finalizar alerta</button> ' +
        '</div>' +
        '</div>';
}

function deleteMarkers(markers) {
    for (var i = 0; i < markers.length; i++) {
        if (markers[i].icon.fillColor != "#ff0000") {
            markers[i].setMap(null);
        }
    }
}

function fillMarker() {
    return "#ff0000";
}