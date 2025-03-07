#include "admindialog.h"
#include "ui_admindialog.h"
#include "signupdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QDateTime>
#include <QList>

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    QPixmap pic("./WELECOME.png");
    int w= ui->image_admin->width();
    int h= ui->image_admin->height();
    ui->image_admin->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));


   ui->comboBox_search->addItem("USERNAME");
    ui->comboBox_search->addItem("ID");
   ui->comboBox_search->addItem("ROLE");
   ui->comboBox_search->addItem("CIN");
   ui->comboBox_2->addItem("USERNAME");
    ui->comboBox_2->addItem("ID");
    ui->comboBox->addItem("1st Year");
     ui->comboBox->addItem("2nd Year");
    ui->comboBox->addItem("3rd Year");
    ui->comboBox_EDIT->addItem("1st Year");
     ui->comboBox_EDIT->addItem("2nd Year");
    ui->comboBox_EDIT->addItem("3rd Year");
    ui->comboBox_search_doc->addItem("REFERENCE");
    ui->comboBox_search_doc->addItem("TITLE");
    ui->comboBox_search_doc->addItem("CATEGORY");
    ui->comboBox_search_doc->addItem("PUBLISH YEAR");
    ui->comboBox_search_doc->addItem("AUTHOR");
    ui->comboBox_search_doc->addItem("TYPE");

    ui->comboBox->hide();
    ui->comboBox_EDIT->hide();
    ui->lineEdit_spe->hide();
    ui->lineEdit_spe_2->hide();
    ui->label_9->hide();
    ui->label_8->hide();
    ui->label_19->hide();
    ui->label_18->hide();
    ui->label_sub->hide();
    ui->label_sub_2->hide();
    ui->label_sub_3->hide();
    ui->label_hp_sup->hide();
    ui->label_hp_sup_2->hide();
    ui->label_hp_sup_3->hide();
    ui->lineEdit_hp_sup->hide();
    ui->lineEdit_hp_sup_2->hide();
    ui->lineEdit_hp_sup_3->hide();
    ui->lineEdit_sub->hide();
    ui->lineEdit_sub_2->hide();
    ui->lineEdit_sub_3->hide();
    /*****************profil*********************/
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

    ui->comboBox_EDIT_3->addItem("1st Year");
     ui->comboBox_EDIT_3->addItem("2nd Year");
    ui->comboBox_EDIT_3->addItem("3rd Year");
    ui->lineEdit_spe_4->hide();
    ui->label_89->hide();
    ui->label_88->hide();
    ui->comboBox_EDIT_3->hide();

}

AdminDialog::~AdminDialog()
{
    delete ui;

}
bool string_is_didgit(QString cin)
{
    bool k=true;
    for (int i =0;i<cin.length();i++)
    {
        if (! cin[i].isDigit())
        {
            k=false;

        }
    }
    return k;
}
bool string_is_alpha(QString cin)
{
    bool k=true;
    for (int i =0;i<cin.length();i++)
    {
        if (! (cin[i].isLetter()||cin[i]==' '))
        {
            k=false;

        }
    }
    return k;
}

bool isChar_a(QChar ch)
{
    return ((ch >= 'a' && ch <= 'z')
            || (ch >= 'A' && ch <= 'Z'));
}


bool isDigit_a(const QChar ch)
{
    return (ch >= '0' && ch <= '9');
}


bool is_valid_a(QString email)
{

    if (!isChar_a(email[0])) {


        return 0;
    }
    int At = -1, Dot = -1;

    for (int i = 0;i < email.length(); i++)
    {

        if (email[i] == '@')
        {

            At = i;
        }

        else if (email[i] == '.')
        {

            Dot = i;
        }
    }

    if (At == -1 || Dot == -1)
        return false;

    if (At >= Dot)
        return false;
    return !(Dot >= (email.length() - 1));
}


void AdminDialog::on_pushButton_clicked()
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
    ui->lineEdit_hp_sup_4->hide();

}

void AdminDialog::on_pushButton_2_clicked()
{
    QString search=ui->search->text();


    if(ui->comboBox_search->currentText()=="USERNAME")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from users where Login = '"+ search+"'");
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
            cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where Login = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search->currentText()=="ROLE")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from users where Role = '"+ search+"'");
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
            cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where Role = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search->currentText()=="CIN")
    {
        int exist=0;


        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from users where CIN = '"+ search+"'");
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
            cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where CIN = '"+ search+"'");
            cur->exec();
            model->setQuery(*cur);
            ui->tableView->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search->currentText()=="ID")
    {
        bool k=true;
        for (int i =0;i<search.length();i++)
        {
            if (! search[i].isDigit())
            {
                k=false;

            }
        }

        if(k==false)
            QMessageBox::warning(this,"Search result","ID must contain only ditgits ");
        else
        {
            int exist=0;


            open_database();
            QSqlQuery cur(db);
            cur.prepare("select * from users where ID = '"+ search+"'");
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
                cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where ID = '"+ search+"'");
                cur->exec();
                model->setQuery(*cur);
                ui->tableView->setModel(model);
                close_database();
                qDebug() <<(model->rowCount());
            }
        }

    }
}

