//
// Created by icy on 24-7-2.
//

#include "../include/BB_knap.h"

BB_knap::BB_knap() {
    steps = 0;
    inputPos = 0;
    workPos = 0;
    outputPos = 0;
    current_weight = 0;
    current_value = 0;
    maxprofit = 0;
    capacity = 0;
    numItems = 0;
    i = 1;
    j = 0;
    profit_bound = 0;
    totweight = 0;
    flag = 0;
    state = READ_CAPACITY;
    bestBranch = NULL;
    temp = "";
}

void BB_knap::updatePara() {
    steps = 0;
    inputPos = 0;
    workPos = 0;
    outputPos = 0;
    current_weight = 0;
    current_value = 0;
    maxprofit = 0;
    capacity = 0;
    numItems = 0;
    i = 1;
    j = 0;
    profit_bound = 0;
    totweight = 0;
    flag = 0;
    state = READ_CAPACITY;
    bestBranch = NULL;
    temp = "";
    bestx.clear();
    temp_value.clear();
    while (!Q.empty()) {
        Q.pop();
    }
}

void BB_knap::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima->setDuration(100);
    Anima->setStartValue(this->start_posTape);
    Anima->setEndValue(this->end_posTape);
    Anima->start();
}

void BB_knap::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(100);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void BB_knap::moveOutputTape(int pos) {
    this->end_posOutputTape = QPoint(start_posOutputTape.x() - TABLEWIDGET_WIDTH * pos, start_posOutputTape.y());
    Anima_output->setDuration(100);
    Anima_output->setStartValue(this->start_posOutputTape);
    Anima_output->setEndValue(this->end_posOutputTape);
    Anima_output->start();
}

void BB_knap::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void BB_knap::Initial() {
    temp = ui->input_Num->text();
    int size_work = 3 * temp.toInt();
    ui->workTape->setColumnCount(size_work);
    ui->workTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth((size_work + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_work; i++) {
        auto item = new QTableWidgetItem("");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }

    temp = ui->input_Num->text();
    int size_output = temp.toInt();
    ui->outputTape->setColumnCount(size_output);
    ui->outputTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->outputTape->setFixedWidth((size_output + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_output; i++) {
        auto item = new QTableWidgetItem("0");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->outputTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->outputTape->setItem(0, i, item);
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

float BB_knap::execute() {
    this->Initial();
    while (true) {
        steps++;
        ui->steps->setText(QString::number(steps));
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
            case WRITE_W:
                ui->output_process->setText("WRITE_W");
                writeWeight();
                break;
            case WRITE_V:
                ui->output_process->setText("WRITE_V");
                writeValue();
                break;
            case WRITE_AVER:
                ui->output_process->setText("WRITE_AVER");
                writeAverage();
                break;
            case SORT:
                ui->output_process->setText("SORT");
                sort();
                break;
            case FIST_BUILD:
                ui->output_process->setText("FIST_BUILD");
                first();
                break;
            case MAX:
                ui->output_process->setText("MAX");
                maxknapsack();
                break;
            case BOND:
                ui->output_process->setText("BOND");
                bond();
                break;
            case READ_W:
                ui->output_process->setText("READ_W");
                readW();
                break;
            case READ_V:
                ui->output_process->setText("READ_V");
                readV();
                break;
            case RightTree:
                ui->output_process->setText("RightTree");
                righttree();
                break;
            case LeftTree:
                ui->output_process->setText("LeftTree");
                lefttree();
                break;
            case READ_W_1:
                ui->output_process->setText("READ_W_1");
                readW1();
                break;
            case READ_V_1:
                ui->output_process->setText("READ_V_1");
                readV1();
                break;
            case Branch_and_bond_SUCCESS:
                ui->output_process->setText("SUCCESS");
                printBestBranch();
                return maxprofit;
        }
        delay(100);
    }
}

void BB_knap::readCapacity() {
    temp = ui->inputTape->item(0, inputPos)->text();
    capacity = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = READ_NUM;
}

void BB_knap::readNum() {
    temp = ui->inputTape->item(0, inputPos)->text();
    numItems = temp.toInt();
    this->moveTape(i * 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = i * 2;
    state = READ_WEIGHT;
}

void BB_knap::readWeight() {
    temp = ui->inputTape->item(0, inputPos)->text();
    current_weight = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = READ_VALUE;
}

void BB_knap::readValue() {
    temp = ui->inputTape->item(0, inputPos)->text();
    current_value = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = WRITE_W;
}

void BB_knap::writeWeight() {
    this->moveWorkTape((i - 1) * 4 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = (i - 1) * 4;
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(current_weight)));
    temp_value.push_back(current_weight);
    state = WRITE_V;
}

void BB_knap::writeValue() {
    this->moveWorkTape(1);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos++;
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(current_value)));
    temp_value.push_back(current_value);
    state = WRITE_AVER;
}

void BB_knap::writeAverage() {
    this->moveWorkTape(1);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos++;
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(1.0 * current_value / current_weight)));
    temp_value.push_back(1.0 * current_value / current_weight);
    i++;
    if (i > numItems) {
        state = SORT;
        i = 1;
    } else {
        state = READ_WEIGHT;
    }
}

