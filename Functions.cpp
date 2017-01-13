#include"Functions.h"

bool validateRegisterInput(std::string name, std::string email, std::string age, std::string password,std::string money)
{
    if(!name.empty() && !email.empty() && !age.empty() && !password.empty())
    {
        istringstream buffer(age);
        int value;
        buffer >> value;

        if(value >= 18 && value < 99)
        {
            istringstream buffer(money);
            int moneyValue;
            buffer >> moneyValue;
            if(moneyValue >= 100)
            {
                return true;
            }
        }
    }
    return false;
}


void registerPlayer(string name, string email, string age, string password, string money)
{

    istringstream buffer1(money);
    int moneyValue;
    buffer1 >> moneyValue;

    istringstream buffer2(age);
    int ageValue;
    buffer2 >> ageValue;

    struct Player newPlayer;

    newPlayer.name = name;
    newPlayer.email=email;
    newPlayer.age = ageValue;
    newPlayer.password = password;
    newPlayer.money=moneyValue;

    printPlayerDetails(&newPlayer);
    writeIntoFile(&newPlayer);
}


void printPlayerDetails(struct Player *player)
{
    cout<< "\nName " << player->name << " |Email "<<player->email<< " |Age " << player->age << "|Money " <<player->money<<endl;
}

void writeIntoFile(struct Player *player)
{
    QMessageBox messageBox;

    std::stringstream sAge;
    sAge << player->age;

    std::stringstream sMoney;
    sMoney << player->money;

    std::string lineToWrite = player->name + "|" + player->email +"|"+ sAge.str()+"|"+player->password+"|"+sMoney.str()+"\n";
    ofstream myfile ("players.txt");

       if (myfile.is_open())
       {
        myfile << lineToWrite;
        myfile.close();
       }
       else {
        messageBox.setText("Can't open file");
        messageBox.exec();
        cout << "Can't open file" <<endl;
        }
}
