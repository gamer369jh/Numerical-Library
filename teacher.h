#ifndef TEACHER_H
#define TEACHER_H
#include "account.h"
class teacher:public account
{
    QString speciality;
public:
    teacher(int,QString,QString,QString,QString,QString,QString,QString,QString,int,QString,QString,QString,QString);
    ~teacher();
    QString get_speciality();
    void set_speciality(QString);

};

#endif // TEACHER_H
