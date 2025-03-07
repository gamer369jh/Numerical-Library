#ifndef GESTDIALOG_H
#define GESTDIALOG_H

#include <QDialog>
#include "signupdialog.h"
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDialog>
namespace Ui {
class GestDialog;
}

class GestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GestDialog(QWidget *parent = 0);
    ~GestDialog();
    QSqlDatabase db;
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
    void on_Search_doc_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_Signup_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::GestDialog *ui;
    SignupDialog *signupdialog;
};

#endif // GESTDIALOG_H
