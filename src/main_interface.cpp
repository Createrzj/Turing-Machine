//
// Created by icy on 24-6-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Main_Interface.h" resolved

#include "../include/main_interface.h"
#include "../ui_main_interface.h"


Main_Interface::Main_Interface(QWidget *parent) :
        QWidget(parent), ui(new Ui::Main_Interface) {
    ui->setupUi(this);
}

Main_Interface::~Main_Interface() {
    delete ui;
}
