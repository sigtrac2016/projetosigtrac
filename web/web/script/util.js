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

exports.segmentoColor = segmentoColor;
exports.getUrlParameter = getUrlParameter;