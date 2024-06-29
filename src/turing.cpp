//
// Created by icy on 24-6-25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Turing.h" resolved

#include "../include/turing.h"

Turing::Turing(QWidget *parent) :
        QWidget(parent), ui(new Ui::Turing) {
    ui->setupUi(this);

    this->Numbers = QStringList();
    Turing_BinarySer.ui = ui;
    Recyrsive_BinarySer.ui = ui;
    Anima->setTargetObject(ui->tape);
    Anima->setPropertyName("pos");
    Anima1->setTargetObject(ui->workTape);
    Anima1->setPropertyName("pos");
    //按钮信号连接
    connect(ui->Iterative_Binary_Search, SIGNAL(clicked(bool)), this, SLOT(BinarySearch_Iterative()));
    connect(ui->Recursive_Binary_Search, SIGNAL(clicked(bool)), this, SLOT(BinarySearch_Recursive()));
    connect(ui->restore, SIGNAL(clicked(bool)), this, SLOT(Restore()));

    ui->picture_turing->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/turing_machine.png")));
    ui->picture_arrowhead->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/arrowhead.png")));
    ui->picture_turing_2->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/turing_machine.png")));
    ui->picture_arrowhead_2->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/arrowhead.png")));

    //初始化纸带
    ui->tape->setRowCount(1);
    ui->tape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->tape->setFixedWidth(TABLEWIDGET_WIDTH * (TABLEWIDGET_INIT_SIZE + 1));
    ui->tape->verticalHeader()->setVisible(false);
    ui->tape->horizontalHeader()->setVisible(false);

    // 初始化工作纸带
    ui->workTape->setRowCount(1);
    ui->workTape->setColumnCount(3);
    ui->workTape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth(TABLEWIDGET_WIDTH * (WORKTAPEWODGET_INIT_SIZE + 1));
    ui->workTape->setRowHeight(0, 50);
    ui->workTape->setColumnWidth(0, 60);
    ui->workTape->setColumnWidth(1, 60);
    ui->workTape->setColumnWidth(2, 60);
    ui->workTape->verticalHeader()->setVisible(false);
    ui->workTape->horizontalHeader()->setVisible(false);

    ui->STACK->setAlignment(Qt::AlignCenter);
    ui->STACK->append("workTape");
    ui->STACK->append("wp");
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
    int result = Turing_BinarySer.execute();
    ui->output_Binary->setText(QString::number(result));
}

void Turing::BinarySearch_Recursive() {
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
//    int result = Turing_BinarySer.execute();
    int result = Recyrsive_BinarySer.execute();
    ui->output_Binary->setText(QString::number(result));
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
    ui->tape->setColumnCount(size + 3);
    ui->tape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->tape->setFixedWidth((size + 4) * TABLEWIDGET_WIDTH);

    auto item = new QTableWidgetItem();
    ui->tape->setColumnWidth(size + 4, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, size + 4, item);
    // low
    auto item1 = new QTableWidgetItem("1");
    item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tape->setColumnWidth(0, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, 0, item1);
    //high
    auto item2 = new QTableWidgetItem(QString::number(size));
    item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tape->setColumnWidth(1, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, 1, item2);
    //目标数字
    auto item3 = new QTableWidgetItem(ui->Target->text());
    item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tape->setColumnWidth(2, TABLEWIDGET_WIDTH);
    ui->tape->setItem(0, 2, item3);

    for (int i = 3; i < size + 3; i++) {
        auto item = new QTableWidgetItem(this->Numbers[i - 3]);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->tape->setItem(0, i, item);
    }
}

void Turing::Restore() {
    ui->input_BianrySer->clear();
    ui->Target->clear();
    ui->steps->clear();
    ui->grids->clear();
    ui->output_Binary->clear();

    Anima->setDuration(2000);
    Anima->setStartValue(ui->tape->geometry().topLeft());
    Anima->setEndValue(QPoint(545, 330));
    Anima->start();

    Anima1->setDuration(2000);
    Anima1->setStartValue(ui->workTape->geometry().topLeft());
    Anima1->setEndValue(QPoint(545, 570));
    Anima1->start();

    auto item1 = new QTableWidgetItem();
    ui->workTape->setItem(0, 0, item1);
    auto item2 = new QTableWidgetItem();
    ui->workTape->setItem(0, 1, item2);
    auto item3 = new QTableWidgetItem();
    ui->workTape->setItem(0, 2, item3);
}

