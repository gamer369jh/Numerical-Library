#ifndef ACADEMICPROJ_H
#define ACADEMICPROJ_H
#include "documents.h"
class academicproj: public documents
{
    QString subject;
    QString supervisor;
public:
    academicproj(QString,QString,QString,QString,QString,QString,int,int,int,QString,QString,QString,QString,QString);
    ~academicproj();
    QString get_subject();
    QString  get_supervisor();
    void set_subject(QString);
    void  set_supervisor(QString);
};

#endif // ACADEMICPROJ_H
