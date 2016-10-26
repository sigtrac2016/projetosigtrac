/*
    Testes unitários para CCC controller
*/

describe('cccVC', function() {
    var controller, scope, $http, $compile, createController;

    beforeEach(module('ccc')); //<--- Hook module

    // Injeção de dependências
    beforeEach(inject(function($rootScope, $controller, _$http_) {
        $http = _$http_;
        scope = $rootScope.$new();
        controller = $controller('cccVC', {
            '$scope': scope,
            '$http': $http
        });
    }));

    it('has a dummy spec to test 2 + 2', function() {
        expect(2 + 2).toEqual(4);
    });

    it('has dummy ok scope function', function() {
        expect(scope.ok()).toEqual("ok");
    });
});