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
#include <QtWidgets/QLabel>
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
    QTableWidget *workTape;
    QLineEdit *steps;
    QLabel *picture_turing;
    QLabel *picture_arrowhead;
    QLabel *picture_arrowhead_2;
    QLabel *picture_turing_2;
    QLineEdit *output_Binary;
    QLineEdit *output_process;
    QLineEdit *grids;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Return;
    QPushButton *Recursive_Binary_Search;
    QPushButton *restore;

    void setupUi(QWidget *Turing)
    {
        if (Turing->objectName().isEmpty())
            Turing->setObjectName(QString::fromUtf8("Turing"));
        Turing->resize(1000, 800);
        Turing->setMinimumSize(QSize(1000, 800));
        Turing->setMaximumSize(QSize(1000, 800));
        QFont font;
        font.setPointSize(13);
        Turing->setFont(font);
        Iterative_Binary_Search = new QPushButton(Turing);
        Iterative_Binary_Search->setObjectName(QString::fromUtf8("Iterative_Binary_Search"));
        Iterative_Binary_Search->setGeometry(QRect(50, 40, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        Iterative_Binary_Search->setFont(font1);
        Iterative_Binary_Search->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        input_BianrySer = new QLineEdit(Turing);
        input_BianrySer->setObjectName(QString::fromUtf8("input_BianrySer"));
        input_BianrySer->setGeometry(QRect(50, 110, 421, 41));
        input_BianrySer->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        input_BianrySer->setAlignment(Qt::AlignCenter);
        tape = new QTableWidget(Turing);
        tape->setObjectName(QString::fromUtf8("tape"));
        tape->setGeometry(QRect(545, 330, 300, 50));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        tape->setFont(font2);
        tape->setStyleSheet(QString::fromUtf8("QTableWidegt\n"
"{\n"
"border:2px solid black;\n"
"}"));
        tape->setTextElideMode(Qt::ElideMiddle);
        Target = new QLineEdit(Turing);
        Target->setObjectName(QString::fromUtf8("Target"));
        Target->setGeometry(QRect(510, 110, 121, 41));
        Target->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 13pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        Target->setAlignment(Qt::AlignCenter);
        workTape = new QTableWidget(Turing);
        workTape->setObjectName(QString::fromUtf8("workTape"));
        workTape->setGeometry(QRect(545, 570, 301, 51));
        workTape->setFont(font2);
        workTape->setStyleSheet(QString::fromUtf8(""));
        steps = new QLineEdit(Turing);
        steps->setObjectName(QString::fromUtf8("steps"));
        steps->setGeometry(QRect(20, 250, 121, 41));
        steps->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        steps->setAlignment(Qt::AlignCenter);
        steps->setReadOnly(false);
        picture_turing = new QLabel(Turing);
        picture_turing->setObjectName(QString::fromUtf8("picture_turing"));
        picture_turing->setGeometry(QRect(530, 210, 91, 81));
        picture_turing->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing->setScaledContents(true);
        picture_arrowhead = new QLabel(Turing);
        picture_arrowhead->setObjectName(QString::fromUtf8("picture_arrowhead"));
        picture_arrowhead->setGeometry(QRect(560, 290, 30, 40));
        picture_arrowhead->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead->setScaledContents(true);
        picture_arrowhead_2 = new QLabel(Turing);
        picture_arrowhead_2->setObjectName(QString::fromUtf8("picture_arrowhead_2"));
        picture_arrowhead_2->setGeometry(QRect(560, 530, 30, 40));
        picture_arrowhead_2->setStyleSheet(QString::fromUtf8(""));
        picture_arrowhead_2->setScaledContents(true);
        picture_turing_2 = new QLabel(Turing);
        picture_turing_2->setObjectName(QString::fromUtf8("picture_turing_2"));
        picture_turing_2->setGeometry(QRect(530, 450, 91, 81));
        picture_turing_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:2px solid white\n"
"}"));
        picture_turing_2->setScaledContents(true);
        output_Binary = new QLineEdit(Turing);
        output_Binary->setObjectName(QString::fromUtf8("output_Binary"));
        output_Binary->setGeometry(QRect(320, 250, 121, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        output_Binary->setFont(font3);
        output_Binary->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        output_Binary->setAlignment(Qt::AlignCenter);
        output_process = new QLineEdit(Turing);
        output_process->setObjectName(QString::fromUtf8("output_process"));
        output_process->setGeometry(QRect(630, 230, 151, 41));
        output_process->setFont(font2);
        output_process->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:2px solid black\n"
"}"));
        output_process->setAlignment(Qt::AlignCenter);
        grids = new QLineEdit(Turing);
        grids->setObjectName(QString::fromUtf8("grids"));
        grids->setGeometry(QRect(170, 250, 121, 41));
        grids->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"border:2px solid black\n"
"}"));
        grids->setAlignment(Qt::AlignCenter);
        label = new QLabel(Turing);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 220, 71, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font4.setPointSize(15);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Turing);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 220, 161, 21));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Turing);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 220, 71, 21));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        Return = new QPushButton(Turing);
        Return->setObjectName(QString::fromUtf8("Return"));
        Return->setGeometry(QRect(820, 40, 171, 41));
        Return->setFont(font1);
        Return->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        Recursive_Binary_Search = new QPushButton(Turing);
        Recursive_Binary_Search->setObjectName(QString::fromUtf8("Recursive_Binary_Search"));
        Recursive_Binary_Search->setGeometry(QRect(240, 40, 171, 41));
        Recursive_Binary_Search->setFont(font1);
        Recursive_Binary_Search->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));
        restore = new QPushButton(Turing);
        restore->setObjectName(QString::fromUtf8("restore"));
        restore->setGeometry(QRect(430, 40, 171, 41));
        restore->setFont(font1);
        restore->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}"));

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
        steps->setText(QString());
        steps->setPlaceholderText(QCoreApplication::translate("Turing", "Steps", nullptr));
        picture_turing->setText(QString());
        picture_arrowhead->setText(QString());
        picture_arrowhead_2->setText(QString());
        picture_turing_2->setText(QString());
        output_Binary->setPlaceholderText(QCoreApplication::translate("Turing", "Result", nullptr));
        grids->setText(QString());
        grids->setPlaceholderText(QCoreApplication::translate("Turing", "grids", nullptr));
        label->setText(QCoreApplication::translate("Turing", "\346\255\245\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("Turing", "\345\267\245\344\275\234\347\272\270\345\270\246\347\251\272\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("Turing", "\347\273\223\346\236\234", nullptr));
        Return->setText(QCoreApplication::translate("Turing", "\350\277\224\345\233\236", nullptr));
        Recursive_Binary_Search->setText(QCoreApplication::translate("Turing", "\351\200\222\345\275\222\344\272\214\345\210\206\346\220\234\347\264\242", nullptr));
        restore->setText(QCoreApplication::translate("Turing", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Turing: public Ui_Turing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURING_H
