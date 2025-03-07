#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupdialog.h"
#include <QMessageBox>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic("./lib.jpg");
    int w= ui->image->width();
    int h= ui->image->height();
    ui->image->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Signup_clicked()
{
    hide();
    signupdialog= new SignupDialog(this);
    signupdialog->show();
}

void MainWindow::on_pushButton_invite_clicked()
{
    hide();
    guestdialog= new GestDialog(this);
    guestdialog->show();
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();

    SignupDialog a;






        int exist=0;


        a.open_database();
        QSqlQuery cur(a.db);
        cur.prepare("select * from users where Login = '"+ username+"'");
        if(cur.exec())
        {
          while(cur.next())
              exist++;
        }
        cur.clear();
        a.close_database();
        if(exist==0)
          QMessageBox::warning(this,"login","your login informations are not valid");
        else
        {
            exist=0;

                a.open_database();
                QSqlQuery cur(a.db);
                cur.prepare("select * from users where Login = '"+ username+"'and Role = 'admin'");
                if(cur.exec())
                {
                  while(cur.next())
                      exist++;
                }
                cur.clear();
                a.close_database();
                if(exist!=0)
                {
                    exist=0;

                    a.open_database();
                    QSqlQuery cur(a.db);
                    cur.prepare("select * from users where Login = '"+ username+"'and Password ='"+ password+"'");
                    if(cur.exec())
                    {
                      while(cur.next())
                          exist++;
                    }
                    cur.clear();
                    a.close_database();
                    if(exist==0)
                      QMessageBox::warning(this,"login","Wrong password !!! Please verify your password");
                    else
                    {

                        QMessageBox::information(this,"login","Connection established");
                        hide();
                        adminDialog= new AdminDialog(this);
                        adminDialog->show();
                        adminDialog->current_username=username;
                        main_lib.upload_data_in_lists();
                        adminDialog->lib=main_lib;
                        adminDialog->initialize();

                    }
                }



                else
                {
                    exist=0;
                    a.open_database();
                   QSqlQuery cur(a.db);

                    cur.prepare("select * from users where Login = '"+ username+"' and Role = 'teacher'");
                    if(cur.exec())
                    {
                      while(cur.next())
                          exist++;
                    }
                    cur.clear();
                    a.close_database();
                    if(exist!=0)
                    {
                        exist=0;

                        a.open_database();
                        QSqlQuery cur(a.db);
                        cur.prepare("select * from users where Login = '"+ username+"'and Password ='"+ password+"'");
                        if(cur.exec())
                        {
                          while(cur.next())
                              exist++;
                        }
                        cur.clear();
                        a.close_database();
                        if(exist==0)
                          QMessageBox::warning(this,"login","Wrong password !!! Please verify your password");
                        else
                        {

                            QMessageBox::information(this,"login","Connection established");
                            hide();
                            userDialog= new UserDialog(this);
                            userDialog->show();
                            userDialog->current_username=username;
                            main_lib.upload_data_in_lists();
                            userDialog->lib=main_lib;
                            userDialog->initialize();

                        }
                    }
                    else
                    {
                        exist=0;
                        a.open_database();
                        QSqlQuery cur(a.db);
                        cur.prepare("select * from users where Login = '"+ username+"' and Role = 'student'");
                        if(cur.exec())
                        {
                          while(cur.next())
                              exist++;
                        }
                        cur.clear();
                        a.close_database();
                        if(exist!=0)
                        {
                            exist=0;

                            a.open_database();
                            QSqlQuery cur(a.db);
                            cur.prepare("select * from users where Login = '"+ username+"'and Password ='"+ password+"'");
                            if(cur.exec())
                            {
                              while(cur.next())
                                  exist++;
                            }
                            cur.clear();
                            a.close_database();
                            if(exist==0)
                              QMessageBox::warning(this,"login","Wrong password !!! Please verify your password");
                            else
                            {

                                QMessageBox::information(this,"login","Connection established");
                                hide();
                                userDialog= new UserDialog(this);
                                userDialog->show();
                                userDialog->current_username=username;
                                userDialog->current_username=username;
                                main_lib.upload_data_in_lists();
                                userDialog->lib=main_lib;
                                userDialog->initialize();

                            }
                        }
                    }

                }

            }
        qDebug()<<main_lib.liste_doc.size();
        qDebug()<<main_lib.liste_users.size();

}
