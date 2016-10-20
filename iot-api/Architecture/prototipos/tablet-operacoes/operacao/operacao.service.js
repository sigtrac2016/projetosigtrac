'use strict';

angular.module('SigTrac')
    .service('operacoesService', function($filter) {
        // TODO - Ler a partir de um DAO
        this.nextId = 5;
        this.rows = [{
            id: 1,
            completed: false,
            title: 'Jardim das Colinas',
            desc: 'Alagamento',
            operacaoInicio: '01/10/2016',
            operacaoTermino: '30/11/2016',
            tipo: 1,
            lat: -23.2041321,
            lng: -45.910916,
            radius: 300
        }, {
            id: 2,
            completed: true,
            title: 'EMEF Prof. Áurea',
            desc: 'Vazamento de Produto Químico',
            operacaoInicio: '01/10/2016',
            operacaoTermino: '30/11/2016',
            tipo: 2,
            lat: -23.1998466,
            lng: -45.8833941,
            radius: 500
        }, {
            id: 3,
            completed: false,
            title: 'Km 116 Via Dutra',
            desc: 'Incendio em Favela',
            operacaoInicio: '01/10/2016',
            operacaoTermino: '30/11/2016',
            tipo: 3,
            lat: -23.2159681,
            lng: -45.894927,
            radius: 750
        }, {
            id: 4,
            completed: false,
            title: 'Shopping Jacareí',
            desc: 'Desabamento',
            operacaoInicio: '01/10/2016',
            operacaoTermino: '30/11/2016',
            tipo: 4,
            lat: -23.304191816171244,
            lng: -45.96250746564141,
            radius: 1000
        }];

        this.filter = {};

        this.filtered = function() {
            if(this.filter == null) {
                return this.rows;
            }
            else {
                return $filter('filter')(this.rows, this.filter);
            }
        };

        this.remainingCount = function() {
            return $filter('filter')(this.rows, {
                completed: false
            }).length;
        };

        this.getOperacaoById = function(operacaoId) {
            var operacao, i;
            for (i = this.rows.length - 1; i >= 0; i--) {
                operacao = this.rows[i];
                if (operacao.id === operacaoId) {
                    return operacao;
                }
            }
            return false;
        };

        this.addOperacao = function(title, desc, operacaoInicio, operacaoTermino, tipo, lat, lng, radius) {
            var newOperacao = {
                id: this.nextId++,
                completed: false,
                title: title,
                desc: desc,
                operacaoInicio: operacaoInicio,
                operacaoTermino: operacaoTermino,
                tipo: tipo,
                lat: lat,
                lng: lng,
                radius: radius && parseFloat(radius) || 100
            };
            this.rows.push(newOperacao);
        };

        this.updateOperacao = function(operacaoId, title, desc, operacaoInicio, operacaoTermino, tipo, lat, lng, radius, comp) {
            var operacao = this.getOperacaoById(operacaoId);
            if (operacao) {
                operacao.title = title;
                operacao.desc = desc;
                operacao.operacaoInicio = operacaoInicio;
                operacao.operacaoTermino = operacaoTermino;
                operacao.tipo = tipo;
                operacao.lat = lat;
                operacao.lng = lng;
                operacao.radius = radius && parseInt(radius) || 100;
                operacao.completed = comp;
                operacao.id = this.nextId++;
            }
        };

        this.prune = function() {
            var flag = false,
                i;
            for (var i = this.rows.length - 1; i >= 0; i--) {
                if (this.rows[i].completed) {
                    flag = true;
                    this.rows.splice(i, 1);
                }
            }
            if (flag) this.nextId++;
        };
    })
    .service('operacaoControlsService', function(infoWindowService, markersService, NEW_RECORD_ID) {
        this.editOperacao = false;
        this.editOperacaoId = NEW_RECORD_ID;
        this.newOperacao = function() {
            this.editOperacaoById();
        };

        this.editOperacaoById = function(operacaoId) {
            this.editOperacaoId = operacaoId || NEW_RECORD_ID;
            this.editOperacao = true;
        };

        this.openInfoWindowByOperacaoId = function(operacaoId) {
            var marker = markersService.getMarkerById(operacaoId);
            if (marker) {
                var operacao = marker.get("operacao");
                infoWindowService.setData(operacaoId, marker.getTitle(), operacao.desc, operacao.operacaoInicio, operacao.operacaoTermino, operacao.tipo);
                infoWindowService.open(marker);
                return;
            }
        };
    });
