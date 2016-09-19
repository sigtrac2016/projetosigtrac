var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var SensorSchema = new Schema({
	alias: String,
	name: String,
	timeCreated: Date,
	value: Number,
	type: String,
	location: {
		latitude: Number,
		longitude: Number
	}
});

module.exports = mongoose.model('Sensor', SensorSchema);