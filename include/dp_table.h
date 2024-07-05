//
// Created by icy on 24-7-4.
//

#ifndef TURING_MACHINE_DP_TABLE_H
#define TURING_MACHINE_DP_TABLE_H

#include "Library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DP_Table; }
QT_END_NAMESPACE

class DP_Table : public QWidget {
Q_OBJECT

public:
    explicit DP_Table(QWidget *parent = nullptr);
    ~DP_Table() override;

    void Initial(int row, int column);//初始化表格
    void Fillform(int row, int column, QString x);// 填表

private:
    Ui::DP_Table *ui;
};


#endif //TURING_MACHINE_DP_TABLE_H
