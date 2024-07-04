//
// Created by icy on 24-7-1.
//

#ifndef TURING_MACHINE_RECUR_KNAPSACK_H
#define TURING_MACHINE_RECUR_KNAPSACK_H

#include "Library.h"
#include "../ui/ui_recur_knapsack.h"
#include "Memory_knap.h"
#include "BackTrack_knap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class recur_knapsack; }
QT_END_NAMESPACE

class recur_knapsack : public QWidget {
Q_OBJECT

public:
    explicit recur_knapsack(QWidget *parent = nullptr);
    ~recur_knapsack() override;
    Memory_knap m_recur_knapsack;// 备忘录0-1背包
    BackTrack_knap backtrack_knap;// 回溯0-1背包

private:
    Ui::recur_knapsack *ui;
    QStringList Numbers;// 二分搜索输入的序列
    QPropertyAnimation *Anima_input = new QPropertyAnimation;// 控制输入纸带
    QPropertyAnimation *Anima_work = new QPropertyAnimation;// 控制工作纸带
    QPropertyAnimation *Anima_output = new QPropertyAnimation;// 控制输出纸带

    void GetInput();
    void initTape();// 初始化纸带

public slots:
    void Knapsack_memory();//备忘录
    void Knapsack_backtrack();// 回溯
    void returnMain();//返回主界面

signals:
    void Show_Father_Widget();
};


#endif //TURING_MACHINE_RECUR_KNAPSACK_H
