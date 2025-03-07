#ifndef STUDENT_H
#define STUDENT_H
#include "account.h"
class student:public account
{
    QString classe;
    QString speciality;
public:
    student(int,QString,QString,QString,QString,QString,QString,QString,QString,int,QString,QString,QString,QString,QString);
    ~student();
    QString get_speciality();
    QString get_classe();
    void set_speciality(QString);
    void set_classe(QString);
};

#endif // STUDENT_H
