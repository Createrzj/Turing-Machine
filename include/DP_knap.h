//
// Created by icy on 24-6-30.
//

#ifndef TURING_MACHINE_DP_KNAP_H
#define TURING_MACHINE_DP_KNAP_H

#include "Library.h"
#include "../ui/ui_knapsack.h"

class DP_knap {
public:
    Ui::Knapsack *ui{};
    DP_knap();
    int execute();
    void readValue();
    void readWeight();
    void readNum();
    void readCapacity();
    void readM();
    void writeM();
    void getresult();
    void calm();
    void cmp();
    void readW();
    void compareAns();
    void readAns();

    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void moveOutputTape(int pos);// 移动输出纸带
    static void delay(int milliseconds);//延时函数
    void Initial();//初始化

private:
    enum KnapsackState {
        READ_CAPACITY, READ_NUM, READ_WEIGHT, READ_VALUE,
        WRITE_M, KNAPSACK_SUCCESS,RESULT,READ_M,CAL_M,CMP,
        READ_W,CMP_ANS,R_ANS
    };
    KnapsackState state; // 当前状态
    int steps;
    int capacity; // 背包容量
    int numItems; // 物品数量
    int current_value, current_weight, current_flag; // 当前物品的价值和重量,临时位置
    int index_items, index_cap; // 当前物品的索引和当前容量的索引
    QString temp; // 读取纸带转换
    int inputPos;// 当前指向输入纸带的位置
    int workPos;// 当前指向工作纸带的位置
    int outputPos;// 当前指向输出纸带的位置
    int L1,L2,MAX;//用于比较两个值大小
    int flag;// 回溯时判断是否加入背包
    int workspace;// 工作纸带空间

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


#endif //TURING_MACHINE_DP_KNAP_H
