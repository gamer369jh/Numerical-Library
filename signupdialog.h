#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDialog>
#include "admindialog.h"
#include "userdialog.h"
#include "library.h"

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT
public:
    library lib;
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

public:
    explicit SignupDialog(QWidget *parent = 0);
    ~SignupDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_radioButton_teacher_clicked();

    void on_radioButton_student_clicked();

private:
    Ui::SignupDialog *ui;
    AdminDialog *adminDialog;
    UserDialog  *userDialog;
};

#endif // SIGNUPDIALOG_H
