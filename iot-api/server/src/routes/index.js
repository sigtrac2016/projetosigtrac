//Index archive
var Express = require('express');
var router = Express.Router();
var crud = require('./crud');

//Schemas
var Sensor = require('../models/sensor');
var Vitima = require('../models/vitima');


router.get('/', function(req, res) {
	res.send("Hello World. Oie.");
});

crud(router, '/sensores', Sensor, {});
crud(router, '/vitimas', Vitima, {"handleVirtuals": "./helpers/handleVirtualsVitimas"});

module.exports = router;