var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var PacienteSchema = new Schema({
	alias: String,
	name: String,
	timeCreated: Date
});

module.exports = mongoose.model('Paciente', PacienteSchema);