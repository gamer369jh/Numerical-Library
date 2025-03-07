#include "student.h"

student::student(int i ,QString n,QString sn,QString un,QString pw,QString c ,QString db,QString e,QString r,int mnb,QString lh,QString ld,QString llt,QString cl,QString spe):account(i,n,sn,un,pw,c,db,e,r,mnb,lh,ld,llt)
{
    classe=cl;
    speciality=spe;
}
student::~student()
{

}

QString student::get_speciality()
{
    return speciality;
}

QString student::get_classe()
{
    return classe;
}

void student::set_speciality(QString x)
{
    speciality=x;
}

void student::set_classe(QString x)
{
    classe=x;
}
