/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *image_admin;
    QWidget *tab;
    QGroupBox *groupBox_6;
    QLabel *label_64;
    QWidget *layoutWidget_56;
    QHBoxLayout *horizontalLayout_67;
    QLabel *label_66;
    QLineEdit *ID_2;
    QLabel *label_65;
    QLineEdit *lineEdit_username_3;
    QLabel *label_61;
    QLineEdit *lineEdit_email_3;
    QWidget *layoutWidget_52;
    QHBoxLayout *horizontalLayout_63;
    QLabel *label_55;
    QLineEdit *lineEdit_surnoun_3;
    QLabel *label_56;
    QLineEdit *lineEdit_noun_3;
    QLabel *label_60;
    QLineEdit *lineEdit_cin_3;
    QLabel *label_57;
    QDateEdit *date_3;
    QLabel *label_74;
    QTableView *tableView_his_3;
    QLabel *label_75;
    QTableView *tableView_his_4;
    QLabel *label_76;
    QLineEdit *ref_4;
    QPushButton *pushButton_23;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_58;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_admin_3;
    QRadioButton *radioButton_teacher_3;
    QRadioButton *radioButton_student_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_61;
    QLabel *label_58;
    QLineEdit *lineEdit_spe_3;
    QHBoxLayout *horizontalLayout_62;
    QLabel *label_59;
    QComboBox *comboBox_EDIT_2;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_49;
    QHBoxLayout *horizontalLayout_65;
    QLabel *label_62;
    QLineEdit *ref_3;
    QLabel *label_63;
    QLineEdit *lineEdit_title_4;
    QHBoxLayout *horizontalLayout_66;
    QLabel *label_67;
    QLineEdit *lineEdit_author_4;
    QLabel *label_68;
    QLineEdit *lineEdit_cathegory_4;
    QPlainTextEdit *plainTextEdit_des_4;
    QLabel *label_69;
    QTableView *tableView_his_2;
    QLabel *label_70;
    QWidget *layoutWidget_53;
    QHBoxLayout *horizontalLayout_68;
    QHBoxLayout *horizontalLayout_69;
    QLabel *label_71;
    QLineEdit *lineEdit_nbr_copie_4;
    QHBoxLayout *horizontalLayout_70;
    QLabel *label_72;
    QLineEdit *lineEdit_year_4;
    QHBoxLayout *horizontalLayout_71;
    QLabel *label_73;
    QLineEdit *lineEdit_nbr_page_4;
    QWidget *layoutWidget_54;
    QHBoxLayout *horizontalLayout_72;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_acproj_4;
    QRadioButton *radioButton_book_4;
    QRadioButton *radioButton_journal_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_73;
    QLabel *label_hp_sup_4;
    QLineEdit *lineEdit_hp_sup_4;
    QHBoxLayout *horizontalLayout_74;
    QLabel *label_sub_4;
    QLineEdit *lineEdit_sub_4;
    QPushButton *pushButton_22;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_34;
    QHBoxLayout *horizontalLayout_59;
    QComboBox *comboBox_search_doc_2;
    QLineEdit *search_3;
    QPushButton *Search_doc_2;
    QTableView *tableView_3;
    QWidget *layoutWidget_48;
    QHBoxLayout *horizontalLayout_60;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName(QStringLiteral("UserDialog"));
        UserDialog->resize(1125, 884);
        tabWidget = new QTabWidget(UserDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1121, 841));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        image_admin = new QLabel(tab_3);
        image_admin->setObjectName(QStringLiteral("image_admin"));
        image_admin->setGeometry(QRect(0, 10, 1111, 781));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 491, 801));
        groupBox_6->setFlat(false);
        label_64 = new QLabel(groupBox_6);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(20, 120, 46, 13));
        layoutWidget_56 = new QWidget(groupBox_6);
        layoutWidget_56->setObjectName(QStringLiteral("layoutWidget_56"));
        layoutWidget_56->setGeometry(QRect(20, 30, 461, 22));
        horizontalLayout_67 = new QHBoxLayout(layoutWidget_56);
        horizontalLayout_67->setObjectName(QStringLiteral("horizontalLayout_67"));
        horizontalLayout_67->setContentsMargins(0, 0, 0, 0);
        label_66 = new QLabel(layoutWidget_56);
        label_66->setObjectName(QStringLiteral("label_66"));

        horizontalLayout_67->addWidget(label_66);

        ID_2 = new QLineEdit(layoutWidget_56);
        ID_2->setObjectName(QStringLiteral("ID_2"));
        ID_2->setReadOnly(true);

        horizontalLayout_67->addWidget(ID_2);

        label_65 = new QLabel(layoutWidget_56);
        label_65->setObjectName(QStringLiteral("label_65"));

        horizontalLayout_67->addWidget(label_65);

        lineEdit_username_3 = new QLineEdit(layoutWidget_56);
        lineEdit_username_3->setObjectName(QStringLiteral("lineEdit_username_3"));
        lineEdit_username_3->setReadOnly(true);

        horizontalLayout_67->addWidget(lineEdit_username_3);

        label_61 = new QLabel(layoutWidget_56);
        label_61->setObjectName(QStringLiteral("label_61"));

        horizontalLayout_67->addWidget(label_61);

        lineEdit_email_3 = new QLineEdit(layoutWidget_56);
        lineEdit_email_3->setObjectName(QStringLiteral("lineEdit_email_3"));
        lineEdit_email_3->setReadOnly(true);

        horizontalLayout_67->addWidget(lineEdit_email_3);

        layoutWidget_52 = new QWidget(groupBox_6);
        layoutWidget_52->setObjectName(QStringLiteral("layoutWidget_52"));
        layoutWidget_52->setGeometry(QRect(14, 80, 461, 22));
        horizontalLayout_63 = new QHBoxLayout(layoutWidget_52);
        horizontalLayout_63->setObjectName(QStringLiteral("horizontalLayout_63"));
        horizontalLayout_63->setContentsMargins(0, 0, 0, 0);
        label_55 = new QLabel(layoutWidget_52);
        label_55->setObjectName(QStringLiteral("label_55"));

        horizontalLayout_63->addWidget(label_55);

        lineEdit_surnoun_3 = new QLineEdit(layoutWidget_52);
        lineEdit_surnoun_3->setObjectName(QStringLiteral("lineEdit_surnoun_3"));
        lineEdit_surnoun_3->setReadOnly(true);

        horizontalLayout_63->addWidget(lineEdit_surnoun_3);

        label_56 = new QLabel(layoutWidget_52);
        label_56->setObjectName(QStringLiteral("label_56"));

        horizontalLayout_63->addWidget(label_56);

        lineEdit_noun_3 = new QLineEdit(layoutWidget_52);
        lineEdit_noun_3->setObjectName(QStringLiteral("lineEdit_noun_3"));
        lineEdit_noun_3->setReadOnly(true);

        horizontalLayout_63->addWidget(lineEdit_noun_3);

        label_60 = new QLabel(layoutWidget_52);
        label_60->setObjectName(QStringLiteral("label_60"));

        horizontalLayout_63->addWidget(label_60);

        lineEdit_cin_3 = new QLineEdit(layoutWidget_52);
        lineEdit_cin_3->setObjectName(QStringLiteral("lineEdit_cin_3"));
        lineEdit_cin_3->setReadOnly(true);

        horizontalLayout_63->addWidget(lineEdit_cin_3);

        label_57 = new QLabel(layoutWidget_52);
        label_57->setObjectName(QStringLiteral("label_57"));

        horizontalLayout_63->addWidget(label_57);

        date_3 = new QDateEdit(layoutWidget_52);
        date_3->setObjectName(QStringLiteral("date_3"));
        date_3->setReadOnly(true);
        date_3->setCalendarPopup(true);

        horizontalLayout_63->addWidget(date_3);

        label_74 = new QLabel(groupBox_6);
        label_74->setObjectName(QStringLiteral("label_74"));
        label_74->setGeometry(QRect(10, 530, 101, 16));
        tableView_his_3 = new QTableView(groupBox_6);
        tableView_his_3->setObjectName(QStringLiteral("tableView_his_3"));
        tableView_his_3->setGeometry(QRect(0, 550, 481, 231));
        label_75 = new QLabel(groupBox_6);
        label_75->setObjectName(QStringLiteral("label_75"));
        label_75->setGeometry(QRect(10, 240, 111, 16));
        tableView_his_4 = new QTableView(groupBox_6);
        tableView_his_4->setObjectName(QStringLiteral("tableView_his_4"));
        tableView_his_4->setGeometry(QRect(0, 260, 481, 171));
        label_76 = new QLabel(groupBox_6);
        label_76->setObjectName(QStringLiteral("label_76"));
        label_76->setGeometry(QRect(7, 439, 27, 22));
        ref_4 = new QLineEdit(groupBox_6);
        ref_4->setObjectName(QStringLiteral("ref_4"));
        ref_4->setEnabled(true);
        ref_4->setGeometry(QRect(40, 440, 201, 20));
        ref_4->setReadOnly(true);
        pushButton_23 = new QPushButton(groupBox_6);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(264, 440, 151, 23));
        layoutWidget = new QWidget(groupBox_6);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 130, 266, 67));
        horizontalLayout_58 = new QHBoxLayout(layoutWidget);
        horizontalLayout_58->setObjectName(QStringLiteral("horizontalLayout_58"));
        horizontalLayout_58->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_admin_3 = new QRadioButton(layoutWidget);
        radioButton_admin_3->setObjectName(QStringLiteral("radioButton_admin_3"));
        radioButton_admin_3->setEnabled(false);

        verticalLayout_3->addWidget(radioButton_admin_3);

        radioButton_teacher_3 = new QRadioButton(layoutWidget);
        radioButton_teacher_3->setObjectName(QStringLiteral("radioButton_teacher_3"));
        radioButton_teacher_3->setEnabled(false);

        verticalLayout_3->addWidget(radioButton_teacher_3);

        radioButton_student_3 = new QRadioButton(layoutWidget);
        radioButton_student_3->setObjectName(QStringLiteral("radioButton_student_3"));
        radioButton_student_3->setEnabled(false);

        verticalLayout_3->addWidget(radioButton_student_3);


        horizontalLayout_58->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setObjectName(QStringLiteral("horizontalLayout_61"));
        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName(QStringLiteral("label_58"));

        horizontalLayout_61->addWidget(label_58);

        lineEdit_spe_3 = new QLineEdit(layoutWidget);
        lineEdit_spe_3->setObjectName(QStringLiteral("lineEdit_spe_3"));
        lineEdit_spe_3->setReadOnly(true);

        horizontalLayout_61->addWidget(lineEdit_spe_3);


        verticalLayout_4->addLayout(horizontalLayout_61);

        horizontalLayout_62 = new QHBoxLayout();
        horizontalLayout_62->setObjectName(QStringLiteral("horizontalLayout_62"));
        label_59 = new QLabel(layoutWidget);
        label_59->setObjectName(QStringLiteral("label_59"));

        horizontalLayout_62->addWidget(label_59);

        comboBox_EDIT_2 = new QComboBox(layoutWidget);
        comboBox_EDIT_2->setObjectName(QStringLiteral("comboBox_EDIT_2"));
        comboBox_EDIT_2->setEnabled(false);
        comboBox_EDIT_2->setEditable(false);

        horizontalLayout_62->addWidget(comboBox_EDIT_2);


        verticalLayout_4->addLayout(horizontalLayout_62);


        horizontalLayout_58->addLayout(verticalLayout_4);

        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(500, 340, 611, 441));
        layoutWidget_49 = new QWidget(groupBox_8);
        layoutWidget_49->setObjectName(QStringLiteral("layoutWidget_49"));
        layoutWidget_49->setGeometry(QRect(10, 20, 591, 24));
        horizontalLayout_65 = new QHBoxLayout(layoutWidget_49);
        horizontalLayout_65->setObjectName(QStringLiteral("horizontalLayout_65"));
        horizontalLayout_65->setContentsMargins(0, 0, 0, 0);
        label_62 = new QLabel(layoutWidget_49);
        label_62->setObjectName(QStringLiteral("label_62"));

        horizontalLayout_65->addWidget(label_62);

        ref_3 = new QLineEdit(layoutWidget_49);
        ref_3->setObjectName(QStringLiteral("ref_3"));
        ref_3->setEnabled(true);
        ref_3->setReadOnly(true);

        horizontalLayout_65->addWidget(ref_3);

        label_63 = new QLabel(layoutWidget_49);
        label_63->setObjectName(QStringLiteral("label_63"));

        horizontalLayout_65->addWidget(label_63);

        lineEdit_title_4 = new QLineEdit(layoutWidget_49);
        lineEdit_title_4->setObjectName(QStringLiteral("lineEdit_title_4"));
        lineEdit_title_4->setEnabled(true);
        lineEdit_title_4->setReadOnly(true);

        horizontalLayout_65->addWidget(lineEdit_title_4);

        horizontalLayout_66 = new QHBoxLayout();
        horizontalLayout_66->setObjectName(QStringLiteral("horizontalLayout_66"));
        label_67 = new QLabel(layoutWidget_49);
        label_67->setObjectName(QStringLiteral("label_67"));

        horizontalLayout_66->addWidget(label_67);

        lineEdit_author_4 = new QLineEdit(layoutWidget_49);
        lineEdit_author_4->setObjectName(QStringLiteral("lineEdit_author_4"));
        lineEdit_author_4->setEnabled(true);
        lineEdit_author_4->setReadOnly(true);

        horizontalLayout_66->addWidget(lineEdit_author_4);

        label_68 = new QLabel(layoutWidget_49);
        label_68->setObjectName(QStringLiteral("label_68"));

        horizontalLayout_66->addWidget(label_68);

        lineEdit_cathegory_4 = new QLineEdit(layoutWidget_49);
        lineEdit_cathegory_4->setObjectName(QStringLiteral("lineEdit_cathegory_4"));
        lineEdit_cathegory_4->setReadOnly(true);

        horizontalLayout_66->addWidget(lineEdit_cathegory_4);


        horizontalLayout_65->addLayout(horizontalLayout_66);

        plainTextEdit_des_4 = new QPlainTextEdit(groupBox_8);
        plainTextEdit_des_4->setObjectName(QStringLiteral("plainTextEdit_des_4"));
        plainTextEdit_des_4->setGeometry(QRect(30, 120, 231, 111));
        plainTextEdit_des_4->setReadOnly(true);
        label_69 = new QLabel(groupBox_8);
        label_69->setObjectName(QStringLiteral("label_69"));
        label_69->setGeometry(QRect(10, 100, 101, 16));
        tableView_his_2 = new QTableView(groupBox_8);
        tableView_his_2->setObjectName(QStringLiteral("tableView_his_2"));
        tableView_his_2->setGeometry(QRect(10, 260, 591, 121));
        label_70 = new QLabel(groupBox_8);
        label_70->setObjectName(QStringLiteral("label_70"));
        label_70->setGeometry(QRect(20, 240, 101, 16));
        layoutWidget_53 = new QWidget(groupBox_8);
        layoutWidget_53->setObjectName(QStringLiteral("layoutWidget_53"));
        layoutWidget_53->setGeometry(QRect(10, 60, 591, 24));
        horizontalLayout_68 = new QHBoxLayout(layoutWidget_53);
        horizontalLayout_68->setObjectName(QStringLiteral("horizontalLayout_68"));
        horizontalLayout_68->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_69 = new QHBoxLayout();
        horizontalLayout_69->setObjectName(QStringLiteral("horizontalLayout_69"));
        label_71 = new QLabel(layoutWidget_53);
        label_71->setObjectName(QStringLiteral("label_71"));

        horizontalLayout_69->addWidget(label_71);

        lineEdit_nbr_copie_4 = new QLineEdit(layoutWidget_53);
        lineEdit_nbr_copie_4->setObjectName(QStringLiteral("lineEdit_nbr_copie_4"));
        lineEdit_nbr_copie_4->setReadOnly(true);

        horizontalLayout_69->addWidget(lineEdit_nbr_copie_4);


        horizontalLayout_68->addLayout(horizontalLayout_69);

        horizontalLayout_70 = new QHBoxLayout();
        horizontalLayout_70->setObjectName(QStringLiteral("horizontalLayout_70"));
        label_72 = new QLabel(layoutWidget_53);
        label_72->setObjectName(QStringLiteral("label_72"));

        horizontalLayout_70->addWidget(label_72);

        lineEdit_year_4 = new QLineEdit(layoutWidget_53);
        lineEdit_year_4->setObjectName(QStringLiteral("lineEdit_year_4"));
        lineEdit_year_4->setReadOnly(true);

        horizontalLayout_70->addWidget(lineEdit_year_4);


        horizontalLayout_68->addLayout(horizontalLayout_70);

        horizontalLayout_71 = new QHBoxLayout();
        horizontalLayout_71->setObjectName(QStringLiteral("horizontalLayout_71"));
        label_73 = new QLabel(layoutWidget_53);
        label_73->setObjectName(QStringLiteral("label_73"));

        horizontalLayout_71->addWidget(label_73);

        lineEdit_nbr_page_4 = new QLineEdit(layoutWidget_53);
        lineEdit_nbr_page_4->setObjectName(QStringLiteral("lineEdit_nbr_page_4"));
        lineEdit_nbr_page_4->setEchoMode(QLineEdit::Normal);
        lineEdit_nbr_page_4->setReadOnly(true);

        horizontalLayout_71->addWidget(lineEdit_nbr_page_4);


        horizontalLayout_68->addLayout(horizontalLayout_71);

        layoutWidget_54 = new QWidget(groupBox_8);
        layoutWidget_54->setObjectName(QStringLiteral("layoutWidget_54"));
        layoutWidget_54->setGeometry(QRect(280, 140, 316, 67));
        horizontalLayout_72 = new QHBoxLayout(layoutWidget_54);
        horizontalLayout_72->setObjectName(QStringLiteral("horizontalLayout_72"));
        horizontalLayout_72->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton_acproj_4 = new QRadioButton(layoutWidget_54);
        radioButton_acproj_4->setObjectName(QStringLiteral("radioButton_acproj_4"));
        radioButton_acproj_4->setEnabled(false);
        radioButton_acproj_4->setCheckable(true);

        verticalLayout_5->addWidget(radioButton_acproj_4);

        radioButton_book_4 = new QRadioButton(layoutWidget_54);
        radioButton_book_4->setObjectName(QStringLiteral("radioButton_book_4"));
        radioButton_book_4->setEnabled(false);
        radioButton_book_4->setCheckable(true);

        verticalLayout_5->addWidget(radioButton_book_4);

        radioButton_journal_4 = new QRadioButton(layoutWidget_54);
        radioButton_journal_4->setObjectName(QStringLiteral("radioButton_journal_4"));
        radioButton_journal_4->setEnabled(false);
        radioButton_journal_4->setCheckable(true);

        verticalLayout_5->addWidget(radioButton_journal_4);


        horizontalLayout_72->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_73 = new QHBoxLayout();
        horizontalLayout_73->setObjectName(QStringLiteral("horizontalLayout_73"));
        label_hp_sup_4 = new QLabel(layoutWidget_54);
        label_hp_sup_4->setObjectName(QStringLiteral("label_hp_sup_4"));

        horizontalLayout_73->addWidget(label_hp_sup_4);

        lineEdit_hp_sup_4 = new QLineEdit(layoutWidget_54);
        lineEdit_hp_sup_4->setObjectName(QStringLiteral("lineEdit_hp_sup_4"));
        lineEdit_hp_sup_4->setReadOnly(true);

        horizontalLayout_73->addWidget(lineEdit_hp_sup_4);


        verticalLayout_6->addLayout(horizontalLayout_73);

        horizontalLayout_74 = new QHBoxLayout();
        horizontalLayout_74->setObjectName(QStringLiteral("horizontalLayout_74"));
        label_sub_4 = new QLabel(layoutWidget_54);
        label_sub_4->setObjectName(QStringLiteral("label_sub_4"));

        horizontalLayout_74->addWidget(label_sub_4);

        lineEdit_sub_4 = new QLineEdit(layoutWidget_54);
        lineEdit_sub_4->setObjectName(QStringLiteral("lineEdit_sub_4"));
        lineEdit_sub_4->setReadOnly(true);

        horizontalLayout_74->addWidget(lineEdit_sub_4);


        verticalLayout_6->addLayout(horizontalLayout_74);


        horizontalLayout_72->addLayout(verticalLayout_6);

        pushButton_22 = new QPushButton(groupBox_8);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(190, 400, 231, 23));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(500, 0, 611, 341));
        layoutWidget_34 = new QWidget(groupBox_7);
        layoutWidget_34->setObjectName(QStringLiteral("layoutWidget_34"));
        layoutWidget_34->setGeometry(QRect(0, 20, 291, 25));
        horizontalLayout_59 = new QHBoxLayout(layoutWidget_34);
        horizontalLayout_59->setObjectName(QStringLiteral("horizontalLayout_59"));
        horizontalLayout_59->setContentsMargins(0, 0, 0, 0);
        comboBox_search_doc_2 = new QComboBox(layoutWidget_34);
        comboBox_search_doc_2->setObjectName(QStringLiteral("comboBox_search_doc_2"));

        horizontalLayout_59->addWidget(comboBox_search_doc_2);

        search_3 = new QLineEdit(layoutWidget_34);
        search_3->setObjectName(QStringLiteral("search_3"));

        horizontalLayout_59->addWidget(search_3);

        Search_doc_2 = new QPushButton(layoutWidget_34);
        Search_doc_2->setObjectName(QStringLiteral("Search_doc_2"));

        horizontalLayout_59->addWidget(Search_doc_2);

        tableView_3 = new QTableView(groupBox_7);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(10, 60, 591, 192));
        layoutWidget_48 = new QWidget(groupBox_7);
        layoutWidget_48->setObjectName(QStringLiteral("layoutWidget_48"));
        layoutWidget_48->setGeometry(QRect(30, 260, 551, 25));
        horizontalLayout_60 = new QHBoxLayout(layoutWidget_48);
        horizontalLayout_60->setObjectName(QStringLiteral("horizontalLayout_60"));
        horizontalLayout_60->setContentsMargins(0, 0, 0, 0);
        pushButton_15 = new QPushButton(layoutWidget_48);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        horizontalLayout_60->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(layoutWidget_48);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        horizontalLayout_60->addWidget(pushButton_16);

        pushButton_17 = new QPushButton(layoutWidget_48);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        horizontalLayout_60->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(groupBox_7);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(220, 290, 171, 23));
        tabWidget->addTab(tab, QString());
        pushButton = new QPushButton(UserDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 850, 141, 23));

        retranslateUi(UserDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QApplication::translate("UserDialog", "Dialog", 0));
        image_admin->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UserDialog", "Welcome", 0));
        groupBox_6->setTitle(QApplication::translate("UserDialog", "User informations :", 0));
        label_64->setText(QApplication::translate("UserDialog", "Role :", 0));
        label_66->setText(QApplication::translate("UserDialog", "ID : ", 0));
        label_65->setText(QApplication::translate("UserDialog", "Username :", 0));
        label_61->setText(QApplication::translate("UserDialog", "Email Adress :", 0));
        label_55->setText(QApplication::translate("UserDialog", "Surnoun: ", 0));
        label_56->setText(QApplication::translate("UserDialog", "Noun :", 0));
        label_60->setText(QApplication::translate("UserDialog", "CIN : ", 0));
        label_57->setText(QApplication::translate("UserDialog", "Birth date :", 0));
        label_74->setText(QApplication::translate("UserDialog", "User History : ", 0));
        label_75->setText(QApplication::translate("UserDialog", "Current loaned books : ", 0));
        label_76->setText(QApplication::translate("UserDialog", "Ref : ", 0));
        pushButton_23->setText(QApplication::translate("UserDialog", "Return book", 0));
        radioButton_admin_3->setText(QApplication::translate("UserDialog", "Admin", 0));
        radioButton_teacher_3->setText(QApplication::translate("UserDialog", "Teacher", 0));
        radioButton_student_3->setText(QApplication::translate("UserDialog", "Student", 0));
        label_58->setText(QApplication::translate("UserDialog", "Speciality :", 0));
        label_59->setText(QApplication::translate("UserDialog", "Acadamec Year :", 0));
        groupBox_8->setTitle(QApplication::translate("UserDialog", "Doc's info", 0));
        label_62->setText(QApplication::translate("UserDialog", "Ref : ", 0));
        label_63->setText(QApplication::translate("UserDialog", "Title : ", 0));
        label_67->setText(QApplication::translate("UserDialog", "Author :", 0));
        label_68->setText(QApplication::translate("UserDialog", "Category :", 0));
        label_69->setText(QApplication::translate("UserDialog", "Description : ", 0));
        label_70->setText(QApplication::translate("UserDialog", "Loan History : ", 0));
        label_71->setText(QApplication::translate("UserDialog", "Number of copies  :", 0));
        label_72->setText(QApplication::translate("UserDialog", "Publish Year :", 0));
        label_73->setText(QApplication::translate("UserDialog", "Number of pages : ", 0));
        radioButton_acproj_4->setText(QApplication::translate("UserDialog", "Academic Project", 0));
        radioButton_book_4->setText(QApplication::translate("UserDialog", "Book", 0));
        radioButton_journal_4->setText(QApplication::translate("UserDialog", "Journal", 0));
        label_hp_sup_4->setText(QApplication::translate("UserDialog", "Supervisor: ", 0));
        label_sub_4->setText(QApplication::translate("UserDialog", "Subject : ", 0));
        pushButton_22->setText(QApplication::translate("UserDialog", "Loan Book", 0));
        groupBox_7->setTitle(QApplication::translate("UserDialog", "GroupBox", 0));
        Search_doc_2->setText(QApplication::translate("UserDialog", "SEARCH", 0));
        pushButton_15->setText(QApplication::translate("UserDialog", "Load Books' Table", 0));
        pushButton_16->setText(QApplication::translate("UserDialog", "Load Journals' Table", 0));
        pushButton_17->setText(QApplication::translate("UserDialog", "Load Academic projects' Table", 0));
        pushButton_18->setText(QApplication::translate("UserDialog", "Load Table", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserDialog", "Profil", 0));
        pushButton->setText(QApplication::translate("UserDialog", "Log out", 0));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
