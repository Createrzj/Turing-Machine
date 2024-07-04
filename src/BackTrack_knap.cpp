//
// Created by icy on 24-7-4.
//

#include "../include/BackTrack_knap.h"

BackTrack_knap::BackTrack_knap() {
    state = READ_CAPACITY;
    temp = "";
    capacity = 0; // 背包容量
    numItems = 0; // 物品数量
    steps = 0;
    inputPos = 0;// 当前指向输入纸带的位置
    workPos = 0;// 当前指向工作纸带的位置
    outputPos = 0;// 当前指向输出纸带的位置
    bestv = 0;
    cwig = 0;
    cval = 0;
    work_stack.push({0,2});
}

void BackTrack_knap::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima_input->setDuration(100);
    Anima_input->setStartValue(this->start_posTape);
    Anima_input->setEndValue(this->end_posTape);
    Anima_input->start();
}

void BackTrack_knap::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(100);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void BackTrack_knap::moveOutputTape(int pos) {
    this->end_posOutputTape = QPoint(start_posOutputTape.x() - TABLEWIDGET_WIDTH * pos, start_posOutputTape.y());
    Anima_output->setDuration(100);
    Anima_output->setStartValue(this->start_posOutputTape);
    Anima_output->setEndValue(this->end_posOutputTape);
    Anima_output->start();
}

void BackTrack_knap::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void BackTrack_knap::Initial() {
    temp = ui->input_Num->text();
    int size_work = 3 + temp.toInt();
    ui->workTape->setColumnCount(size_work);
    ui->workTape->setRowHeight(0, TABLEWIDGET_HEIGHT);
    ui->workTape->setFixedWidth((size_work + 1) * TABLEWIDGET_WIDTH);
    for (int i = 0; i < size_work; i++) {
        auto item = new QTableWidgetItem("");
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->workTape->setColumnWidth(i, TABLEWIDGET_WIDTH);
        ui->workTape->setItem(0, i, item);
    }

    Anima_input->setTargetObject(ui->inputTape);
    Anima_input->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    Anima_output->setTargetObject(ui->outputTape);
    Anima_output->setPropertyName("pos");

    start_posTape = ui->inputTape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();
    start_posOutputTape = ui->outputTape->geometry().topLeft();
}

void BackTrack_knap::execute() {
    this->Initial();
    int flag_first = 0;
    while (!work_stack.empty()) {
        float bound = 0;
        node current = work_stack.top();
        bool flag = true;
        if(flag_first)
            state = JUDGE_LEAF;
        else
            state = READ_CAPACITY;
        while (flag) {
            steps++;
            ui->steps->setText(QString::number(steps));
            switch (state) {
                case READ_CAPACITY:
                    readCapacity();
                    flag_first = 1;
                    break;
                case READ_NUM:
                    readNum();
                    break;
                case JUDGE_LEAF://叶节点判断+处理，
                    judgeleaf(current);
                    break;
                case UPDATE_BESTV:
                    updatebestv(current);
                    popnode(current);
                    flag = false;
                    break;
                case JUDEG_VIS://判断节点访问次数，回
                    judgevis(current);
                    if (state == END) {
                        flag = false;
                        popnode(current);
                    }
                    break;
                case COM_CAP://判断下个物品能装入，能则生成左节点，否则判断右节点
                    if (compcap(current))
                        state = PUSH_LEFT;
                    else
                        state = CAL_BOUND;
                    break;
                case CAL_BOUND://计算上界
                    work_stack.top().xi = 0;
                    updatexi(current.n, 0);
                    bound = calbound(current);
                case CAMP_BOUND://比较上界和bestv
                    if (campbound(bound))
                        state = PUSH_RIGHT;
                    else
                        flag = false;
                    break;
                case PUSH_LEFT://压栈左孩子
                    updatexi(current.n, 1);
                    work_stack.top().xi = 1;
                    pushleft(current);
                    flag = false;
                    break;
                case PUSH_RIGHT://压栈右孩子
                    updatexi(current.n, 0);
                    pushright(current);// 压栈右孩子
                    flag = false;
                    break;
                case END:
                    break;
            }
        }
        delay(500);
        showstack();
        showwork();
        cout<<endl;
    }
    updateoutput();
    ui->output_process->setText("SUCESS");
}

