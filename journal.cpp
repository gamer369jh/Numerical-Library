#include "journal.h"

journal::journal(QString r, QString t, QString ti, QString au, QString ca , QString des, int nc, int np , int y , QString av, QString mrt, QString lh,QString ph):documents(r,t,ti,au,ca,des,nc,np,y,av,mrt,lh)
{
    pub_housej=ph;
}

journal::~journal()
{

}
QString journal::get_pub_house()
{
    return pub_housej;
}

void journal::set_pub_house(QString x)
{
    pub_housej=x;
}
