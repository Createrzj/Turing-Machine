//
// Created by Azure on 2024/6/25.
//

#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef struct {
    int low;
    int high;
    int mid;
} Frame;

class Recursive {
private:
    int current_in;
    int current_work;
    int step;
    int grid;
public:
    vector<int> inputtap;
    vector<int> worktap;
    vector<int> output;
    stack<Frame> work_stack;

    int heigh;
    int low;

    //Function:
    Recursive();

    void initwork(vector<int> input,int find);

    void showinputtap();

    void TuringStart();
    void scan();
    void readlow();
    void getstack();
    int compareHeigh();
    int getMiddle();
    int findMiddle();
    int compareMiddle();
    void updateLow();
    void updateHigh();
    void callstack();
    void success();
    int stop();

    void showstack();


    ~Recursive();

};



#endif //RECURSIVE_H
