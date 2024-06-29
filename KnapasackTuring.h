//
// Created by 11356 on 2024/6/27.
//

#ifndef KNAPASACKTURING_H
#define KNAPASACKTURING_H
#include <vector>
#include <iostream>
using namespace std;
class KnapsackTuringMachine {
public:
    KnapsackTuringMachine(const std::vector<int>& tapes, int capacity, int numItems);
    int Kexecute();
    int getSteps() const { return steps; }
    int getTapeSpace() const { return tapeSpace; }

private:
    enum KnapsackState {
        READ_CAPACITY, READ_NUM, READ_WEIGHT, READ_VALUE,
        WRITE_M, KNAPSACK_SUCCESS,
    };
    int steps;
    int tapeSpace;
    std::vector<int> intputtape;
    std::vector<int> worktape;
    std::vector<int> outputtape;
    int capacity; // 背包容量
    int numItems; // 物品数量
    int i, j; // 当前物品的索引和当前容量的索引
    int current_value, current_weight; // 当前物品的价值和重量
    KnapsackState knapsackState; // 当前状态
    void readValue();
    void readWeight();
    void readNum();
    void readCapacity();
    void writeM();
    void getresult();
};



#endif //KNAPASACKTURING_H