void AdminDialog::on_DELETE_clicked()
{
    QString d=ui->delete_2->text();



    if(ui->comboBox_2->currentText()=="USERNAME")
    {
        int exist=0;
        open_database();
        QSqlQuery cur(db);
        cur.prepare("select * from users where Login = '"+ d+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        close_database();
        if(exist==0)
            QMessageBox::warning(this,"DELETE","No account match this username");
        else
        {
            if(d==current_username)
            {
                QMessageBox::warning(this,"DELETE","You are trying to delete the current account you are using");
            }
            else
            {
                open_database();
                QSqlQuery del(db);
                del.prepare("DELETE from users where Login = '"+ d+"'");
                del.exec();
                del.clear();
                close_database();
                QMessageBox::information(this,"DELETE","Account deleted successfully");
                 ui->delete_2->setText("");
                 QSqlQueryModel * model=new QSqlQueryModel();
                 open_database();
                 QSqlQuery * cur=new QSqlQuery(db) ;
                 cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users ");
                 cur->exec();
                 model->setQuery(*cur);
                 ui->tableView->setModel(model);
                 close_database();
                 qDebug() <<(model->rowCount());
            }

        }
    }
    if(ui->comboBox_2->currentText()=="ID")
    {
        bool k=true;
        for (int i =0;i<d.length();i++)
        {
            if (! d[i].isDigit())
            {
                k=false;

            }
        }

        if(k==false)
            QMessageBox::warning(this,"DELETE","ID must contain only ditgits ");
        else
        {
            int exist=0;
            open_database();
            QSqlQuery cur(db);
            cur.prepare("select * from users where ID = '"+ d+"'");
            if(cur.exec())
            {
              while(cur.next())
                  exist++;
            }
            cur.clear();
            close_database();
            if(exist==0)
                QMessageBox::warning(this,"DELETE","No account match this ID");
            else
            {
                QString current_id;
                open_database();
                QSqlQuery cur22(db);
                cur22.prepare("select * from users where Login = '"+current_username+"'");
                cur22.exec();
                while(cur22.next())
                {
                  current_id=cur22.value(0).toString();
                }

                cur22.clear();
                close_database();
                if(d==current_id)
                {
                    QMessageBox::warning(this,"DELETE","You are trying to delete the current account you are using");
                }
                else
                {
                    open_database();
                    QSqlQuery del(db);
                    del.prepare("DELETE from users where ID = '"+ d+"'");
                    del.exec();
                    del.clear();
                    close_database();
                    QMessageBox::information(this,"DELETE","Account deleted successfully");
                    ui->delete_2->setText("");
                    QSqlQueryModel * model=new QSqlQueryModel();
                    open_database();
                    QSqlQuery * cur=new QSqlQuery(db) ;
                    cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users ");
                    cur->exec();
                    model->setQuery(*cur);
                    ui->tableView->setModel(model);
                    close_database();
                    qDebug() <<(model->rowCount());
                }

            }
        }
    }

}









void AdminDialog::on_EDIT_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    QString con_password=ui->lineEdit_password_2->text();
    QString cin=ui->lineEdit_cin->text();
    QDate d2= ui->date->date();
    QString email=ui->lineEdit_email->text();
    QString noun=ui->lineEdit_noun->text();
    QString surnoun=ui->lineEdit_surnoun->text();
    QString speciality=ui->lineEdit_spe->text();
    QString classe=ui->comboBox_EDIT->currentText();
    QString role;
    bool admin=ui->radioButton_admin->isChecked();
    bool student=ui->radioButton_student->isChecked();
    bool teacher=ui->radioButton_teacher->isChecked();
    bool p=ui->checkBox_password->isChecked();
    bool d=ui->checkBox_date->isChecked();
    bool r=ui->checkBox_role->isChecked();
    bool c=ui->checkBox_cin->isChecked();
    bool e=ui->checkBox_email->isChecked();
    bool sn=ui->checkBox_surnoun->isChecked();
    bool n=ui->checkBox_noun->isChecked();
    QString date = d2.toString("dd/MM/yyyy");
    QString max_numb_of_doc;



    int exist=0;


    open_database();
    QSqlQuery cur(db);
    cur.prepare("select * from users where Login = '"+ username+"'");
    if(cur.exec())
    {
      while(cur.next())
          exist++;
    }
    cur.clear();
    close_database();
    if(exist==0)
      QMessageBox::warning(this,"EDIT","No account match this username");
    else
    {
        if(p==true)
        {
            if(password!=con_password)
                QMessageBox::warning(this,"Sign Up","please confirm your password ");
            else
            {
              open_database();
              QSqlQuery cur(db);
              cur.prepare("update users set Password ='"+password+"' where Login ='"+username+"'");
              cur.exec();
              cur.clear();
              close_database();
            }
        }
        if(r==true)
        {
            if ((admin==false)&&(teacher==false)&&(student==false))
            {
               QMessageBox::warning(this,"EDIT","please check your role ");
            }
            else
            {
                if(admin==true)
                {
                   role="admin";
                   max_numb_of_doc="10";
                   open_database();
                   QSqlQuery cur(db);
                   cur.prepare("update users set Role ='"+role+"', speciality = NULL , class = NULL ,max_number_of_doc= '"+max_numb_of_doc+"' where Login ='"+username+"'");
                   cur.exec();
                   cur.clear();
                   close_database();

                }

                if(student==true)
                {
                    role="student";
                    max_numb_of_doc="5";
                    open_database();
                    QSqlQuery cur(db);
                    cur.prepare("update users set Role ='"+role+"', speciality='"+speciality+"' , class='"+classe+"',max_number_of_doc= '"+max_numb_of_doc+"' where Login ='"+username+"'");
                    cur.exec();
                    cur.clear();
                    close_database();

                }
                if(teacher==true)
                {
                    role="teacher";
                    max_numb_of_doc="3";
                    open_database();
                    QSqlQuery cur(db);
                    cur.prepare("update users set Role ='"+role+"', speciality='"+speciality+"' , class=NULL ,max_number_of_doc= '"+max_numb_of_doc+"' where Login ='"+username+"'");
                    cur.exec();
                    cur.clear();
                    close_database();
                }

            }
        }
        if(d==true)
        {
            open_database();
            QSqlQuery cur(db);
            cur.prepare("update users set date_of_birth ='"+date+"' where Login ='"+username+"'");
            cur.exec();
            cur.clear();
            close_database();
        }
        if(c==true)
        {

                if(cin.length()!=8)
                    QMessageBox::warning(this,"EDIT","C.I.N must contain 8 ditgits ");
                else
                {
                    bool k=true;
                    for (int i =0;i<8;i++)
                    {
                        if (! cin[i].isDigit())
                        {
                            k=false;

                        }
                    }



                        if(k==false)
                            QMessageBox::warning(this,"EDIT","C.I.N must contain only ditgits ");
                        else
                        {
                            open_database();
                            QSqlQuery cur(db);
                            cur.prepare("update users set CIN ='"+cin+"' where Login ='"+username+"'");
                            cur.exec();
                            cur.clear();
                            close_database();
                        }





                }


        }
        if(e==true)
        {


                if(is_valid_a(email)==false)
                   QMessageBox::warning(this,"EDIT","This email is not valid!!! ");
                else
                {
                    open_database();
                    QSqlQuery cur(db);
                    cur.prepare("update users set email ='"+email+"' where Login ='"+username+"'");
                    cur.exec();
                    cur.clear();
                    close_database();

                }



        }
        if(sn==true)
        {
            if(string_is_alpha(surnoun))
            {
                open_database();
                QSqlQuery cur(db);
                cur.prepare("update users set surnoun ='"+surnoun+"' where Login ='"+username+"'");
                cur.exec();
                cur.clear();
                close_database();

            }
            else
                QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");



        }
        if(n==true)
        {
            if(string_is_alpha(noun))
            {
                open_database();
                QSqlQuery cur(db);
                cur.prepare("update users set noun ='"+noun+"' where Login ='"+username+"'");
                cur.exec();
                cur.clear();
                close_database();
            }
            else
                QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");


        }
        QMessageBox::information(this,"EDIT","Account updated successfully");

   }
}











