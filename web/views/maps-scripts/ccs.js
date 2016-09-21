function genContentString(coor) {
    contentString = '<div id="content">' +
        '<h1 >Alerta de incêndio</h1>' +
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

function deleteMarkers(param) {    
    for (var i = 0; i < markers.length; i++){
        if (markers[i].icon.fillColor != "#ff0000") {
            markers[i].setMap(null);
        }  
    }
}

function fillMarker(){
    return "#ff0000";
}