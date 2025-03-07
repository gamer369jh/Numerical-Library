#ifndef JOURNAL_H
#define JOURNAL_H
#include "documents.h"
class journal:public documents
{
    QString pub_housej;
public:
    journal(QString,QString,QString,QString,QString,QString,int,int,int,QString,QString,QString,QString);
    ~journal();
    QString get_pub_house();
    void set_pub_house(QString);
};

#endif // JOURNAL_H