void BackTrack_knap::readCapacity() {
    ui->output_process->setText("readCapacity");
    temp = ui->inputTape->item(0, inputPos)->text();
    capacity = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    state = READ_NUM;
}

void BackTrack_knap::readNum() {
    ui->output_process->setText("readNum");
    temp = ui->inputTape->item(0, inputPos)->text();
    numItems = temp.toInt();
    bestx.assign(numItems,0);
    state = JUDGE_LEAF;
}

void BackTrack_knap::judgeleaf(node current) {
    qDebug() << "judgeleaf";
    ui->output_process->setText("judgeleaf");
    if (current.n >= numItems) {
        state =  UPDATE_BESTV;
    }
    else {
        state =  JUDEG_VIS;
    }
}

void BackTrack_knap::updatebestv(node current) {
    qDebug() << "updatebestv";
    ui->output_process->setText("updatebestv");
    readcval();
    readbestv();
}

void BackTrack_knap::readcval() {
    // 将 worktap[1] 的值赋给当前节点的 cval
    qDebug() << "readcval";
    ui->output_process->setText("readcval");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(1 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 1;
    temp = ui->workTape->item(0, workPos)->text();
    cval = temp.toInt();
}

void BackTrack_knap::readbestv() {
    qDebug() << "readbestv";
    ui->output_process->setText("readbestv");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(2 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 2;
    if (cval > bestv) {
        bestv = cval;
        ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(cval)));
        updatebestx();
    }
}

void BackTrack_knap::updatebestx() {
    qDebug() << "updatebestx";
    ui->output_process->setText("updatebestx");
    for (int i = 0; i < numItems; i++) {
        this->moveWorkTape(3 + i - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = 3 + i;
        temp = ui->workTape->item(0, workPos)->text();
        bestx[i] = temp.toInt();
    }
}

void BackTrack_knap::popnode(node current) {
    qDebug() << "popnode";
    ui->output_process->setText("popnode");
    work_stack.pop();
    updatexi(current.n, 2);
    if (!work_stack.empty() && work_stack.top().xi == 1) {
        readwigi(current.n - 1);
        temp = ui->inputTape->item(0, inputPos)->text();
        int temp_value = ui->workTape->item(0, 0)->text().toInt() - temp.toInt();
        this->moveWorkTape(0 - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = 0;
        ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(temp_value)));

        readvali(current.n - 1);
        temp = ui->inputTape->item(0, inputPos)->text();
        int temp_value2= ui->workTape->item(0, 1)->text().toInt() - temp.toInt();
        this->moveWorkTape(1 - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = 1;
        ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(temp_value2)));
    }
}

void BackTrack_knap::readwigi(int i) {
    ui->output_process->setText("readwigi");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveTape(i * 2 + 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = i * 2 + 2;
}

void BackTrack_knap::updatexi(int n, int xi) {
    ui->output_process->setText("updatexi");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(3 + n - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 3 + n;
    if (xi == 2) {
        ui->workTape->setItem(0, workPos, new QTableWidgetItem("0"));
    } else {
        ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(xi)));
    }
}

void BackTrack_knap::judgevis(node current) {
    ui->output_process->setText("judgevis");
    if (current.xi == 0) {
        state =  END;
    } else if (current.xi == 1)
        state = CAL_BOUND;
    else
        state = COM_CAP;
}

bool BackTrack_knap::compcap(node current) {
    ui->output_process->setText("compcap");
    readcwig();
    readwigi(current.n);
    temp = ui->inputTape->item(0, inputPos)->text();
    int temp_value = ui->workTape->item(0, workPos)->text().toInt() + temp.toInt();
    if (temp_value <= capacity) {//处理左孩子
        return true;
    }
    return false;
}

