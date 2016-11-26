module.exports = function(config){
    config.set({
        files: [
            'test/*.js', {
                pattern: 'src/**/*.js',
                included: false,
                mutated: true }
            ],
        testFramework: 'mocha',
        testRunner: 'mocha',
        testSelector: null,
        logLevel: 'all'
    });
}
