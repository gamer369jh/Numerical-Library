#ifndef LIBRARY_H
#define LIBRARY_H
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QDialog>
#include "documents.h"
#include "academicproj.h"
#include "journal.h"
#include "book.h"
#include "account.h"
#include "admin.h"
#include "student.h"
#include "teacher.h"
#include <QVector>
class library
{
public:
    library();


    ~library()
    {

    }

    QVector<documents *> liste_doc;
    QVector<account *> liste_users;

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

    void upload_data_in_lists();
    library& operator=(const library &n);


};

#endif // LIBRARY_H
