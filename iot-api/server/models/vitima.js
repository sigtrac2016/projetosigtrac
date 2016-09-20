var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var VitimaSchema = new Schema({
	alias: String,
	name: String,
	timeCreated: Date,
	location: {
		latitude: Number,
		longitude: Number
	},
	deambulando: Boolean,
	respiracao: Number,
	respiraViasAereas: Boolean,
	reenchimentoCapilar: Number,
	pulsoRadial: Boolean,
	cumpreOrdens: Boolean,
	status: String
});

VitimaSchema
.virtual('START')
.get(function(){
	if (this.deambulando == true){
		return "Verde"
	}

	if (this.respiracao == 0){
		if(this.respiraViasAereas == false){
			return "Preto"
		}
		else{
			return "Vermelho"
		}
	}
	else if (this.respiracao > 30){
		return "Vermelho"
	}
	else{
		if (this.reenchimentoCapilar > 2 || this.pulsoRadial == false){
			return "Vermelho"
		}
		else{
			if (this.cumpreOrdens == false){
				return "Vermelho"
			}
			else{
				return "Amarelo"
			}
		}
	}
});

module.exports = mongoose.model('Vitima', VitimaSchema);