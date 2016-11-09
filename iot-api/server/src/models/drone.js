var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var DroneSchema = new Schema({
    "alias": String,
    "alt": Number,
    "lat": Number,
    "lon": Number,
    "vel_x": Number,
    "vel_y": Number,
    "vel_z": Number,
    "pitch": Number,
    "roll": Number,
    "yaw": Number,
    "temp": Number,
    "bat": Number,
    "press": Number,
    "image_url": String
});

module.exports = mongoose.model('Drone', DroneSchema);
