function genContentString(coor) {
    contentString = '<div id="content">' +
        '<h1 >Alerta de Incêndio</h1>' +
        '<div>' +
        '<p><b>Horário de ocorrência: </b> 13:30h</p>' +
        '<p><b>Coordenadas: </b>' + coor + '</p>' +
        '<p><a href="http://www.argus-engenharia.com.br/site/wp-content/uploads/2015/03/incendio620x465.jpg">Fotos do alerta</a></p> ' +
        '<h4>Delegar segmento</h4>' +
        '<button class="btn btn-primary" onclick="colorMarker(\'blue\')">Segmento 1</button> ' +
        '<button class="btn btn-danger" onclick="colorMarker(\'red\')">Segmento 2</button> ' +
        '<button class="btn btn-default" onclick="colorMarker(\'black\')">Segmento 3</button> ' +
        '<button class="btn btn-success" onclick="colorMarker(\'green\')">Segmento 4</button> ' +
        '<hr>' +
        '<h4>Comandos:</h4>' +
       '<button class="btn btn-warning" onclick="deleteMarker()">Alerta falso</button> ' +
        '<button class="btn btn-default" onclick="deleteMarker()">Alerta de Reforços</button>' +
        '<button class="btn btn-danger" onclick="deleteMarker()">Finalizar alerta</button> ' +
        '</div>' +
        '</div>';
}

function fillMarker(){
    return "#aaa";
}