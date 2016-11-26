var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var ChamadoSchema = new Schema({
	alias: String,
	titulo: String,
	descricao: String,
	segmento: String,
	fotos: [String],
	status: String,
	data_hora: Date,
	lat: Number,
	long: Number
});

module.exports = mongoose.model('Chamado', ChamadoSchema);
