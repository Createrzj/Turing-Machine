//
// Created by icy on 24-6-27.
//

#include "../include/Inter_BinarySer.h"

Inter_BinarySer::Inter_BinarySer() {
    steps = 0;
    workSpace = 0;
    state = INIT_LOW;
    target = 0;
}

void Inter_BinarySer::updatePara() {
    steps = 0;
    workSpace = 0;
    state = INIT_LOW;
    target = 0;
}

int Inter_BinarySer::execute() {
    // 初始化指针
    int low = 0;
    int high = 0;
    int mid = 0;
    int work = 0;// 中间数
    int workPos = 0;// 工作纸带位置
    int inputPos = 0;// 输入纸带位置
    QString temp = "";
    this->Initial();

    // 状态机执行
    while (true) {
        steps++; // 增加步数
        ui->steps->setText(QString::number(steps));
        ui->grids->setText(QString::number(workSpace));
        switch (state) {
            case INIT_LOW:
                ui->output_process->setText("INIT_LOW");
                temp = ui->tape->item(0, 0)->text();
                work = temp.toInt();
                this->moveTape(1);
                this->start_posTape = this->end_posTape;
                inputPos++;
                state = WRITE_LOW;
                break;

            case WRITE_LOW:
                ui->output_process->setText("WRITE_LOW");
                low = work;
                temp = QString::number(low);
                ui->workTape->setItem(0, workPos++, new QTableWidgetItem(temp));
                updateline();
                this->moveWorkTape(1);
                this->start_posWorkTape = this->end_posWorkTape;
                workSpace++;
                state = INIT_HIGH;
                break;

            case INIT_HIGH:
                ui->output_process->setText("INIT_HIGH");
                temp = ui->tape->item(0, 1)->text();
                work = temp.toInt();
                this->moveTape(1);
                this->start_posTape = this->end_posTape;
                inputPos++;
                state = WRITE_HIGH;
                break;

            case WRITE_HIGH:
                ui->output_process->setText("WRITE_HIGH");
                high = work;
                temp = QString::number(high);
                ui->workTape->setItem(0, workPos--, new QTableWidgetItem(temp));
                this->moveWorkTape(-1);
                this->start_posWorkTape = this->end_posWorkTape;
                updateline();
                workSpace++;
                state = COMPARE_LOW;
                break;

            case COMPARE_LOW:
                ui->output_process->setText("COMPARE_LOW");
                if (low > high) {
                    state = STOP;
                } else {
                    state = CAI_MID;
                }
                break;

            case STOP:
                ui->output_process->setText("STOP");
                ui->output_tape_line->setText("#output tape：-1");
                return -1; // 查找失败

            case CAI_MID:
                ui->output_process->setText("CAI_MID");
                mid = low + (high - low) / 2;
                this->moveWorkTape(2 - workPos);
                this->start_posWorkTape = this->end_posWorkTape;
                workPos = 2;
                temp = QString::number(mid);
                ui->workTape->setItem(0, workPos, new QTableWidgetItem(temp));
                updateline();
                workSpace = 3;
                state = READ_MID;
                break;

            case READ_MID:
                ui->output_process->setText("READ_MID");
                this->moveTape(mid + 2 - inputPos);
                this->start_posTape = this->end_posTape;
                temp = ui->tape->item(0, mid + 2)->text();
                work = temp.toInt();
                inputPos = mid + 2;
                state = COMPARE_MID;
                break;

            case COMPARE_MID:
                ui->output_process->setText("COMPARE_MID");
                this->moveTape(2 - inputPos);
                this->start_posTape = this->end_posTape;
                inputPos = 2;
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
                ui->output_tape_line->setText("#output tape：" + QString::number(mid));
                return mid; // 查找成功

            case UPDATE_LOW:
                ui->output_process->setText("UPDATE_LOW");
                low = mid + 1;
                workPos = 0;
                this->moveWorkTape(-2);
                this->start_posWorkTape = this->end_posWorkTape;
                temp = QString::number(low);
                ui->workTape->setItem(0, workPos, new QTableWidgetItem(temp));
                updateline();
                state = COMPARE_LOW;
                break;

            case UPDATE_HIGH:
                ui->output_process->setText("UPDATE_HIGH");
                high = mid - 1;
                workPos = 1;
                this->moveWorkTape(-1);
                this->start_posWorkTape = this->end_posWorkTape;
                temp = QString::number(high);
                ui->workTape->setItem(0, workPos, new QTableWidgetItem(temp));
                updateline();
                state = COMPARE_LOW;
                break;
        }
        Inter_BinarySer::delay(2000);
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

void Inter_BinarySer::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void Inter_BinarySer::Initial() {
    steps = 0;
    workSpace = 0;
    Anima->setTargetObject(ui->tape);
    Anima->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    target = ui->Target->text().toInt();
    start_posTape = ui->tape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();
}

void Inter_BinarySer::updateline() {
    QString WorkTape_line = "#work tape：";
    for(int i = 0; i < ui->workTape->columnCount() ; i++) {
        WorkTape_line += " " + ui->workTape->item(0, i)->text();
    }
    ui->work_tape_line->setText(WorkTape_line);
}


