/********************************************************************************
** Form generated from reading UI file 'gestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTDIALOG_H
#define UI_GESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestDialog
{
public:
    QWidget *layoutWidget_23;
    QHBoxLayout *horizontalLayout_26;
    QComboBox *comboBox_search_doc;
    QLineEdit *search_2;
    QPushButton *Search_doc;
    QTableView *tableView_2;
    QPushButton *pushButton_12;
    QLabel *label_25;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Signup;
    QWidget *layoutWidget_24;
    QHBoxLayout *horizontalLayout_27;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QDialog *GestDialog)
    {
        if (GestDialog->objectName().isEmpty())
            GestDialog->setObjectName(QStringLiteral("GestDialog"));
        GestDialog->resize(649, 613);
        layoutWidget_23 = new QWidget(GestDialog);
        layoutWidget_23->setObjectName(QStringLiteral("layoutWidget_23"));
        layoutWidget_23->setGeometry(QRect(170, 60, 291, 25));
        horizontalLayout_26 = new QHBoxLayout(layoutWidget_23);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        comboBox_search_doc = new QComboBox(layoutWidget_23);
        comboBox_search_doc->setObjectName(QStringLiteral("comboBox_search_doc"));

        horizontalLayout_26->addWidget(comboBox_search_doc);

        search_2 = new QLineEdit(layoutWidget_23);
        search_2->setObjectName(QStringLiteral("search_2"));

        horizontalLayout_26->addWidget(search_2);

        Search_doc = new QPushButton(layoutWidget_23);
        Search_doc->setObjectName(QStringLiteral("Search_doc"));

        horizontalLayout_26->addWidget(Search_doc);

        tableView_2 = new QTableView(GestDialog);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(20, 100, 611, 351));
        pushButton_12 = new QPushButton(GestDialog);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(230, 500, 171, 23));
        label_25 = new QLabel(GestDialog);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(70, 60, 71, 16));
        layoutWidget = new QWidget(GestDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 550, 321, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_Signup = new QPushButton(layoutWidget);
        pushButton_Signup->setObjectName(QStringLiteral("pushButton_Signup"));

        horizontalLayout->addWidget(pushButton_Signup);

        layoutWidget_24 = new QWidget(GestDialog);
        layoutWidget_24->setObjectName(QStringLiteral("layoutWidget_24"));
        layoutWidget_24->setGeometry(QRect(40, 460, 551, 25));
        horizontalLayout_27 = new QHBoxLayout(layoutWidget_24);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(layoutWidget_24);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_27->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget_24);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_27->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(layoutWidget_24);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_27->addWidget(pushButton_11);


        retranslateUi(GestDialog);

        QMetaObject::connectSlotsByName(GestDialog);
    } // setupUi

    void retranslateUi(QDialog *GestDialog)
    {
        GestDialog->setWindowTitle(QApplication::translate("GestDialog", "Dialog", 0));
        Search_doc->setText(QApplication::translate("GestDialog", "SEARCH", 0));
        pushButton_12->setText(QApplication::translate("GestDialog", "Load Table", 0));
        label_25->setText(QApplication::translate("GestDialog", "SEARCH BY :", 0));
        pushButton_2->setText(QApplication::translate("GestDialog", "Previous", 0));
        pushButton_Signup->setText(QApplication::translate("GestDialog", "Sign up", 0));
        pushButton_9->setText(QApplication::translate("GestDialog", "Load Books' Table", 0));
        pushButton_10->setText(QApplication::translate("GestDialog", "Load Journals' Table", 0));
        pushButton_11->setText(QApplication::translate("GestDialog", "Load Academic projects' Table", 0));
    } // retranslateUi

};

namespace Ui {
    class GestDialog: public Ui_GestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTDIALOG_H
