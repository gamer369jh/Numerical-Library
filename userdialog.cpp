#include "userdialog.h"
#include "ui_userdialog.h"
#include "signupdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QDateTime>
#include <QList>


UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    QPixmap pic("./WELECOME.png");
    int w= ui->image_admin->width();
    int h= ui->image_admin->height();
    ui->image_admin->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    ui->comboBox_search_doc_2->addItem("REFERENCE");
    ui->comboBox_search_doc_2->addItem("TITLE");
    ui->comboBox_search_doc_2->addItem("CATEGORY");
    ui->comboBox_search_doc_2->addItem("PUBLISH YEAR");
    ui->comboBox_search_doc_2->addItem("AUTHOR");
    ui->comboBox_search_doc_2->addItem("TYPE");
    ui->lineEdit_sub_4->hide();
    ui->lineEdit_hp_sup_4->hide();
    ui->label_hp_sup_4->hide();
    ui->label_sub_4->hide();
    ui->comboBox_EDIT_2->addItem("1st Year");
     ui->comboBox_EDIT_2->addItem("2nd Year");
    ui->comboBox_EDIT_2->addItem("3rd Year");
    ui->lineEdit_spe_3->hide();
    ui->label_59->hide();
    ui->label_58->hide();
    ui->comboBox_EDIT_2->hide();
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::on_Search_doc_2_clicked()
{
    QString search=ui->search_3->text();


    if(ui->comboBox_search_doc_2->currentText()=="REFERENCE")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where ref= '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where ref = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc_2->currentText()=="TITLE")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where title= '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where title = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc_2->currentText()=="CATEGORY")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where category = '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where category = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc_2->currentText()=="PUBLISH YEAR")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where year = '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where year = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc_2->currentText()=="AUTHOR")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where author = '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where author = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc_2->currentText()=="TYPE")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from docs where type = '"+ search+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"Search result","No match for your search result");
        else
        {


            QSqlQueryModel * model=new QSqlQueryModel();
            open_database();
            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where type = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_3->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
}

void UserDialog::on_pushButton_18_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_3->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void UserDialog::on_pushButton_15_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,pub_house from docs where type='book' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_3->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void UserDialog::on_pushButton_16_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,pub_house from docs where type='journal' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_3->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void UserDialog::on_pushButton_17_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,supervisor,subject from docs where type='academic project'");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_3->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void UserDialog::on_tableView_3_activated(const QModelIndex &index)
{
    QString user_info =ui->tableView_3->model()->data(index).toString();
    open_database();
    QSqlQuery cur(db);


    cur.prepare("select * from docs where ref = '"+user_info +"' or title = '"+ user_info+"'or author= '"+user_info+"' or number_of_copies = '"+user_info+"' or number_of_pages = '"+user_info+"'or category= '"+user_info+"'or description= '"+user_info+"' or year='"+user_info+"' or type='"+user_info+"'or maximum_rent_time ='"+user_info+"'");
    if(cur.exec())
    {
      while(cur.next())
      {

          ui->ref_3->setText(cur.value(0).toString());



          ui->lineEdit_title_4->setText(cur.value(2).toString());


          ui->lineEdit_author_4->setText(cur.value(3).toString());



          ui->lineEdit_nbr_copie_4->setText(cur.value(4).toString());



          ui->lineEdit_cathegory_4->setText(cur.value(5).toString());




          ui->lineEdit_nbr_page_4->setText(cur.value(7).toString());






          ui->lineEdit_year_4->setText(cur.value(8).toString());





          ui->plainTextEdit_des_4->document()->setPlainText(cur.value(6).toString());


         QStringList history=cur.value(9).toString().split(';');



          QString con="";

          con=history.join("' OR ID ='");
          con="ID = '"+con+"'";
          if(history.size()>0)
          {
              QSqlQueryModel * model=new QSqlQueryModel();

              QSqlQuery * cur=new QSqlQuery(db) ;
              cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where "+con);
              cur->exec();
              model->setQuery(*cur);
              ui->tableView_his_2->setModel(model);

              qDebug() <<(model->rowCount());
              qDebug() << con;

          }



          QString doc_type=cur.value(1).toString();
          if(doc_type=="book")
          {



              ui->radioButton_book_4->setChecked(true);
              ui->label_sub_4->hide();
              ui->label_hp_sup_4->show();
              ui->lineEdit_hp_sup_4->setText(cur.value(12).toString());
              ui->label_hp_sup_4->setText("House of publish");
              ui->lineEdit_hp_sup_4->show();
              ui->lineEdit_sub_4->hide();

          }


          if(doc_type=="journal")
          {



              ui->radioButton_journal_4->setChecked(true);
              ui->label_sub_4->hide();
              ui->label_hp_sup_4->show();
              ui->label_hp_sup_4->setText("House of publish");
              ui->lineEdit_hp_sup_4->setText(cur.value(12).toString());
              ui->lineEdit_hp_sup_4->show();
              ui->lineEdit_sub_4->hide();
          }

          if(doc_type=="academic project")
          {



              ui->radioButton_acproj_4->setChecked(true);
              ui->label_sub_4->show();
              ui->label_hp_sup_4->show();
              ui->lineEdit_hp_sup_4->setText(cur.value(13).toString());
              ui->label_hp_sup_4->setText("Supervisor");
              ui->lineEdit_hp_sup_4->show();
              ui->lineEdit_sub_4->show();
              ui->lineEdit_sub_4->setText(cur.value(14).toString());
          }

      }


    }
    cur.clear();
    close_database();
}


