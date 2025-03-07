#ifndef BOOK_H
#define BOOK_H
#include "documents.h"
class book:public documents
{
    QString pub_house;
public:

    book(QString,QString,QString,QString,QString,QString,int,int,int,QString,QString,QString,QString);
    ~book();
    QString get_pub_house();
    void set_pub_house(QString x);
};

#endif // BOOK_H
