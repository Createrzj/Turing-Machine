//
// Created by icy on 24-7-1.
//

#ifndef TURING_MACHINE_MEMORY_KNAP_H
#define TURING_MACHINE_MEMORY_KNAP_H

#include "Library.h"
#include "../ui/ui_recur_knapsack.h"

class Memory_knap {
public:
    Ui::recur_knapsack *ui{};
    Memory_knap();
    void execute();
    void START();

    void readCapacity();
    void readNum();
    void readMemo();
    void pushWrite();
    void writeMemo();
    void compareWig();
    void readWig();
    void pushstack_1();
    void pushstack_2();
    void writeMax();
    void readVal();

    void traceSolution();
    void readMemo(int n,int cap);
    void readWig(int n);
    void getMax();

    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void moveOutputTape(int pos);// 移动输出纸带
    static void delay(int milliseconds);//延时函数
    void Initial();//初始化
    void updatePara();
    void writeMax2();
    void popStack();

private:
    enum KnapsackState {
        READ_CAPACITY, READ_NUM, READ_MEMO, COMPRAE_WIG,
        PUSH_STACK_1, PUSH_STACK_2, WRITE_MAX, WRITE_MAX2, END
    };
    typedef struct {
        int cap;
        int n;
        KnapsackState state; // 当前状态
    } Frame;
    int steps;
    int workspace;// 工作纸带空间
    QStack<Frame> work_stack;
    Frame frame{};

    int capacity; // 背包容量
    int numItems; // 物品数量
    QString temp; // 读取纸带转换
    int inputPos;// 当前指向输入纸带的位置
    int workPos;// 当前指向工作纸带的位置
    int outputPos;// 当前指向输出纸带的位置
    int SPEED;

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


#endif //TURING_MACHINE_MEMORY_KNAP_H
