//
// Created by Azure on 2024/6/27.
//

#ifndef RECUR_KANP_H
#define RECUR_KANP_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct {
    int cap;
    int n;
    int state;
} Frame;

class Recur_kanp {
private:
    int step;
    int grid;
    int current_in;
    int current_work;
    int current_put;
    int N;
public:
    vector<int> weight;
    vector<int> value;
    vector<int> inputtap;
    vector<int> worktap;
    vector<int> output;
    stack<Frame> work_stack;
    vector<vector<int>> memo;

    int capcity;

    Recur_kanp();

    void initwork(vector<int>& weights, vector<int>& values, int capcity);
    void TuringStart();
    //void getstack();
    void push_write(Frame& frame);
    void writememo1(Frame& frame);
    void comparewig(Frame& frame);
    void pushstack_1(Frame& frame);
    void pushstack_2(Frame& frame);
    void readmemo(Frame& frame);
    void readmemo(int n,int cap);
    void writemax(Frame& frame);
    void readwig(Frame& frame);
    void readwig(int n);
    void readval(Frame& frame);

    void getmaxvule();
    void scan();
    void printstack();
    void printmemo();

    void traceSolution();

    int getstacksize();
};



#endif //RECUR_KANP_H
