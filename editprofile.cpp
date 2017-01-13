#include "editprofile.h"
#include "ui_editprofile.h"
#include"Functions.h"


using namespace std;


static std::string globalValueToEdit;
EditProfile::EditProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfile)
{

    ui->setupUi(this);
    ui->eScore->setReadOnly(true);
}

EditProfile::~EditProfile()
{
    delete ui;
}

//search Button
void EditProfile::on_pushButton_clicked()
{
    std::string userToEdit =  returnUser(ui->searchEdit->text().toStdString());
    globalValueToEdit=userToEdit;

    char *name;
    char *emailLogin;
    char *age;
    char *passLogin;
    char *money;
    char *score;

    char helpingArray[1024];


    strcpy(helpingArray, userToEdit.c_str());

    name = strtok(helpingArray,"|");
    emailLogin = strtok(NULL,"|");
    age= strtok(NULL,"|");
    passLogin = strtok(NULL,"|");
    money= strtok(NULL,"|");
    score =strtok(NULL,"|");

    ui->eName->setText(name);
    ui->eEmail->setText(emailLogin);
    ui->eMoney->setText(money);
    ui->ePassword->setText(passLogin);
    ui->eAge->setText(age);
    ui->eScore->setText(score);
}

void EditProfile::on_pushButton_10_clicked()
{
    istringstream buffer1(ui->eAge->text().toStdString());
    int ageValue;
    buffer1 >> ageValue;

    istringstream buffer2(ui->eMoney->text().toStdString());
    int moneyValue;
    buffer2 >> moneyValue;

    istringstream buffer3(ui->eMoney->text().toStdString());
    int scoreValue;
    buffer2 >> scoreValue;

    struct Player player1;
    player1.name = ui->eName->text().toStdString();
    player1.email = ui->eEmail->text().toStdString();
    player1.age = ageValue;
    player1.score =scoreValue ;
    player1.money =  moneyValue;
    player1.password = ui->ePassword->text().toStdString();


    int scoreV = scoreValue;
    std::stringstream sScore;
    sScore << scoreV;

    int moneyV = moneyValue;
    std::stringstream mValue;
    mValue << moneyV;

    int ageV = ageValue;
    std::stringstream aValue;
    aValue << ageV;

    std::string lineToWrite = player1.name + "|" + player1.email +"|"+ aValue.str()+"|"+player1.password+"|"+mValue.str() + "|" + sScore.str() +"\n";
    printPlayerDetails(&player1);
    replaceLineInFile(globalValueToEdit,lineToWrite);
}
