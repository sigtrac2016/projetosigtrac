// ITA position
var my_position = {
    lat: -23.21,
    lng: -45.87
};

// Mock positions
var position_1 = {
    lat: -23.20,
    lng: -45.87
};

var position_2 = {
    lat: -23.22,
    lng: -45.87
};

var position_3 = {
    lat: -23.20,
    lng: -45.88
};

var position_4 = {
    lat: -23.22,
    lng: -45.86
};

var position_5 = {
    lat: -23.20,
    lng: -45.89
};

var position_6 = {
    lat: -23.205,
    lng: -45.89
};

// Initializes the map
var mapCanvas = document.getElementById("map");
var mapOptions = {
    center: my_position,
    zoom: 14
}
var contentString, infoWindow;
var map, selection, coor;

// Mock variables
var marker, marker_1, marker_2, marker_3, marker_4, marker_5, marker_6;

var markers = [];

function loadMap() {

    /***********************************************
                Initializes map and stuff
    ***********************************************/

    // Initializes map
    map = new google.maps.Map(mapCanvas, mapOptions);

    // Initializes a marker
    marker = new google.maps.Marker({
        position: my_position,
        map: map,
        draggable: true,
        icon: pinSymbol("#aaa")
    });
    markers.push(marker);

    // Initializes mock marker
    marker_1 = new google.maps.Marker({
        position: position_1,
        map: map,
        draggable: true,
        icon: pinSymbol("#0000ff")
    });
    markers.push(marker_1);

    marker_2 = new google.maps.Marker({
        position: position_2,
        map: map,
        draggable: true,
        // Color red
        icon: pinSymbol("#ff0000")
    });
    markers.push(marker_2);

    marker_3 = new google.maps.Marker({
        position: position_3,
        map: map,
        draggable: true,
        icon: pinSymbol("#008000")
    });
    markers.push(marker_3);

    marker_4 = new google.maps.Marker({
        position: position_4,
        map: map,
        draggable: true,
        icon: pinSymbol("##000000")
    });
    markers.push(marker_4);

    marker_5 = new google.maps.Marker({
        position: position_5,
        map: map,
        draggable: true,
        // Color red
        icon: pinSymbol("#ff0000")
    });
    markers.push(marker_5);

    marker_6 = new google.maps.Marker({
        position: position_6,
        map: map,
        draggable: true,
        // Color red
        icon: pinSymbol("#ff0000")
    });
    markers.push(marker_6);

    // Initializes infowindow
    infowindow = new google.maps.InfoWindow({
        content: contentString
    })

    /***********************************************
                Creates new markers
    ***********************************************/

    // Event to create a new marker
    google.maps.event.addListener(map, 'click', function(event) {
        var new_marker = new google.maps.Marker({
            position: event.latLng,
            map: map,
            draggable: true,
            icon: pinSymbol(fillMarker())
        });
        new_marker.addListener('click', function(event) {
            genContentString(event.latLng);
            map.setCenter(new_marker.getPosition());
            selection = new_marker;
            infowindow.setContent(contentString);
            infowindow.open(map, new_marker);
        });
        markers.push(new_marker);
    });

    /***********************************************
                Displays alert information
    ***********************************************/

    // Function for displaying alert information.
    marker.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker.getPosition());
        selection = marker;
        infowindow.setContent(contentString);
        infowindow.open(map, marker);
    });

    marker_1.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_1.getPosition());
        selection = marker_1;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_1);
    });

    marker_2.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_2.getPosition());
        selection = marker_2;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_2);
    });

    marker_3.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_3.getPosition());
        selection = marker_3;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_3);
    });

    marker_4.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_4.getPosition());
        selection = marker_4;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_4);
    });

    marker_5.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_5.getPosition());
        selection = marker_5;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_5);
    });

    marker_6.addListener('click', function(event) {
        genContentString(event.latLng);
        map.setCenter(marker_6.getPosition());
        selection = marker_6;
        infowindow.setContent(contentString);
        infowindow.open(map, marker_6);
    });
    // Função para ajudar o Mock
    deleteMarkers(markers);

}

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

function colorMarker(color) {
    selection.setIcon(pinSymbol(color));
}

function deleteMarker(param) {
    selection.setMap(null);
    // Remove o marcador e salva os dados
    markers.splice(markers.indexOf(selection), 1);
}