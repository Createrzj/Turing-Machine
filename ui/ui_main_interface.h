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

    void setupUi(QWidget *Main_Interface)
    {
        if (Main_Interface->objectName().isEmpty())
            Main_Interface->setObjectName(QString::fromUtf8("Main_Interface"));
        Main_Interface->resize(905, 862);
        pushButton = new QPushButton(Main_Interface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 190, 211, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        pushButton_2 = new QPushButton(Main_Interface);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 290, 211, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        pushButton_3 = new QPushButton(Main_Interface);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 390, 211, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));

        retranslateUi(Main_Interface);

        QMetaObject::connectSlotsByName(Main_Interface);
    } // setupUi

    void retranslateUi(QWidget *Main_Interface)
    {
        Main_Interface->setWindowTitle(QCoreApplication::translate("Main_Interface", "Main_Interface", nullptr));
        pushButton->setText(QCoreApplication::translate("Main_Interface", "\344\272\214\345\210\206\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Main_Interface", "\345\233\276\347\201\265\346\234\2720-1\350\203\214\345\214\205", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Main_Interface", "\351\200\222\345\275\2220-1\350\203\214\345\214\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Interface: public Ui_Main_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INTERFACE_H
