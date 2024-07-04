//
// Created by icy on 24-6-30.
//

#include "../include/DP_knap.h"

DP_knap::DP_knap() {
    state = READ_CAPACITY;
    steps = 0;
    capacity = 0;
    temp = "";
    inputPos = 0;
    workPos = 0;
    outputPos = 0;
    numItems = 0;
    current_weight = 0;
    current_value = 0;
    current_flag = 0;
    index_items = 0;
    index_cap = 0;
    workPos = 0;
    L1 = 0;
    L2 = 0;
    MAX = 0;
    flag = 0;
    workspace = 0;
}

void DP_knap::updatePara() {
    state = READ_CAPACITY;
    steps = 0;
    capacity = 0;
    temp = "";
    inputPos = 0;
    workPos = 0;
    outputPos = 0;
    numItems = 0;
    current_weight = 0;
    current_value = 0;
    current_flag = 0;
    index_items = 0;
    index_cap = 0;
    workPos = 0;
    L1 = 0;
    L2 = 0;
    MAX = 0;
    flag = 0;
    workspace = 0;
}

void DP_knap::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima->setDuration(100);
    Anima->setStartValue(this->start_posTape);
    Anima->setEndValue(this->end_posTape);
    Anima->start();
}

void DP_knap::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(100);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void DP_knap::moveOutputTape(int pos) {
    this->end_posOutputTape = QPoint(start_posOutputTape.x() - TABLEWIDGET_WIDTH * pos, start_posOutputTape.y());
    Anima_output->setDuration(100);
    Anima_output->setStartValue(this->start_posOutputTape);
    Anima_output->setEndValue(this->end_posOutputTape);
    Anima_output->start();
}

void DP_knap::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

int DP_knap::execute() {
    this->Initial();
    while (true) {
        steps++;
        ui->steps->setText(QString::number(steps));
        ui->grids->setText(QString::number(workspace));
        switch (state) {
            case READ_CAPACITY:
                ui->output_process->setText("READ_CAPACITY");
                readCapacity();
                break;
            case READ_NUM:
                ui->output_process->setText("READ_NUM");
                readNum();
                break;
            case READ_WEIGHT:
                ui->output_process->setText("READ_WEIGHT");
                readWeight();
                break;
            case READ_VALUE:
                ui->output_process->setText("READ_VALUE");
                readValue();
                break;
            case WRITE_M:
                ui->output_process->setText("WRITE_M");
                writeM();
                break;
            case READ_M:
                ui->output_process->setText("READ_M");
                readM();
                break;
            case CAL_M:
                ui->output_process->setText("CAL_M");
                calm();
                break;
            case CMP:
                ui->output_process->setText("CMP");
                cmp();
                break;
            case READ_W:
                ui->output_process->setText("READ_W");
                readW();
                break;
            case RESULT:
                ui->output_process->setText("RESULT");
                getresult();
                break;
            case R_ANS:
                ui->output_process->setText("R_ANS");
                readAns();
                break;
            case CMP_ANS:
                ui->output_process->setText("CMP_ANS");
                compareAns();
                break;
            case KNAPSACK_SUCCESS:
                ui->output_process->setText("KNAPSACK_SUCCESS");
                temp = ui->workTape->item(0, capacity)->text();
                return temp.toInt();
        }
        DP_knap::delay(100);
    }
}

void DP_knap::readCapacity() {
    temp = ui->inputTape->item(0, inputPos)->text();
    capacity = temp.toInt();
    index_cap = capacity;
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = READ_NUM;
}

