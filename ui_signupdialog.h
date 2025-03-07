/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QDateEdit *date;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_surnoun;
    QLineEdit *lineEdit_noun;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_teacher;
    QRadioButton *radioButton_student;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_spe;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *comboBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_cin;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLineEdit *lineEdit_email;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *lineEdit_username;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLineEdit *lineEdit_password;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLineEdit *lineEdit_password_2;
    QLabel *background;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_6;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_7;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QStringLiteral("SignupDialog"));
        SignupDialog->resize(571, 630);
        groupBox = new QGroupBox(SignupDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(70, 0, 431, 621));
        groupBox->setFlat(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 61, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 50, 46, 13));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 340, 101, 16));
        date = new QDateEdit(groupBox);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(150, 370, 110, 22));
        date->setCalendarPopup(true);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(33, 80, 371, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_surnoun = new QLineEdit(layoutWidget);
        lineEdit_surnoun->setObjectName(QStringLiteral("lineEdit_surnoun"));

        horizontalLayout->addWidget(lineEdit_surnoun);

        lineEdit_noun = new QLineEdit(layoutWidget);
        lineEdit_noun->setObjectName(QStringLiteral("lineEdit_noun"));

        horizontalLayout->addWidget(lineEdit_noun);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 590, 251, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 440, 351, 19));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_teacher = new QRadioButton(layoutWidget2);
        radioButton_teacher->setObjectName(QStringLiteral("radioButton_teacher"));

        horizontalLayout_3->addWidget(radioButton_teacher);

        radioButton_student = new QRadioButton(layoutWidget2);
        radioButton_student->setObjectName(QStringLiteral("radioButton_student"));

        horizontalLayout_3->addWidget(radioButton_student);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 480, 351, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_spe = new QLineEdit(layoutWidget3);
        lineEdit_spe->setObjectName(QStringLiteral("lineEdit_spe"));

        horizontalLayout_4->addWidget(lineEdit_spe);

        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(38, 520, 351, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        comboBox = new QComboBox(layoutWidget4);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 290, 381, 22));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_12->addWidget(label_10);

        lineEdit_cin = new QLineEdit(layoutWidget_2);
        lineEdit_cin->setObjectName(QStringLiteral("lineEdit_cin"));

        horizontalLayout_12->addWidget(lineEdit_cin);

        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 120, 381, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        lineEdit_email = new QLineEdit(layoutWidget5);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));

        horizontalLayout_8->addWidget(lineEdit_email);

        layoutWidget6 = new QWidget(groupBox);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(30, 160, 381, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget6);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        lineEdit_username = new QLineEdit(layoutWidget6);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        horizontalLayout_9->addWidget(lineEdit_username);

        layoutWidget7 = new QWidget(groupBox);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(30, 200, 381, 22));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget7);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        lineEdit_password = new QLineEdit(layoutWidget7);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_10->addWidget(lineEdit_password);

        layoutWidget8 = new QWidget(groupBox);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(30, 240, 381, 22));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget8);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_11->addWidget(label_6);

        lineEdit_password_2 = new QLineEdit(layoutWidget8);
        lineEdit_password_2->setObjectName(QStringLiteral("lineEdit_password_2"));
        lineEdit_password_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_11->addWidget(lineEdit_password_2);

        background = new QLabel(SignupDialog);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 571, 631));
        layoutWidget9 = new QWidget(SignupDialog);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        layoutWidget10 = new QWidget(SignupDialog);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        layoutWidget->raise();
        layoutWidget->raise();
        background->raise();
        groupBox->raise();

        retranslateUi(SignupDialog);

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QApplication::translate("SignupDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("SignupDialog", "Sign up", 0));
        label->setText(QApplication::translate("SignupDialog", "Surnoun: ", 0));
        label_2->setText(QApplication::translate("SignupDialog", "Noun :", 0));
        label_7->setText(QApplication::translate("SignupDialog", "Birth date :", 0));
        pushButton_2->setText(QApplication::translate("SignupDialog", "Previous", 0));
        pushButton->setText(QApplication::translate("SignupDialog", "Login", 0));
        radioButton_teacher->setText(QApplication::translate("SignupDialog", "Teacher", 0));
        radioButton_student->setText(QApplication::translate("SignupDialog", "Student", 0));
        label_8->setText(QApplication::translate("SignupDialog", "Speciality :", 0));
        label_9->setText(QApplication::translate("SignupDialog", "Acadamec Year :", 0));
        label_10->setText(QApplication::translate("SignupDialog", "CIN", 0));
        label_3->setText(QApplication::translate("SignupDialog", "Email Adress :", 0));
        label_4->setText(QApplication::translate("SignupDialog", "Username :", 0));
        label_5->setText(QApplication::translate("SignupDialog", "Password :", 0));
        label_6->setText(QApplication::translate("SignupDialog", "Confirm Password :", 0));
        background->setText(QApplication::translate("SignupDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
