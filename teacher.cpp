#include "teacher.h"

teacher::teacher(int i ,QString n,QString sn,QString un,QString pw,QString c ,QString db,QString e,QString r,int mnb,QString lh,QString ld,QString llt,QString spe):account(i,n,sn,un,pw,c,db,e,r,mnb,lh,ld,llt)
{
    speciality=spe;
}
teacher::~teacher()
{

}

QString teacher::get_speciality()
{
    return speciality;
}

void teacher::set_speciality(QString x)
{
    speciality=x;
}