void UserDialog::initialize()
{

        open_database();
        QSqlQuery cur(db);

        cur.prepare("select * from users where login = '"+current_username+"'");
        if(cur.exec())
        {
          while(cur.next())
          {
              ui->ID_2->setText(cur.value(0).toString());
              ui->lineEdit_username_3->setText(cur.value(1).toString());

              ui->lineEdit_cin_3->setText(cur.value(4).toString());
              ui->lineEdit_noun_3->setText(cur.value(6).toString());
              ui->lineEdit_surnoun_3->setText(cur.value(7).toString());
              ui->lineEdit_email_3->setText(cur.value(8).toString());
              QStringList history=cur.value(14).toString().split(';');
              QStringList history1=cur.value(13).toString().split(';');


               QString con="";

               con=history.join("' OR ref ='");
               con="ref = '"+con+"'";
               if(history.size()>0)
               {
                   QSqlQueryModel * model=new QSqlQueryModel();

                   QSqlQuery * cur=new QSqlQuery(db) ;
                   cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where "+con);
                   cur->exec();
                   model->setQuery(*cur);
                   ui->tableView_his_3->setModel(model);

                   qDebug() <<(model->rowCount());
                   qDebug() << con;

               }
               QString con1="";

               con1=history1.join("' OR ref ='");
               con1="ref = '"+con1+"'";
               if(history1.size()>0)
               {
                   QSqlQueryModel * model=new QSqlQueryModel();

                   QSqlQuery * cur=new QSqlQuery(db) ;
                   cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where "+con1);
                   cur->exec();
                   model->setQuery(*cur);
                   ui->tableView_his_4->setModel(model);

                   qDebug() <<(model->rowCount());
                   qDebug() << con1;

               }

              QString date_string_on_db = cur.value(5).toString();
              QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");
              ui->date_3->setDate(Date);
              QString acyear;
              QString user_role=cur.value(3).toString();
              if(user_role=="admin")
              {
                  ui->radioButton_admin_3->setChecked(true);
                  ui->lineEdit_spe_3->hide();
                  ui->comboBox_EDIT_2->hide();
                  ui->label_59->hide();
                  ui->label_58->hide();
              }


              if(user_role=="teacher")
              {
                  ui->radioButton_teacher_3->setChecked(true);
                  ui->lineEdit_spe_3->setText(cur.value(10).toString());
                  ui->lineEdit_spe_3->show();
                  ui->comboBox_EDIT_2->hide();
                  ui->label_59->hide();
                  ui->label_58->show();
              }

              if(user_role=="student")
              {
                  ui->radioButton_student_3->setChecked(true);
                  ui->lineEdit_spe_3->setText(cur.value(10).toString());
                  ui->lineEdit_spe_3->show();
                  ui->comboBox_EDIT_2->show();
                  ui->label_59->show();
                  ui->label_58->show();
                  acyear=cur.value(9).toString();
                  if(acyear=="1st Year")
                    ui->comboBox_EDIT_2->setCurrentIndex(0);
                  if(acyear=="2nd Year")
                    ui->comboBox_EDIT_2->setCurrentIndex(1);
                  if(acyear=="3rd Year")
                    ui->comboBox_EDIT_2->setCurrentIndex(2);
              }

          }


        }
        cur.clear();
        close_database();

}

