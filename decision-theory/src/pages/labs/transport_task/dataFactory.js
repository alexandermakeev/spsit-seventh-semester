(function () {
    'use strict';
    angular
        .module('app')
        .factory('dataFactory', ['$http', function ($http) {
            let promise;
            return {
                get: function () {
                    if (!promise) {
                        promise = $http({
                            method: 'GET',
                            url: 'src/pages/labs/transport_task/data.json',
                        });
                    }
                    return promise;
                }
            }
        }])
})();