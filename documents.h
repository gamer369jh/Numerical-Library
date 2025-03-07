#ifndef DOCUMENTS_H
#define DOCUMENTS_H
#include <QString>
#include "account.h"

class documents
{
private:
    QString type;
    QString title;
    QString Author;
    int number_of_copies;
    QString category;
    QString description;
    int number_of_pages;
    int year;
    QString loan_history;
    QString ref;
    QString availbility;
    QString Maximum_rent_time;
public:
    documents(QString,QString,QString,QString,QString,QString,int,int,int,QString,QString,QString);
    ~documents();
    bool operator ==(const documents&c);
    bool operator !=(const documents&c);


    QString get_type();
    QString  get_title();
    QString  get_author();
    int get_number_of_copies();
    QString  get_category();
    QString  get_description();
    int get_number_of_pages();
    int get_year();
    QString  get_loan_history();
    QString  get_ref();
    QString  get_availibility();
    QString  get_maximum_rent_time();


     void set_type(QString);
      void set_title(QString);
      void set_author(QString);
     void set_number_of_copies(int);
      void set_category(QString);
      void set_description(QString);
     void set_number_of_pages(int);
     void set_year(int);
      void set_loan_history(QString);
     void  set_ref(QString);
     void  set_availibility(QString);
    void  set_maximum_rent_time(QString );



};

#endif // DOCUMENTS_H
