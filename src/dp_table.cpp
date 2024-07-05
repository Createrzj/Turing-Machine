//
// Created by icy on 24-7-4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DP_Table.h" resolved

#include "../include/dp_table.h"
#include "../ui/ui_dp_table.h"


DP_Table::DP_Table(QWidget *parent) :
        QWidget(parent), ui(new Ui::DP_Table) {
    ui->setupUi(this);
}

DP_Table::~DP_Table() {
    delete ui;
}

void DP_Table::Initial(int row, int column) {
    qDebug()<<column;
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);
    ui->tableWidget->setFixedHeight(TABLEWIDGET_HEIGHT * row);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < column; i++) {
        ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(""));
    }
}

void DP_Table::Fillform(int row, int column, QString x) {
    ui->tableWidget->setItem(row, column, new QTableWidgetItem(x));
}
