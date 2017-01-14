(function () {
    'use strict';
    angular
        .module('app', ['ui.router', 'ui.bootstrap', 'ui.bootstrap.datetimepicker', 'n3-line-chart'])
        .config(['$stateProvider', '$urlRouterProvider', function ($stateProvider, $urlRouterProvider) {

            $urlRouterProvider.otherwise('/labs/knapsack');

            $stateProvider
                .state('labs', {
                    url: '/labs',
                    abstract: true,
                    templateUrl: 'src/pages/labs/index.html',
                }).state('labs.queue', {
                url: '/queue',
                templateUrl: 'src/pages/labs/queue/index.html',
                controller: 'queueController',
                controllerAs: 'queueCtrl',
            }).state('labs.knapsack', {
                url: '/knapsack',
                templateUrl: 'src/pages/labs/knapsack/index.html',
                controller: 'knapsackController',
                controllerAs: 'knapsackCtrl',
            }).state('labs.transport_task', {
                url: '/transport_task',
                templateUrl: 'src/pages/labs/transport_task/index.html',
                controller: 'transportTaskController',
                controllerAs: 'transportTaskCtrl',
            }).state('labs.rock_paper_scissors', {
                url: '/rock_paper_scissors',
                templateUrl: 'src/pages/labs/rock_paper_scissors/index.html',
                controller: 'rockPaperScissorsController',
                controllerAs: 'rockPaperScissorsCtrl',
            });

        }]);

})();
