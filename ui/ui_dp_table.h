/********************************************************************************
** Form generated from reading UI file 'dp_table.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DP_TABLE_H
#define UI_DP_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DP_Table
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *DP_Table)
    {
        if (DP_Table->objectName().isEmpty())
            DP_Table->setObjectName(QString::fromUtf8("DP_Table"));
        DP_Table->resize(1875, 589);
        tableWidget = new QTableWidget(DP_Table);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 140, 1821, 321));

        retranslateUi(DP_Table);

        QMetaObject::connectSlotsByName(DP_Table);
    } // setupUi

    void retranslateUi(QWidget *DP_Table)
    {
        DP_Table->setWindowTitle(QCoreApplication::translate("DP_Table", "DP_Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DP_Table: public Ui_DP_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DP_TABLE_H
