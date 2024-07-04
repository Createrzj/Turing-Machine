//
// Created by Azure on 24-6-29.
//

#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct {
    int n;    //物品n
    int xi;    //访问次数
}node;

class BackTrack {

private:
    int N;//
    int capcity;
    int step;
    vector<int> inputtap;
    vector<int> worktap;
    vector<int> output;
    vector<int> bestx;
    stack<node> work_stack;

    int current_in;
    int current_work;
    int current_out;


public:
    int bestv;

    vector<int> weight;
    vector<int> value;
    int cwig;
    int cval;
    BackTrack();
    void initwork(vector<int> weight,vector<int>value,int cap);

    void showinput();
    void TuringStart();
    void scan();

    void pushleft(node current);
    void pushright(node current);
    void popnode(node current);
    void popleft();
    void popright();

    void readcval();
    void writecval(int value);
    void readcwig();
    void writecwig(int weight);
    void readbestv();
    void readwigi(int i);
    void readvali(int i);
    int calbound(node current);
    bool campbound(float bound);

    int judgeleaf(node current);

    void updatexi(int n,int xi);
    void updatebestv(node current);
    void updatebestx();
    void updateoutput();
    int judgevis(node current);
    bool compcap(node current);

    void showstack();
    void showwork();
    void showoutput();


};



#endif //BACKTRACK_H