void AdminDialog::on_pushButton_3_clicked()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());

}

void AdminDialog::on_tableView_activated(const QModelIndex &index)
{
    QString user_info =ui->tableView->model()->data(index).toString();
    open_database();
    QSqlQuery cur(db);
    QString id;
    cur.prepare("select * from users where ID = '"+user_info +"' or Login = '"+ user_info+"'or Password= '"+user_info+"' or Role = '"+user_info+"' or CIN = '"+user_info+"'or date_of_birth= '"+user_info+"'or noun= '"+user_info+"' or surnoun='"+user_info+"' or email='"+user_info+"'or max_number_of_doc='"+user_info+"'or last_login_time ='"+user_info+"'");
    if(cur.exec())
    {
      while(cur.next())
      {
          ui->ID->setText(cur.value(0).toString());
          id=cur.value(0).toString();
          ui->lineEdit_username->setText(cur.value(1).toString());
          ui->lineEdit_password->setText(cur.value(2).toString());
          ui->lineEdit_cin->setText(cur.value(4).toString());
          ui->lineEdit_noun->setText(cur.value(6).toString());
          ui->lineEdit_surnoun->setText(cur.value(7).toString());
          ui->lineEdit_email->setText(cur.value(8).toString());
          QString date_string_on_db = cur.value(5).toString();
          QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");
          ui->date->setDate(Date);
          QString acyear;
          QString user_role=cur.value(3).toString();
          if(user_role=="admin")
          {
              ui->radioButton_admin->setChecked(true);
              ui->lineEdit_spe->hide();
              ui->comboBox_EDIT->hide();
              ui->label_9->hide();
              ui->label_8->hide();
          }


          if(user_role=="teacher")
          {
              ui->radioButton_teacher->setChecked(true);
              ui->lineEdit_spe->setText(cur.value(10).toString());
              ui->lineEdit_spe->show();
              ui->comboBox_EDIT->hide();
              ui->label_9->hide();
              ui->label_8->show();
          }

          if(user_role=="student")
          {
              ui->radioButton_student->setChecked(true);
              ui->lineEdit_spe->setText(cur.value(10).toString());
              ui->lineEdit_spe->show();
              ui->comboBox_EDIT->show();
              ui->label_9->show();
              ui->label_8->show();
              acyear=cur.value(9).toString();
              if(acyear=="1st Year")
                ui->comboBox_EDIT->setCurrentIndex(0);
              if(acyear=="2nd Year")
                ui->comboBox_EDIT->setCurrentIndex(1);
              if(acyear=="3rd Year")
                ui->comboBox_EDIT->setCurrentIndex(2);
          }

      }


    }
    cur.clear();
    close_database();
    ui->stackedWidget->setCurrentIndex(0);


    open_database();
    QSqlQuery cur0(db);

    cur0.prepare("select * from users where ID = '"+id+"'");
    if(cur0.exec())
    {

      while(cur0.next())
      {
          ui->ID_3->setText(cur0.value(0).toString());
          ui->lineEdit_username_4->setText(cur0.value(1).toString());

          ui->lineEdit_cin_4->setText(cur0.value(4).toString());
          ui->lineEdit_noun_4->setText(cur0.value(6).toString());
          ui->lineEdit_surnoun_4->setText(cur0.value(7).toString());
          ui->lineEdit_email_4->setText(cur0.value(8).toString());
          QStringList history=cur0.value(14).toString().split(';');
          QStringList history1=cur0.value(13).toString().split(';');


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
               ui->tableView_his_5->setModel(model);

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
               ui->tableView_his_6->setModel(model);

               qDebug() <<(model->rowCount());
               qDebug() << con1;

           }

          QString date_string_on_db = cur0.value(5).toString();
          QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");
          ui->date_4->setDate(Date);
          QString acyear;
          QString user_role=cur0.value(3).toString();
          if(user_role=="admin")
          {
              ui->radioButton_admin_4->setChecked(true);
              ui->lineEdit_spe_4->hide();
              ui->comboBox_EDIT_3->hide();
              ui->label_89->hide();
              ui->label_88->hide();
          }


          if(user_role=="teacher")
          {
              ui->radioButton_teacher_4->setChecked(true);
              ui->lineEdit_spe_4->setText(cur0.value(10).toString());
              ui->lineEdit_spe_4->show();
              ui->comboBox_EDIT_3->hide();
              ui->label_89->hide();
              ui->label_88->show();
          }

          if(user_role=="student")
          {
              ui->radioButton_student_4->setChecked(true);
              ui->lineEdit_spe_4->setText(cur0.value(10).toString());
              ui->lineEdit_spe_4->show();
              ui->comboBox_EDIT_3->show();
              ui->label_89->show();
              ui->label_88->show();
              acyear=cur0.value(9).toString();
              if(acyear=="1st Year")
                ui->comboBox_EDIT_3->setCurrentIndex(0);
              if(acyear=="2nd Year")
                ui->comboBox_EDIT_3->setCurrentIndex(1);
              if(acyear=="3rd Year")
                ui->comboBox_EDIT_3->setCurrentIndex(2);
          }

      }


    }
    cur0.clear();
    close_database();


}

