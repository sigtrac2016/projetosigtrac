	//Basic Crud template
var _ = require('lodash');



function readRequest(object, Model, req) {
	var Attributes = _.keys(Model.schema.paths);
	
	_.forEach(Attributes, function(path){
		value = _.get(req.body, path);
		if(!_.isUndefined(value)){
			_.set(object, path, value);
		}
	});

	return object;
}

function saveModel(object, res){
	object.save(function(err, saved) {
		if(err){
			console.log(err)
			res.send(err);
		}
		else {
			console.log('Modelo salvo!', object);
			res.status(200).json({SUCCESS: object});
		}
	});
}

module.exports = function(router, route, Model, config) {
	if (_.isUndefined(config.handleVirtuals)){
		handleVirtuals = function(object){
			return object
		}
	}
	else {
		handleVirtuals = require(config.handleVirtuals);
	}
	
	//LIST
	router.get(route, function(req, res) {

        Model.find(function(err, objects) {
          if (err)
              res.send(err);

          res.json(objects);

        });
	});

	//CREATE
	router.post(route, function(req, res) {

		var objectPost = new Model();

		objectPost = readRequest(objectPost, Model, req);

		//Checking if it is unique
		Model.findOne({'alias': objectPost.alias}, function(err, object){
			if (err){
				res.send(err);
			}
			if (object == null){
				saveModel(objectPost, res);
			}
			else{
				res.send("Já existe um objeto com este alias.");
			}
		});

	});
	
	//READ
	router.get(route + '/:Alias', function(req, res){

		Model.findOne({'alias': req.params.Alias}, function(err, object){
			if(err){
				console.log(err)
				res.send(err);
			}
			if (object == null){
				res.status(404).json("Nenhum objeto encontrado");
			}
			else{
				object = handleVirtuals(object);
				res.send(object);
			} 
		});
	});

	//UPDATE
	router.patch(route + '/:Alias', function(req, res){

		Model.findOne({'alias': req.params.Alias}, function(err, object){
			
			if(err){
				console.log(err)
				res.send(err);
			}

			if (object == null){
				res.status(404).json("Nenhum objeto encontrado");
			}
			else{
				object = readRequest(object, Model, req);
				saveModel(object, res);
			}
		});
	});

	//DELETE
	router.delete(route + '/:Alias', function(req,res){
		Model.findOne({'alias': req.params.Alias}, function(err, object) {
			if(err) {
				res.send(err);
			}
			if (object == null){
				res.status(404).json("Nenhum objeto encontrado");
			}
			else {
				object.remove(function(err) {
					if(err) {
						res.send(err);
					}
					else {
						res.json({DELETED: object});
					}
				});
			}
		});
	});




	return router;
}