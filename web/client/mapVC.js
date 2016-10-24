/*===========================================================================
                  Mapa - Controller AngularJS
===========================================================================
*/

app.controller("mapVC", function($scope, $http, $compile) {
    /***********************************************
                Initializes map and stuff
    ***********************************************/
    // Initializes map
    $scope.map = new google.maps.Map(document.getElementById("map"), {
        center: my_position,
        zoom: 14
    });

    $scope.markers = [];
    $scope.contentString = "<div id='infowindow'></div>";

    $scope.createMarker = function() {
        var marker = new google.maps.Marker({
            position: positions[i],
            map: $scope.map,
            draggable: true,
            icon: pinSymbol(colors[i])
        });
        marker.addListener('click', function(event) {
            $scope.genContentString(event.latLng);
            $scope.map.setCenter(marker.getPosition());
            $scope.selection = marker;
            $scope.infowindow.setContent("<div id=\'infowindow'></div>");
            $scope.infowindow.open($scope.map, marker);
            $("#infowindow").html($compile($scope.contentString)($scope));
        });
        $scope.markers.push(marker);
    }

    for (var i = 0; i < 7; i++) {
        $scope.createMarker();
    }

    // Initializes infowindow
    $scope.infowindow = new google.maps.InfoWindow({
        content: $scope.contentString
    })


    /***********************************************
                    Toggle Heatmap
    ***********************************************/

    $scope.heatmap = new google.maps.visualization.HeatmapLayer({
        data: getPoints(),
        map: null,
        radius: 60
    });

    function getPoints() {
        var points = [];
        $scope.markers.forEach(function(marker) {
            points.push(new google.maps.LatLng(
                marker.position.lat(), marker.position.lng()));
        });
        return points;
    }

    $scope.toggleHeatmap = function() {
        $scope.heatmap.setMap($scope.heatmap.getMap() ? null : $scope.map);
    }

    $scope.changeRadius = function() {
        $scope.heatmap.set('radius', $scope.heatmap.get('radius') ? null : 60);
    }

    $scope.changeOpacity = function() {
        $scope.heatmap.set('opacity', $scope.heatmap.get('opacity') ? null : 0.2);
    }

    /***********************************************
                Creates new $scope.markers
    ***********************************************/

    // Event to create a new marker
    google.maps.event.addListener($scope.map, 'click', function(event) {
        var new_marker = new google.maps.Marker({
            position: event.latLng,
            map: $scope.map,
            draggable: true,
            icon: pinSymbol(fillMarker())
        });
        new_marker.addListener('click', function(event) {
            $scope.genContentString(event.latLng);
            $scope.map.setCenter(new_marker.getPosition());
            $scope.selection = new_marker;
            $scope.infowindow.setContent("<div id=\'infowindow\'></div>");
            $scope.infowindow.open($scope.map, new_marker);
            $("#infowindow").html($compile($scope.contentString)($scope));
        });
        $scope.markers.push(new_marker);
    });

    /***********************************************
                Displays alert information
    ***********************************************/

    // Creates a custom color pin
    function pinSymbol(color) {
        return {
            path: 'M 0,0 C -2,-20 -10,-22 -10,-30 A 10,10 0 1,1 10,-30 C 10,-22 2,-20 0,0 z M -2,-30 a 2,2 0 1,1 4,0 2,2 0 1,1 -4,0',
            fillColor: color,
            fillOpacity: 1,
            strokeColor: '#000',
            strokeWeight: 2,
            scale: 1,
        };
    }

    $scope.colorMarker = function(color) {
        $scope.selection.setIcon(pinSymbol(color));
    }

    $scope.deleteMarker = function(param) {
        $scope.selection.setMap(null);
        // Remove o marcador e salva os dados
        $scope.markers.splice($scope.markers.indexOf($scope.selection), 1);
    }

    $scope.genContentString = function(coor) {
        $scope.contentString = '<div id="content">' +
            '<h1 >Alerta de Incêndio</h1>' +
            '<div>' +
            '<p><b>Horário de ocorrência: </b> 13:30h</p>' +
            '<p><b>Coordenadas: </b>' + coor + '</p>' +
            '<p><a href="http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg">Fotos do alerta</a></p> ';
        if (segmento == 'global')
            $scope.contentString +=
            '<h4>Delegar segmento</h4>' +
            '<button class="btn btn-primary" ng-click="colorMarker(\'blue\')">Segmento 1</button> ' +
            '<button class="btn btn-danger" ng-click="colorMarker(\'red\')">Segmento 2</button> ' +
            '<button class="btn btn-default" ng-click="colorMarker(\'black\')">Segmento 3</button> ' +
            '<button class="btn btn-success" ng-click="colorMarker(\'green\')">Segmento 4</button> ';
        $scope.contentString +=
            '<hr>' +
            '<h4>Comandos:</h4>' +
            '<button class="btn btn-warning" ng-click="deleteMarker()">Alerta falso</button> ' +
            '<button class="btn btn-default" ng-click="deleteMarker()">Alerta de Reforços</button>' +
            '<button class="btn btn-danger" ng-click="deleteMarker()">Finalizar alerta</button> ' +
            '</div>' +
            '</div>';
    }

    $scope.deleteMarkers = function() {
        if (segmento != 'global') {
            for (var i = 0; i < $scope.markers.length; i++) {
                if ($scope.markers[i].icon.fillColor != segmentoColor(segmento)) {
                    $scope.markers[i].setMap(null);
                }
            }
        }
    }

    // Função para ajudar o Mock
    $scope.deleteMarkers();

    function fillMarker() {
        return segmentoColor(segmento);
    }

    /* Método para invocar FullScreen */
    $scope.fullscreen = function() {
        if (!screenfull.isFullscreen) {
            $("#map").css("height", "100%");
            $("#mapVC").css("height", "100%");
            $("#mapVC").css("width", "100%");
        } else {
            $("#map").css("height", "500px");
            $("#mapVC").css("height", "");
            $("#mapVC").css("width", "");
        }
        screenfull.toggle($("#mapVC")[0]);
    }

});

/* Detecta Esc para sair de FullScreen*/
$(document).keyup(function(e) {
    if (e.keyCode == 27) {
        $("#map").css("height", "500px");
        $("#mapVC").css("height", "");
        $("#mapVC").css("width", "");
        screenfull.toggle($("#mapVC")[0]);
        screenfull.exit($("#mapVC")[0]);
    }
});


function reload_js(src) {
    $('script[src="' + src + '"]').remove();
    $('<script>').attr('src', src).appendTo('head');
}

function loadMap() {}

var colors = [
    "#aaa", "blue", "red", "green", "black", "red", "red", "red", "red"
]
var positions = [
    { lat: -23.21, lng: -45.87 },
    { lat: -23.21, lng: -45.872 },
    { lat: -23.208, lng: -45.87 },
    { lat: -23.20, lng: -45.87 },
    { lat: -23.22, lng: -45.87 },
    { lat: -23.20, lng: -45.88 },
    { lat: -23.22, lng: -45.86 },
    { lat: -23.20, lng: -45.89 },
    { lat: -23.21, lng: -45.89 }
]

// ITA position
var my_position = {
    lat: -23.21,
    lng: -45.87
};