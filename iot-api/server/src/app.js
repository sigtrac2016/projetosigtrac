var Express = require('express');
//var _ = require ("lodash");
var bodyParser = require ("body-parser");
var logger = require('morgan');
var routes = require('./routes/index');
var mongoose = require('mongoose');

//Setting up the app
var app = new Express();
var router = Express.Router();

//Database settings
var config = require('../config');
mongoose.Promise = global.Promise;
mongoose.connect("localhost:27017/teste1")

/*mongoose.connect(config.db[app.settings.env]);/*,function(){
    mongoose.connection.db.dropDatabase();
 });*/

var db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function() {
    console.log("Database connected");
});


//Setup Port
var port = process.env.PORT || 8080;
app.set('port', port);

//Setting config.
app.set('views',  __dirname + '/views');
app.use(Express.static(__dirname + '/views'));
app.use(Express.static(__dirname + '/public'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(logger('dev'));
app.use(router);
app.use(function(req, res, next) {
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Header', '*');
    next();
});

//Configuring routes
app.use('/api', routes);

// START THE app
var server = app.listen(app.get('port'), function(){
    console.log("Server listening to port " + app.get('port'));
});

app.closeServer = function() {
    server.close();
    process.exit();
};

module.exports = app;
