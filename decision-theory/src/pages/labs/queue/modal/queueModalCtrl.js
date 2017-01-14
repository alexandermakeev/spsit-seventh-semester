(function () {
    'use strict';
    angular
        .module('app')
        .controller('queueModalController', ['$uibModalInstance', function ($uibModalInstance) {
            let vm = this;

            vm.hour = {};

            vm.add = () => {
                if (vm.form.$valid) {
                    $uibModalInstance.close(vm.hour);
                } else {
                    angular.forEach(vm.form.$error, (field) =>
                        angular.forEach(field, (errorField) => errorField.$setTouched()));
                }
            };

            vm.cancel = () => $uibModalInstance.dismiss('cancel');

        }]);
})();