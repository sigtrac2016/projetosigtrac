var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var PedidoReforcoSchema = new Schema({
	titulo: String,
	segmento: String,
	status: String,
	descricao: String,
	lat: Number,
	long: Number,
	timeCreated: Date,
	timeLastUpdated: Date,
	data_hora: Date
});

module.exports = mongoose.model('PedidoReforco', PedidoReforcoSchema);