void DP_knap::readNum() {
    temp = ui->inputTape->item(0, inputPos)->text();
    numItems = temp.toInt();
    index_items = numItems;
    this->moveTape(numItems * 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = numItems * 2;
    state = READ_WEIGHT;
}

void DP_knap::readWeight() {
    temp = ui->inputTape->item(0, inputPos)->text();
    current_weight = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = READ_VALUE;
}

void DP_knap::readValue() {
    temp = ui->inputTape->item(0, inputPos)->text();
    current_value = temp.toInt();
    this->moveTape(-3);
    this->start_posTape = this->end_posTape;
    inputPos -= 3;
    if (index_items == numItems) {
        state = WRITE_M;
    } else
        state = READ_M;
}

void DP_knap::readM() {
    if (index_cap < current_weight) {
        this->moveWorkTape(index_cap + (index_items) * (capacity + 1) - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = index_cap + (index_items) * (capacity + 1);
        state = WRITE_M;
    } else {
        this->moveWorkTape(index_cap + (index_items) * (capacity + 1) - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = index_cap + (index_items) * (capacity + 1);
        temp = ui->workTape->item(0, workPos)->text();
        L1 = temp.toInt();
        state = CAL_M;
    }
}

void DP_knap::calm() {
    int index = index_cap + (index_items) * (capacity + 1) - current_weight;
    this->moveWorkTape(index - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = index;
    L2 = ui->workTape->item(0, workPos)->text().toInt() + current_value;
    state = CMP;
}

void DP_knap::cmp() {
    if (L1 > L2)
        MAX = L1;
    else
        MAX = L2;
    state = WRITE_M;
}

void DP_knap::writeM() {
    int index = 0;
    workspace++;
    if (index_items > 0 && index_cap >= current_weight && index_items == numItems) {
        index = index_cap + (index_items - 1) * (capacity + 1);
        this->moveWorkTape(index - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        ui->workTape->setItem(0, index, new QTableWidgetItem(QString::number(current_value)));
        workPos = index;
    } else if (index_items > 0 && index_items == numItems) {
        index = index_cap + (index_items - 1) * (capacity + 1);
        this->moveWorkTape(index - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        ui->workTape->setItem(0, index, new QTableWidgetItem("0"));
        workPos = index;
    } else if (index_items > 0 && index_cap >= current_weight && index_items < numItems) {
        index = index_cap + (index_items - 1) * (capacity + 1);
        this->moveWorkTape(index - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        ui->workTape->setItem(0, index, new QTableWidgetItem(QString::number(MAX)));
        workPos = index;
    } else if (index_items > 0 && index_items < numItems) {
        index = index_cap + (index_items - 1) * (capacity + 1);
        this->moveWorkTape(index - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        ui->workTape->setItem(0, index, new QTableWidgetItem(ui->workTape->item(0, workPos)->text()));
        workPos = index;
    }
    if (index_cap > 0 && index_items == numItems) {
        index_cap--;
        delay(100);
        state = WRITE_M;
    } else if (index_cap > 0) {
        index_cap--;
        delay(100);
        state = READ_M;
    } else {
        index_items--;
        index_cap = capacity;
        delay(100);
        state = READ_WEIGHT;
    }
    if (index_items == 0) {
        delay(100);
        this->moveWorkTape(capacity - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = capacity;
        state = RESULT;
    }
}

void DP_knap::readW() {
    this->moveTape((index_items + 1) * 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = (index_items + 1) * 2;
    temp = ui->inputTape->item(0, inputPos)->text();
    current_weight = temp.toInt();
    if (flag == 0) {
        this->moveOutputTape(index_items - outputPos);
        this->start_posOutputTape = this->end_posOutputTape;
        outputPos = index_items;
        ui->outputTape->setItem(0, outputPos, new QTableWidgetItem("0"));
        index_items++;
    } else {
        this->moveOutputTape(index_items - outputPos);
        this->start_posOutputTape = this->end_posOutputTape;
        outputPos = index_items;
        ui->outputTape->setItem(0, outputPos, new QTableWidgetItem("1"));
        workPos -= current_weight;
        index_items++;
    }
    state = RESULT;
}

void DP_knap::readAns() {
    current_flag = (index_items + 1) * (capacity + 1) + workPos - ((capacity + 1) * index_items);
    state = CMP_ANS;
}

void DP_knap::compareAns() {
    qDebug()<<workPos;
    qDebug()<<current_flag;
    int temp1 = ui->workTape->item(0, workPos)->text().toInt();
    int temp2 = ui->workTape->item(0, current_flag)->text().toInt();
    this->moveWorkTape(current_flag - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = current_flag;
    if (temp1 == temp2) {
        qDebug() << "flag=0";
        flag = 0;
    }
    else{
        qDebug() << "flag=1";
        flag = 1;
    }

    state = READ_W;
}

void DP_knap::getresult() {
    if (index_items == numItems - 1) {
        qDebug()<<"我进来了";
        if (ui->workTape->item(0, workPos)->text().toInt() != 0) {
            ui->outputTape->setItem(0, index_items, new QTableWidgetItem("1"));
        } else
            ui->outputTape->setItem(0, index_items, new QTableWidgetItem("0"));
        state = KNAPSACK_SUCCESS;
    } else {
        state = R_ANS;
    }
}

void DP_knap::Initial() {
    temp = ui->input_Num->text();
    int size_output = temp.toInt();
    ui->workTape->setColumnCount(size_output);
    ui->workTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth((size_output + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_output; i++) {
        auto item = new QTableWidgetItem("0");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }

    temp = ui->input_Capacity->text();
    int size_work = (temp.toInt()+1) * size_output;
    ui->workTape->setColumnCount(size_work);
    ui->workTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth((size_work + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_work; i++) {
        auto item = new QTableWidgetItem("");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }

    Anima->setTargetObject(ui->inputTape);
    Anima->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    Anima_output->setTargetObject(ui->outputTape);
    Anima_output->setPropertyName("pos");

    start_posTape = ui->inputTape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();
    start_posOutputTape = ui->outputTape->geometry().topLeft();
}


