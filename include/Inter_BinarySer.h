//
// Created by icy on 24-6-27.
//

#ifndef INTER_BINARYSER_H
#define INTER_BINARYSER_H

#include "Library.h"
#include "../ui_turing.h"

using namespace std;


class Inter_BinarySer {
public:
    Ui::Turing *ui;
    Inter_BinarySer();
    int execute();// 运行主函数
    void moveTape(int pos);// 移动输入纸带
    void moveWorkTape(int pos);// 移动工作纸带
    void delay(int milliseonds);
    void Initial();// 初始化

private:
    enum State {
        INIT_LOW, WRITE_LOW, INIT_HIGH,
        WRITE_HIGH, COMPARE_LOW, STOP,
        CAI_MID, UPDATE_LOW, UPDATE_HIGH,
        READ_MID, COMPARE_MID, SUCCESS
    };
    int steps;// 运行步数
    int workSpace;// 工作纸带运行空间
    int target;// 目标数字
    State state;// 运行状态
    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPoint start_posTape;// 输入纸带运动起始位置
    QPoint end_posTape;// 输入纸带运动终止位置

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;// 工作纸带运动起始位置
    QPoint end_posWorkTape;// 工作纸带运动终止位置
};


#endif //INTER_BINARYSER_H
