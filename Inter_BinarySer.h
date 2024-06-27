//
// Created by 11356 on 2024/6/25.
//

#ifndef TURING_H
#define TURING_H
#include <iostream>
#include <vector>
using namespace std;


class TuringMachine {
public:
    TuringMachine(const std::vector<int>& arr, int x);
    int execute();
    int getSteps() const { return steps; }
    int getTapeSpace() const { return tapeSpace; }

protected:
    int steps;
    int tapeSpace;
    std::vector<int> intputtape;
    std::vector<int> worktape;
    std::vector<int> outputtape;
    enum State {
        INIT_LOW, WRITE_LOW, INIT_HIGH,
        WRITE_HIGH, COMPARE_LOW, STOP,
        CAI_MID, UPDATE_LOW, UPDATE_HIGH,
        READ_MID, COMPARE_MID, SUCCESS
    };
    int target;
    State state;
};
#endif //TURING_H