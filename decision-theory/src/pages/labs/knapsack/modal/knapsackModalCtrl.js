(function () {
    'use strict';
    angular
        .module('app')
        .controller('knapsackModalController', ['$uibModalInstance', function ($uibModalInstance) {
            let vm = this;

            vm.item = {};

            vm.add = () => {
                if (vm.form.$valid) {
                    $uibModalInstance.close(vm.item);
                } else {
                    angular.forEach(vm.form.$error, (field) =>
                        angular.forEach(field, (errorField) => errorField.$setTouched()));
                }
            };

            vm.cancel = () => $uibModalInstance.dismiss('cancel');

        }]);
})();