void BB_knap::sort() {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            if (temp_value[j * 3 + 2] < temp_value[(j + 1) * 3 + 2]) {
                for (int k = 0; k < 3; k++) {
                    std::swap(temp_value[j * 3 + k], temp_value[(j + 1) * 3 + k]);
                }
            }
        }
    }
    for (int i = 0; i < ui->workTape->columnCount(); i++) {
        auto item = new QTableWidgetItem(QString::number(temp_value[i]));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }
    steps--;
    state = FIST_BUILD;
}

void BB_knap::first() {
    u = {-1, 0, 0, 0.0f, new Treenode};
    Q.push(u);
    state = MAX;
    steps--;
}

void BB_knap::maxknapsack() {
    if (!Q.empty()) {
        u = Q.front();
        Q.pop();
        steps++;
        if (u.level == -1)
            v.level = 0;
        if (u.level == numItems - 1) {
            state = Branch_and_bond_SUCCESS;
        } else {
            state = READ_W;
        }
    } else {
        state = Branch_and_bond_SUCCESS;
    }
    steps--;
}

void BB_knap::bond() {
    if (v.weight >= capacity)
        v.bound = 0;
    if (j < numItems  && totweight + current_weight <= capacity) {
        totweight += current_weight;
        profit_bound += current_value;
        j++;
        if(j == numItems) {
            v.bound = profit_bound;
            if (v.bound > maxprofit){
                Q.push(v);
                steps++;
            }

            if (flag == 1)
                state = RightTree;
            else if (flag == 0)
                state = MAX;
        }
        else
            state = READ_W_1;
    } else if (j < numItems) {
        profit_bound += (capacity - totweight) * current_value / current_weight;
        v.bound = profit_bound;
        if (v.bound > maxprofit){
            Q.push(v);
            steps++;
        }

        if (flag == 1)
            state = RightTree;
        else if (flag == 0)
            state = MAX;
    }
    else {
        v.bound = profit_bound;
        if (v.bound > maxprofit)
            Q.push(v);
        if (flag == 1)
            state = RightTree;
        else if (flag == 0)
            state = MAX;
    }
    steps--;
}

void BB_knap::readW() {
    v.level = u.level + 1;
    this->moveWorkTape(3 * v.level - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 3 * v.level;
    temp = ui->workTape->item(0, workPos)->text();
    current_weight = temp.toFloat();
    state = READ_V;
}

void BB_knap::readV() {
    this->moveWorkTape(1);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos++;
    temp = ui->workTape->item(0, workPos)->text();
    current_value = temp.toFloat();
    state = LeftTree;
}

void BB_knap::righttree() {
    flag = 0;
    v.level = u.level + 1;
    v.weight = u.weight;
    v.profit = u.profit;
    v.ptr = new Treenode(u.ptr, false); // 创建新的右子节点
    profit_bound = v.profit;
    j = v.level + 1;
    totweight = v.weight;
    if(j == numItems)
        state = BOND;
    else
        state = READ_W_1;
    steps--;
}

void BB_knap::lefttree() {
    flag = 1;
    v.weight = u.weight + current_weight;
    v.profit = u.profit + current_value;
    v.ptr = new Treenode(u.ptr, true); // 创建新的左子节点

    if (v.weight <= capacity && v.profit > maxprofit) {
        maxprofit = v.profit;
        bestBranch = v.ptr; // 更新最优分支
    }
    profit_bound = v.profit;
    j = v.level + 1;
    totweight = v.weight;
    if(j == numItems)
        state = BOND;
    else
        state = READ_W_1;
    steps--;
}

void BB_knap::readW1() {
    qDebug()<<"readW1";
    qDebug()<<3 * j;
    this->moveWorkTape(3 * j - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 3 * j;
    temp = ui->workTape->item(0, workPos)->text();
    current_weight = temp.toFloat();
    state = READ_V_1;
}

void BB_knap::readV1() {
    this->moveWorkTape(1);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos++;
    temp = ui->workTape->item(0, workPos)->text();
    current_value = temp.toFloat();
    state = BOND;
}

void BB_knap::printBestBranch() {
    QVector<int> bestItems;
    Treenode *current = bestBranch;
    while (current->parent != nullptr) {
        bestItems.push_back(current->Lchild);
        current = current->parent;
    }
    std::reverse(bestItems.begin(), bestItems.end());
    for (int i = 0; i < numItems; ++i) {
        ui->outputTape->setItem(0, i, new QTableWidgetItem(QString::number(bestItems[i])));
    }
}
