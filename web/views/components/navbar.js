/*
 *   Carrega os links da navbar e determina sua cor
 */
$(document).ready(function() {
    $.getJSON("/data/segmentos.json", function(data) {
        data.forEach(function(seg) {
            if (seg.url != "") {
                var link = '<ul class="nav navbar-nav">' +
                    '<li><a href="' + seg.url + '">' +
                    seg.name.split(" ")[0] + '</a></li></ul>';
                $("#navlinks").append(link);
                if (segmento != undefined && seg.url.indexOf(segmento) != -1)
                    $("#nav").css('background-color', seg.navcolor);
            }
        });
    });
});