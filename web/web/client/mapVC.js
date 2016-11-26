/*
 ===========================================================================
 Mapa - Controller AngularJS
 ===========================================================================
 */

var apiURL = "http://localhost:8080/api/chamados/";
var nSeconds = 15;



/* Templates used to render HTML */

app.directive('menu', function() {
    return { restrict: "E", templateUrl: "menu.html" };
});
app.directive('menugen', function() {
    return { restrict: "E", templateUrl: "menuGen.html" };
});
app.directive('position', function() {
    return { restrict: "E", templateUrl: "position.html" };
});
app.directive('route', function() {
    return { restrict: "E", templateUrl: "route.html" };
});
app.directive('drone', function() {
    return { restrict: "E", templateUrl: "drone.html" };
});

app.controller("mapVC", function($scope, $http, $compile, $interval) {

    /***********************************************
     Initializes map and stuff
     ***********************************************/
    $scope.markers = [];
    $scope.segmento = segmento;
    function serializeData( data ) {
        var buffer = [];
        // Serialize each key in the object.
        for ( var name in data ) {
            if ( ! data.hasOwnProperty( name ) ) {
                continue;
            }
            var value = data[ name ];
            buffer.push(
                encodeURIComponent( name ) +
                "=" +
                encodeURIComponent( ( value == null ) ? "" : value )
            );
        }
        // Serialize the buffer and clean it up for transportation.
        var source = buffer
            .join( "&" )
            .replace( /%20/g, "+" )
        ;
        return( source );
    }
    arrayOfJsons = [];
    function getSegmentColorByChar(c){
        switch (c){
            case 'p':
                return "blue";
            case 'h':
                return "red";
            case 'f':
                return "black";
            case 'c':
                return "green";
            default:
                return "#aaa";
        }
    }
    
    // Initializes map
    $scope.map = new google.maps.Map(document.getElementById("map"), {
        center: my_position,
        zoom: 14
    });

    $scope.updateArrayOfJsons = function(json){
        correctdata = serializeData(json);
        $scope.makePostRequest(json, correctdata);        
        $scope.makeGetRequest();        
    }
    $scope.makePostRequest = function(json, correctdata){    
        $http({
            method: 'POST',
            url: apiURL,
            data: correctdata,
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            }
        }).then(
            function(response){
                // success callback
                console.log("Colocou: " + json)
                //make get request
            }, 
            function(response){
                // failure callback
                console.log("Failed to load data")
            }
        );
    }

    $scope.heatmap = new google.maps.visualization.HeatmapLayer({
        data: getPoints(),
        map: null,
        radius: 200
    });

    // Initializes infowindow 
    $scope.infowindow = new google.maps.InfoWindow({
        content: "<div id='infowindow'></div>"
        ///content: $scope.contentString
    });

    // Routes API 
    var directionsService = new google.maps.DirectionsService;
    var directionsDisplay = new google.maps.DirectionsRenderer;
    directionsDisplay.setMap($scope.map);

    $scope.getDistance = function(coor) {
        $scope.coor = { lat: coor.lat(), lng: coor.lng() };
        $scope.distance = getDistance($scope.my_position, $scope.coor).toFixed(2);
    }

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
                segmento == "global")
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
    $scope.contentString = "<div id='infowindow'></div>";

    /*********************************************** 
     Creates new $scope.markers 
     ***********************************************/

    $scope.markers = [];

    $scope.createMarker = function(elem) {
        var pos = {lat: elem.lat , lng: elem.long};
        var color =getSegmentColorByChar(elem.segmento);

        var marker = new google.maps.Marker({
            position: positions[i],
            map: $scope.map,
            draggable: true,
            obj: elem,
            icon: pinSymbol(colors[i])
        });

        marker.addListener('click', function(event) {
            $scope.genContentString(this.obj);
            $scope.map.setCenter(this.getPosition());
            $scope.selection = this;
            $scope.infowindow.setContent("<div id=\'infowindow'></div>");
            $scope.infowindow.open($scope.map, this);
            $("#infowindow").html($compile($scope.contentString)($scope));
            $scope.getDistance(marker.position);
            //$("#infowindow").html($compile('<menu/>')($scope));
            $scope.infowindow.setPosition(marker.getPosition());
        });
        google.maps.event.addListener(marker, 'dragend', function() {
            $scope.updateHeatmap();
        });
        $scope.markers.push(marker);
        $scope.updateHeatmap();
    }////

    

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
                $scope.route = response.routes[0].legs;
                $("#infowindow").html($compile('<route/>')($scope));
                $scope.infowindow.setPosition($scope.selection.getPosition());
                $scope.map.setCenter($scope.selection.getPosition());
            } else
                alert('Directions request failed due to ' + status);
        });
    }

    /*********************************************** 
     Getting my position 
     ***********************************************/

    $scope.openMyPosition = function(marker) {
        $scope.getDistance(marker.position);
        $scope.infowindow.open($scope.map, marker);
        $("#infowindow").html($compile('<position/>')($scope));
        $scope.infowindow.setPosition(marker.getPosition());
        $scope.map.setCenter(marker.getPosition());
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

    // Espera a tela carregar o infowindow
    setTimeout(function() {
        $scope.pickPosition();
    }, 1000);

    $scope.pickPosition = function() {
        // Try HTML5 geolocation. 
        if (navigator.geolocation && Object.keys(navigator.geolocation).length > 0) {
            navigator.geolocation.getCurrentPosition(function(position) {
                $scope.myPositionMarker({
                    lat: position.coords.latitude,
                    lng: position.coords.longitude
                });
            });
        } else
            $scope.myPositionMarker(my_position);
    }

    /***********************************************/


    $scope.genericPointModel = {
        "id": "", // gerado pelo BD
        "titulo": "Colinas's Shopping", // string vazia ou nao
        "segmento": "C", // char com a letra referente ao segmento
        "descricao": "After a tempest [...]", // string vazia ou nao
        "feedback": "Please, add an information here...", // string vazia ou nao
        "url_icone": "https://maxcdn.icons8.com/iOS7/PNG/50/Users/fireman-50.png", // array de strings, vazio ou contendo URL das fotos        "lat": "", //latitude
        "long": "", //longitude
        "endereco": "",
        "foto": "http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg", // array de strings, vazio ou contendo URL das fotos
        "status": "reinforcements", // nao-iniciado, iniciado, cancelado, reforcos, finalizado **
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
            $scope.getDistance(event.latLng);
            $scope.selection = marker;
            $scope.infowindow.open($scope.map, marker);
            $("#infowindow").html($compile('<menugen/>')($scope));
            $scope.infowindow.setPosition(marker.getPosition());
            $scope.map.setCenter(marker.getPosition());
        });
        $scope.markers.push(marker);
        $scope.updateHeatmap();
    }

    for (var i = 0; i < 6; i++) {
        $scope.createMarker(positions[i]);
    }

    for (var i = 0; i < 1; i++) {
        $scope.createGenericPoint();
    }

    /***********************************************
     Creates new air drone
     ***********************************************/
    $http.get('/airDrone')
        .then(function success(data) {
            data = data.data;
            var marker = new google.maps.Marker({
                position: { lat: data['lat'], lng: data['lon'] },
                map: $scope.map,
                icon: 'https://cdn3.iconfinder.com/data/icons/faticons/32/send-01-48.png',
                title: 'drone',
            });

            marker.addListener('click', function(event) {
                $scope.getDistance(marker.position);
                $scope.selection = marker;
                $scope.infowindow.open($scope.map, marker);
                $("#infowindow").html($compile("<drone\>")($scope));
                $scope.infowindow.setPosition(marker.getPosition());
                $scope.map.setCenter(marker.getPosition());
            });

            google.maps.event.addListener(marker, 'dragend', function() {
                $scope.updateHeatmap();
            });

            $scope.markers.push(marker);
            $scope.updateHeatmap();

        });
    /***********************************************
     Creates new $scope.markers
     ***********************************************/

    // Event to create a new marker
    google.maps.event.addListener($scope.map, 'click', function(event) {
        $scope.updateArrayOfJsons(newJson(event.latLng.lat(), event.latLng.lng()));
        var new_marker = new google.maps.Marker({
            position: event.latLng,
            map: $scope.map,
            draggable: true,
            icon: pinSymbol(fillMarker())
        });
        new_marker.addListener('click', function(event) {
            $scope.getDistance(new_marker.position);
            $scope.selection = new_marker;
            $scope.infowindow.setContent("<div id='infowindow'></div>");
            $scope.infowindow.open($scope.map, new_marker);
            $("#infowindow").html($compile('<menu/>')($scope));
            $scope.infowindow.setPosition(new_marker.getPosition());
            $scope.map.setCenter(new_marker.getPosition());
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
    $scope.makePatchRequest = function(id, json,correctdata) {        
        $http({
            method: 'PATCH',
            url: apiURL+id,
            data: correctdata,
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            }
        }).then(
            function(response){
                // success callback
                console.log("Colocou: " + json)
                //make get request
            }, 
            function(response){
                // failure callback
                console.log("Failed to load data")
            }
        );

    }
    $scope.colorMarker = function(id,color, segment) {
        $scope.ocurrenceModel.segmento = segment;

        var idDB=arrayOfJsons[$scope.markers.indexOf($scope.selection)]._id;
        $scope.selection.setIcon(pinSymbol(color));
        console.log("id"+id+" "+idDB)
        var json={
            "segmento":segment
        };
        correctdata = serializeData(json);
        $scope.makePatchRequest(idDB, json, correctdata);
        $scope.makeGetRequest();

    }

    $scope.deleteMarker = function() {
        var id=arrayOfJsons[$scope.markers.indexOf($scope.selection)]._id;
        console.log("id"+id);
        $scope.selection.setMap(null);
        // Remove o marcador e salva os dados
        $scope.deleteRequest(id);
        $scope.markers.splice($scope.markers.indexOf($scope.selection), 1);
        $scope.updateHeatmap();
    }
    $scope.falseAlert = function(param){
        //TODO
    }
    $scope.endAlert = function(param){
        //TODO
    }
    $scope.reinforcementAlert = function(param){
        //TODO
    }
    $scope.genContentString = function(m) {
        //var coor= {lat: m.lat, lng: m.long};
        var id = m.id;
        // TODO: Corrigir aqui
        $scope.contentString = '<div id="content">' +
            '<h1 >'+m.titulo+'</h1>' +
            '<div>' +
            '<p><b>Horário de ocorrência: </b>'+ m.data_hora  + '</p>' +
            '<p><b>Coordenadas: </b>{' + m.lat+', '+m.long + '}</p>' +
            '<p><a href="http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg">Fotos do alerta</a></p> ';
        if (segmento == 'global')
            $scope.contentString +=
            '<h4>Delegar segmento</h4>' +
            '<button class="btn btn-primary" ng-click="colorMarker('+id+',\'blue\',\'p\')">Segmento 1</button> ' +
            '<button class="btn btn-danger" ng-click="colorMarker('+id+',\'red\',\'h\')">Segmento 2</button> ' +
            '<button class="btn btn-default" style="color:white; background-color:black;" ng-click="colorMarker('+id+',\'black\',\'f\')">Segmento 3</button> ' +
            '<button class="btn btn-success" ng-click="colorMarker('+id+',\'green\',\'c\')">Segmento 4</button> ';
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
    
    arrayOfJsons.forEach($scope.createMarker);

    // Função para ajudar o Mock
    $scope.deleteMarkers();
    $scope.ocurrenceModel = {
        "id": "", // gerado pelo BD
        "titulo": "Fireman Alert", // string vazia ou nao
        "segmento": "F", // char com a letra referente ao segmento
        "descricao": "", // string vazia ou nao
        "lat": "", //latitude
        "long": "", //longitude
        "endereco": "",
        "foto": "http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg", // array de strings, vazio ou contendo URL das fotos
        "status": "reforcos", // nao-iniciado, iniciado, cancelado, reforcos, finalizado **
        "data_hora": "" // formato padrão de timestamp
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
    $scope.deleteRequest = function(id){
        $http({
            method: 'DELETE',
            url: apiURL+id,
            headers: {
                'Content-Type': 'application/json'
            }
        }).then(function successCallback(response){
            console.log("delete request")    
            
        }, function errorCallback(response){
            console.log("Error")
        });
    }
    $scope.loadMarkers = function(){
        // Paint the map
        $scope.markers.forEach(function (m){
            m.setMap(null);
        });
        $scope.markers = [];
        for (i = 0; i < arrayOfJsons.length; i++){
            if(getUrlParameter("segmento")==undefined || getUrlParameter("segmento")[0]==arrayOfJsons[i].segmento)
            {
                var pos = {lat: arrayOfJsons[i].lat , lng: arrayOfJsons[i].long};
                var color = getSegmentColorByChar(arrayOfJsons[i].segmento)
                var marker = new google.maps.Marker({
                    position: pos,
                    map: $scope.map,
                    draggable: true,
                    obj: arrayOfJsons[i],
                    icon: pinSymbol(color)
                });
                marker.addListener('click', function(event) {
                    $scope.genContentString(this.obj);
                    $scope.map.setCenter(this.getPosition());
                    $scope.selection = this;
                    $scope.infowindow.setContent("<div id=\'infowindow'></div>");
                    $scope.infowindow.open($scope.map, this);
                    $("#infowindow").html($compile($scope.contentString)($scope));
                });  
                $scope.markers.push(marker);
                $scope.updateHeatmap();
            }
        }
    }     
    $scope.makeGetRequest = function(){
        $http({
            method: 'GET',
            url: apiURL,
            headers: {
                'Content-Type': 'application/json'
            }
        }).then(function successCallback(response){
                arrayOfJsons = response.data;
                $scope.loadMarkers();
                // apply changes in view
                console.log("OK")
            
        }, function errorCallback(response){
            console.log("Error")
        });
    }
    $interval(
        function(){
            $scope.makeGetRequest();
        }, 
        nSeconds*1000
    );
    $scope.makeGetRequest();
    $scope.loadMarkers();
    function fillMarker() {
        return segmentoColor(segmento);
    }

    function serializeData( data ) {
        var buffer = [];
        // Serialize each key in the object.
        for ( var name in data ) {
            if ( ! data.hasOwnProperty( name ) ) {
                continue;
            }
            var value = data[ name ];
            buffer.push(
                encodeURIComponent( name ) +
                "=" +
                encodeURIComponent( ( value == null ) ? "" : value )
            );
        }
        // Serialize the buffer and clean it up for transportation.
        var source = buffer
            .join( "&" )
            .replace( /%20/g, "+" )
        ;
        return( source );
    }
    function newJson(lat, lng){
        var dt=new Date();
        var date=dt.getFullYear()+"-"+(dt.getMonth()+1)+"-"+dt.getDate()+" "+
            dt.getHours()+":"+dt.getMinutes()+":"+dt.getSeconds();
        var json;
        if(getUrlParameter("segmento")!=undefined)
        {    
            json={
                "titulo": "titulo1", // string vazia ou não
                "segmento": getUrlParameter("segmento")[0], // char com a letra referente ao segmento
                "descricao": "descricao1", // string vazia ou não
                "lat": lat, //latitude
                "long": lng, //longitude
                //"foto": ["foto1", "foto2"], // array de strings, vazio ou contendo URL das fotos
                "status": "nao-iniciado", // não-iniciado, iniciado, cancelado, reforços, finalizado **
                "data_hora": date // formato padrão de timestamp
            };
        }
        else
        {    
            json={
                "titulo": "titulo1", // string vazia ou não
                "segmento": 'n', // char com a letra referente ao segmento
                "descricao": "descricao1", // string vazia ou não
                "lat": lat, //latitude
                "long": lng, //longitude
                //"foto": ["foto1", "foto2"], // array de strings, vazio ou contendo URL das fotos
                "status": "nao-iniciado", // não-iniciado, iniciado, cancelado, reforços, finalizado **
                "data_hora": date // formato padrão de timestamp
            };
        }
        return json;
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
var positions2 = [

    { lat: -23.21, lng: -45.89 }
]

// ITA position
var my_position = {
    lat: -23.20,
    lng: -45.86
};