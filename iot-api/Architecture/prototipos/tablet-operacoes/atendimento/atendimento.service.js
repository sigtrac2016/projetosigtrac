'use strict';

angular.module('SigTrac')
    .service('atendimentosService', function($filter) {
        // TODO - Ler a partir de um DAO
        this.nextId = 11;
        this.rows = [{
            id: 1,
            completed: false,
            title: 'Jardim das Colinas',
            desc: 'Alagamento',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 0,
            respiracao: 0,
            tipo: 1,
            lat: -23.2041321,
            lng: -45.910916,
            radius: 200
        }, {
            id: 2,
            completed: true,
            title: 'Bombeiro',
            desc: 'Sd. Balthazar',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 0,
            respiracao: 0,
            tipo: 2,
            lat: -23.204243995281182,
            lng: -45.91079798280333,
            radius: 0
        }, {
            id: 3,
            completed: false,
            title: 'Bombeiro',
            desc: 'Sgt. Luciana',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 0,
            respiracao: 0,
            tipo: 2,
            lat: -23.204091150634987,
            lng: -45.911098390213,
            radius: 0
        }, {
            id: 4,
            completed: false,
            title: 'Paramédico',
            desc: 'João da Silva',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 0,
            respiracao: 0,
            tipo: 3,
            lat: -23.20405170682695,
            lng: -45.91103401719664,
            radius: 0
        }, {
            id: 5,
            completed: false,
            title: 'Paramédico',
            desc: 'Regina Moraes',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 0,
            respiracao: 0,
            tipo: 3,
            lat: -23.20414045537867,
            lng: -45.91098573743437,
            radius: 0
        }, {
            id: 6,
            completed: true,
            title: 'Vitima',
            desc: 'Não identificado',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: false,
            cumpreOrdens: true,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 4,
            respiracao: 40,
            tipo: 4,
            lat: -23.20392351437043,
            lng: -45.91112521230315,
            radius: 0
        }, {
            id: 7,
            completed: false,
            title: 'Vitima',
            desc: 'Não identificado',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: false,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 4,
            respiracao: 40,
            tipo: 4,
            lat: -23.203987610614053,
            lng: -45.9109911018524,
            radius: 0
        }, {
            id: 8,
            completed: false,
            title: 'Vitima',
            desc: 'Não identificado',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: false,
            reenchimentoCapilar: 5,
            respiracao: 0,
            tipo: 4,
            lat: -23.204061567780062,
            lng: -45.91081407605742,
            radius: 0
        }, {
            id: 9,
            completed: false,
            title: 'Ambulância',
            desc: 'SAMU-4531413',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: false,
            respiracaoViaAerea: true,
            reenchimentoCapilar: 4,
            respiracao: 40,
            tipo: 5,
            lat: -23.20372629496648,
            lng: -45.91036346494292,
            radius: 0
        }, {
            id: 10,
            completed: false,
            title: 'Viatura Resgate',
            desc: 'PMSP-45245523',
            atendimentoInicio: '01/10/2016',
            atendimentoTermino: '30/11/2016',
            deambulando: true,
            cumpreOrdens: true,
            respiracaoViaAerea: false,
            reenchimentoCapilar: 5,
            respiracao: 0,
            tipo: 6,
            lat: -23.203983639804218,
            lng: -45.910197167983995,
            radius: 0
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

        this.getAtendimentoById = function(atendimentoId) {
            var atendimento, i;
            for (i = this.rows.length - 1; i >= 0; i--) {
                atendimento = this.rows[i];
                if (atendimento.id === atendimentoId) {
                    return atendimento;
                }
            }
            return false;
        };

        this.addAtendimento = function(title, desc, atendimentoInicio, atendimentoTermino, deambulando, cumpreOrdens, respiracaoViaAerea, reenchimentoCapilar, respiracao, tipo, lat, lng, radius) {
            var newAtendimento = {
                id: this.nextId++,
                completed: false,
                title: title,
                desc: desc,
                atendimentoInicio: atendimentoInicio,
                atendimentoTermino: atendimentoTermino,
                deambulando: deambulando,
                cumpreOrdens: cumpreOrdens,
                respiracaoViaAerea: respiracaoViaAerea,
                reenchimentoCapilar: reenchimentoCapilar,
                respiracao: respiracao,
                tipo: tipo,
                lat: lat,
                lng: lng,
                radius: radius && parseFloat(radius) || 100
            };
            this.rows.push(newAtendimento);
        };

        this.updateAtendimento = function(atendimentoId, title, desc, atendimentoInicio, atendimentoTermino, deambulando, cumpreOrdens, respiracaoViaAerea, reenchimentoCapilar, respiracao, tipo, lat, lng, radius, comp) {
            var atendimento = this.getAtendimentoById(atendimentoId);
            if (atendimento) {
                atendimento.title = title;
                atendimento.desc = desc;
                atendimento.atendimentoInicio = atendimentoInicio;
                atendimento.atendimentoTermino = atendimentoTermino;
                atendimento.deambulando = deambulando;
                atendimento.cumpreOrdens = cumpreOrdens;
                atendimento.respiracaoViaAerea = respiracaoViaAerea;
                atendimento.reenchimentoCapilar = reenchimentoCapilar;
                atendimento.respiracao = respiracao;
                atendimento.tipo = tipo;
                atendimento.lat = lat;
                atendimento.lng = lng;
                atendimento.radius = radius && parseInt(radius) || 100;
                atendimento.completed = comp;
                atendimento.id = this.nextId++;
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
    .service('atendimentoControlsService', function(infoWindowService, markersService, NEW_RECORD_ID) {
        this.editAtendimento = false;
        this.editAtendimentoId = NEW_RECORD_ID;
        this.newAtendimento = function() {
            this.editAtendimentoById();
        };

        this.editAtendimentoById = function(atendimentoId) {
            this.editAtendimentoId = atendimentoId || NEW_RECORD_ID;
            this.editAtendimento = true;
        };

        this.openInfoWindowByAtendimentoId = function(atendimentoId) {
            var marker = markersService.getMarkerById(atendimentoId);
            if (marker) {
                var atendimento = marker.get("atendimento");
                infoWindowService.setData(atendimentoId, marker.getTitle(), atendimento.desc, atendimento.atendimentoInicio, atendimento.atendimentoTermino, atendimento.deambulando, atendimento.cumpreOrdens, atendimento.respiracaoViaAerea, atendimento.reenchimentoCapilar, atendimento.respiracao, atendimento.tipo);
                infoWindowService.open(marker);
                return;
            }
        };
    });
