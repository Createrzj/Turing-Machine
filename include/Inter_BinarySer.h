//
// Created by icy on 24-6-27.
//

#ifndef INTER_BINARYSER_H
#define INTER_BINARYSER_H


#include "Library.h"
#include "../ui_turing.h"

using namespace std;


class Inter_BinarySer {
public:
    Ui::Turing *ui;
    Inter_BinarySer();
    int execute();
    void moveTape(int pos);
    void moveWorkTape(int pos);
    void delay(int milliseonds);
    void Initial();

private:
    int steps;
    enum State {
        INIT_LOW, WRITE_LOW, INIT_HIGH,
        WRITE_HIGH, COMPARE_LOW, STOP,
        CAI_MID, UPDATE_LOW, UPDATE_HIGH,
        READ_MID, COMPARE_MID, SUCCESS
    };
    int target;
    State state;
    QPropertyAnimation *Anima = new QPropertyAnimation;
    QPoint start_posTape;
    QPoint end_posTape;

    QPropertyAnimation *Anima_work = new QPropertyAnimation;
    QPoint start_posWorkTape;
    QPoint end_posWorkTape;
};


#endif //INTER_BINARYSER_H
