var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var SensorSchema = new Schema({
	alias: String,
	name: String,
	timeCreated: Date,
	timeLastUpdated: Date,
	value: Schema.Types.Mixed,
	type: String,
	location: {
		latitude: Number,
		longitude: Number,
		altitude: Number
	}
});

module.exports = mongoose.model('Sensor', SensorSchema);
