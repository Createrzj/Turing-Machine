/********************************************************************************
** Form generated from reading UI file 'knapsack.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNAPSACK_H
#define UI_KNAPSACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Knapsack
{
public:
    QPushButton *DP;
    QPushButton *restore;
    QPushButton *Return;
    QLineEdit *input_Knap;
    QLineEdit *input_Capacity;
    QLineEdit *input_Num;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *inputTape;
    QLineEdit *grids;
    QLineEdit *steps;
    QLineEdit *output_process;
    QLabel *picture_turing;
    QTableWidget *workTape;
    QLabel *picture_arrowhead;
    QLabel *picture_turing_2;
    QLabel *picture_arrowhead_2;
    QTableWidget *outputTape;
    QLabel *picture_arrowhead_3;
    QLabel *picture_turing_3;
    QLineEdit *max_value;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *BB;
    QSlider *horizontalSlider;
    QTextEdit *Queue;
    QLabel *label_5;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Knapsack)
    {
        if (Knapsack->objectName().isEmpty())
            Knapsack->setObjectName(QString::fromUtf8("Knapsack"));
        Knapsack->resize(1500, 800);
        Knapsack->setMinimumSize(QSize(1500, 800));
        Knapsack->setMaximumSize(QSize(1500, 800));
        DP = new QPushButton(Knapsack);
        DP->setObjectName(QString::fromUtf8("DP"));
        DP->setGeometry(QRect(60, 60, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        DP->setFont(font);
        DP->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        restore = new QPushButton(Knapsack);
        restore->setObjectName(QString::fromUtf8("restore"));
        restore->setGeometry(QRect(520, 60, 171, 41));
        restore->setFont(font);
        restore->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        Return = new QPushButton(Knapsack);
        Return->setObjectName(QString::fromUtf8("Return"));
        Return->setGeometry(QRect(1000, 40, 171, 41));
        Return->setFont(font);
        Return->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        input_Knap = new QLineEdit(Knapsack);
        input_Knap->setObjectName(QString::fromUtf8("input_Knap"));
        input_Knap->setGeometry(QRect(60, 120, 421, 41));
        input_Knap->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Knap->setAlignment(Qt::AlignCenter);
        input_Capacity = new QLineEdit(Knapsack);
        input_Capacity->setObjectName(QString::fromUtf8("input_Capacity"));
        input_Capacity->setGeometry(QRect(500, 120, 121, 41));
        input_Capacity->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Capacity->setAlignment(Qt::AlignCenter);
        input_Num = new QLineEdit(Knapsack);
        input_Num->setObjectName(QString::fromUtf8("input_Num"));
        input_Num->setGeometry(QRect(640, 120, 121, 41));
        input_Num->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_Num->setAlignment(Qt::AlignCenter);
        label = new QLabel(Knapsack);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 190, 101, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Knapsack);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 180, 171, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        inputTape = new QTableWidget(Knapsack);
        inputTape->setObjectName(QString::fromUtf8("inputTape"));
        inputTape->setGeometry(QRect(635, 300, 300, 50));
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
        grids = new QLineEdit(Knapsack);
        grids->setObjectName(QString::fromUtf8("grids"));
        grids->setGeometry(QRect(220, 220, 121, 41));
        grids->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        grids->setAlignment(Qt::AlignCenter);
        steps = new QLineEdit(Knapsack);
        steps->setObjectName(QString::fromUtf8("steps"));
        steps->setGeometry(QRect(40, 220, 121, 41));
        steps->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        steps->setAlignment(Qt::AlignCenter);
        steps->setReadOnly(false);
        output_process = new QLineEdit(Knapsack);
        output_process->setObjectName(QString::fromUtf8("output_process"));
        output_process->setGeometry(QRect(720, 200, 261, 41));
        output_process->setFont(font2);
        output_process->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:2px solid black\n"
"}"));
        output_process->setAlignment(Qt::AlignCenter);
        picture_turing = new QLabel(Knapsack);
        picture_turing->setObjectName(QString::fromUtf8("picture_turing"));
        picture_turing->setGeometry(QRect(620, 180, 91, 81));
        picture_turing->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing->setScaledContents(true);
        workTape = new QTableWidget(Knapsack);
        workTape->setObjectName(QString::fromUtf8("workTape"));
        workTape->setGeometry(QRect(635, 500, 301, 51));
        workTape->setFont(font2);
        workTape->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead = new QLabel(Knapsack);
        picture_arrowhead->setObjectName(QString::fromUtf8("picture_arrowhead"));
        picture_arrowhead->setGeometry(QRect(650, 260, 30, 40));
        picture_arrowhead->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead->setScaledContents(true);
        picture_turing_2 = new QLabel(Knapsack);
        picture_turing_2->setObjectName(QString::fromUtf8("picture_turing_2"));
        picture_turing_2->setGeometry(QRect(620, 380, 91, 81));
        picture_turing_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing_2->setScaledContents(true);
        picture_arrowhead_2 = new QLabel(Knapsack);
        picture_arrowhead_2->setObjectName(QString::fromUtf8("picture_arrowhead_2"));
        picture_arrowhead_2->setGeometry(QRect(650, 460, 30, 40));
        picture_arrowhead_2->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_2->setScaledContents(true);
        outputTape = new QTableWidget(Knapsack);
        outputTape->setObjectName(QString::fromUtf8("outputTape"));
        outputTape->setGeometry(QRect(635, 690, 301, 51));
        outputTape->setFont(font2);
        outputTape->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_3 = new QLabel(Knapsack);
        picture_arrowhead_3->setObjectName(QString::fromUtf8("picture_arrowhead_3"));
        picture_arrowhead_3->setGeometry(QRect(650, 650, 30, 40));
        picture_arrowhead_3->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_3->setScaledContents(true);
        picture_turing_3 = new QLabel(Knapsack);
        picture_turing_3->setObjectName(QString::fromUtf8("picture_turing_3"));
        picture_turing_3->setGeometry(QRect(620, 570, 91, 81));
        picture_turing_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing_3->setScaledContents(true);
        max_value = new QLineEdit(Knapsack);
        max_value->setObjectName(QString::fromUtf8("max_value"));
        max_value->setGeometry(QRect(400, 220, 121, 41));
        max_value->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        max_value->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Knapsack);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 180, 161, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Knapsack);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 10, 241, 31));
        QFont font3;
        font3.setPointSize(12);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        BB = new QPushButton(Knapsack);
        BB->setObjectName(QString::fromUtf8("BB"));
        BB->setGeometry(QRect(290, 60, 171, 41));
        BB->setFont(font);
        BB->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        horizontalSlider = new QSlider(Knapsack);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(820, 140, 160, 16));
        horizontalSlider->setMaximum(2000);
        horizontalSlider->setSliderPosition(1000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        Queue = new QTextEdit(Knapsack);
        Queue->setObjectName(QString::fromUtf8("Queue"));
        Queue->setGeometry(QRect(10, 590, 281, 201));
        Queue->setLayoutDirection(Qt::LeftToRight);
        Queue->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border-width: 0px 2px 0px 2px; /* \344\270\212\343\200\201\345\217\263\343\200\201\344\270\213\350\276\271\346\241\2061px\357\274\214\345\267\246\350\276\271\346\241\2060px */\n"
