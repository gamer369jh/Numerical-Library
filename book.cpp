#include "book.h"

book::book(QString r, QString t, QString ti, QString au, QString ca , QString des, int nc, int np , int y , QString av, QString mrt, QString lh,QString ph):documents(r,t,ti,au,ca,des,nc,np,y,av,mrt,lh)
{
    pub_house=ph;
}

book::~book()
{

}
QString book::get_pub_house()
{
    return pub_house;
}

void book::set_pub_house(QString x)
{
    pub_house=x;
}
