//
// Created by icy on 24-7-1.
//

#include "../include/Memory_knap.h"

Memory_knap::Memory_knap() {
    steps = 0;
    workspace = 0;
    capacity = 0;
    numItems = 0;
    inputPos = 0;
    workPos = 0;
    outputPos = 0;
    temp = "";
}

void Memory_knap::START() {
    execute();
    getMax();
    traceSolution();
    ui->output_process->setText("SUCESS");
}

void Memory_knap::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima_input->setDuration(100);
    Anima_input->setStartValue(this->start_posTape);
    Anima_input->setEndValue(this->end_posTape);
    Anima_input->start();
}

void Memory_knap::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(100);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void Memory_knap::moveOutputTape(int pos) {
    this->end_posOutputTape = QPoint(start_posOutputTape.x() - TABLEWIDGET_WIDTH * pos, start_posOutputTape.y());
    Anima_output->setDuration(100);
    Anima_output->setStartValue(this->start_posOutputTape);
    Anima_output->setEndValue(this->end_posOutputTape);
    Anima_output->start();
}

void Memory_knap::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void Memory_knap::Initial() {
    Anima_input->setTargetObject(ui->inputTape);
    Anima_input->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    Anima_output->setTargetObject(ui->outputTape);
    Anima_output->setPropertyName("pos");

    start_posTape = ui->inputTape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();
    start_posOutputTape = ui->outputTape->geometry().topLeft();
    work_stack.push({ui->inputTape->item(0, 0)->text().toInt(),
                     ui->inputTape->item(0, 1)->text().toInt(),
                     READ_CAPACITY});
}

void Memory_knap::execute() {
    this->Initial();
    while (!work_stack.empty()) {
        steps++;
        frame = work_stack.top();
        work_stack.pop();
        ui->steps->setText(QString::number(steps));
        int flag = 1;
        while (flag != 0) {
            switch (frame.state) {
                case READ_CAPACITY:
                    readCapacity();
                    break;
                case READ_NUM:
                    readNum();
                    break;
                case READ_MEMO:
                    readMemo();
                    pushWrite();
                    flag = frame.state == COMPRAE_WIG ? 1 : 0;
                    break;
                case COMPRAE_WIG:
                    compareWig();
                    break;
                case PUSH_STACK_1:
                    pushstack_1();
                    flag = 0;
                    break;
                case PUSH_STACK_2:
                    pushstack_2();
                    flag = 0;
                    break;
                case WRITE_MAX:
                    flag = 0;
                    writeMax();
                    break;
                case END:
                    flag = 0;
            }
        }
        delay(100);
    }
}

void Memory_knap::readCapacity() {
    ui->output_process->setText("readCapacity");
    temp = ui->inputTape->item(0, inputPos)->text();
    capacity = temp.toInt();
    this->moveTape(1);
    this->start_posTape = this->end_posTape;
    inputPos++;
    frame.state = READ_NUM;
}

void Memory_knap::readNum() {
    ui->output_process->setText("readNum");
    temp = ui->inputTape->item(0, inputPos)->text();
    numItems = temp.toInt();
    frame.state = READ_MEMO;
}

void Memory_knap::readMemo() {
    ui->output_process->setText("readMemo");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(frame.n * (capacity + 1) + frame.cap - workPos);//index
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = frame.n * (capacity + 1) + frame.cap;
}

