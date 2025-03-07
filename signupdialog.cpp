#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
    QPixmap pic("./sb.png");
    int w= ui->background->width();
    int h= ui->background->height();
    ui->background->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    ui->comboBox->addItem("1st Year");
     ui->comboBox->addItem("2nd Year");
    ui->comboBox->addItem("3rd Year");
    ui->comboBox->hide();
    ui->lineEdit_spe->hide();
    ui->label_9->hide();
    ui->label_8->hide();

}

SignupDialog::~SignupDialog()
{
    delete ui;
}


bool isChar(QChar c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}


bool isDigit(const QChar c)
{
    return (c >= '0' && c <= '9');
}


bool is_valid(QString email)
{

    if (!isChar(email[0])) {


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


void SignupDialog::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void SignupDialog::on_pushButton_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    QString con_password=ui->lineEdit_password_2->text();
    QString cin=ui->lineEdit_cin->text();
    QDate d= ui->date->date();
    QString email=ui->lineEdit_email->text();
    QString noun=ui->lineEdit_noun->text();
    QString surnoun=ui->lineEdit_surnoun->text();
    QString speciality=ui->lineEdit_spe->text();
    QString classe=ui->comboBox->currentText();
    QString role;
    QString max_numb_of_doc;
    bool teacher=ui->radioButton_teacher->isChecked();
    bool student=ui->radioButton_student->isChecked();
    QString date = d.toString("dd/MM/yyyy");




    if ((teacher==false)&&(student==false))
    {
       QMessageBox::warning(this,"Signup","please check your status (Teacher/Student) ");
    }
    else
    {
        if(teacher==true)
        {
            role="teacher";
            /*ui->lineEdit_spe->show();
            ui->comboBox->hide();*/
            max_numb_of_doc="3";
        }
        if(student==true)
        {
            role="student";
            /*ui->lineEdit_spe->show();
            ui->comboBox->show();*/
            max_numb_of_doc="5";

        }
        if(username==""||password==""||cin==""||email==""||noun==""||surnoun==""||speciality=="")
            QMessageBox::warning(this,"signup","please complete all the form to create your account !!! ");
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
                QMessageBox::warning(this,"Sign Up","This username already exist!!! ");

            else
                {
                    if(is_valid(email)==false)
                       QMessageBox::warning(this,"Sign Up","This email is not valid!!! ");
                    else
                    {

                        if(password!=con_password)
                            QMessageBox::warning(this,"Sign Up","please confirm your password ");
                        else
                        {
                            if(cin.length()!=8)
                                QMessageBox::warning(this,"Sign Up","C.I.N must contain 8 ditgits ");
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
                                    QMessageBox::warning(this,"Sign Up","C.I.N must contain only ditgits ");


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
                                        QMessageBox::information(this,"Sign Up","account registred in the data base");
                                    }
                                    if(student==true)
                                    {
                                        open_database();
                                        QSqlQuery cur(db);
                                        cur.prepare("insert into users (Login,Password,Role,CIN,date_of_birth,noun,surnoun,email,max_number_of_doc,class,speciality) values('" + username+"','" + password + "','" + role + "','" + cin + "','" + date +"','"+noun+"','"+surnoun+"','"+email+"','"+max_numb_of_doc+"','"+classe+"','"+speciality +"' ); ");

                                        cur.exec();
                                        cur.clear();
                                        close_database();
                                        QMessageBox::information(this,"Sign Up","account registred in the data base");
                                    }




                                      hide();
                                      userDialog= new UserDialog(this);
                                      userDialog->show();
                                      userDialog->current_username=username;
                                      userDialog->initialize();



                                }
                            }

                        }

                  }
                }
     }
   }
}

void SignupDialog::on_radioButton_teacher_clicked()
{
    ui->lineEdit_spe->show();
    ui->label_8->show();
    ui->comboBox->hide();
    ui->label_9->hide();
}

void SignupDialog::on_radioButton_student_clicked()
{
    ui->lineEdit_spe->show();
    ui->label_8->show();
    ui->comboBox->show();
    ui->label_9->show();
}