"    border-style: solid;\n"
"    border-color: black; /* \350\276\271\346\241\206\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"	font: 12pt \"\345\256\213\344\275\223\";\n"
"}\n"
""));
        label_5 = new QLabel(Knapsack);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 560, 91, 21));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);
        textBrowser = new QTextBrowser(Knapsack);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(320, 730, 151, 61));

        retranslateUi(Knapsack);

        QMetaObject::connectSlotsByName(Knapsack);
    } // setupUi

    void retranslateUi(QWidget *Knapsack)
    {
        Knapsack->setWindowTitle(QCoreApplication::translate("Knapsack", "Knapsack", nullptr));
        DP->setText(QCoreApplication::translate("Knapsack", "\345\212\250\346\200\201\350\247\204\345\210\222", nullptr));
        restore->setText(QCoreApplication::translate("Knapsack", "\351\207\215\347\275\256", nullptr));
        Return->setText(QCoreApplication::translate("Knapsack", "\350\277\224\345\233\236", nullptr));
        input_Knap->setInputMask(QString());
        input_Knap->setText(QString());
        input_Knap->setPlaceholderText(QCoreApplication::translate("Knapsack", "\347\211\251\344\275\223\351\207\215\351\207\217\344\273\245\345\217\212\344\273\267\345\200\274\357\274\214(w,v)", nullptr));
        input_Capacity->setPlaceholderText(QCoreApplication::translate("Knapsack", "\346\200\273\346\211\277\351\207\215", nullptr));
        input_Num->setPlaceholderText(QCoreApplication::translate("Knapsack", "\347\211\251\344\275\223\346\225\260\351\207\217", nullptr));
        label->setText(QCoreApplication::translate("Knapsack", "\346\255\245\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("Knapsack", "\345\267\245\344\275\234\347\272\270\345\270\246\347\251\272\351\227\264", nullptr));
        grids->setText(QString());
        grids->setPlaceholderText(QCoreApplication::translate("Knapsack", "grids", nullptr));
        steps->setText(QString());
        steps->setPlaceholderText(QCoreApplication::translate("Knapsack", "Steps", nullptr));
        picture_turing->setText(QString());
        picture_arrowhead->setText(QString());
        picture_turing_2->setText(QString());
        picture_arrowhead_2->setText(QString());
        picture_arrowhead_3->setText(QString());
        picture_turing_3->setText(QString());
        max_value->setText(QString());
        max_value->setPlaceholderText(QCoreApplication::translate("Knapsack", "max_value", nullptr));
        label_3->setText(QCoreApplication::translate("Knapsack", "\346\234\200\345\244\247\344\273\267\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("Knapsack", "\345\233\276\347\201\265\346\234\2720-1\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        BB->setText(QCoreApplication::translate("Knapsack", "\345\210\206\346\224\257\351\231\220\347\225\214", nullptr));
        label_5->setText(QCoreApplication::translate("Knapsack", "QUEUE", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Knapsack", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">level,profit,</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">weight,bound</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Knapsack: public Ui_Knapsack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNAPSACK_H
