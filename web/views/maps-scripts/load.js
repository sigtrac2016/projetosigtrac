// ITA position
var my_position = {
    lat: -23.21,
    lng: -45.87
};

// Initializes the map
var mapCanvas = document.getElementById("map");
var mapOptions = {
    center: my_position,
    zoom: 14
}
var contentString, infoWindow;
var map, marker, selection, coor;
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

    // Initializes infowindow
    infowindow = new google.maps.InfoWindow({
        content: contentString
    })

    /***********************************************
                Creates new markers
    ***********************************************/

    // Event to create a new marker
    google.maps.event.addListener(map, 'click', function(event) {
        new_marker = new google.maps.Marker({
            position: event.latLng,
            map: map,
            draggable: true,
            icon: pinSymbol("#aaa")
        });
        new_marker.addListener('click', function(event) {
            genContentString(event.latLng);
            selection = new_marker;
            infowindow.setContent(contentString);
            infowindow.open(map, new_marker);
        });
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
}