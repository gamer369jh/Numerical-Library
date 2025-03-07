#include "library.h"

library::library()
{
}

void library::upload_data_in_lists()
{

    open_database();
    QSqlQuery cur(db);
    cur.prepare("select * from users");
    cur.exec();
    while(cur.next())
    {
        if(cur.value(3).toString()=="admin")
        {

            admin *a=new admin(cur.value(0).toInt(),cur.value(6).toString(),cur.value(7).toString(),cur.value(1).toString(),cur.value(2).toString(),cur.value(4).toString(),cur.value(5).toString(),cur.value(8).toString(),cur.value(3).toString(),cur.value(11).toInt(),cur.value(14).toString(),cur.value(13).toString(),cur.value(12).toString());
            liste_users.push_back(a);
        }
        if(cur.value(3).toString()=="student")
        {

            student *a=new student(cur.value(0).toInt(),cur.value(6).toString(),cur.value(7).toString(),cur.value(1).toString(),cur.value(2).toString(),cur.value(4).toString(),cur.value(5).toString(),cur.value(8).toString(),cur.value(3).toString(),cur.value(11).toInt(),cur.value(14).toString(),cur.value(13).toString(),cur.value(12).toString(),cur.value(9).toString(),cur.value(10).toString());
            liste_users.push_back(a);
        }
        if(cur.value(3).toString()=="teacher")
        {

            teacher *a=new teacher(cur.value(0).toInt(),cur.value(6).toString(),cur.value(7).toString(),cur.value(1).toString(),cur.value(2).toString(),cur.value(4).toString(),cur.value(5).toString(),cur.value(8).toString(),cur.value(3).toString(),cur.value(11).toInt(),cur.value(14).toString(),cur.value(13).toString(),cur.value(12).toString(),cur.value(10).toString());
            liste_users.push_back(a);
        }
    }
    cur.clear();
    close_database();

    open_database();
    QSqlQuery cur1(db);
    cur1.prepare("select * from docs");
    cur1.exec();
    while(cur1.next())
    {
        if(cur1.value(1).toString()=="book")
        {


            book *a=new book(cur1.value(0).toString(),cur1.value(1).toString(),cur1.value(2).toString(),cur1.value(3).toString(),cur1.value(5).toString(),cur1.value(6).toString(),cur1.value(4).toInt(),cur1.value(7).toInt(),cur1.value(8).toInt(),cur1.value(10).toString(),cur1.value(11).toString(),cur1.value(9).toString(),cur1.value(12).toString());
            liste_doc.push_back(a);
        }
        if(cur1.value(1).toString()=="journal")
        {

           journal *a=new journal(cur1.value(0).toString(),cur1.value(1).toString(),cur1.value(2).toString(),cur1.value(3).toString(),cur1.value(5).toString(),cur1.value(6).toString(),cur1.value(4).toInt(),cur1.value(7).toInt(),cur1.value(8).toInt(),cur1.value(10).toString(),cur1.value(11).toString(),cur1.value(9).toString(),cur1.value(12).toString());
            liste_doc.push_back(a);
        }
        if(cur1.value(1).toString()=="academic project")
        {

            academicproj *a=new academicproj(cur1.value(0).toString(),cur1.value(1).toString(),cur1.value(2).toString(),cur1.value(3).toString(),cur1.value(5).toString(),cur1.value(6).toString(),cur1.value(4).toInt(),cur1.value(7).toInt(),cur1.value(8).toInt(),cur1.value(10).toString(),cur1.value(11).toString(),cur1.value(9).toString(),cur1.value(13).toString(),cur1.value(14).toString());
            liste_doc.push_back(a);
        }
    }
    cur1.clear();
    close_database();
}
library& library::operator=(const library &n)
{
    this->liste_doc=n.liste_doc;
    this->liste_users=n.liste_users;
    return(*this);
}
