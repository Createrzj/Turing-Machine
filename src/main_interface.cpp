//
// Created by icy on 24-6-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Main_Interface.h" resolved

#include "../include/main_interface.h"

Main_Interface::Main_Interface(QWidget *parent) :
        QWidget(parent), ui(new Ui::Main_Interface) {
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(show_Binary()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_Knapsack()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(show_Recurknapsack()));
    connect(&BinarySearch, SIGNAL(Show_Father_Widget()), this, SLOT(show_again()));
    connect(&knapsack, SIGNAL(Show_Father_Widget()), this, SLOT(show_again()));
    connect(&recurknapsack, SIGNAL(Show_Father_Widget()), this, SLOT(show_again()));
}

Main_Interface::~Main_Interface() {
    delete ui;
}

void Main_Interface::show_Binary() {
    BinarySearch.show();
    this->close();
}

void Main_Interface::show_again() {
    this->show();
}

void Main_Interface::show_Knapsack() {
    knapsack.show();
    this->close();
}

void Main_Interface::show_Recurknapsack() {
    recurknapsack.show();
    this->close();
}
