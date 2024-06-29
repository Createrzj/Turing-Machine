//
// Created by icy on 24-6-25.
//

#ifndef TURING_H
#define TURING_H

#include "QuickSort.h"
#include "Library.h"
#include "Inter_BinarySer.h"
#include "Recur_BinarySer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Turing; }
QT_END_NAMESPACE

class Turing : public QWidget {
Q_OBJECT

public:
    explicit Turing(QWidget *parent = nullptr);
    ~Turing() override;
    Inter_BinarySer Turing_BinarySer;// 二分搜索图灵机
    Recur_BinarySer Recyrsive_BinarySer;// 二分搜索递归

private:
    Ui::Turing *ui;
    QuickSort *quicksort{};// 快速排序
    QStringList Numbers;// 二分搜索输入的序列
    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPropertyAnimation *Anima1 = new QPropertyAnimation;

    void initTape();// 初始化纸带
    void ChangeToList();// 快速排序之后数据转换为QStringList

public slots:
    void BinarySearch_Iterative();// 图灵机二分搜索
    void BinarySearch_Recursive();// 递归二分搜索
    void Restore();// 重置
};


#endif //TURING_H
