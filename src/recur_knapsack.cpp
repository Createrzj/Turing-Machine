//
// Created by icy on 24-7-1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_recur_knapsack.h" resolved

#include "../include/recur_knapsack.h"

recur_knapsack::recur_knapsack(QWidget *parent) :
        QWidget(parent), ui(new Ui::recur_knapsack) {
    ui->setupUi(this);

    this->Numbers = QStringList();

    m_recur_knapsack.ui = ui;
    backtrack_knap.ui = ui;
    Anima_input->setTargetObject(ui->inputTape);
    Anima_input->setPropertyName("pos");
    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");
    Anima_output->setTargetObject(ui->outputTape);
    Anima_output->setPropertyName("pos");
    //按钮信号连接
    connect(ui->memory_knap, SIGNAL(clicked(bool)), this, SLOT(Knapsack_memory()));
    connect(ui->backtrack_knap, SIGNAL(clicked(bool)), this, SLOT(Knapsack_backtrack()));
    connect(ui->return_main, SIGNAL(clicked(bool)), this, SLOT(returnMain()));
    connect(ui->restore, SIGNAL(clicked(bool)), this, SLOT(Restore()));

    ui->picture_turing->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/turing_machine.png")));
    ui->picture_arrowhead->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/arrowhead.png")));
    ui->picture_turing_2->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/turing_machine.png")));
    ui->picture_arrowhead_2->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/arrowhead.png")));
    ui->picture_turing_3->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/turing_machine.png")));
    ui->picture_arrowhead_3->setPixmap(
            QPixmap(QString::fromUtf8("D:/programing/CLionProjects/Turing Machine/resources/arrowhead.png")));

    //初始化纸带
    ui->inputTape->setRowCount(1);
    ui->inputTape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->inputTape->setFixedWidth(TABLEWIDGET_WIDTH * (TABLEWIDGET_INIT_SIZE + 1));
    ui->inputTape->verticalHeader()->setVisible(false);
    ui->inputTape->horizontalHeader()->setVisible(false);

    // 初始化工作纸带
    ui->workTape->setRowCount(1);
    ui->workTape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth(TABLEWIDGET_WIDTH * (TABLEWIDGET_INIT_SIZE + 1));
    ui->workTape->verticalHeader()->setVisible(false);
    ui->workTape->horizontalHeader()->setVisible(false);

    // 初始化输出纸带
    ui->outputTape->setRowCount(1);
    ui->outputTape->setFixedHeight(TABLEWIDGET_HEIGHT);
    ui->outputTape->setFixedWidth(TABLEWIDGET_WIDTH * (TABLEWIDGET_INIT_SIZE + 1));
    ui->outputTape->verticalHeader()->setVisible(false);
    ui->outputTape->horizontalHeader()->setVisible(false);
}

recur_knapsack::~recur_knapsack() {
    delete ui;
}

void recur_knapsack::Knapsack_memory() {
    if (ui->input_Knap->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入目标序列!");
        return;
    }
    if (ui->input_Capacity->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入总承重!");
        return;
    }
    if (ui->input_Num->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入物体数量!");
        return;
    }
    this->Numbers.clear();
    this->GetInput();
    this->initTape();
    m_recur_knapsack.START();
}

void recur_knapsack::Knapsack_backtrack() {
    if (ui->input_Knap->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入目标序列!");
        return;
    }
    if (ui->input_Capacity->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入总承重!");
        return;
    }
    if (ui->input_Num->text().isEmpty()) {
        QMessageBox::warning(this, "Warning!", "请输入物体数量!");
        return;
    }
    this->Numbers.clear();
    this->GetInput();
    this->initTape();
    backtrack_knap.execute();
}

void recur_knapsack::GetInput() {
    Numbers.append(ui->input_Capacity->text());
    Numbers.append(ui->input_Num->text());
    QStringList temp = ui->input_Knap->text().split("，", QString::SkipEmptyParts);
    foreach(const QString &number, temp) {
        Numbers.append(number);
    }
}

void recur_knapsack::initTape() {
    int size_input = this->Numbers.size();
    int size_output = Numbers[1].toInt();
    int size_work = (Numbers[0].toInt() + 1) *(size_output+1);

    ui->inputTape->setColumnCount(size_input);
    ui->inputTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->inputTape->setFixedWidth((size_input + 1) * TABLEWIDGET_WIDTH);

    auto item = new QTableWidgetItem("");
    ui->inputTape->setColumnWidth(size_input, TABLEWIDGET_WIDTH);
    ui->inputTape->setItem(0, size_input, item);

    for (int i = 0; i < size_input; i++) {
        auto item = new QTableWidgetItem(this->Numbers[i]);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->inputTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->inputTape->setItem(0, i, item);
    }

    ui->outputTape->setColumnCount(size_output);
    ui->outputTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->outputTape->setFixedWidth((size_output + 1) * TABLEWIDGET_WIDTH);

    for (int i = 0; i < size_output; i++) {
        auto item = new QTableWidgetItem("0");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->outputTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->outputTape->setItem(0, i, item);
    }

    ui->workTape->setColumnCount(size_work);
    ui->workTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth((size_work + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_work; i++) {
        if((i>=0&&i<=Numbers[0].toInt())||i%(Numbers[0].toInt() + 1)==0) {
            auto item = new QTableWidgetItem("0");
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
            ui->workTape->setItem(0, i, item);
        }
        else {
            auto item = new QTableWidgetItem("-1");
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
            ui->workTape->setItem(0, i, item);
        }
    }
}

void recur_knapsack::returnMain() {
//    Restore();
    emit Show_Father_Widget();
    this->close();
}

void recur_knapsack::Restore() {
    ui->input_Capacity->clear();
    ui->input_Num->clear();
    ui->input_Knap->clear();
    ui->steps->clear();
    ui->grids->clear();
    ui->output_process->clear();
    ui->STACK->clear();
    ui->max_value->clear();
    //还原输入纸带位置
    Anima_input->setDuration(2000);
    Anima_input->setStartValue(ui->inputTape->geometry().topLeft());
    Anima_input->setEndValue(QPoint(655, 340));
    Anima_input->start();
    //还原工作纸带位置
    Anima_work->setDuration(2000);
    Anima_work->setStartValue(ui->workTape->geometry().topLeft());
    Anima_work->setEndValue(QPoint(655, 540));
    Anima_work->start();
    //还原工作纸带位置
    Anima_output->setDuration(2000);
    Anima_output->setStartValue(ui->outputTape->geometry().topLeft());
    Anima_output->setEndValue(QPoint(655, 730));
    Anima_output->start();
    //更新输入纸带
    for (int i = 0; i < ui->inputTape->columnCount(); i++) {
        ui->inputTape->setItem(0, i, new QTableWidgetItem(""));
    }
    //更新工作纸带
    for (int i = 0; i < ui->workTape->columnCount(); i++) {
        ui->workTape->setItem(0, i, new QTableWidgetItem(""));
    }
    //更新输出纸带
    for (int i = 0; i < ui->outputTape->columnCount(); i++) {
        ui->outputTape->setItem(0, i, new QTableWidgetItem(""));
    }

    ui->horizontalSlider->setValue(1000);

    m_recur_knapsack.updatePara();
    backtrack_knap.updatePara();
}
