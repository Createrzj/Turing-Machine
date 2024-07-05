//
// Created by icy on 24-6-30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Knapsack.h" resolved

#include "../include/knapsack.h"

Knapsack::Knapsack(QWidget *parent) :
        QWidget(parent), ui(new Ui::Knapsack) {
    ui->setupUi(this);

    this->Numbers = QStringList();
    dpKnap.ui = ui;
    bbKnap.ui = ui;
    dpKnap.table = &dpTable;
    Anima->setTargetObject(ui->inputTape);
    Anima->setPropertyName("pos");
    Anima1->setTargetObject(ui->workTape);
    Anima1->setPropertyName("pos");
    Anima2->setTargetObject(ui->outputTape);
    Anima2->setPropertyName("pos");
    //按钮信号连接
    connect(ui->DP, SIGNAL(clicked(bool)), this, SLOT(Knapsack_DP()));
    connect(ui->BB, SIGNAL(clicked(bool)), this, SLOT(Knapsack_BB()));
    connect(ui->restore, SIGNAL(clicked(bool)), this, SLOT(Restore()));
    connect(ui->Return, SIGNAL(clicked(bool)), this, SLOT(returnMain()));

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

Knapsack::~Knapsack() {
    delete ui;
}

//动态规划
void Knapsack::Knapsack_DP() {
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
    dpTable.show();
    dpTable.Initial(Numbers[1].toInt(), Numbers[0].toInt() + 1);
    int result = dpKnap.execute();
    ui->max_value->setText(QString::number(result));
}

void Knapsack::Knapsack_BB() {
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
    float result = bbKnap.execute();
    ui->max_value->setText(QString::number(result));
}

void Knapsack::GetInput() {
    Numbers.append(ui->input_Capacity->text());
    Numbers.append(ui->input_Num->text());
    QStringList temp = ui->input_Knap->text().split("，", QString::SkipEmptyParts);
            foreach(const QString &number, temp) {
            Numbers.append(number);
        }
}

void Knapsack::initTape() {
    int size_input = this->Numbers.size();
    int size_output = Numbers[1].toInt();
    int size_work = (Numbers[0].toInt() + 1) * size_output;

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
        auto item = new QTableWidgetItem("");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }
}

void Knapsack::Restore() {
    ui->input_Knap->clear();
    ui->input_Capacity->clear();
    ui->input_Num->clear();
    ui->steps->clear();
    ui->grids->clear();
    ui->output_process->clear();
    ui->max_value->clear();
    //还原输入纸带位置
    Anima->setDuration(2000);
    Anima->setStartValue(ui->inputTape->geometry().topLeft());
    Anima->setEndValue(QPoint(635, 300));
    Anima->start();
    //还原工作纸带位置
    Anima1->setDuration(2000);
    Anima1->setStartValue(ui->workTape->geometry().topLeft());
    Anima1->setEndValue(QPoint(635, 500));
    Anima1->start();
    //还原输出纸带位置
    Anima2->setDuration(2000);
    Anima2->setStartValue(ui->outputTape->geometry().topLeft());
    Anima2->setEndValue(QPoint(635, 690));
    Anima2->start();

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

    dpTable.close();
    ui->Queue->clear();
    dpKnap.updatePara();
    bbKnap.updatePara();
}

void Knapsack::returnMain() {
    Restore();
    emit Show_Father_Widget();
    this->close();
}
