//
// Created by icy on 24-6-28.
//

#ifndef TURING_MACHINE_RECUR_BINARYSER_H
#define TURING_MACHINE_RECUR_BINARYSER_H

#include "Library.h"
#include "../ui/ui_turing.h"

class Recur_BinarySer {
public:
    Ui::Turing *ui{};
    Recur_BinarySer();
    void updatePara();// 重复运行初始化参数
    int execute();// 运行主函数
    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    static void delay(int milliseconds);
    void Initial();// 初始化
    void restore();// 调用call还原
    void updateline();//更新line

private:
    enum State {
        READ_LOW, COMPARE_HIGH,CAI_MID,
        READ_MID,COMPARE_MID,UPDATE_LOW,
        UPDATE_HIGH,CALL,SUCCESS,
        STOP
    };
    int steps;// 运行步数
    int workSpace;// 工作纸带运行空间
    int target;// 目标数字
    State state;// 运行状态
    QStack<QString> Stack;//递归栈
    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPoint start_posTape;// 输入纸带运动起始位置
    QPoint end_posTape;// 输入纸带运动终止位置

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;// 工作纸带运动起始位置
    QPoint end_posWorkTape;// 工作纸带运动终止位置

};


#endif //TURING_MACHINE_RECUR_BINARYSER_H
