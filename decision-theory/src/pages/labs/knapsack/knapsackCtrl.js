(function () {
    'use strict';
    angular
        .module('app')
        .controller('knapsackController', ['$scope', '$uibModal', function ($scope, $uibModal) {

            let greedy = () => {
                let T = [];
                vm.items.forEach((item, index) => {
                    T[item.weight / item.cost] = index;
                });
                let K = Object.keys(T);
                K = K.sort();
                let cost = 0, weight = 0;
                K.forEach(item => {
                    if (weight + vm.items[T[item]].weight <= vm.total) {
                        weight = weight + vm.items[T[item]].weight;
                        cost = cost + vm.items[T[item]].cost;
                    }
                });
                return {weight: weight, cost: cost};
            };

            let dynamic = () => {
                let T = {};

                T[0] = {weight: 0, cost: 0};

                vm.items.forEach(item => {
                    let newT = [];
                    Object.keys(T).map(key => T[key]).forEach(sol => {
                        let test = {weight: sol.weight + item.weight, cost: sol.cost + item.cost};
                        if (test.weight <= vm.total && (T[test.cost] == undefined || test.weight < T[test.cost].weight))
                            newT.push(test);
                    });
                    newT.forEach(sol => T[sol.cost] = sol);
                });

                return T[Math.max(...Object.keys(T))];
            };

            let vm = this;

            vm.total = 10;

            vm.result = {};

            vm.items = [];

            vm.updateResult = () => vm.result = {dynamic: dynamic(), greedy: greedy()};

            vm.addItem = () => {
                let modalInstance = $uibModal.open({
                    animation: true,
                    templateUrl: 'src/pages/labs/knapsack/modal/index.html',
                    controller: 'knapsackModalController',
                    controllerAs: 'modalCtrl',
                });

                modalInstance.result.then((item) => {
                    vm.items.push(item);
                    vm.updateResult();
                });
            };

        }]);
})();