void AdminDialog::on_ADD_clicked()
{
    QString username=ui->lineEdit_username_2->text();
    QString password=ui->lineEdit_password_3->text();
    QString con_password=ui->lineEdit_password_4->text();
    QString cin=ui->lineEdit_cin_2->text();
    QDate d= ui->date->date();
    QString email=ui->lineEdit_email_2->text();
    QString noun=ui->lineEdit_noun_2->text();
    QString surnoun=ui->lineEdit_surnoun_2->text();
    QString speciality=ui->lineEdit_spe_2->text();
    QString classe=ui->comboBox->currentText();
    QString role;
    QString max_numb_of_doc;
    bool teacher=ui->radioButton_teacher_2->isChecked();
    bool student=ui->radioButton_student_2->isChecked();
    bool admin=ui->radioButton_admin_2->isChecked();
    QString date = d.toString("dd/MM/yyyy");




    if ((teacher==false)&&(student==false))
    {
       QMessageBox::warning(this,"ADD Account","please check your status (Admin/Teacher/Student) ");
    }
    else
    {
        if(teacher==true)
        {
            role="teacher";

            max_numb_of_doc="3";
        }
        if(student==true)
        {
            role="student";

            max_numb_of_doc="5";

        }
        if(admin==true)
        {
            role="admin";

            max_numb_of_doc="10";
        }
        if(username==""||password==""||cin==""||email==""||noun==""||surnoun==""||speciality=="")
            QMessageBox::warning(this,"ADD Account","please complete all the form to create your account !!! ");
        else
        {


            int exist=0;
            open_database();
            QSqlQuery cur(db);
            cur.prepare("select * from users where Login = '"+ username+"'");
            if(cur.exec())
            {
              while(cur.next())
                  exist++;
            }
            cur.clear();
            close_database();
            if (exist!=0)
                QMessageBox::warning(this,"ADD Account","This username already exist!!! ");

            else
                {
                    if(is_valid_a(email)==false)
                       QMessageBox::warning(this,"ADD Account","This email is not valid!!! ");
                    else
                    {

                        if(password!=con_password)
                            QMessageBox::warning(this,"ADD Account","please confirm your password ");
                        else
                        {
                            if(cin.length()!=8)
                                QMessageBox::warning(this,"ADD Account","C.I.N must contain 8 ditgits ");
                            else
                            {
                                bool k=true;
                                for (int i =0;i<8;i++)
                                {
                                    if (! cin[i].isDigit())
                                    {
                                        k=false;

                                    }
                                }

                                if(k==false)
                                    QMessageBox::warning(this,"ADD Account","C.I.N must contain only ditgits ");


                                else
                                {
                                    if(teacher==true)
                                    {
                                        open_database();
                                        QSqlQuery cur(db);
                                        cur.prepare("insert into users (Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,speciality) values('" + username+"','" + password + "','" + role + "','" + cin + "','" + date +"','"+noun+"','"+surnoun+"','"+email+"','"+max_numb_of_doc+"','"+speciality +"' ); ");

                                        cur.exec();
                                        cur.clear();
                                        close_database();
                                        QMessageBox::information(this,"ADD Account","account registred in the data base");
                                    }
                                    if(student==true)
                                    {
                                        open_database();
                                        QSqlQuery cur(db);
                                        cur.prepare("insert into users (Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,class,speciality) values('" + username+"','" + password + "','" + role + "','" + cin + "','" + date +"','"+noun+"','"+surnoun+"','"+email+"','"+max_numb_of_doc+"','"+classe+"','"+speciality +"' ); ");

                                        cur.exec();
                                        cur.clear();
                                        close_database();
                                        QMessageBox::information(this,"ADD Account","account registred in the data base");
                                    }
                                    if(admin==true)
                                    {
                                        open_database();
                                        QSqlQuery cur(db);
                                        cur.prepare("insert into users (Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc) values('" + username+"','" + password + "','" + role + "','" + cin + "','" + date +"','"+noun+"','"+surnoun+"','"+email+"','"+max_numb_of_doc+"' ); ");

                                        cur.exec();
                                        cur.clear();
                                        close_database();
                                        QMessageBox::information(this,"Sign Up","account registred in the data base");
                                    }



                                }
                            }

                        }

                  }
                }
     }
   }
}

