//
// Created by icy on 24-7-4.
//

#ifndef TURING_MACHINE_BACKTRACK_KNAP_H
#define TURING_MACHINE_BACKTRACK_KNAP_H

#include "Library.h"
#include "../ui/ui_recur_knapsack.h"

using namespace std;

typedef struct {
    int n;    //物品n
    int xi;    //访问次数
}node;

class BackTrack_knap {
public:
    Ui::recur_knapsack *ui{};
    BackTrack_knap();
    void execute();

    void readCapacity();
    void readNum();

    void initwork(vector<int> weight,vector<int>value,int cap);

    void showinput();
    void TuringStart();

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

    void judgeleaf(node current);

    void updatexi(int n,int xi);
    void updatebestv(node current);
    void updatebestx();
    void updateoutput();
    void judgevis(node current);
    bool compcap(node current);

    void showstack();
    void showwork();

    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void moveOutputTape(int pos);// 移动输出纸带
    static void delay(int milliseconds);//延时函数
    void Initial();//初始化

private:
    int capacity; // 背包容量
    int numItems; // 物品数量
    int steps;
    enum KnapsackState {
        READ_CAPACITY, READ_NUM, JUDGE_LEAF, UPDATE_BESTV,
        JUDEG_VIS, COM_CAP, CAL_BOUND, CAMP_BOUND,PUSH_LEFT,
        PUSH_RIGHT, END
    };
    KnapsackState state; // 当前状态
    int inputPos;// 当前指向输入纸带的位置
    int workPos;// 当前指向工作纸带的位置
    int outputPos;// 当前指向输出纸带的位置
    QString temp;
    int bestv;
    int cwig;
    int cval;

    vector<int> bestx;
    stack<node> work_stack;

    QPropertyAnimation *Anima_input = new QPropertyAnimation;
    QPoint start_posTape;// 输入纸带运动起始位置
    QPoint end_posTape;// 输入纸带运动终止位置

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;// 工作纸带运动起始位置
    QPoint end_posWorkTape;// 工作纸带运动终止位置

    QPropertyAnimation *Anima_output = new QPropertyAnimation;
    QPoint start_posOutputTape;// 工作纸带运动起始位置
    QPoint end_posOutputTape;// 工作纸带运动终止位置

};


#endif //TURING_MACHINE_BACKTRACK_KNAP_H
