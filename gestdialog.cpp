#include "gestdialog.h"
#include "ui_gestdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
GestDialog::GestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestDialog)
{
    ui->setupUi(this);
    ui->comboBox_search_doc->addItem("REFERENCE");
    ui->comboBox_search_doc->addItem("TITLE");
    ui->comboBox_search_doc->addItem("CATEGORY");
    ui->comboBox_search_doc->addItem("PUBLISH YEAR");
    ui->comboBox_search_doc->addItem("AUTHOR");
    ui->comboBox_search_doc->addItem("TYPE");
}

GestDialog::~GestDialog()
{
    delete ui;
}

void GestDialog::on_Search_doc_clicked()
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



void GestDialog::on_pushButton_12_clicked()
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

void GestDialog::on_pushButton_Signup_clicked()
{
    hide();
    signupdialog= new SignupDialog(this);
    signupdialog->show();
}

void GestDialog::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void GestDialog::on_pushButton_9_clicked()
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

void GestDialog::on_pushButton_10_clicked()
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

void GestDialog::on_pushButton_11_clicked()
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
