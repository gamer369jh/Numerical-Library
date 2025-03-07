#include "academicproj.h"

academicproj::academicproj(QString r, QString t, QString ti, QString au, QString ca , QString des, int nc, int np , int y , QString av, QString mrt, QString lh,QString sub,QString sup):documents(r,t,ti,au,ca,des,nc,np,y,av,mrt,lh)
{
    subject=sub;
    supervisor=sup;
}
academicproj::~academicproj()
{

}
QString academicproj::get_subject()
{
    return subject;
}

QString  academicproj::get_supervisor()
{
    return supervisor;
}

void academicproj::set_subject(QString x)
{
    subject=x;
}

void  academicproj::set_supervisor(QString x)
{
    supervisor=x;
}

