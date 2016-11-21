/*
===========================================================================
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
    $scope.contentString2 = "<div id='infowindow2'></div>";

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

    


    $scope.genericPointModel = {
        "id": "", // gerado pelo BD
        "titulo": "Ambulância 386", // string vazia ou nao
        "segmento": "F",// char com a letra referente ao segmento
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
            $scope.infowindow2.setContent("<div id=\'infowindow2'></div>");
            $scope.infowindow2.open($scope.map, marker);
            $("#infowindow2").html($compile($scope.contentString2)($scope));
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

    $scope.infowindow2 = new google.maps.InfoWindow({
        content: $scope.contentString2
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

    $scope.colorMarker = function(color, segmento) {
        $scope.selection.setIcon(pinSymbol(color));
        $scope.ocurrenceModel.segmento=segmento;
    }

    $scope.deleteMarker = function(param) {
        $scope.selection.setMap(null);
        // Remove o marcador e salva os dados
        $scope.markers.splice($scope.markers.indexOf($scope.selection), 1);
    }


    $scope.ocurrenceModel = {
        "id": "", // gerado pelo BD
        "titulo": "Alerta de Incendio ", // string vazia ou nao
        "segmento": "P",// char com a letra referente ao segmento
        "descricao": "Princípio de Incêndio", // string vazia ou nao
        "lat": "", //latitude
        "long": "", //longitude
        "endereco": "",
        "foto": "http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg", // array de strings, vazio ou contendo URL das fotos
        "status": "reforcos", // nao-iniciado, iniciado, cancelado, reforcos, finalizado **
        "data_hora": "" // formato padrão de timestamp
    }

    

    

    $scope.genContentString = function(coor) {
        $scope.contentString = '<div id="content">' +
            '<h4>{{ ocurrenceModel.titulo }}</h4>' +
            '<div>' +
            '<textarea readonly ng-model="ocurrenceModel.descricao" rows="2" cols="100">'+
            '</textarea>'+
            '<p><b>Horário de ocorrência: </b> 13:30h&nbsp;&nbsp<b>Coordenadas: </b>' + coor + '</p>' +            
            '<p><a href="{{ocurrenceModel.foto}}">Fotos do alerta</a></p> ';
        if (segmento == 'global')
            $scope.contentString +=
            '<h4>Delegar segmento</h4>' +            
            '<button class="btn btn-primary" ng-click="colorMarker(\'blue\', \'P\')">POLICE DEPARTMENT</button> ' +
            '<button class="btn btn-danger" ng-click="colorMarker(\'red\', \'H\')">HEALTH CARE</button> ' +
            '<button class="btn btn-default" ng-click="colorMarker(\'black\', \'F\')">FIRE DEPARTMENT</button> ' +
            '<button class="btn btn-success" ng-click="colorMarker(\'green\', \'C\')">CIVIL DEFENSE</button> '+
            '<hr>' +
            '<h4>Comandos:</h4>' +            
            '<b>Status:</b>&nbsp;&nbsp;&nbsp;&nbsp'+
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
        $scope.contentString2 = '<div id="content">' +
            '<h4>{{ genericPointModel.titulo }}</h4>' +
            '<div>' +                   
            '<button ng-if="genericPointModel.segmento==\'P\'" class="btn btn-primary">POLICE DEPARTMENT</button>' +
            '<button ng-if="genericPointModel.segmento==\'H\'" class="btn btn btn-danger">HEALTH CARE</button>' +
            '<button ng-if="genericPointModel.segmento==\'F\'" class="btn btn btn-default">FIRE DEPARTMENT</button>' +
            '<button ng-if="genericPointModel.segmento==\'C\'" class="btn btn btn-success">CIVIL DEFENSE</button>' +
            '<br/><br/><textarea readonly ng-model="ocurrenceModel.descricao" rows="2" cols="100">'+
            '</textarea>'+
            '<p><b>Horário de ocorrência: </b> 13:30h&nbsp;&nbsp<b>Coordenadas: </b>' + coor + '</p>' +            
            '<p><a href="{{ocurrenceModel.foto}}">Fotos do alerta</a></p> ';
        if (segmento == 'global')
            $scope.contentString2 += 
            '<p><b>Entrada Operador:</b></p>' +                      
            '<textarea ng-model="ocurrenceModel.feedback" rows="2" cols="100">'+
            '</textarea>'+            
            '<h4>Comandos:</h4>' +            
            '<b>Status:</b>&nbsp;&nbsp;&nbsp;&nbsp'+
            '<select class="selectpicker" ng-model="ocurrenceModel.status">' + 
            '<option value="nao-iniciado">Não Iniciado</option>' +
            '<option value="iniciado">Iniciado</option>' +
            '<option value="cancelado">Cancelado</option>' +
            '<option value="reforcos">Reforços</option>' + 
            '<option value="finalizado">Finalizadp</option>' + 
            '</select>';
        $scope.contentString2 +=              
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

        function success(data){
            console.log(data);
        }

        function failure(err){

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
    "#aaa", "blue", "red", "green", "black", "red", "red"
]
var positions = [
    { lat: -23.21, lng: -45.87 },
    { lat: -23.20, lng: -45.87 },
    { lat: -23.22, lng: -45.87 },
    { lat: -23.20, lng: -45.88 },
    { lat: -23.22, lng: -45.86 },
   
]

var positions2 = [   
    
    { lat: -23.21, lng: -45.89 }
]

// ITA position
var my_position = {
    lat: -23.21,
    lng: -45.87
};