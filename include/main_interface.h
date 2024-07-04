//
// Created by icy on 24-6-28.
//

#ifndef TURING_MACHINE_MAIN_INTERFACE_H
#define TURING_MACHINE_MAIN_INTERFACE_H

#include "Library.h"
#include "turing.h"
#include "../ui/ui_turing.h"
#include "knapsack.h"
#include "../ui/ui_knapsack.h"
#include "../ui/ui_main_interface.h"
#include "recur_knapsack.h"
#include "../ui/ui_recur_knapsack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Interface; }
QT_END_NAMESPACE

class Main_Interface : public QWidget {
Q_OBJECT

public:
    explicit Main_Interface(QWidget *parent = nullptr);
    ~Main_Interface() override;

private:
    Ui::Main_Interface *ui;
    Turing BinarySearch;
    Knapsack knapsack;
    recur_knapsack recurknapsack;

public slots:
    void show_Binary();
    void show_Knapsack();
    void show_Recurknapsack();
    void show_again();
};


#endif //TURING_MACHINE_MAIN_INTERFACE_H
