//
// Created by icy on 24-6-28.
//

#include "../include/Recur_BinarySer.h"

Recur_BinarySer::Recur_BinarySer() {
    steps = 0;
    state = READ_LOW;
    target = 0;
}

int Recur_BinarySer::execute() {
    // 初始化指针
    int low = 0;
    int high = 0;
    int mid = 0;
    int work = 0;// 中间数
    int worksteps = 0;// 工作纸带位置
    int inputsteps = 0;// 输入纸带位置
    QString temp = "";
    this->Initial();

    // 状态机执行
    while (true) {
        steps++; // 增加步数
        ui->steps->setText(QString::number(steps));
        switch (state) {
            case READ_LOW:
                ui->output_process->setText("READ_LOW");
                temp = ui->tape->item(0, 0)->text();
                low = temp.toInt();
                this->moveTape(1);
                this->start_posTape = this->end_posTape;
                inputsteps++;
                state = COMPARE_HIGH;
                break;

            case COMPARE_HIGH:
                ui->output_process->setText("COMPARE_HIGH");
                temp = ui->tape->item(0, 0)->text();
                high = temp.toInt();
                if (low <= high)
                    state = CAI_MID;
                else
                    state = STOP;
                break;

            case CAI_MID:
                ui->output_process->setText("CAI_MID");
                mid = low + (high - low) / 2;
                temp = QString::number(mid);
                ui->workTape->setItem(0, worksteps++, new QTableWidgetItem(temp));
                this->moveWorkTape(1);
                this->start_posWorkTape = this->end_posWorkTape;
                state = READ_MID;
                break;

            case READ_MID:
                ui->output_process->setText("READ_MID");
                temp = ui->tape->item(0, mid + 2)->text();
                work = temp.toInt();
                this->moveTape(mid + 2 - inputsteps);
                this->start_posTape = this->end_posTape;
                state = COMPARE_MID;
                break;

            case STOP:
                ui->output_process->setText("STOP");
                if (low > high) {
                    state = STOP;
                } else {
                    state = CAI_MID;
                }
                break;

            case COMPARE_MID:
                ui->output_process->setText("COMPARE_MID");
                if (work == target)
                    state = SUCCESS;
                else if (work < target)
                    state = UPDATE_LOW;
                else
                    state = UPDATE_HIGH;
                break;

            case UPDATE_LOW:
                ui->output_process->setText("UPDATE_LOW");
                mid = low + (high - low) / 2;
                this->moveWorkTape(2 - worksteps);
                this->start_posWorkTape = this->end_posWorkTape;
                worksteps = 2;
                temp = QString::number(mid);
                ui->workTape->setItem(0, worksteps, new QTableWidgetItem(temp));
                state = CALL;
                break;

            case UPDATE_HIGH:
                ui->output_process->setText("UPDATE_HIGH");
                this->moveTape(mid + 2 - inputsteps);
                this->start_posTape = this->end_posTape;
                temp = ui->tape->item(0, mid + 2)->text();
                work = temp.toInt();
                inputsteps = mid + 2;
                state = CALL;
                break;

            case CALL:
                ui->output_process->setText("COMPARE_MID");
                if (work == target) {
                    state = SUCCESS;
                } else if (work < target) {
                    state = UPDATE_LOW;
                } else {
                    state = UPDATE_HIGH;
                }
                break;

            case SUCCESS:
                ui->output_process->setText("SUCCESS");
                return mid; // 查找成功

            case RETURN:
                ui->output_process->setText("UPDATE_LOW");
                low = mid + 1;
                worksteps = 0;
                this->moveWorkTape(-2);
                this->start_posWorkTape = this->end_posWorkTape;
                temp = QString::number(low);
                ui->workTape->setItem(0, worksteps, new QTableWidgetItem(temp));
                state = COMPARE_LOW;
                break;
        }
        this->delay(2000);
    }
}

void Inter_BinarySer::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima->setDuration(2000);
    Anima->setStartValue(this->start_posTape);
    Anima->setEndValue(this->end_posTape);
    Anima->start();
}

void Inter_BinarySer::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(2000);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void Inter_BinarySer::delay(int milliseonds) {
    QEventLoop loop;
    QTimer::singleShot(milliseonds, &loop, &QEventLoop::quit);
    loop.exec();
}

void Inter_BinarySer::Initial() {
    Anima->setTargetObject(ui->tape);
    Anima->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    target = ui->Target->text().toInt();
    start_posTape = ui->tape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();
}