void UserDialog::on_tableView_his_4_activated(const QModelIndex &index)
{
    QString user_info =ui->tableView_his_4->model()->data(index).toString();
    open_database();
    QSqlQuery cur(db);


    cur.prepare("select * from docs where ref = '"+user_info +"' or title = '"+ user_info+"'or author= '"+user_info+"' or number_of_copies = '"+user_info+"' or number_of_pages = '"+user_info+"'or category= '"+user_info+"'or description= '"+user_info+"' or year='"+user_info+"' or type='"+user_info+"'or maximum_rent_time ='"+user_info+"'");
    if(cur.exec())
    {
      while(cur.next())
      {

          ui->ref_4->setText(cur.value(0).toString());
       }
    }
    cur.clear();
    close_database();
}

void UserDialog::on_pushButton_23_clicked()
{
    QString ref=ui->ref_4->text();
    qDebug()<<ref;
    if(ref=="")
        QMessageBox::warning(this,"Return Document","Please select a document");
    else
    {
        open_database();
        QSqlQuery cur(db);
        cur.prepare("select loaned_doc from users where Login ='"+current_username+"'");
        cur.exec();
        QString newel;
        while(cur.next())
        {
            QStringList history2=(cur.value(0).toString()).split(';');
            history2.removeAll(ref);
            newel=history2.join(';');
            qDebug() <<"yes"<<newel;
        }

        cur.clear();

        open_database();
        QSqlQuery cur1(db);
        cur1.prepare("update users set loaned_doc ='"+newel+"' where Login ='"+current_username+"'");
        cur1.exec();
        cur1.clear();
        close_database();
        open_database();
        QSqlQuery cur2(db);
        cur2.prepare("select * from docs where ref ='"+ref+"'");
        cur2.exec();
        QString newnum;
        while(cur2.next())
        {
            qDebug()<<cur2.value(4).toString();
            newnum=QString::number(cur2.value(4).toInt()+1);
            qDebug() <<newnum;
            qDebug() <<ref;
        }
        cur2.clear();
        close_database();
        open_database();
        QSqlQuery cur3(db);
        cur3.prepare("update docs set number_of_copies ='"+newnum+"'where ref= '"+ref+"'");
        cur3.exec();
        cur3.clear();
        close_database();


        open_database();

        QSqlQuery cur4(db);
        cur4.prepare("select * from users where login = '"+current_username+"'");
        cur4.exec();
        QStringList history1;
        QString con1;
        while(cur4.next())
        {
            history1=cur4.value(13).toString().split(';');
            con1="";

            con1=history1.join("' OR ref ='");
            con1="ref = '"+con1+"'";
        }

        if(history1.size()>0)
        {
            QSqlQueryModel * model=new QSqlQueryModel();

            QSqlQuery * cur=new QSqlQuery(db) ;
            cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs where "+con1);
            cur->exec();
            model->setQuery(*cur);
            ui->tableView_his_4->setModel(model);

            qDebug() <<(model->rowCount());
            qDebug() << con1;

        }
        cur4.clear();
        close_database();
        open_database();
        QSqlQuery cur21(db);
        cur21.prepare("select max_number_of_doc from users where Login ='"+current_username+"'");
        cur21.exec();
        QString newnum2;
        while(cur21.next())
        {
            qDebug()<<cur21.value(0).toString();
            newnum2=QString::number(cur21.value(0).toInt()+1);
            qDebug() <<newnum2;
            qDebug() <<ref;
        }
        cur21.clear();
        close_database();


        open_database();
        QSqlQuery cur31(db);
        cur31.prepare("update users set max_number_of_doc ='"+newnum2+"'where Login= '"+current_username+"'");
        cur31.exec();
        cur31.clear();
        close_database();

    }


}
/********************************************************************************************/