void AdminDialog::on_radioButton_admin_2_clicked()
{
    ui->lineEdit_spe_2->hide();
    ui->comboBox->hide();
    ui->label_19->hide();
    ui->label_18->hide();
}

void AdminDialog::on_radioButton_teacher_2_clicked()
{
    ui->lineEdit_spe_2->show();
    ui->comboBox->hide();
    ui->label_19->hide();
    ui->label_18->show();
}

void AdminDialog::on_radioButton_student_2_clicked()
{
    ui->lineEdit_spe_2->show();
    ui->comboBox->show();
    ui->label_19->show();
    ui->label_18->show();
}

void AdminDialog::on_radioButton_admin_clicked()
{
    ui->lineEdit_spe->hide();
    ui->comboBox_EDIT->hide();
    ui->label_9->hide();
    ui->label_8->hide();
}

void AdminDialog::on_radioButton_teacher_clicked()
{
    ui->lineEdit_spe->show();
    ui->comboBox_EDIT->hide();
    ui->label_9->hide();
    ui->label_8->show();
}

void AdminDialog::on_radioButton_student_clicked()
{
    ui->lineEdit_spe->show();
    ui->comboBox_EDIT->show();
    ui->label_9->show();
    ui->label_8->show();
}


void AdminDialog::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AdminDialog::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AdminDialog::on_pushButton_4_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time from users where Role = 'admin' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void AdminDialog::on_pushButton_5_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time,speciality from users where Role = 'teacher' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void AdminDialog::on_pushButton_6_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ID,Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,last_login_time,speciality,class from users where Role = 'student' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

/*****************************************************************************__Documents__*******************************************************************************/
void AdminDialog::on_pushButton_13_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void AdminDialog::on_pushButton_14_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}







void AdminDialog::on_EDIT_3_clicked()
{
    QString ref;
    QString title=ui->lineEdit_title_2->text();
    QString author=ui->lineEdit_author_2->text();
    QString category=ui->lineEdit_cathegory_2->text();
    QString nbre_of_copies=ui->lineEdit_nbr_copie_2->text();
    QString nbre_of_pages= ui->lineEdit_nbr_page_2->text();
    QString max_rent_time;
    QString pub_y=ui->lineEdit_year_2->text();
    QString des=ui->plainTextEdit_des_2->toPlainText();
    QString hp_sup=ui->lineEdit_hp_sup_2->text();
    QString sub=ui->lineEdit_sub_2->text();
    QString type;
    bool acproj=ui->radioButton_acproj_2->isChecked();
    bool book=ui->radioButton_book_2->isChecked();
    bool journal=ui->radioButton_journal_2->isChecked();





    if ((journal==false)&&(acproj==false)&&(book==false))
    {
       QMessageBox::warning(this,"ADD Doc","please check your document type (book/journal/academic project) ");
    }
    else
    {
        if(journal==true)
        {
            type="journal";

            max_rent_time="7 days";
        }
        if(book==true)
        {
            type="book";

            max_rent_time="21 days";

        }
        if(acproj==true)
        {
            type="academic project";

            max_rent_time="15 days";
        }
        if(title==""||author==""||category==""||nbre_of_copies==""||nbre_of_pages==""||pub_y==""||des==""||hp_sup=="")
            QMessageBox::warning(this,"ADD Doc","please complete all the form to create your document !!! ");
        else
        {
            if(!((string_is_didgit(nbre_of_copies))&&(string_is_didgit(nbre_of_pages))&&(string_is_didgit(pub_y))))
                QMessageBox::warning(this,"ADD Doc","This element must be a DIDGIT  !!! ");
            else
            {
                if(!((string_is_alpha(category))&&(string_is_alpha(author))&&(string_is_alpha(hp_sup))&&(string_is_alpha(sub))))
                    QMessageBox::warning(this,"ADD Doc","This element must be an ALPHABATIC STRING !!! ");
                else
                {
                   if(category.length()<3)
                      QMessageBox::warning(this,"ADD Doc","The Category must at least 3 caracters !!! ");
                   else
                   {
                       int exist=0;
                       QSqlQueryModel * model=new QSqlQueryModel();
                       open_database();
                       QSqlQuery * cur=new QSqlQuery(db) ;
                       cur->prepare("select * from docs ");
                       cur->exec();
                       model->setQuery(*cur);

                       close_database();
                       exist=model->rowCount();

                       QString num=QString::number(exist+1);

                       ref.push_back(category[0]);
                       ref.push_back(category[1]);
                       ref.push_back(category[2]);
                       ref.push_back(type[0]);
                       ref.push_back(type[1]);
                       ref.push_back(type[2]);
                       ref.push_back(num);
                       if(book==true)
                       {
                           open_database();
                           QSqlQuery cur(db);
                           cur.prepare("insert into docs (ref,type,title,author,number_of_copies,number_of_pages,category,description,year,pub_house,maximum_rent_time) values('" + ref+"','" + type + "','" + title + "','" + author + "','" + nbre_of_copies +"','"+nbre_of_pages+"','"+category+"','"+des+"','"+pub_y+"','"+hp_sup +"','"+max_rent_time+"' ); ");

                           cur.exec();
                           cur.clear();
                           close_database();
                           if(nbre_of_copies=="0")
                           {
                               open_database();
                               QSqlQuery cur(db);
                               cur.prepare("update docs set availibility ='NO' where ref = '"+ ref+"'");
                               cur.exec();
                               cur.clear();
                               close_database();
                           }
                           else
                           {
                               open_database();
                               QSqlQuery cur(db);
                               cur.prepare("update docs set availibility ='YES' where ref = '"+ ref+"'");
                               cur.exec();
                               cur.clear();
                               close_database();
                           }
                           QMessageBox::information(this,"Admin","Document registred in the data base");
                       }
                       if(journal==true)
                       {
                           open_database();
                           QSqlQuery cur(db);
                           cur.prepare("insert into docs (ref,type,title,author,number_of_copies,number_of_pages,category,description,year,pub_house,maximum_rent_time) values('" + ref+"','" + type + "','" + title + "','" + author + "','" + nbre_of_copies +"','"+nbre_of_pages+"','"+category+"','"+des+"','"+pub_y+"','"+hp_sup +"','"+max_rent_time+"' ); ");
                           cur.exec();
                           cur.clear();
                           close_database();
                           QMessageBox::information(this,"Admin","Document registred in the data base");
                       }
                       if(acproj==true)
                       {
                           if(sub=="")
                               QMessageBox::warning(this,"ADD Doc","please complete all the form to create your document !!! ");
                           else
                           {
                               open_database();
                               QSqlQuery cur(db);
                               cur.prepare("insert into docs (ref,type,title,author,number_of_copies,number_of_pages,category,description,year,supervisor,subject,maximum_rent_time) values('" + ref+"','" + type + "','" + title + "','" + author + "','" + nbre_of_copies +"','"+nbre_of_pages+"','"+category+"','"+des+"','"+pub_y+"','"+hp_sup +"','"+sub +"','"+max_rent_time+"' ); ");

                               cur.exec();
                               cur.clear();
                               close_database();
                               QMessageBox::information(this,"Admin","Document registred in the data base");
                           }

                       }




                   }
                }
            }
        }

   }
}





