/********************************************************************************
** Form generated from reading UI file 'main_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_INTERFACE_H
#define UI_MAIN_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Interface
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Main_Interface)
    {
        if (Main_Interface->objectName().isEmpty())
            Main_Interface->setObjectName(QString::fromUtf8("Main_Interface"));
        Main_Interface->resize(905, 862);
        pushButton = new QPushButton(Main_Interface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 140, 211, 51));
        pushButton_2 = new QPushButton(Main_Interface);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 240, 211, 51));
        pushButton_3 = new QPushButton(Main_Interface);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 330, 211, 51));
        pushButton_4 = new QPushButton(Main_Interface);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 440, 211, 51));
        pushButton_5 = new QPushButton(Main_Interface);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(320, 560, 211, 51));

        retranslateUi(Main_Interface);

        QMetaObject::connectSlotsByName(Main_Interface);
    } // setupUi

    void retranslateUi(QWidget *Main_Interface)
    {
        Main_Interface->setWindowTitle(QCoreApplication::translate("Main_Interface", "Main_Interface", nullptr));
        pushButton->setText(QCoreApplication::translate("Main_Interface", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Main_Interface", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Main_Interface", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Main_Interface", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Main_Interface", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Interface: public Ui_Main_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INTERFACE_H
