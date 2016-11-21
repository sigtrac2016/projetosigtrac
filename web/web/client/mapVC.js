/*
===========================================================================
                    Mapa - Controller AngularJS
===========================================================================
*/

function getSegmentColorByChar(c) {
    switch (c) {
        case 'p':
            return "blue";
        case 'h':
            return "red";
        case 'f':
            return "black";
        case 'c':
            return "green";
        default:
            return "#aaaa";
    }
}

function getNewId() {
    var max = 1;
    for (var key in jsonOfJsons) {
        if (jsonOfJsons.hasOwnProperty(key)) {
            var json = jsonOfJsons[key];
            if (json.id > max)
                max = json.id;
        }
    }
    return max + 1;
}

function newJson(id, lat, lng) {
    var dt = new Date();
    var date = dt.getFullYear() + "-" + dt.getMonth() + "-" + dt.getDay() + " " +
        dt.getHours() + ":" + dt.getMinutes() + ":" + dt.getSeconds();
    var json = {
        "id": id, // gerado pelo BD 
        "titulo": "titulo1", // string vazia ou não 
        "segmento": 'p', // char com a letra referente ao segmento 
        "descricao": "descricao1", // string vazia ou não 
        "lat": lat, //latitude 
        "long": lng, //longitude 
        "foto": ["foto1", "foto2"], // array de strings, vazio ou contendo URL das fotos 
        "status": "nao-iniciado", // não-iniciado, iniciado, cancelado, reforços, finalizado ** 
        "data_hora": date // formato padrão de timestamp 
    };
    return json;
}

function getJsonOfJsons() {
    var json1 = {
        "id": 5, // gerado pelo BD 
        "titulo": "titulo1", // string vazia ou não 
        "segmento": 'p', // char com a letra referente ao segmento 
        "descricao": "descricao1", // string vazia ou não 
        "lat": -23.21, //latitude 
        "long": -45.87, //longitude 
        "foto": ["foto1", "foto2"], // array de strings, vazio ou contendo URL das fotos 
        "status": "nao-iniciado", // não-iniciado, iniciado, cancelado, reforços, finalizado ** 
        "data_hora": "2016-11-07 18:03:00" // formato padrão de timestamp 
    };
    var json2 = {
        "id": 6, // gerado pelo BD 
        "titulo": "titulo2", // string vazia ou não 
        "segmento": 'h', // char com a letra referente ao segmento 
        "descricao": "descricao2", // string vazia ou não 
        "lat": -23.208, //latitude 
        "long": -45.87, //longitude 
        "foto": ["foto1", "foto2"], // array de strings, vazio ou contendo URL das fotos 
        "status": "iniciado", // não-iniciado, iniciado, cancelado, reforços, finalizado ** 
        "data_hora": "2016-11-07 18:04:00" // formato padrão de timestamp 
    };
    jsonOfJsons = { "5": json1, "6": json2 };
    return jsonOfJsons;
}