void AdminDialog::on_radioButton_acproj_2_clicked()
{

    ui->label_sub_2->show();

    ui->label_hp_sup_2->show();
    ui->label_hp_sup_2->setText("Supervisor");
    ui->lineEdit_hp_sup_2->show();

    ui->lineEdit_sub_2->show();
}

void AdminDialog::on_radioButton_book_2_clicked()
{
    ui->label_sub_2->hide();
    ui->label_hp_sup_2->show();
    ui->label_hp_sup_2->setText("House of publish");
    ui->lineEdit_hp_sup_2->show();
    ui->lineEdit_sub_2->hide();
}

void AdminDialog::on_radioButton_journal_2_clicked()
{
    ui->label_sub_2->hide();
    ui->label_hp_sup_2->show();
    ui->label_hp_sup_2->setText("House of publish");
    ui->lineEdit_hp_sup_2->show();
    ui->lineEdit_sub_2->hide();
}

void AdminDialog::on_pushButton_12_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_2->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void AdminDialog::on_pushButton_9_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,pub_house from docs where type='book' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_2->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void AdminDialog::on_pushButton_10_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,pub_house from docs where type='journal' ");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_2->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}

void AdminDialog::on_pushButton_11_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    open_database();
    QSqlQuery * cur=new QSqlQuery(db) ;
    cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time,supervisor,subject from docs where type='academic project'");
    cur->exec();
    model->setQuery(*cur);
    ui->tableView_2->setModel(model);
    close_database();
    qDebug() <<(model->rowCount());
}


