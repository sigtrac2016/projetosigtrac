// Importação dos modulos necessários.
var express = require('express');
var app = express();
var fs = require("fs");

// Configuração das rotas principais
var about = require('./web/server/about');
var login = require('./web/server/login');
var ccs = require('./web/server/ccs');
var ccc = require('./web/server/ccc');

// Store all HTML files in view folder.
app.use(express.static(__dirname + '/web/views'));
// Store all JS in Scripts folder.
app.use(express.static(__dirname + '/web/script'));
app.use(express.static(__dirname + '/web/client'));
// Store all CSS in style folder.
app.use(express.static(__dirname + '/web/style'));
// Store all static files
app.use(express.static(__dirname + '/web/public'));
// Store web path
app.use(express.static(__dirname + '/web'));

app.use('/about', about);
app.use('/login', login);
app.use('/ccs', ccs);
app.use('/', ccc);

// set the port of our application
// process.env.PORT lets the port be set by Heroku
var port = process.env.PORT || 8081;

var server = app.listen(port, function() {
    var host = server.address().address
    var port = server.address().port

    console.log("Example app listening at http://%s:%s", host, port)
})

module.exports = app;