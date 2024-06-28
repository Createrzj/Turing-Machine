//
// Created by icy on 24-6-28.
//

#ifndef TURING_MACHINE_RECUR_BINARYSER_H
#define TURING_MACHINE_RECUR_BINARYSER_H

#include "Library.h"
#include "../ui_turing.h"

class Recur_BinarySer {
public:
    Ui::Turing *ui;
    Recur_BinarySer();
    int execute();// 运行主函数
    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void delay(int milliseonds);
    void Initial();// 初始化

private:
    enum State {
        READ_LOW, COMPARE_HIGH,CAI_MID,
        READ_MID,COMPARE_MID,UPDATE_LOW,
        UPDATE_HIGH,CALL,SUCCESS,
        RETURN,STOP
    };
    int steps;// 运行步数
    int target;// 目标数字
    State state;// 运行状态
    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPoint start_posTape;// 输入纸带运动起始位置
    QPoint end_posTape;// 输入纸带运动终止位置

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;// 工作纸带运动起始位置
    QPoint end_posWorkTape;// 工作纸带运动终止位置

};


#endif //TURING_MACHINE_RECUR_BINARYSER_H
