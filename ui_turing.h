/********************************************************************************
** Form generated from reading UI file 'turing.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURING_H
#define UI_TURING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Turing
{
public:
    QPushButton *Iterative_Binary_Search;
    QLineEdit *input_BianrySer;
    QTableWidget *tape;
    QLineEdit *Target;

    void setupUi(QWidget *Turing)
    {
        if (Turing->objectName().isEmpty())
            Turing->setObjectName(QString::fromUtf8("Turing"));
        Turing->resize(1200, 1000);
        Turing->setMinimumSize(QSize(1200, 1000));
        Turing->setMaximumSize(QSize(1200, 1000));
        Iterative_Binary_Search = new QPushButton(Turing);
        Iterative_Binary_Search->setObjectName(QString::fromUtf8("Iterative_Binary_Search"));
        Iterative_Binary_Search->setGeometry(QRect(120, 110, 171, 31));
        input_BianrySer = new QLineEdit(Turing);
        input_BianrySer->setObjectName(QString::fromUtf8("input_BianrySer"));
        input_BianrySer->setGeometry(QRect(110, 170, 421, 31));
        input_BianrySer->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 10pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        input_BianrySer->setAlignment(Qt::AlignCenter);
        tape = new QTableWidget(Turing);
        tape->setObjectName(QString::fromUtf8("tape"));
        tape->setGeometry(QRect(500, 400, 300, 50));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        tape->setFont(font);
        tape->setStyleSheet(QString::fromUtf8(""));
        tape->setTextElideMode(Qt::ElideMiddle);
        Target = new QLineEdit(Turing);
        Target->setObjectName(QString::fromUtf8("Target"));
        Target->setGeometry(QRect(580, 169, 121, 31));
        Target->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 10pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        Target->setAlignment(Qt::AlignCenter);

        retranslateUi(Turing);

        QMetaObject::connectSlotsByName(Turing);
    } // setupUi

    void retranslateUi(QWidget *Turing)
    {
        Turing->setWindowTitle(QCoreApplication::translate("Turing", "Turing", nullptr));
        Iterative_Binary_Search->setText(QCoreApplication::translate("Turing", "\345\233\276\347\201\265\346\234\272\344\272\214\345\210\206\346\220\234\347\264\242", nullptr));
        input_BianrySer->setInputMask(QString());
        input_BianrySer->setText(QString());
        input_BianrySer->setPlaceholderText(QCoreApplication::translate("Turing", "\344\272\214\345\210\206\346\220\234\347\264\242\357\274\214\350\257\267\350\276\223\345\205\245\345\210\235\345\247\213\345\272\217\345\210\227", nullptr));
        Target->setPlaceholderText(QCoreApplication::translate("Turing", "\347\233\256\346\240\207\346\225\260\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Turing: public Ui_Turing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURING_H
