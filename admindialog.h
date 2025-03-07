#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDialog>
#include "library.h"
namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = 0);
    ~AdminDialog();
public:
    QString current_username;
    library lib;
    QSqlDatabase db;
    void initialize();
    void close_database()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool open_database()
    {
        db =QSqlDatabase::addDatabase("QSQLITE") ;
        db.setDatabaseName("./utilisateur3.db");
        if(db.open()==false)
        {
            qDebug()<<("Failed to open database");
            return false;
        }
        else
        {
            qDebug()<<("Connected Successfully to the database");
            return true;
        }
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_DELETE_clicked();

    void on_EDIT_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_ADD_clicked();

    void on_radioButton_admin_2_clicked();

    void on_radioButton_teacher_2_clicked();

    void on_radioButton_student_2_clicked();

    void on_radioButton_admin_clicked();

    void on_radioButton_teacher_clicked();

    void on_radioButton_student_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();



    void on_EDIT_3_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_radioButton_acproj_2_clicked();

    void on_radioButton_book_2_clicked();

    void on_radioButton_journal_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_EDIT_2_clicked();

    void on_Search_doc_clicked();

    void on_DELETE_2_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_Search_doc_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_tableView_3_activated(const QModelIndex &index);



    void on_tableView_his_4_activated(const QModelIndex &index);

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::AdminDialog *ui;


};

#endif // ADMINDIALOG_H