void BackTrack_knap::readcwig() {
    ui->output_process->setText("readcwig");
    // 将 worktap[0] 的值赋给当前节点的 cwig
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(0 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 0;
    temp = ui->workTape->item(0, workPos)->text();
    cwig = temp.toInt();
}

int BackTrack_knap::calbound(node current) {
    ui->output_process->setText("calbound");
    readcval();
    temp = ui->workTape->item(0, workPos)->text();
    float bound = temp.toInt();
    readcwig();
    temp = ui->workTape->item(0, workPos)->text();
    int totalWeight = temp.toInt();
    for (int i = current.n + 1; i < numItems; ++i) {
        readwigi(i);
        temp = ui->inputTape->item(0, inputPos)->text();
        if (totalWeight + temp.toInt() <= capacity) {
            totalWeight += temp.toInt();
            readvali(i);
            temp = ui->inputTape->item(0, inputPos)->text();
            bound += temp.toInt();
        } else {
            float t = (capacity - totalWeight) * 1.0 / temp.toInt();
            readvali(i);
            temp = ui->inputTape->item(0, inputPos)->text();
            t *= temp.toInt();
            bound += t;
            break;
        }
    }
    return bound;
}

void BackTrack_knap::readvali(int i) {
    ui->output_process->setText("readvali");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveTape(i * 2 + 3 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = i * 2 + 3;
}

bool BackTrack_knap::campbound(float bound) {
    ui->output_process->setText("campbound");
    if (bound > bestv)
        return true;
    return false;
}

void BackTrack_knap::pushleft(node current) {
    ui->output_process->setText("pushleft");
    readcwig();
    readwigi(current.n);
    temp = ui->inputTape->item(0, inputPos)->text();
    int newWeight = ui->workTape->item(0, workPos)->text().toInt() + temp.toInt();
    readcval();

    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;

    temp = ui->inputTape->item(0, inputPos)->text();
    int newValue = ui->workTape->item(0, workPos)->text().toInt() + temp.toInt();

    writecwig(newWeight);
    writecval(newValue);
    work_stack.push({current.n + 1, 2});
}

void BackTrack_knap::writecwig(int weight) {
    ui->output_process->setText("writecwig");
    // 将当前节点的 cwig 写入 worktap[0]
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(0 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 0;
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(weight)));
}

void BackTrack_knap::writecval(int value) {
    ui->output_process->setText("writecval");
    // 将当前节点的 cval 写入 worktap[1]
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(1 - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = 1;
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(value)));
}

void BackTrack_knap::pushright(node current) {
    ui->output_process->setText("pushright");
    work_stack.push({current.n + 1, 2});
}

void BackTrack_knap::updateoutput() {
    ui->output_process->setText("updateoutput");
    for (int i = 0; i < numItems; i++) {
        this->moveOutputTape(i - outputPos);
        this->start_posOutputTape = this->end_posOutputTape;
        outputPos = i;
        ui->outputTape->setItem(0, outputPos, new QTableWidgetItem(QString::number(bestx[i])));
    }
}

void BackTrack_knap::showwork() {
    for(int i=0;i<ui->workTape->columnCount();i++) {
        temp = ui->workTape->item(0, i)->text();
        cout<<temp.toStdString()<<" ";
    }
    cout<<endl;
}

void BackTrack_knap::showstack() {
    stack<node> temp = work_stack;
    node t ;
    static int time = 0;
    time++;
    cout<<"time: "<<time<<endl;
    while(!temp.empty()) {
        t = temp.top();
        temp.pop();
        if(t.xi!=2)
            cout<<" n "<<t.n<<" xi "<<t.xi<<endl;
        else
            cout<<" n "<<t.n<<endl;
    }
    cout<<"------"<<endl;
}