void AdminDialog::on_EDIT_2_clicked()
{
    QString ref=ui->ref->text();
    QString title=ui->lineEdit_title->text();
    QString author=ui->lineEdit_author->text();
    QString category=ui->lineEdit_cathegory->text();
    QString nbre_of_copies=ui->lineEdit_nbr_copie->text();
    QString nbre_of_pages= ui->lineEdit_nbr_page->text();
    QString max_rent_time;
    QString pub_y=ui->lineEdit_year->text();
    QString des=ui->plainTextEdit_des->toPlainText();
    QString hp_sup=ui->lineEdit_hp_sup->text();
    QString sub=ui->lineEdit_sub->text();
    QString type;
    bool acproj=ui->radioButton_acproj->isChecked();
    bool book=ui->radioButton_book->isChecked();
    bool journal=ui->radioButton_journal->isChecked();
    bool a=ui->checkBox_author->isChecked();
    bool c=ui->checkBox_category->isChecked();
    bool d=ui->checkBox_description->isChecked();
    bool t=ui->checkBox_type->isChecked();
    bool y=ui->checkBox_year->isChecked();
    bool np=ui->checkBox_numbreofpages->isChecked();
    bool nc=ui->checkBox_numberofcopies->isChecked();
    bool ti=ui->checkBox_title->isChecked();

    int exist=0;


    open_database();
    QSqlQuery cur(db);
    cur.prepare("select * from docs where ref = '"+ ref+"'");
    if(cur.exec())
    {
      while(cur.next())
          exist++;
    }
    cur.clear();
    close_database();
    if(exist==0)
      QMessageBox::warning(this,"EDIT","No Document match this reference");
    else
    {
       if(ti==true)
       {
           open_database();
           QSqlQuery cur(db);
           cur.prepare("update docs set title ='"+title+"'where ref = '"+ ref+"'");
           cur.exec();
           cur.clear();
           close_database();
       }
       if(d==true)
       {
           open_database();
           QSqlQuery cur(db);
           cur.prepare("update docs set description ='"+des+"'where ref = '"+ ref+"'");
           cur.exec();
           cur.clear();
           close_database();
       }
       if(a==true)
       {
         if(string_is_alpha(author))
         {
             open_database();
             QSqlQuery cur(db);
             cur.prepare("update docs set author ='"+author+"'where ref = '"+ ref+"'");
             cur.exec();
             cur.clear();
             close_database();
         }
         else
             QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");
       }
       if(c==true)
       {
           if(string_is_alpha(category))
           {
               open_database();
               QSqlQuery cur(db);
               cur.prepare("update docs set category ='"+category+"'where ref = '"+ ref+"'");
               cur.exec();
               cur.clear();
               close_database();
           }
           else
               QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");
       }
       if(y==true)
       {
           if(string_is_didgit(pub_y))
           {
               open_database();
               QSqlQuery cur(db);
               cur.prepare("update docs set year ='"+pub_y+"'where  ref = '"+ ref+"'");
               cur.exec();
               cur.clear();
               close_database();
           }
           else
               QMessageBox::warning(this,"EDIT","This element must be a DIDGIT  !!! ");
       }
       if(nc==true)
       {
           if(string_is_didgit(nbre_of_copies))
           {
               open_database();
               QSqlQuery cur(db);
               cur.prepare("update docs set number_of_copies ='"+nbre_of_copies+"'where ref = '"+ ref+"'");
               cur.exec();
               cur.clear();
               close_database();
               if(nbre_of_copies=="0")
               {
                   open_database();
                   QSqlQuery cur(db);
                   cur.prepare("update docs set availibility ='NO' where ref = '"+ ref+"'");
                   cur.exec();
                   cur.clear();
                   close_database();
               }
               else
               {
                   open_database();
                   QSqlQuery cur(db);
                   cur.prepare("update docs set availibility ='YES' where ref = '"+ ref+"'");
                   cur.exec();
                   cur.clear();
                   close_database();
               }
           }
           else
               QMessageBox::warning(this,"EDIT","This element must be a DIDGIT  !!! ");
       }
       if(np==true)
       {
           if(string_is_didgit(nbre_of_pages))
           {
               open_database();
               QSqlQuery cur(db);
               cur.prepare("update docs set number_of_pages ='"+nbre_of_pages+"' where ref = '"+ ref+"'");
               cur.exec();
               cur.clear();
               close_database();
           }
           else
               QMessageBox::warning(this,"EDIT","This element must be a DIDGIT  !!! ");
       }
       if(t==true)
       {
           if ((acproj==false)&&(book==false)&&(journal==false))
           {
              QMessageBox::warning(this,"EDIT","please check your type ");
           }
           else
           {
               if(acproj==true)
               {
                   if(string_is_alpha(hp_sup)==true && string_is_alpha(sub)==true)
                   {
                       type="academic project";
                       max_rent_time="15 days";
                       open_database();
                       QSqlQuery cur(db);
                       cur.prepare("update docs set type ='"+type+"', supervisor = '"+hp_sup+"' , subject = '"+sub+"',maximum_rent_time = '"+max_rent_time+"'  where ref ='"+ref+"'");
                       cur.exec();
                       cur.clear();
                       close_database();
                   }
                   else
                      QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");


               }

               if(book==true)
               {
                   if(string_is_alpha(hp_sup)==true)
                   {
                       type="book";
                       max_rent_time="21 days";
                       open_database();
                       QSqlQuery cur(db);
                       cur.prepare("update docs set type ='"+type+"', pub_house = '"+hp_sup+"' ,maximum_rent_time = '"+max_rent_time+"'  where ref ='"+ref+"'");
                       cur.exec();
                       cur.clear();
                       close_database();
                   }
                   else
                       QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");

               }
               if(journal==true)
               {
                   if(string_is_alpha(hp_sup)==true)
                   {
                       type="journal";
                       max_rent_time="7 days";
                       open_database();
                       QSqlQuery cur(db);
                       cur.prepare("update docs set type ='"+type+"', pub_house = '"+hp_sup+"' ,maximum_rent_time = '"+max_rent_time+"'  where ref ='"+ref+"'");
                       cur.exec();
                       cur.clear();
                       close_database();
                   }
                   else
                       QMessageBox::warning(this,"EDIT","This element must be an ALPHABATIC STRING !!! ");

               }

           }
       }

        QMessageBox::information(this,"EDIT","Document updated successfully");

    }

}





void AdminDialog::on_Search_doc_clicked()
{
    QString search=ui->search_2->text();


    if(ui->comboBox_search_doc->currentText()=="REFERENCE")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc->currentText()=="TITLE")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc->currentText()=="CATEGORY")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc->currentText()=="PUBLISH YEAR")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc->currentText()=="AUTHOR")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
    if(ui->comboBox_search_doc->currentText()=="TYPE")
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
            ui->tableView_2->setModel(model);
            close_database();
            qDebug() <<(model->rowCount());
        }
    }
}

void AdminDialog::on_DELETE_2_clicked()
{
    QString d=ui->delete_doc->text();
    int exist=0;
    open_database();
    QSqlQuery cur(db);
    cur.prepare("select * from docs where ref = '"+ d+"'");
    if(cur.exec())
    {
      while(cur.next())
          exist++;
    }
    cur.clear();
    close_database();
    if(exist==0)
        QMessageBox::warning(this,"DELETE","No document match this reference");
    else
    {
        open_database();
        QSqlQuery del(db);
        del.prepare("DELETE from docs where ref = '"+ d+"'");
        del.exec();
        del.clear();
        close_database();
        QMessageBox::information(this,"DELETE","Document deleted successfully");
         ui->delete_doc->setText("");
         QSqlQueryModel * model=new QSqlQueryModel();
         open_database();
         QSqlQuery * cur=new QSqlQuery(db) ;
         cur->prepare("select ref,type,title,author,number_of_copies,number_of_pages,category,description,year,maximum_rent_time from docs ");
         cur->exec();
         model->setQuery(*cur);
         ui->tableView_2->setModel(model);
         close_database();
         qDebug() <<(model->rowCount());
    }
    initialize();
}


