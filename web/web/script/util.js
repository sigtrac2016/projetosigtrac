/*
 *   Determina um parâmetro da URL da página atual
 */
var getUrlParameter = function getUrlParameter(sParam) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
        sURLVariables = sPageURL.split('&'),
        sParameterName,
        i;

    for (i = 0; i < sURLVariables.length; i++) {
        sParameterName = sURLVariables[i].split('=');
        if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : sParameterName[1];
        }
    }
};

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

/*
 *   Determina a cor padrão de um dado segmento
 */
var segmentoColor = function segmentoColor(segmento) {
    switch (segmento) {
        case 'police':
            return "blue";
        case 'health':
            return "red";
        case 'fire':
            return "black";
        case 'civil':
            return "green";
        default:
            return "#aaa";
    }
}

var rad = function(x) {
    return x * Math.PI / 180;
};

var checkUndefined = function(p1, p2) {
    return p1 == undefined || p2 == undefined ||
        p1.lat == undefined || p1.lng == undefined ||
        p2.lat == undefined || p2.lng == undefined;
}
var getDistance = function(p1, p2) {
    if (checkUndefined(p1, p2)) return 0;
    var R = 6378137; // Earth’s mean radius in meter
    var dLat = rad(p2.lat - p1.lat);
    var dLong = rad(p2.lng - p1.lng);
    var a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
        Math.cos(rad(p1.lat)) * Math.cos(rad(p2.lat)) *
        Math.sin(dLong / 2) * Math.sin(dLong / 2);
    var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
    var d = R * c / 1000;
    return d; // returns the distance in km
};

exports.segmentoColor = segmentoColor;
exports.getUrlParameter = getUrlParameter;