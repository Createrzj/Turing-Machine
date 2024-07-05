/********************************************************************************
** Form generated from reading UI file 'recur_knapsack.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECUR_KNAPSACK_H
#define UI_RECUR_KNAPSACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recur_knapsack
{
public:
    QPushButton *memory_knap;
    QPushButton *backtrack_knap;
    QPushButton *restore;
    QPushButton *return_main;
    QLabel *label_4;
    QTextEdit *STACK;
    QLineEdit *input_Knap;
    QLineEdit *input_Capacity;
    QLineEdit *input_Num;
    QLineEdit *grids;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *max_value;
    QLineEdit *steps;
    QLabel *label_3;
    QTableWidget *inputTape;
    QLabel *picture_turing_2;
    QLabel *picture_arrowhead_3;
    QLineEdit *output_process;
    QLabel *picture_arrowhead_2;
    QLabel *picture_arrowhead;
    QTableWidget *outputTape;
    QLabel *picture_turing_3;
    QTableWidget *workTape;
    QLabel *picture_turing;
    QSlider *horizontalSlider;

    void setupUi(QWidget *recur_knapsack)
    {
        if (recur_knapsack->objectName().isEmpty())
            recur_knapsack->setObjectName(QString::fromUtf8("recur_knapsack"));
        recur_knapsack->resize(1970, 1000);
        recur_knapsack->setMinimumSize(QSize(1200, 1000));
        recur_knapsack->setMaximumSize(QSize(999999, 1000));
        memory_knap = new QPushButton(recur_knapsack);
        memory_knap->setObjectName(QString::fromUtf8("memory_knap"));
        memory_knap->setGeometry(QRect(40, 50, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        memory_knap->setFont(font);
        memory_knap->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        backtrack_knap = new QPushButton(recur_knapsack);
        backtrack_knap->setObjectName(QString::fromUtf8("backtrack_knap"));
        backtrack_knap->setGeometry(QRect(270, 50, 201, 41));
        backtrack_knap->setFont(font);
        backtrack_knap->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        restore = new QPushButton(recur_knapsack);
        restore->setObjectName(QString::fromUtf8("restore"));
        restore->setGeometry(QRect(500, 50, 191, 41));
        restore->setFont(font);
        restore->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        return_main = new QPushButton(recur_knapsack);
        return_main->setObjectName(QString::fromUtf8("return_main"));
        return_main->setGeometry(QRect(980, 50, 171, 41));
        return_main->setFont(font);
        return_main->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        label_4 = new QLabel(recur_knapsack);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 690, 91, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        STACK = new QTextEdit(recur_knapsack);
        STACK->setObjectName(QString::fromUtf8("STACK"));
        STACK->setGeometry(QRect(30, 720, 261, 231));
        STACK->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border-width: 2px 2px 0px 2px; /* \344\270\212\343\200\201\345\217\263\343\200\201\344\270\213\350\276\271\346\241\2061px\357\274\214\345\267\246\350\276\271\346\241\2060px */\n"
"    border-style: solid;\n"
"    border-color: black; /* \350\276\271\346\241\206\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"	font: 13pt \"\345\256\213\344\275\223\";\n"
"}\n"
""));
        input_Knap = new QLineEdit(recur_knapsack);
        input_Knap->setObjectName(QString::fromUtf8("input_Knap"));
        input_Knap->setGeometry(QRect(40, 130, 421, 41));
        input_Knap->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Knap->setAlignment(Qt::AlignCenter);
        input_Capacity = new QLineEdit(recur_knapsack);
        input_Capacity->setObjectName(QString::fromUtf8("input_Capacity"));
        input_Capacity->setGeometry(QRect(480, 130, 121, 41));
        input_Capacity->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Capacity->setAlignment(Qt::AlignCenter);
        input_Num = new QLineEdit(recur_knapsack);
        input_Num->setObjectName(QString::fromUtf8("input_Num"));
        input_Num->setGeometry(QRect(620, 130, 121, 41));
        input_Num->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Num->setAlignment(Qt::AlignCenter);
        grids = new QLineEdit(recur_knapsack);
        grids->setObjectName(QString::fromUtf8("grids"));
        grids->setGeometry(QRect(200, 220, 121, 41));
        grids->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        grids->setAlignment(Qt::AlignCenter);
        label = new QLabel(recur_knapsack);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 180, 101, 31));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(recur_knapsack);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 180, 181, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        max_value = new QLineEdit(recur_knapsack);
        max_value->setObjectName(QString::fromUtf8("max_value"));
        max_value->setGeometry(QRect(380, 220, 121, 41));
        max_value->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        max_value->setAlignment(Qt::AlignCenter);
        steps = new QLineEdit(recur_knapsack);
        steps->setObjectName(QString::fromUtf8("steps"));
        steps->setGeometry(QRect(20, 220, 121, 41));
        steps->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        steps->setAlignment(Qt::AlignCenter);
        steps->setReadOnly(false);
        label_3 = new QLabel(recur_knapsack);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 180, 121, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        inputTape = new QTableWidget(recur_knapsack);
        inputTape->setObjectName(QString::fromUtf8("inputTape"));
        inputTape->setGeometry(QRect(655, 340, 300, 50));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        inputTape->setFont(font2);
        inputTape->setStyleSheet(QString::fromUtf8("QTableWidegt\n"
"{\n"
"border:2px solid black;\n"
"}"));
        inputTape->setTextElideMode(Qt::ElideMiddle);
        picture_turing_2 = new QLabel(recur_knapsack);
        picture_turing_2->setObjectName(QString::fromUtf8("picture_turing_2"));
        picture_turing_2->setGeometry(QRect(640, 420, 91, 81));
        picture_turing_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing_2->setScaledContents(true);
        picture_arrowhead_3 = new QLabel(recur_knapsack);
        picture_arrowhead_3->setObjectName(QString::fromUtf8("picture_arrowhead_3"));
        picture_arrowhead_3->setGeometry(QRect(670, 690, 30, 40));
        picture_arrowhead_3->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_3->setScaledContents(true);
        output_process = new QLineEdit(recur_knapsack);
        output_process->setObjectName(QString::fromUtf8("output_process"));
        output_process->setGeometry(QRect(740, 240, 201, 41));
        output_process->setFont(font2);
        output_process->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:2px solid black\n"