void AdminDialog::on_tableView_2_activated(const QModelIndex &index)
{
    QString user_info =ui->tableView_2->model()->data(index).toString();
    open_database();
    QSqlQuery cur(db);


    cur.prepare("select * from docs where ref = '"+user_info +"' or title = '"+ user_info+"'or author= '"+user_info+"' or number_of_copies = '"+user_info+"' or number_of_pages = '"+user_info+"'or category= '"+user_info+"'or description= '"+user_info+"' or year='"+user_info+"' or type='"+user_info+"'or maximum_rent_time ='"+user_info+"'");
    if(cur.exec())
    {
      while(cur.next())
      {
          ui->ref->setText(cur.value(0).toString());
          ui->ref_2->setText(cur.value(0).toString());


          ui->lineEdit_title->setText(cur.value(2).toString());
          ui->lineEdit_title_3->setText(cur.value(2).toString());

          ui->lineEdit_author->setText(cur.value(3).toString());
          ui->lineEdit_author_3->setText(cur.value(3).toString());


          ui->lineEdit_nbr_copie->setText(cur.value(4).toString());
          ui->lineEdit_nbr_copie_3->setText(cur.value(4).toString());


          ui->lineEdit_cathegory->setText(cur.value(5).toString());
          ui->lineEdit_cathegory_3->setText(cur.value(5).toString());



          ui->lineEdit_nbr_page->setText(cur.value(7).toString());
          ui->lineEdit_nbr_page_3->setText(cur.value(7).toString());





          ui->lineEdit_year->setText(cur.value(8).toString());
          ui->lineEdit_year_3->setText(cur.value(8).toString());




          ui->plainTextEdit_des->document()->setPlainText(cur.value(6).toString());
          ui->plainTextEdit_des_3->document()->setPlainText(cur.value(6).toString());


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
              ui->tableView_his->setModel(model);

              qDebug() <<(model->rowCount());
              qDebug() << con;

          }



          QString doc_type=cur.value(1).toString();
          if(doc_type=="book")
          {
              ui->radioButton_book->setChecked(true);
              ui->label_sub->hide();
              ui->label_hp_sup->show();
              ui->lineEdit_hp_sup->setText(cur.value(12).toString());
              ui->label_hp_sup->setText("House of publish");
              ui->lineEdit_hp_sup->show();
              ui->lineEdit_sub->hide();


              ui->radioButton_book_3->setChecked(true);
              ui->label_sub_3->hide();
              ui->label_hp_sup_3->show();
              ui->lineEdit_hp_sup_3->setText(cur.value(12).toString());
              ui->label_hp_sup_3->setText("House of publish");
              ui->lineEdit_hp_sup_3->show();
              ui->lineEdit_sub_3->hide();

          }


          if(doc_type=="journal")
          {
              ui->radioButton_journal->setChecked(true);
              ui->label_sub->hide();
              ui->label_hp_sup->show();
              ui->lineEdit_hp_sup->setText(cur.value(12).toString());
              ui->label_hp_sup->setText("House of publish");
              ui->lineEdit_hp_sup->show();
              ui->lineEdit_sub->hide();


              ui->radioButton_journal_3->setChecked(true);
              ui->label_sub_3->hide();
              ui->label_hp_sup_3->show();
              ui->label_hp_sup_3->setText("House of publish");
              ui->lineEdit_hp_sup_3->setText(cur.value(12).toString());
              ui->lineEdit_hp_sup_3->show();
              ui->lineEdit_sub_3->hide();
          }

          if(doc_type=="academic project")
          {
              ui->radioButton_acproj->setChecked(true);
              ui->label_sub->show();
              ui->label_hp_sup->show();
              ui->lineEdit_hp_sup->setText(cur.value(13).toString());
              ui->label_hp_sup->setText("Supervisor");
              ui->lineEdit_hp_sup->show();
              ui->lineEdit_sub->show();
              ui->lineEdit_sub->setText(cur.value(14).toString());


              ui->radioButton_acproj_3->setChecked(true);
              ui->label_sub_3->show();
              ui->label_hp_sup_3->show();
              ui->lineEdit_hp_sup_3->setText(cur.value(13).toString());
              ui->label_hp_sup_3->setText("Supervisor");
              ui->lineEdit_hp_sup_3->show();
              ui->lineEdit_sub_3->show();
              ui->lineEdit_sub_3->setText(cur.value(14).toString());
          }

      }


    }
    cur.clear();
    close_database();


    ui->stackedWidget_2->setCurrentIndex(0);
}
/*******************************************************************************Profil**********************************************************************************************************/


void AdminDialog::on_Search_doc_2_clicked()
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

void AdminDialog::on_pushButton_18_clicked()
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

void AdminDialog::on_pushButton_15_clicked()
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

void AdminDialog::on_pushButton_16_clicked()
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

void AdminDialog::on_pushButton_17_clicked()
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

void AdminDialog::on_tableView_3_activated(const QModelIndex &index)
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


void AdminDialog::initialize()
{

        open_database();
        QSqlQuery cur(db);

        cur.prepare("select * from users where Login = '"+current_username+"'");
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
        qDebug()<<"admin"<<lib.liste_doc.size();

        qDebug()<<"admin"<<lib.liste_users.size();
}

void AdminDialog::on_tableView_his_4_activated(const QModelIndex &index)
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

void AdminDialog::on_pushButton_23_clicked()
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
        open_database();
        QSqlQuery qur(db);
        qur.prepare("update docs set availibility ='YES' where ref = '"+ ref+"'");
        qur.exec();
        qur.clear();
        close_database();

    }

}
/********************************************************************************************/

void AdminDialog::on_pushButton_22_clicked()
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
                QSqlQuery qur(db);
                qur.prepare("update docs set availibility ='NO' where ref = '"+ ref+"'");
                qur.exec();
                qur.clear();



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
