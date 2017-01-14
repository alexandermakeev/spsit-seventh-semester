(function () {
    'use strict';
    angular
        .module('app')
        .controller('transportTaskController', ['dataFactory', function (dataFactory) {

            let vm = this;

            vm.setDefault = () => dataFactory.get().then((response) => {
                vm.params = {
                    suppliers: 4,
                    customers: 3,
                };
                vm.data = angular.copy(response.data);
                vm.onChange();
            });

            vm.setDefault();

            vm.resize = () => {
                if (vm.form.$invalid) return;
                let customers = [];
                for (let i = 0; i < vm.params.customers; i++) customers.push({need: 0});
                let suppliers = [];
                let transfers = [];
                for (let i = 0; i < vm.params.suppliers; i++) {
                    let supplier = {stock: 0};
                    let supplierTransfers = [];
                    suppliers.push(supplier);
                    for (let j = 0; j < vm.params.customers; j++) {
                        supplierTransfers.push({cost: 0, amount: 0});
                    }
                    transfers.push(supplierTransfers);
                }
                vm.data = {
                    total: 0,
                    customers: customers,
                    suppliers: suppliers,
                    transfers: transfers
                };
                vm.onChange();
            };

            vm.onChange = () => {
                vm.northWestCorner();
                vm.smallestElement();
            };

            vm.northWestCorner = () => {
                vm.nwCorner = angular.copy(vm.data);

                vm.nwCorner.customers.forEach((customer, i) => {
                    vm.nwCorner.suppliers.forEach((supplier, j) => {
                        if (supplier.stock != 0 && customer.need != 0) {
                            let balance = supplier.stock  - customer.need;
                            if (balance > 0) {
                                vm.nwCorner.transfers[j][i].amount += customer.need;
                                supplier.stock = balance;
                                customer.need = 0;
                            } else {
                                vm.nwCorner.transfers[j][i].amount += supplier.stock;
                                supplier.stock = 0;
                                customer.need = Math.abs(balance);
                            }
                        }
                    });
                });

                vm.nwCorner.customers.forEach((customer, i) => {
                    vm.nwCorner.suppliers.forEach((supplier, j) => {
                        vm.nwCorner.total += vm.nwCorner.transfers[j][i].amount * vm.nwCorner.transfers[j][i].cost;
                    });
                });
            };

            vm.smallestElement = () => {
                vm.sElement = angular.copy(vm.data);
                for (;;) {
                    let available = vm.sElement.transfers.reduce((a, b) => a.concat(b))
                        .filter((transfer) => transfer.amount == 0);
                    if (available.length == 0) break;
                    let min = available.reduce((prev, current) => (prev.cost < current.cost) ? prev : current);
                    let i, j;
                    for (i = 0; i < vm.sElement.transfers.length; i++) {
                        j = vm.sElement.transfers[i].indexOf(min);
                        if (j != -1) break;
                    }
                    if (vm.sElement.suppliers[i].stock == 0 || vm.sElement.customers[j].need == 0)
                        vm.sElement.transfers[i][j].amount = -1;
                    else {
                        let balance = vm.sElement.suppliers[i].stock - vm.sElement.customers[j].need;
                        if (balance > 0) {
                            vm.sElement.transfers[i][j].amount = vm.sElement.customers[j].need;
                            vm.sElement.suppliers[i].stock = balance;
                            vm.sElement.customers[j].need = 0;
                        } else {
                            vm.sElement.transfers[i][j].amount = vm.sElement.suppliers[i].stock;
                            vm.sElement.suppliers[i].stock = 0;
                            vm.sElement.customers[j].need = Math.abs(balance);
                        }
                    }
                }

                vm.sElement.transfers.reduce((a, b) => a.concat(b)).forEach((transfer) =>
                    vm.sElement.total += transfer.amount * transfer.cost);
            };

        }]);
})();