"}"));
        output_process->setAlignment(Qt::AlignCenter);
        picture_arrowhead_2 = new QLabel(recur_knapsack);
        picture_arrowhead_2->setObjectName(QString::fromUtf8("picture_arrowhead_2"));
        picture_arrowhead_2->setGeometry(QRect(670, 500, 30, 40));
        picture_arrowhead_2->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_2->setScaledContents(true);
        picture_arrowhead = new QLabel(recur_knapsack);
        picture_arrowhead->setObjectName(QString::fromUtf8("picture_arrowhead"));
        picture_arrowhead->setGeometry(QRect(670, 300, 30, 40));
        picture_arrowhead->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead->setScaledContents(true);
        outputTape = new QTableWidget(recur_knapsack);
        outputTape->setObjectName(QString::fromUtf8("outputTape"));
        outputTape->setGeometry(QRect(655, 730, 301, 51));
        outputTape->setFont(font2);
        outputTape->setStyleSheet(QString::fromUtf8(""));
        picture_turing_3 = new QLabel(recur_knapsack);
        picture_turing_3->setObjectName(QString::fromUtf8("picture_turing_3"));
        picture_turing_3->setGeometry(QRect(640, 610, 91, 81));
        picture_turing_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing_3->setScaledContents(true);
        workTape = new QTableWidget(recur_knapsack);
        workTape->setObjectName(QString::fromUtf8("workTape"));
        workTape->setGeometry(QRect(655, 540, 301, 51));
        workTape->setFont(font2);
        workTape->setStyleSheet(QString::fromUtf8(""));
        picture_turing = new QLabel(recur_knapsack);
        picture_turing->setObjectName(QString::fromUtf8("picture_turing"));
        picture_turing->setGeometry(QRect(640, 220, 91, 81));
        picture_turing->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing->setScaledContents(true);
        horizontalSlider = new QSlider(recur_knapsack);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(770, 140, 160, 16));
        horizontalSlider->setMaximum(2000);
        horizontalSlider->setSliderPosition(1000);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(recur_knapsack);

        QMetaObject::connectSlotsByName(recur_knapsack);
    } // setupUi

    void retranslateUi(QWidget *recur_knapsack)
    {
        recur_knapsack->setWindowTitle(QCoreApplication::translate("recur_knapsack", "recur_knapsack", nullptr));
        memory_knap->setText(QCoreApplication::translate("recur_knapsack", "\345\244\207\345\277\230\345\275\2250-1\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        backtrack_knap->setText(QCoreApplication::translate("recur_knapsack", "\345\233\236\346\272\2570-1\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        restore->setText(QCoreApplication::translate("recur_knapsack", "\351\207\215\347\275\256", nullptr));
        return_main->setText(QCoreApplication::translate("recur_knapsack", "\350\277\224\345\233\236", nullptr));
        label_4->setText(QCoreApplication::translate("recur_knapsack", "STACK", nullptr));
        input_Knap->setInputMask(QString());
        input_Knap->setText(QString());
        input_Knap->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "\347\211\251\344\275\223\351\207\215\351\207\217\344\273\245\345\217\212\344\273\267\345\200\274\357\274\214(w,v)", nullptr));
        input_Capacity->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "\346\200\273\346\211\277\351\207\215", nullptr));
        input_Num->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "\347\211\251\344\275\223\346\225\260\351\207\217", nullptr));
        grids->setText(QString());
        grids->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "grids", nullptr));
        label->setText(QCoreApplication::translate("recur_knapsack", "\346\255\245\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("recur_knapsack", "\345\267\245\344\275\234\347\272\270\345\270\246\347\251\272\351\227\264", nullptr));
        max_value->setText(QString());
        max_value->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "max_value", nullptr));
        steps->setText(QString());
        steps->setPlaceholderText(QCoreApplication::translate("recur_knapsack", "Steps", nullptr));
        label_3->setText(QCoreApplication::translate("recur_knapsack", "\346\234\200\345\244\247\344\273\267\345\200\274", nullptr));
        picture_turing_2->setText(QString());
        picture_arrowhead_3->setText(QString());
        picture_arrowhead_2->setText(QString());
        picture_arrowhead->setText(QString());
        picture_turing_3->setText(QString());
        picture_turing->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recur_knapsack: public Ui_recur_knapsack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECUR_KNAPSACK_H
