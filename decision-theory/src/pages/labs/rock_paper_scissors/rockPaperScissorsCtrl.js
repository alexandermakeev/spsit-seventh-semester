(function () {
    'use strict';
    angular
        .module('app')
        .controller('rockPaperScissorsController', ['$scope', function ($scope) {
            let vm = this;
            vm.count = 5;
            class Shape {
                constructor(name, action) {
                    this.name = name;
                    this.action = action;
                }

                isBeaten(shape) {
                    return shape == this.beats;
                }

                setBeats(beats) {
                    this.beats = beats;
                }

                getAction() {
                    return this.action;
                }
            }
            let rock = new Shape('Rock', 'Paper covers rock'); //fixme
            let paper = new Shape('Paper', 'Scissors cut paper');
            let scissors = new Shape('Scissors', 'Rock crushes scissors');
            rock.setBeats(paper);
            paper.setBeats(scissors);
            scissors.setBeats(rock);

            let random = () => {
                let rand = Math.floor(Math.random() * 3);
                return rand == 0 ? rock : (rand == 1 ? paper : scissors);
            };

            $scope.$watch(() => vm.count, (count) => {
                if (vm.form.$invalid) return;
                vm.total = {first: 0, second: 0, tie: 0};
                vm.results = [];
                for (let i = 0; i < count; i++) {
                    let first = random();
                    let second = random();
                    let result = {first: first.name, second: second.name};
                    if (second.isBeaten(first)) {
                        vm.total.first++;
                        result.msg = 'Player 1 won: ' + second.getAction();
                    } else if (first.isBeaten(second)) {
                        vm.total.second++;
                        result.msg = 'Player 2 won: ' + first.getAction();
                    } else {
                        vm.total.tie++;
                        result.msg = 'Tie';
                    }
                    vm.results.push(result);
                }
            });
        }]);
})();