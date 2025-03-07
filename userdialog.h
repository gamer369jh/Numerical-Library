#ifndef USERDIALOG_H
#define USERDIALOG_H
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDialog>
#include "library.h"

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    QString current_username;
    library lib;
public:
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
    void on_Search_doc_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_tableView_3_activated(const QModelIndex &index);



    void on_tableView_his_4_activated(const QModelIndex &index);

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