void Memory_knap::pushWrite() {
    ui->output_process->setText("pushWrite");
    int index = frame.n * (capacity + 1) + frame.cap;
    if (frame.cap <= 0 || frame.n <= 0) {
        writeMemo();
    } else if (ui->workTape->item(0, index)->text() == "-1") {
        this->moveWorkTape(index - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = index;
        frame.state = COMPRAE_WIG;
    } else {
        frame.state = END;
    }
}

void Memory_knap::writeMemo() {
    ui->output_process->setText("writeMemo");
    int index = frame.n * (capacity + 1) + frame.cap;
    this->moveWorkTape(index - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    ui->workTape->setItem(0, index, new QTableWidgetItem("0"));
    workPos = index;
}

void Memory_knap::compareWig() {
    ui->output_process->setText("compareWig");
    readWig();
    temp = ui->inputTape->item(0, inputPos)->text();
    if (temp.toInt() > frame.cap) {
        frame.state = PUSH_STACK_1;
    } else {
        frame.state = PUSH_STACK_2;
    }
}

void Memory_knap::readWig() {
    ui->output_process->setText("readWig");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveTape((frame.n - 1) * 2 + 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = (frame.n - 1) * 2 + 2;
}

void Memory_knap::pushstack_1() {
    ui->output_process->setText("pushstack_1");
    work_stack.push_back({frame.cap, frame.n - 1, READ_MEMO});//不取
}

void Memory_knap::pushstack_2() {
    ui->output_process->setText("pushstack_2");
    temp = ui->inputTape->item(0, inputPos)->text();
    work_stack.push_back({frame.cap, frame.n, WRITE_MAX});//合并问题
    work_stack.push_back({frame.cap, frame.n - 1, READ_MEMO});//不取
    work_stack.push_back({frame.cap - temp.toInt(), frame.n - 1, READ_MEMO});//取
}

void Memory_knap::writeMax() {
    ui->output_process->setText("writeMax");
    frame = {frame.cap, frame.n, END};
    readMemo();
    this->moveWorkTape((frame.n - 1) * (capacity + 1) + frame.cap - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = (frame.n - 1) * (capacity + 1) + frame.cap;
    int value_no = ui->workTape->item(0, workPos)->text().toInt();//不取

    frame = {frame.cap, frame.n, END};
    readVal();
    int value_yes = ui->inputTape->item(0, inputPos)->text().toInt();
    readWig();

    int index = ui->inputTape->item(0, inputPos)->text().toInt();
    this->moveWorkTape((frame.n - 1) * (capacity + 1) + frame.cap - index - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = (frame.n - 1) * (capacity + 1) + frame.cap - index;
    value_yes += ui->workTape->item(0, workPos)->text().toInt();
    readMemo();

    this->moveWorkTape(frame.n * (capacity + 1) + frame.cap - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = frame.n * (capacity + 1) + frame.cap;
    value_yes = std::max(value_yes, value_no);
    ui->workTape->setItem(0, workPos, new QTableWidgetItem(QString::number(value_yes)));
}

void Memory_knap::readVal() {
    ui->output_process->setText("readVal");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveTape((frame.n - 1) * 2 + 3 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = (frame.n - 1) * 2 + 3;
}

void Memory_knap::traceSolution() {
    ui->output_process->setText("traceSolution");
    int cap = capacity;
    for (int i = numItems; i > 0; i--) {
        this->moveOutputTape(i - 1 - outputPos);
        this->start_posOutputTape = this->end_posOutputTape;
        outputPos = i - 1;
        readMemo(i, cap);

        this->moveWorkTape(i * (capacity + 1) + cap - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = i * (capacity + 1) + cap;
        int now = ui->workTape->item(0, workPos)->text().toInt();
        readMemo(i, cap);
        this->moveWorkTape((i - 1) * (capacity + 1) + cap - workPos);
        this->start_posWorkTape = this->end_posWorkTape;
        workPos = (i - 1) * (capacity + 1) + cap;
        int pre = ui->workTape->item(0, workPos)->text().toInt();
        if (now != pre) {
            steps++;
            ui->steps->setText(QString::number(steps));
            ui->outputTape->setItem(0, outputPos, new QTableWidgetItem("1"));
            readWig(i);
            cap -= ui->inputTape->item(0, inputPos)->text().toInt();
        }
    }
}

void Memory_knap::readMemo(int n, int cap) {
    ui->output_process->setText("readMemo");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveWorkTape(n * (capacity + 1) + cap - workPos);
    this->start_posWorkTape = this->end_posWorkTape;
    workPos = n * (capacity + 1) + cap;
}

void Memory_knap::readWig(int n) {
    ui->output_process->setText("readWig");
    steps++;
    ui->steps->setText(QString::number(steps));
    this->moveTape((n - 1) * 2 + 2 - inputPos);
    this->start_posTape = this->end_posTape;
    inputPos = (n - 1) * 2 + 2;
}

void Memory_knap::getMax() {
    ui->output_process->setText("getMax");
    int index = numItems * (capacity + 1) + capacity;
    temp = ui->workTape->item(0, index)->text();
    ui->max_value->setText(temp);
}

