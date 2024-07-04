//
// Created by icy on 24-7-2.
//

#ifndef TURING_MACHINE_BB_KNAP_H
#define TURING_MACHINE_BB_KNAP_H

#include "Library.h"
#include "../ui/ui_knapsack.h"

using namespace std;

struct Treenode {
    Treenode *parent;
    bool Lchild;
    Treenode(Treenode* p = nullptr, bool left = false) : parent(p), Lchild(left) {}
};


struct Node {
    int level;
    float profit;
    int weight;
    float bound;
    Treenode *ptr;
};

class BB_knap {
public:
    Ui::Knapsack *ui{};
    BB_knap();
    void updatePara();// 重复运行初始化参数
    float execute();

    void readValue();
    void readWeight();
    void readNum();
    void readCapacity();
    void writeWeight();
    void writeValue();
    void writeAverage();
    void sort();
    void first();
    void maxknapsack();
    void bond();
    void righttree();
    void lefttree();
    void readV();
    void readW();
    void readV1();
    void readW1();
    void printBestBranch();

    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void moveOutputTape(int pos);// 移动输出纸带
    static void delay(int milliseconds);//延时函数
    void Initial();//初始化

private:
    enum Branch_and_bondState {
        READ_CAPACITY, READ_NUM, READ_WEIGHT, READ_VALUE,
        WRITE_W,WRITE_V,WRITE_AVER, SORT, FIST_BUILD, MAX, LeftTree, RightTree,
        READ_W,READ_V,READ_W_1,READ_V_1,BOND, Branch_and_bond_SUCCESS,
    };
    Node u, v;
    queue<Node> Q;
    int steps;
    int inputPos;// 当前指向输入纸带的位置
    int workPos;// 当前指向工作纸带的位置
    int outputPos;// 当前指向输出纸带的位置
    QVector<bool> bestx;// 回溯时找最优解
    QVector<float> temp_value;
    float current_weight, current_value;// 当前物品的价值和重量
    float maxprofit;// 最大value
    int capacity; // 背包容量
    int numItems; // 物品数量
    int i, j;
    float profit_bound;
    float totweight;
    int flag;
    QString temp;
    Branch_and_bondState state;// 当前状态
    Treenode* bestBranch; // 指向最优分支的指针

    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPoint start_posTape;// 输入纸带运动起始位置
    QPoint end_posTape;// 输入纸带运动终止位置

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;// 工作纸带运动起始位置
    QPoint end_posWorkTape;// 工作纸带运动终止位置

    QPropertyAnimation *Anima_output = new QPropertyAnimation;
    QPoint start_posOutputTape;// 工作纸带运动起始位置
    QPoint end_posOutputTape;// 工作纸带运动终止位置
};


#endif //TURING_MACHINE_BB_KNAP_H
