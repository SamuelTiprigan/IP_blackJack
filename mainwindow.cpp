#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Functions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->registerGroupBox->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->qAge->setValidator( new QDoubleValidator(0, 100, 2, this) ); //setam sa ofere doar numere pe casuta de age si bani
    ui->qMoney->setValidator(new QDoubleValidator(0, 100, 2, this));

    QMessageBox messageBox;
    std::string fullName = ui->qFullName->text().toStdString();
    std::string email = ui->qEmail->text().toStdString();
    std::string age = ui->qAge->text().toStdString();
    std::string password = ui->qPassword->text().toStdString();
    std::string money = ui->qMoney->text().toStdString();

    if(validateRegisterInput(fullName,email,age,password,money) == false)
    {
        messageBox.setText(" Please check the inputs ! \n All fields must be completed !");
        messageBox.exec();
    }
    else
    {
        qDebug("Input is valid ! proceeding to Register Operation...");
        registerPlayer(fullName,email,age,password,money);
    }
}
