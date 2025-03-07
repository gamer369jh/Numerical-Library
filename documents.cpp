#include "documents.h"

documents::documents(QString r, QString t, QString ti, QString au, QString ca , QString des, int nc, int np , int y , QString av, QString mrt, QString lh)
{
    type=t;
    title=ti;
    Author=au;
    number_of_copies=nc;
    category =ca;
    description=des;
    number_of_pages=np;
    year =y;
    ref =r;
    availbility=av;
    Maximum_rent_time=mrt;
    loan_history=lh;
}
documents::~documents()
{

}

bool documents::operator ==(const documents&c)
{
    return(this->ref==c.ref);
}
bool documents::operator !=(const documents&c)
{
    return(this->ref!=c.ref);
}
QString documents::get_type()
{
    return type;
}

QString  documents::get_title()
{
    return title;
}

QString  documents::get_author()
{
    return Author;
}

int documents::get_number_of_copies()
{
    return number_of_copies;
}

QString  documents::get_category()
{
    return category;
}

QString  documents::get_description()
{
    return description;
}

int documents::get_number_of_pages()
{
    return number_of_pages;
}

int documents::get_year()
{
    return year;
}

QString  documents::get_loan_history()
{
    return loan_history;
}

QString  documents::get_ref()
{
    return ref;
}

QString  documents::get_availibility()
{
    return availbility;
}

QString  documents::get_maximum_rent_time()
{
    return Maximum_rent_time;
}


 void documents::set_type(QString x)
 {
     type=x;
 }
  void documents::set_title(QString x)
  {
      title=x;
  }

  void documents::set_author(QString x)
  {
      Author=x;
  }

 void documents::set_number_of_copies(int x)
 {
     number_of_copies=x;
 }
  void documents::set_category(QString x)
  {
      category=x;
  }

  void documents::set_description(QString x)
  {
      description =x;
  }

 void documents::set_number_of_pages(int x)
 {
     number_of_pages=x;
 }

 void documents::set_year(int x)
 {
     year=x;
 }
  void documents::set_loan_history(QString x)
  {
      loan_history=x;
  }

 void  documents::set_ref(QString x)
 {
     ref=x;
 }

 void  documents::set_availibility(QString x)
 {
     availbility=x;
 }

void  documents::set_maximum_rent_time(QString x)
{
    Maximum_rent_time=x;
}
