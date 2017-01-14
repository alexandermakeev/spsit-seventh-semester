(function () {
    'use strict';
    angular
        .module('app')
        .controller('queueController', ['$uibModal', function ($uibModal) {

            let getRandomInt = (min, max) => Math.floor(Math.random() * (max - min + 1)) + min;

            let vm = this;

            vm.generateClients = () => {

                if (vm.form && vm.form.$valid) {
                    let queue = [];

                    let freeVisit = vm.timestamp;

                    vm.hours = [];

                    for (let i = 0; i < vm.hoursAmount; i++) {
                        vm.hours.push({
                            clients: vm.clientsPerHour,
                        });
                    }

                    vm.hours.forEach((hour, index) => {
                        //generate random clients
                        let clients = [];
                        let currentTimestamp = new Date(vm.timestamp.getTime() + index * 60 * 60 * 1000);

                        for (let i = 0; i < vm.clientsPerHour; i++) {
                            //generate random time arrival from 0 to 59 minutes of current hour
                            let arrival = new Date(getRandomInt(0, 59) * 60 * 1000 + currentTimestamp.getTime());
                            //generate random duration of visit time from operations min to max
                            let duration = getRandomInt(vm.operationsMin, vm.operationsMax);
                            clients.push({
                                arrival: arrival,
                                duration: duration,
                                hour: index + 1,
                            });
                        }

                        queue = queue.concat(clients.sort((a, b) => a.arrival - b.arrival)); //sort by arrival time
                    });

                    queue.forEach((client, index) => {
                        //when client pop out from query
                        let visit = client.arrival.getTime() > freeVisit.getTime() ? client.arrival : freeVisit;
                        freeVisit = new Date(visit.getTime() + client.duration * 1000 * 60);
                        client.visit = visit;
                        client.waiting = (client.visit.getTime() - client.arrival.getTime()) / 60 / 1000;
                        client.len = 0;
                        client.leaving = freeVisit;
                        for (let i = index - 1; i >= 0; i--) {
                            if (queue[i].leaving > client.arrival) client.len++;
                            else break;
                        }
                    });

                    /* * время, количество человек в очереди, среднее кол-во, макс время ожидания, макс очередь*/

                    vm.avgLength = queue.map((client) => client.len).reduce((a, b) => a + b, 0) / queue.length;
                    vm.maxLength = Math.max(...queue.map((client) => client.len));
                    vm.maxWaiting = Math.max(...queue.map((client) => client.waiting));

                    vm.plotData = {
                        queue: queue
                    };

                }

            };


            vm.timestamp = new Date();
            vm.clientsPerHour = 10;
            vm.operationsMin = 5;
            vm.operationsMax = 50;
            vm.hoursAmount = 24;
            vm.hours = [];
            // vm.hours = [
            //     {
            //         clients: 5,
            //         operations: {
            //             min: 10,
            //             max: 15,
            //         }
            //     },
            //     {
            //         clients: 3,
            //         operations: {
            //             min: 20,
            //             max: 30,
            //         }
            //     }
            // ];

            vm.options = {
                margin: {
                    top: 10,
                },
                series: [
                    {
                        axis: "y",
                        dataset: "queue",
                        key: "len",
                        label: "Queue length",
                        color: "#1f77b4",
                        type: ["line"],
                    }
                ],
                axes: {
                    x: {key: "arrival", type: "date"},
                },
                grid: {
                    x: true,
                    y: true
                }
            };

            // vm.addHour = () => {
            //     let modalInstance = $uibModal.open({
            //         animation: true,
            //         templateUrl: 'src/pages/labs/queue/modal/index.html',
            //         controller: 'queueModalController',
            //         controllerAs: 'modalCtrl',
            //     });
            //
            //     modalInstance.result.then((hour) => {
            //         vm.hours.push(hour);
            //         vm.generateClients();
            //     });
            // };

        }]);
})();