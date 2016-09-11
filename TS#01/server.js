// Importação dos modulos necessários.
var express = require('express');
var app = express();
var fs = require("fs");

//Store all HTML files in view folder.
app.use(express.static(__dirname + '/views'));
//Store all JS in Scripts folder.
app.use(express.static(__dirname + '/script'));
//Store all CSS in style folder.
app.use(express.static(__dirname + '/style'));
//Store all static files
app.use(express.static(__dirname + '/public'));

app.get('/', function(req, res) {
    res.send(fs.readFileSync("views/main.html", "utf8"));
})

// set the port of our application
// process.env.PORT lets the port be set by Heroku
var port = process.env.PORT || 8080;

var server = app.listen(port, function() {
    var host = server.address().address
    var port = server.address().port

    console.log("Example app listening at http://%s:%s", host, port)
})

module.exports = app;