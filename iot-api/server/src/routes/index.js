//Index archive
var Express = require('express');
var _ = require('lodash');


var crud = require('./crud');
var router = Express.Router();


/*config:{
	//Se quiser pesquisar por outro uniqueIdentifier do objeto
	//Se não passar, todo o crud será feito procurando pelo id dado pela DB
	"uniqueIdentifier": "NameOfSchemaAttribute"
	//Segurança. Pode passar um arquivo com a função de segurança
	//Path da pasta do arquivo com a função de verificação. Ela receberá como parâmetro:
	//resultado, req, qual tipo de operacao está sendo chamado ("POST", "GET", "DELETE", "PATCH", "LIST")
	//Deve retornar o que se está autorizado ou não.
	//Se security não for especificado, o crud retornará normalmente
	"security": "PATH ABSOLUTO PARA ARQUIVO COM A FUNCAO DE SEGURANÇA"
	}
}
*/
index = [];

var apiDefinition = [
	{
		"route": "/sensores",
		"model": '../models/sensor',
		"config": {"uniqueIdentifier": "alias"}
	},
	{
		"route": "/vitimas",
		"model": '../models/vitima',
		"config": {"uniqueIdentifier": "alias"}
	},
	{
		"route": "/paciente",
		"model": '../models/paciente',
		"config": {"uniqueIdentifier": "alias"}
	},
	{
		"route": "/chamados",
		"model": '../models/chamado',
		"config": {}
	},
	{
		"route": "/policia/boletimocorrencias",
		"model": '../models/boletimocorrencia',
		"config": {}	
	},
	{
		"route": "/policia/pedidoreforcos",
		"model": '../models/pedidoreforco',
		"config": {}	
	}
];


_.forEach(apiDefinition, function(api){
	var Model = require(api.model);
	attributes = {}
	paths = Model.schema.paths
	_.forEach(paths, function(path){
		attributes[path.path] = {"instance": path.instance, "options": path.options} 
	})
	index.push({	"route": api.route,
					"model": attributes
				});
	crud(router, api.route, api.model, api.config);
});

router.get('/', function(req, res){
	res.send(index);
});



module.exports = router;