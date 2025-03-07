#include "account.h"

account::account(int i ,QString n,QString sn,QString un,QString pw,QString c ,QString db,QString e,QString r,int mnb,QString lh,QString ld,QString llt)
{
    id=i;
     username=un;
     password=pw;
     date_of_birth=db;
     noun=n;
     surnoun=sn;
    email=e;
     cin=c;
     role=r;
    last_login_time=llt;
     max_number_of_book=mnb;
   loan_history=lh;
    loaned_documents=ld;
}

account::~account()
{

}

QString account::get_loan_history()
{
    return loan_history;
}

QString account::get_loaned_documents()
{
    return loaned_documents;
}

int account::get_max_number_of_book()
{
    return max_number_of_book;
}

int account::get_id()
{
    return id;
}

QString account::get_role()
{
    return role;
}

QString account::get_username()
{
    return username;
}

QString account::get_password()
{
    return password;
}

QString account::get_date()
{
    return date_of_birth;
}

QString account::get_noun()
{
    return noun;
}

QString account::get_surnoun()
{
    return surnoun;
}

QString account::get_email()
{
    return email;
}

QString account::get_cin()
{
    return cin;
}

QString account::get_last_login_time()
{
    return last_login_time;
}

void account::set_loan_history(QString x)
{
    loan_history=x;
}

void account::set_loaned_documents(QString x)
{
    loaned_documents=x;
}
void account::set_max_number_of_book(int x)
{
    max_number_of_book=x;
}
void account::set_id(int x)
{
    id=x;
}
void account::set_role(QString x)
{
    role=x;
}
void account::set_username(QString  x)
{
    username=x;
}

void account::set_password(QString x)
{
    password=x;
}

void account::set_date(QString x)
{
    date_of_birth=x;
}

void account::set_noun(QString x)
{
    noun=x;
}

void account::set_surnoun(QString x)
{
    surnoun=x;
}

void account::set_email(QString x)
{
    email=x;
}

void account::set_cin(QString x)
{
    cin=x;
}

void account::set_last_login_time( QString x)
{
    last_login_time=x;
}
