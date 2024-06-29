//
// Created by icy on 24-6-28.
//

#ifndef TURING_MACHINE_MAIN_INTERFACE_H
#define TURING_MACHINE_MAIN_INTERFACE_H

#include <QWidget>


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
};


#endif //TURING_MACHINE_MAIN_INTERFACE_H
