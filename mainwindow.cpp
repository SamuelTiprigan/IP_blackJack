#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Functions.h"
#include"editprofile.h"
#include"BlackJack.cpp"

static int countLoggedUsers =0;


static std::string player1;
static std::string player2;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->registerGroupBox->setVisible(false);
    ui->gameTypeBox->setVisible(true);
    ui->loginGroup->setVisible(false);
    ui->matchBox->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//register new user
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

//select type of game
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Question");
    msgBox.setText("Are you a new User?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes){

        ui->registerGroupBox->setVisible(true);
        ui->loginGroup->setVisible(false);
        ui->gameTypeBox->setVisible(false);

    }else {
        ui->registerGroupBox->setVisible(false);
        ui->gameTypeBox->setVisible(false);
        ui->loginGroup->setVisible(true);
    }
}

//login
void MainWindow::on_pushButton_4_clicked()
{

    ui->lEmail->setText("samy.tiprigan@gmail.com");
    ui->lPassword->setText("hpf101");

    QMessageBox msgBox;
    std::string email = ui->lEmail->text().toStdString();
    std::string pass = ui->lPassword->text().toStdString();

    if(email.empty() || pass.empty())
    {
        msgBox.setText("Please complete the username(email) and password!");
        msgBox.exec();
    }
    else
    {
        if(userExists(email) ==false)
        {
            msgBox.setText(" User not found in the database ! \nPlease register!");
            msgBox.exec();
        }
        else
        {
            std::string player11 = loginPlayer(email,pass);
            std::cout<<" User logat !" <<player11<<endl;

            countLoggedUsers++;
            player1 = player11;

            msgBox.setText("Player 1 has logged in !");
            msgBox.exec();

            ui->loginGroup->setVisible(false);
            ui->matchBox->setVisible(true);

        }
    }
}

//edit profile user 1
void MainWindow::on_pushButton_6_clicked()
{

    EditProfile *editProfile = new EditProfile();
    editProfile->show();


}

//play single
void MainWindow::on_pushButton_10_clicked()
{
    struct Deck deck;
    deck = InitializeDeck();
    std::cout<<deck[2]<<endl;

    struct Card card;
    card = GiveMeACard(deck);


    cout<<"Am gasit" << PrintOnScreenCard(card)<<endl;


}