app.controller("mapVC", function($scope, $http, $compile) {
    /***********************************************
                Initializes map and stuff
    ***********************************************/


    // Initializes map
    $scope.map = new google.maps.Map(document.getElementById("map"), {
        center: my_position,
        zoom: 14
    });

    $scope.heatmap = new google.maps.visualization.HeatmapLayer({
        data: getPoints(),
        map: null,
        radius: 200
    });

    // Initializes infowindow 
    $scope.infowindow = new google.maps.InfoWindow({
        content: $scope.contentString
    })

    // Routes API 
    var directionsService = new google.maps.DirectionsService;
    var directionsDisplay = new google.maps.DirectionsRenderer;
    directionsDisplay.setMap($scope.map);

    /*********************************************** 
                    Toggle Heatmap 
    ***********************************************/

    /* Atualiza o Heatmap quando array de marcadores mudar */
    $scope.updateHeatmap = function() {
        $scope.heatmap.setMap(null);
        $scope.heatmap = new google.maps.visualization.HeatmapLayer({
            data: getPoints(),
            map: $scope.map,
            radius: 100
        });
    }
    $scope.updateHeatmap();

    function getPoints() {
        var points = [];
        if ($scope.markers == undefined) return [];
        $scope.markers.forEach(function(marker) {
            if (marker.icon.fillColor == segmentoColor(segmento) ||
                segmento == "global" && marker.position != undefined)
                points.push(new google.maps.LatLng(
                    marker.position.lat(), marker.position.lng()));
        });
        return points;
    }

    $scope.toggleHeatmap = function() {
        $scope.heatmap.setMap($scope.heatmap.getMap() ? null : $scope.map);
    }

    $scope.changeRadius = function() {
        $scope.heatmap.set('radius', ($scope.heatmap.get('radius') + 30) % 300);
    }

    $scope.changeOpacity = function() {
        $scope.heatmap.set('opacity', $scope.heatmap.get('opacity') ? null : 0.2);
    }


    /*********************************************** 
                Creates new $scope.markers 
    ***********************************************/

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
            $scope.genContentString(marker);
            $scope.map.setCenter(marker.getPosition());
            $scope.selection = marker;
            $scope.infowindow.setContent("<div id=\'infowindow'></div>");
            $scope.infowindow.open($scope.map, marker);
            $("#infowindow").html($compile($scope.contentString)($scope));
        });
        google.maps.event.addListener(marker, 'dragend', function() {
            $scope.updateHeatmap();
        });
        $scope.markers.push(marker);
        $scope.updateHeatmap();
    }

    var jsonOfJsons = getJsonOfJsons();

    for (var key in jsonOfJsons) {
        if (jsonOfJsons.hasOwnProperty(key)) {
            var json = jsonOfJsons[key];
            var pos = { lat: json.lat, lng: json.long };
            var color = getSegmentColorByChar(json.segmento)
            $scope.createMarker(key, pos, color);
        }
        /* 
        for (var i = 1; i <= len; i++) { 
            var indexString=i.toString(); 
            var json=jsonOfJsons[indexString]; 
            var pos = {lat: json.lat , lng: json.long};         
            var color =getSegmentColorByChar(json.segmento) 
            $scope.createMarker(indexString,pos, color); 
        }*/
    }

    /*********************************************** 
                    Routes Service 
    ***********************************************/
    $scope.displayRoute = function() {
        directionsService.route({
            origin: $scope.my_position_marker.getPosition(),
            destination: $scope.selection.getPosition(),
            travelMode: google.maps.TravelMode.DRIVING
        }, function(response, status) {
            if (status === google.maps.DirectionsStatus.OK) {
                directionsDisplay.setDirections(response);
                var route = response.routes[0];
                var routeHTML = '';
                // For each route, display summary information. 
                for (var i = 0; i < route.legs.length; i++) {
                    var routeSegment = i + 1;
                    routeHTML +=
                        '<h4>Route Segment: ' + routeSegment + ' - ' +
                        route.legs[i].distance.text + '</h4>' +
                        '<b>From: </b>' + route.legs[i].start_address + '<br>' +
                        '<b>To: </b>' + route.legs[i].end_address + '<br>';
                }
                $scope.infowindow.setContent(routeHTML);
            } else window.alert('Directions request failed due to ' + status);
        });
    }

    /*********************************************** 
                Getting my position 
    ***********************************************/

    $scope.openMyPosition = function(marker) {
        $scope.infowindow.setPosition($scope.my_position);
        $scope.infowindow.setContent('<h3>Sua localização</h3><p><b>Coordenadas: </b>{' +
            $scope.my_position.lat.toFixed(3) + ', ' + $scope.my_position.lng.toFixed(3) + '}');
        $scope.infowindow.open($scope.map, marker);
        $scope.map.setCenter($scope.my_position);
    }

    // My position marker
    $scope.myPositionMarker = function(my_position) {
        $scope.my_position = my_position;
        var marker = new google.maps.Marker({
            position: $scope.my_position,
            map: $scope.map,
            draggable: true,
            icon: pinSymbol('white')
        });
        $scope.my_position_marker = marker;
        $scope.openMyPosition(marker);

        marker.addListener('click', function(event) {
            $scope.map.setCenter(marker.getPosition());
            $scope.openMyPosition(marker);
        });

        google.maps.event.addListener(marker, 'dragend', function() {
            $scope.my_position = {
                'lat': marker.getPosition().lat(),
                'lng': marker.getPosition().lng()
            }
            $scope.openMyPosition(marker);
        });
    }

    // Try HTML5 geolocation. 
    if (navigator.geolocation && Object.keys(navigator.geolocation).length > 0) {
        navigator.geolocation.getCurrentPosition(function(position) {
            $scope.myPositionMarker({
                lat: position.coords.latitude,
                lng: position.coords.longitude
            });
        });
    } else $scope.myPositionMarker(my_position);

    /***********************************************/


    $scope.genericPointModel = {
        "id": "", // gerado pelo BD
        "titulo": "Ambulância 386", // string vazia ou nao
        "segmento": "F", // char com a letra referente ao segmento
        "descricao": "Princípio de Incêndio", // string vazia ou nao
        "feedback": "Princípio de Incêndio", // string vazia ou nao
        "url_icone": "https://maxcdn.icons8.com/iOS7/PNG/50/Users/fireman-50.png", // array de strings, vazio ou contendo URL das fotos        "lat": "", //latitude
        "long": "", //longitude
        "endereco": "",
        "foto": "http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg", // array de strings, vazio ou contendo URL das fotos
        "status": "reforcos", // nao-iniciado, iniciado, cancelado, reforcos, finalizado **
        "data_hora": "" // formato padrão de timestamp
    }

    var imageIconModel = $scope.genericPointModel.url_icone;


    $scope.createGenericPoint = function() {
        var marker = new google.maps.Marker({
            position: positions2[i],
            map: $scope.map,
            draggable: true,
            icon: imageIconModel
        });
        marker.addListener('click', function(event) {
            $scope.genContentString2(event.latLng);
            $scope.map.setCenter(marker.getPosition());
            $scope.selection = marker;
            $scope.infowindow.setContent("<div id=\'infowindow'></div>");
            $scope.infowindow.open($scope.map, marker);
            $("#infowindow").html($compile($scope.contentString)($scope));
        });
        $scope.markers.push(marker);
    }

    for (var i = 0; i < 6; i++) {
        $scope.createMarker();
    }

    for (var i = 0; i < 1; i++) {
        $scope.createGenericPoint();
    }



    // Initializes infowindow
    $scope.infowindow = new google.maps.InfoWindow({
        content: $scope.contentString
    })

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
            $scope.genContentString(new_marker);
            $scope.map.setCenter(new_marker.getPosition());
            $scope.selection = new_marker;
            $scope.infowindow.setContent("<div id=\'infowindow\'></div>");
            $scope.infowindow.open($scope.map, new_marker);
            $("#infowindow").html($compile($scope.contentString)($scope));
        });
        $scope.markers.push(new_marker);
        google.maps.event.addListener(new_marker, 'dragend', function() {
            $scope.updateHeatmap();
        });
        $scope.markers.push(new_marker);
        $scope.updateHeatmap();
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

    $scope.colorMarker = function(color, segmento) {
        $scope.selection.setIcon(pinSymbol(color));
        $scope.ocurrenceModel.segmento = segmento;
    }

    $scope.deleteMarker = function(param) {
        $scope.selection.setMap(null);
        // Remove o marcador e salva os dados
        $scope.markers.splice($scope.markers.indexOf($scope.selection), 1);
    }


    $scope.ocurrenceModel = {
        "id": "", // gerado pelo BD
        "titulo": "Alerta de Incendio ", // string vazia ou nao
        "segmento": "P", // char com a letra referente ao segmento
        "descricao": "Princípio de Incêndio", // string vazia ou nao
        "lat": "", //latitude
        "long": "", //longitude
        "endereco": "",
        "foto": "http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg", // array de strings, vazio ou contendo URL das fotos
        "status": "reforcos", // nao-iniciado, iniciado, cancelado, reforcos, finalizado **
        "data_hora": "" // formato padrão de timestamp
    }





    $scope.genContentString = function(marker) {
        var coor = { lat: marker.position.lat(), lng: marker.position.lng() };
        var obj = marker.obj;
        var distance = getDistance($scope.my_position, coor).toFixed(2);
        $scope.contentString = '<div id="content">' +
            '<h4>{{ ocurrenceModel.titulo }}</h4>' +
            '<div>' +
            '<textarea readonly ng-model="ocurrenceModel.descricao" rows="2" cols="90">' +
            '</textarea>' +
            '<p><b>Horário de ocorrência: </b> 13:30h&nbsp;&nbsp' +
            '<b>Coordenadas: </b>{' + coor.lat.toFixed(3) + ', ' + coor.lng.toFixed(3) + '}    ' +
            '<b>Distância: </b>' + distance + ' km</p>' +
            '<p><a href="{{ocurrenceModel.foto}}">Fotos do alerta</a> ' +
            '<button class="btn btn-default" ng-click="displayRoute()">Calcular Rota</button></p>';
        if (segmento == 'global')
            $scope.contentString +=
            '<h4>Delegar segmento</h4>' +
            '<button class="btn btn-primary" ng-click="colorMarker(\'blue\', \'P\')">POLICE DEPARTMENT</button> ' +
            '<button class="btn btn-danger" ng-click="colorMarker(\'red\', \'H\')">HEALTH CARE</button> ' +
            '<button class="btn btn-default" ng-click="colorMarker(\'black\', \'F\')">FIRE DEPARTMENT</button> ' +
            '<button class="btn btn-success" ng-click="colorMarker(\'green\', \'C\')">CIVIL DEFENSE</button> ' +
            '<hr>' +
            '<h4>Comandos:</h4>' +
            '<b>Status:</b>&nbsp;&nbsp;&nbsp;&nbsp' +
            '<select class="selectpicker" ng-model="ocurrenceModel.status">' +
            '<option value="nao-iniciado">Não Iniciado</option>' +
            '<option value="iniciado">Iniciado</option>' +
            '<option value="cancelado">Cancelado</option>' +
            '<option value="reforcos">Reforços</option>' +
            '<option value="finalizado">Finalizadp</option>' +
            '</select>';
        $scope.contentString +=
            //'<button class="btn btn-warning" ng-click="deleteMarker()">Alerta falso</button> ' +
            //'<button class="btn btn-default" ng-click="deleteMarker()">Alerta de Reforços</button>' +
            '&nbsp;&nbsp;&nbsp;&nbsp<button class="btn btn-default" ng-click="sendOccurrence()">Salvar</button> ' +
            '<button class="btn btn-danger" ng-click="deleteMarker()">Finalizar alerta</button> ' +
            '</div>' +
            '</div>';
    }


    $scope.genContentString2 = function(coor) {
        var coor = { lat: coor.lat(), lng: coor.lng() };
        var distance = getDistance($scope.my_position, coor).toFixed(2);
        $scope.contentString = '<div id="content">' +
            '<h4>{{ genericPointModel.titulo }}' +
            '<button ng-if="genericPointModel.segmento==\'P\'" class="btn btn-primary">POLICE DEPARTMENT</button>' +
            '<button ng-if="genericPointModel.segmento==\'H\'" class="btn btn btn-danger">HEALTH CARE</button>' +
            '<button ng-if="genericPointModel.segmento==\'F\'" class="btn btn btn-default">FIRE DEPARTMENT</button>' +
            '<button ng-if="genericPointModel.segmento==\'C\'" class="btn btn btn-success">CIVIL DEFENSE</button>' +
            '</h4>' +
            '<textarea readonly ng-model="ocurrenceModel.descricao" rows="2" cols="90">' +
            '</textarea>' +
            '<p><b>Horário de ocorrência: </b> 13:30h&nbsp;&nbsp' +
            '<b>Coordenadas: </b>{' + coor.lat.toFixed(3) + ', ' + coor.lng.toFixed(3) + '}    ' +
            '<b>Distância: </b>' + distance + ' km</p>' +
            '<p><a href="{{ocurrenceModel.foto}}">Fotos do alerta</a> ' +
            '<button class="btn btn-default" ng-click="displayRoute()">Calcular Rota</button></p>';;
        if (segmento == 'global')
            $scope.contentString +=
            '<p><b>Entrada Operador:</b></p>' +
            '<textarea ng-model="ocurrenceModel.feedback" rows="2" cols="90">' +
            '</textarea>' +
            '<h4>Comandos:</h4>' +
            '<b>Status:</b>&nbsp;&nbsp;&nbsp;&nbsp' +
            '<select class="selectpicker" ng-model="ocurrenceModel.status">' +
            '<option value="nao-iniciado">Não Iniciado</option>' +
            '<option value="iniciado">Iniciado</option>' +
            '<option value="cancelado">Cancelado</option>' +
            '<option value="reforcos">Reforços</option>' +
            '<option value="finalizado">Finalizadp</option>' +
            '</select>';
        $scope.contentString +=
            //'<button class="btn btn-warning" ng-click="deleteMarker()">Alerta falso</button> ' +
            //'<button class="btn btn-default" ng-click="deleteMarker()">Alerta de Reforços</button>' +
            '&nbsp;&nbsp;&nbsp;&nbsp<button class="btn btn-default" ng-click="sendOccurrence()">Salvar</button> ' +
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


    /***********************************************
                Envio de Upload ocorrencia
    ***********************************************/
    $scope.sendOccurrence = function() {

        $http.post('/api/v0/upload-ocorrencia', $scope.ocurrenceModel, success, failure);

        function success(data) {
            console.log(data);
        }

        function failure(err) {

        }
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
]

var positions2 = [

    { lat: -23.21, lng: -45.89 }
]

// ITA position
var my_position = {
    lat: -23.20,
    lng: -45.86
};