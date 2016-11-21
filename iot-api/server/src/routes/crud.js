//Basic Crud template
var _ = require('lodash');
var mongoose = require('mongoose');
/*var User = require('../models/user.js')*/

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

function readQuery(object, Model, query) {
	var Attributes = _.keys(Model.schema.paths);
	_.forEach(Attributes, function(path){
		value = _.get(query, path);
		if(!_.isUndefined(value)){
			_.set(object, path, JSON.parse(value));
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
			console.log('Modelo salvo! \n', object);
			res.status(200).json({SUCCESS: object});
		}
	});
}

function findObject(Model, param, uniqueIdentifier, res, cb){
	var returnObject;
	if (_.isUndefined(uniqueIdentifier)){
		Model.findById(param).exec(function(err, object){
			if (err)
			  res.send(err);
		
			cb(object);
			});			
	}
	else{
		var query = {};
		query[uniqueIdentifier] = param;
		Model.findOne(query, function(err, object){
			if (err)
			  res.send(err);

			cb(object);
		});
	}
}

module.exports = function(router, route, ModelPath, config) {
	
	//Initial configurations
	var Model = require(ModelPath);
	var securityFilter;
	if (_.isUndefined(config.security)){
		securityFilter = function(req, MethodType){
			return true;
		}
	}
	else{
		securityFilter = require(config.security);
	}

	//LIST
	router.get(route, function(req, res) {

		var query = {}
		query = readQuery(query, Model, req.query)
		Model.find(query, function(err, objects) {
			if (securityFilter(objects, req, "LIST")){
				if (err)
					res.send(err);
				res.json(objects);
				}
				else {
					res.status(403);
					res.send('Acesso não autorizado');
				}
		});
	});
	//CREATE
	router.post(route, function(req, res) {
	
		var object = new Model();
	
		object = readRequest(object, Model, req);

		/*dummyuser = new User()
		dummyuser.name="Dummy"
		dummyuser.age =4
		dummyuser.save(function(err, saved) {
			if(err){
				console.log(err)
				res.send(err);
			}
			else {
				console.log('Modelo salvo! \n', object);
				res.status(200).json({SUCCESS: object});
			}
		}).then(object.creator=dummyuser);*/

		
		if (securityFilter(object, req, "POST")){	
			saveModel(object, res);
		}
		else {
			res.status(403);
			res.send('Acesso não autorizado');
		}
	});
	
	//READ
	router.get(route + '/:UniqueIdentifier', function(req, res){
		findObject(Model, req.params.UniqueIdentifier, config.uniqueIdentifier, res, function(object){
			// ESTUDAR O USO DE POPULATE PRA PREENCHER TODOS OS CAMPOS NECESSARIOS.
			if (securityFilter(object, req, "GET")){
				res.send(object);
			}
			else {
				res.status(403);
				res.send('Acesso não autorizado');
			}

		});
	});	


	//UPDATE
	router.patch(route + '/:UniqueIdentifier', function(req, res){
		findObject(Model, req.params.UniqueIdentifier, config.uniqueIdentifier, res, function(object){
			if (securityFilter(object, req, "PATCH")){
				object = readRequest(object, Model, req);
				saveModel(object, res);
			}
			else {
				res.status(403);
				res.send('Acesso não autorizado');
			}
		});
	});

	//DELETE
	router.delete(route + '/:UniqueIdentifier', function(req,res){
		findObject(Model, req.params.UniqueIdentifier, config.uniqueIdentifier, res, function(object){
			if (securityFilter(object, req, "DELETE")){
				object.remove(function(err) {
					if(err) {
						res.json({ERROR: err});
					}
					else {
						res.json({DELETED: object});
					}
				});
			}
			else{
				res.status(403);
				res.send('Acesso não autorizado');
			}
		});

	});

	return router;
}