//
// Created by icy on 24-6-25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Turing.h" resolved

#include "../include/turing.h"

Turing::Turing(QWidget *parent) :
        QWidget(parent), ui(new Ui::Turing) {
    ui->setupUi(this);

    this->Numbers = QStringList();
    //按钮信号连接
    connect(ui->Iterative_Binary_Search, SIGNAL(clicked(bool)), this, SLOT(BinarySearch_Iterative()));

    //初始化纸带
    Anima->setTargetObject(ui->tape);
    ui->tape->setRowCount(1);
    ui->tape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->tape->setFixedWidth(TABLEWIDGET_WIDTH * (TABLEWIDGET_INIT_SIZE + 1));
    ui->tape->verticalHeader()->setVisible(false);
    ui->tape->horizontalHeader()->setVisible(false);

}

Turing::~Turing() {
    delete ui;
}

// 图灵机二分搜索
void Turing::BinarySearch_Iterative() {
    if (ui->input_BianrySer->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入目标序列!");
        return;
    }
    if (ui->Target->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入目标数字!");
        return;
    }
    QString input = ui->input_BianrySer->text();
    quicksort->Preprocess(input);
    quicksort->quickSort(intNumbers, 0, intNumbers.size() - 1);
    this->Numbers.clear();
    this->ChangeToList();
    this->initTape();
//    Anima->setPropertyName("pos");
//    Anima->setDuration(2000);
//    Anima->setStartValue(QPoint(50, 270));
//    Anima->setEndValue(QPoint(200, 270));
//    Anima->start();
}

// 快速排序之后数据转换为QStringList
void Turing::ChangeToList() {
    for (int number: intNumbers) {
        Numbers.append(QString::number(number));
    }
}

// 输入值初始化纸带
void Turing::initTape() {
    int size = this->Numbers.size();
    ui->tape->setColumnCount(size + 1);
    ui->tape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->tape->setFixedWidth((size + 2) * TABLEWIDGET_WIDTH);

    auto item = new QTableWidgetItem();
    auto item1 = new QTableWidgetItem();
    ui->tape->setColumnWidth(0, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, 0, item);
    ui->tape->setColumnWidth(size + 1, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, size + 1, item1);

    for (int i = 1; i < size + 1; i++) {
        auto item = new QTableWidgetItem(this->Numbers[i - 1]);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->tape->setItem(0, i, item);
    }
}

