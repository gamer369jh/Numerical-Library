#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signupdialog.h"
#include "gestdialog.h"
#include "admindialog.h"
#include "userdialog.h"
#include "library.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    library main_lib;
private slots:
    void on_pushButton_Signup_clicked();

    void on_pushButton_invite_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    SignupDialog *signupdialog;
    GestDialog *guestdialog;
    AdminDialog *adminDialog;
    UserDialog *userDialog;


};


#endif // MAINWINDOW_H
