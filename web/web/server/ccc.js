var request = require('request');
var express = require('express');
var router = express.Router();
var fs = require("fs");

var droneUrl = 'http://52.67.201.69:5001/ardroneMiddleware/tm';

router.get('/', function(req, res) {
    res.send(fs.readFileSync("web/web/views/ccc.html", "utf8"));
})

router.get('/airDrone', function(req, res) {
    request.get(droneUrl, function(error, response, body) {
        if (!error && response.statusCode == 200)
            res.send(body);
        else res.send(error);
    });
})

module.exports = router;