void UserDialog::on_pushButton_22_clicked()
{
    QString ref=ui->ref_3->text();
    open_database();
    QSqlQuery cur21(db);
    cur21.prepare("select * from users where Login ='"+current_username+"'");
    cur21.exec();
    while(cur21.next())
    {
    qDebug()<<(cur21.value(11).toInt());
    if((cur21.value(11).toInt())<=0)
    {
        QMessageBox::warning(this,"Loan Book","You have excited your maximum number of documents to loan");
    }
     else
        {
        QSqlQuery cur22(db);
        cur22.prepare("select * from docs where ref ='"+ref+"'");
        cur22.exec();
        while(cur22.next())
        {
            qDebug()<<(cur22.value(4).toInt());
            if((cur22.value(4).toInt())<=0)
            {
                QMessageBox::warning(this,"Loan Book","Sorry no more available copies right now");
            }
            else
            {
                QSqlQuery cur23(db);
                cur23.prepare("select * from users where Login ='"+current_username+"'");
                cur23.exec();
                while(cur23.next())
                {
                    QString current_loaned_docs=cur23.value(13).toString();

                    if(current_loaned_docs.contains(ref))
                    {
                        QMessageBox::warning(this,"Loan Book","this Document is currently on your  posession");
                    }
                    else
                    {
                        //open_database();
                        QSqlQuery cur0(db);
                        cur0.prepare("select ID from users where Login ='"+current_username+"'");
                        cur0.exec();
                        QString id;
                        while(cur0.next())
                        {
                           id=cur0.value(0).toString();
                            qDebug()<<id;
                        }

                        cur0.clear();
                        //close_database();

                        qDebug()<<ref;
                        //open_database();
                        QSqlQuery cur(db);
                        cur.prepare("select loaned_doc from users where Login ='"+current_username+"'");
                        cur.exec();
                        QString newel;
                        while(cur.next())
                        {
                            QStringList history2=(cur.value(0).toString()).split(';');
                            history2.append(ref);
                            newel=history2.join(';');
                            qDebug() <<"yes"<<newel;
                        }

                        cur.clear();
                        //close_database();
                        //open_database();
                        QSqlQuery cur1(db);
                        cur1.prepare("update users set loaned_doc ='"+newel+"' where Login ='"+current_username+"'");
                        cur1.exec();
                        cur1.clear();
                        //close_database();
                       // open_database();
                        QSqlQuery cur2(db);
                        cur2.prepare("select * from docs where ref ='"+ref+"'");
                        cur2.exec();
                        QString newnum;
                        while(cur2.next())
                        {
                            qDebug()<<cur2.value(4).toString();
                            newnum=QString::number(cur2.value(4).toInt()-1);
                            qDebug() <<newnum;
                            qDebug() <<ref;
                        }
                        cur2.clear();
                        //close_database();


                        //open_database();
                        QSqlQuery cur3(db);
                        cur3.prepare("update docs set number_of_copies ='"+newnum+"'where ref= '"+ref+"'");
                        cur3.exec();
                        cur3.clear();
                        //close_database();



                        /***doc loan_history**/

                        //open_database();
                        QSqlQuery cur5(db);
                        cur5.prepare("select * from docs where ref = '"+ref+"'");
                        cur5.exec();
                        QStringList history5;
                        QString con5;
                        while(cur5.next())
                        {
                            history5=cur5.value(9).toString().split(';');
                            history5.append(id);
                            con5=history5.join(';');
                        }
                        cur5.clear();
                        //close_database();

                        //open_database();
                        QSqlQuery cur7(db);
                        cur7.prepare("update docs set loan_history ='"+con5+"'where ref= '"+ref+"'");
                        cur7.exec();
                        cur7.clear();
                        //close_database();




                        /***user loan_history**/




                        //open_database();
                        QSqlQuery cur8(db);
                        cur8.prepare("select * from users where Login = '"+current_username+"'");
                        cur8.exec();
                        QStringList history8;
                        QString con8;
                        while(cur8.next())
                        {
                            history8=cur8.value(14).toString().split(';');
                            history8.append(ref);
                            con8=history8.join(';');
                        }
                        cur8.clear();
                        //close_database();

                        //open_database();
                        QSqlQuery cur9(db);
                        cur9.prepare("update users set loan_history ='"+con8+"'where Login= '"+current_username+"'");
                        cur9.exec();
                        cur9.clear();
                        //close_database();

                        //open_database();
                        QSqlQuery cur24(db);
                        cur24.prepare("select max_number_of_doc from users where Login ='"+current_username+"'");
                        cur24.exec();
                        QString newnum2;
                        while(cur24.next())
                        {
                            qDebug()<<cur24.value(0).toString();
                            newnum2=QString::number(cur24.value(0).toInt()-1);
                            qDebug() <<newnum2;
                            qDebug() <<ref;
                        }
                        cur24.clear();
                        //close_database();


                        //open_database();
                        QSqlQuery cur31(db);
                        cur31.prepare("update users set max_number_of_doc ='"+newnum2+"'where Login= '"+current_username+"'");
                        cur31.exec();
                        cur31.clear();
                        //close_database();



                    }
                }
                cur23.clear();

            }

     }
        cur22.clear();
    }


        }
    cur21.clear();
    close_database();

    initialize();

}

void UserDialog::on_pushButton_clicked()
{

        hide();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        QDateTime current_dt=QDateTime::currentDateTime();
        QString cdt=current_dt.toString("dd/MM/yyyy HH:mm:ss");
        open_database();
        QSqlQuery cur(db);
        cur.prepare("update users set last_login_time ='"+cdt+"' where Login ='"+current_username+"'");
        cur.exec();
        cur.clear();
        close_database();



}
