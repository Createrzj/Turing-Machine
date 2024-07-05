//
// Created by icy on 24-6-30.
//

#ifndef TURING_MACHINE_KNAPSACK_H
#define TURING_MACHINE_KNAPSACK_H

#include "Library.h"
#include "DP_knap.h"
#include "BB_knap.h"
#include "dp_table.h"
#include "../ui/ui_dp_table.h"
#include "../ui/ui_knapsack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Knapsack; }
QT_END_NAMESPACE

class Knapsack : public QWidget {
Q_OBJECT

public:
    explicit Knapsack(QWidget *parent = nullptr);
    ~Knapsack() override;
    DP_knap dpKnap;//0-1背包动态规划
    BB_knap bbKnap;// 0-1背包分支界限
    DP_Table dpTable;// 打印动态规划数组表

private:
    Ui::Knapsack *ui;
    QStringList Numbers;// 0-1背包问题输入的序列
    QPropertyAnimation *Anima = new QPropertyAnimation;// 控制输入纸带
    QPropertyAnimation *Anima1 = new QPropertyAnimation;// 控制工作纸带
    QPropertyAnimation *Anima2 = new QPropertyAnimation;// 控制输出纸带

    void GetInput();
    void initTape();// 初始化纸带


public slots:
    void Knapsack_DP();// 动态规划
    void Knapsack_BB();// 分支界限
    void Restore();// 重置
    void returnMain();//返回主界面

signals:
    void Show_Father_Widget();
};


#endif //TURING_MACHINE_KNAPSACK_H
