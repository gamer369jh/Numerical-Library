#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "documents.h"
#include <QVector>

class account
{
private:
    int id;
    QString username;
    QString password;
    QString date_of_birth;
    QString noun;
    QString surnoun;
    QString email;
    QString cin;
    QString role;
    QString last_login_time;
    int max_number_of_book;
   QString loan_history;
   QString loaned_documents;

public:
    account(int,QString,QString,QString,QString,QString,QString,QString,QString,int,QString,QString,QString);
    ~account();
    QString get_loan_history();
    QString get_loaned_documents();
    int get_max_number_of_book();
    int get_id();
    QString get_role();
    QString get_username();
    QString get_password();
    QString get_date();
    QString get_noun();
    QString get_surnoun();
    QString get_email();
    QString get_cin();
    QString get_last_login_time();

    void set_loan_history(QString);
    void set_loaned_documents(QString);
    void set_max_number_of_book(int);
    void set_id(int);
    void set_role(QString);
    void set_username(QString );
    void set_password(QString);
    void set_date(QString);
    void set_noun(QString);
    void set_surnoun(QString);
    void set_email(QString);
    void set_cin(QString);
    void set_last_login_time( QString);






};

#endif // ACCOUNT_H
