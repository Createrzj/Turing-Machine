//
// Created by icy on 24-6-28.
//

#include "../include/Recur_BinarySer.h"

Recur_BinarySer::Recur_BinarySer() {
    steps = 0;
    workSpace = 0;
    state = READ_LOW;
    target = 0;
}

void Recur_BinarySer::updatePara() {
    steps = 0;
    workSpace = 0;
    state = READ_LOW;
    target = 0;
}

int Recur_BinarySer::execute() {
    // 初始化指针
    int low = 0;
    int high = 0;
    int mid = 0;
    int work = 0;// 中间数
    int workPos = 0;// 工作纸带位置
    int inputPos = 0;// 输入纸带位置
    QString temp;
    this->Initial();

    // 状态机执行
    while (true) {
        ui->steps->setText(QString::number(steps));
        ui->grids->setText(QString::number(workSpace));
        switch (state) {
            case READ_LOW:
                ui->output_process->setText("READ_LOW");
                Recur_BinarySer::delay(2000);
                temp = ui->tape->item(0, 0)->text();
                low = temp.toInt();
                this->moveTape(1);
                this->start_posTape = this->end_posTape;
                inputPos++;
                state = COMPARE_HIGH;
                steps++; // 增加步数
                break;

            case COMPARE_HIGH:
                ui->output_process->setText("COMPARE_HIGH");
                temp = ui->tape->item(0, 1)->text();
                high = temp.toInt();
                if (low <= high) {
                    state = CAI_MID;
                }
                else
                    state = STOP;
                steps++; // 增加步数
                break;

            case CAI_MID:
                ui->output_process->setText("CAI_MID");
                mid = low + (high - low) / 2;
                temp = "";
                temp += "low:";
                temp += QString::number(low);
                temp += " high:";
                temp += QString::number(high);
                temp += " mid:";
                temp += QString::number(mid);
                ui->STACK->append(temp);
                temp = QString::number(mid);
                ui->workTape->setItem(0, workPos++, new QTableWidgetItem(temp));
                updateline();
                this->moveWorkTape(1);
                this->start_posWorkTape = this->end_posWorkTape;
                this->moveTape(mid + 2 - inputPos);
                this->start_posTape = this->end_posTape;
                workSpace = 1;
                inputPos = mid + 2;
                state = READ_MID;
                steps++; // 增加步数
                break;

            case READ_MID:
                ui->output_process->setText("READ_MID");
                temp = ui->tape->item(0, mid + 2)->text();
                work = temp.toInt();
                state = COMPARE_MID;
                steps++; // 增加步数
                break;

            case STOP:
                ui->output_process->setText("STOP");
                steps++; // 增加步数
                temp = "";
                temp += ui->tape->item(0, 0)->text();
                temp += " ";
                temp += ui->tape->item(0, 1)->text();
                Stack.push(temp);
                return -1;

            case COMPARE_MID:
                ui->output_process->setText("COMPARE_MID");
                this->moveTape(2 - inputPos);
                this->start_posTape = this->end_posTape;
                inputPos = 2;
                if (work == target)
                    state = SUCCESS;
                else if (work < target)
                    state = UPDATE_LOW;
                else
                    state = UPDATE_HIGH;
                steps++; // 增加步数
                break;

            case UPDATE_LOW:
                ui->output_process->setText("UPDATE_LOW");
                temp = "";
                temp += QString::number(mid + 1);
                temp += " ";
                temp += QString::number(high);
                Stack.push(temp);
                state = CALL;
                break;

            case UPDATE_HIGH:
                ui->output_process->setText("UPDATE_HIGH");
                temp = "";
                temp += QString::number(low);
                temp += " ";
                temp += QString::number(mid - 1);
                Stack.push(temp);
                state = CALL;
                break;

            case CALL:
                ui->output_process->setText("CALL");
                //还原输入纸带
                this->moveTape(0 - inputPos);
                this->start_posTape = this->end_posTape;
                inputPos = 0;
                //还原工作纸带
                this->moveWorkTape(0 - workPos);
                this->start_posWorkTape = this->end_posWorkTape;
                workPos = 0;
                this->restore();
                state = READ_LOW;
                break;

            case SUCCESS:
                ui->output_process->setText("SUCCESS");
                steps++; // 增加步数
                ui->steps->setText(QString::number(steps));
                Stack.push(temp);
                return mid; // 查找成功
        }
        Recur_BinarySer::delay(2000);
    }
}

void Recur_BinarySer::moveTape(int pos) {
    this->end_posTape = QPoint(start_posTape.x() - TABLEWIDGET_WIDTH * pos, start_posTape.y());
    Anima->setDuration(2000);
    Anima->setStartValue(this->start_posTape);
    Anima->setEndValue(this->end_posTape);
    Anima->start();
}

void Recur_BinarySer::moveWorkTape(int pos) {
    this->end_posWorkTape = QPoint(start_posWorkTape.x() - TABLEWIDGET_WIDTH * pos, start_posWorkTape.y());
    Anima_work->setDuration(2000);
    Anima_work->setStartValue(this->start_posWorkTape);
    Anima_work->setEndValue(this->end_posWorkTape);
    Anima_work->start();
}

void Recur_BinarySer::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void Recur_BinarySer::Initial() {
    steps = 0;
    workSpace = 0;
    Anima->setTargetObject(ui->tape);
    Anima->setPropertyName("pos");

    Anima_work->setTargetObject(ui->workTape);
    Anima_work->setPropertyName("pos");

    target = ui->Target->text().toInt();
    start_posTape = ui->tape->geometry().topLeft();
    start_posWorkTape = ui->workTape->geometry().topLeft();

    QString temp = "";
    temp += ui->tape->item(0, 0)->text();
    temp += " ";
    temp += ui->tape->item(0, 1)->text();
    Stack.push(temp);
}

void Recur_BinarySer::restore() {
    QString temp = Stack.top();
    QStringList numbers = temp.split(" ", QString::SkipEmptyParts);
    auto item = new QTableWidgetItem(numbers[0]);
    ui->tape->setItem(0, 0, item);
    auto item1 = new QTableWidgetItem(numbers[1]);
    ui->tape->setItem(0, 1, item1);

    auto item2 = new QTableWidgetItem("");
    ui->workTape->setItem(0, 0, item2);
    updateline();
}

void Recur_BinarySer::updateline() {
    QString WorkTape_line = "#work tape：";
    WorkTape_line += " " + ui->workTape->item(0, 0)->text();
    ui->work_tape_line->setText(WorkTape_line);
}
