#include"Functions.h"


using namespace std;

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
    newPlayer.score=0;

    printPlayerDetails(&newPlayer);
    writeIntoFile(&newPlayer);
}


void printPlayerDetails(struct Player *player)
{
    cout<< "\nName " << player->name << " |Email "<<player->email<< " |Age " << player->age << "|Money " <<player->money << " | " << player->score<<endl;
}

void writeIntoFile(struct Player *player)
{
    int initialScore =0;
    QMessageBox messageBox;

    std::stringstream sAge;
    sAge << player->age;

    std::stringstream sMoney;
    sMoney << player->money;

    std::stringstream sScore;
    sScore << initialScore;

    std::string lineToWrite = player->name + "|" + player->email +"|"+ sAge.str()+"|"+player->password+"|"+sMoney.str() + "|" + sScore.str() +"\n";
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

bool userExists(string email)
{
    QMessageBox messageBox;
    string filename = "players.txt";

    ifstream dafi(filename.c_str());

    if (dafi)
    {
        string search;
        string line;

        search = email;

        while (getline(dafi, line))
        {
            if (line.find(search) != std::string::npos)
            {
                return true;
            }
        }
    }
    else
    {
        messageBox.setText("Can't open file");
        messageBox.exec();
        cerr << "Cannot open file " << filename << endl;
        return -1;
    }

    return false;
}

std::string loginPlayer(string email, string password)
{
    QMessageBox messageBox;

    char *name;
    char *emailLogin;
    char *age;
    char *passLogin;
    char *money;
    char *score;

    string filename = "players.txt";
    ifstream dafi(filename.c_str());
    if (dafi)
    {
        string search;
        string line;
        search = email;
        while (getline(dafi, line))
        {
            if (line.find(search) != std::string::npos)
            {
                std::cout<<line<<endl;

                char helpingArray[1024];
                strcpy(helpingArray, line.c_str());

                name = strtok(helpingArray,"|");
                emailLogin = strtok(NULL,"|");
                age= strtok(NULL,"|");
                passLogin = strtok(NULL,"|");
                money= strtok(NULL,"|");
                score =strtok(NULL,"|");


                cout<<string(emailLogin)<<endl;
                cout<<string(password)<<endl;

                if(string(emailLogin) == email && passLogin == password)
                {
                    cout<<"adevarat"<<endl;
                    return email;
                }
            }
            else
            {
                messageBox.setText(" User not found in the database ! \nPlease register!");
                messageBox.exec();
            }
        }
    }
    else
    {
        messageBox.setText("Can't open file");
        messageBox.exec();
        cerr << "Cannot open file " << filename << endl;
    }

    return "";
}

std::string returnUser(string email)
{
    QMessageBox messageBox;

    string filename = "players.txt";
    ifstream dafi(filename.c_str());
    if (dafi)
    {
        string search;
        string line;
        search = email;
        while (getline(dafi, line))
        {
            if (line.find(search) != std::string::npos)
            {
                return line;
            }
            else
            {
                messageBox.setText(" User not found in the database ! \nPlease register!");
                messageBox.exec();
            }
        }
    }
    else
    {
        messageBox.setText("Can't open file");
        messageBox.exec();
        cerr << "Cannot open file " << filename << endl;
    }

    return "";
}

int checkPointsUser(string email)
{
    QMessageBox messageBox;

    char *name;
    char *emailLogin;
    char *age;
    char *passLogin;
    char *money;
    char *score;

    string filename = "players.txt";
    ifstream dafi(filename.c_str());
    if (dafi)
    {
        string search;
        string line;
        search = email;
        while (getline(dafi, line))
        {
            if (line.find(search) != std::string::npos)
            {
                std::cout<<line<<endl;

                char helpingArray[1024];
                strcpy(helpingArray, line.c_str());

                name = strtok(helpingArray,"|");
                emailLogin = strtok(NULL,"|");
                age= strtok(NULL,"|");
                passLogin = strtok(NULL,"|");
                money= strtok(NULL,"|");
                score =strtok(NULL,"|");

                return atoi(score);
            }
            else
            {
                messageBox.setText(" User not found in the database ! \nPlease register!");
                messageBox.exec();
            }
        }
    }
    else
    {
        messageBox.setText("Can't open file");
        messageBox.exec();
        cerr << "Cannot open file " << filename << endl;
    }

    return 0;
}


void replaceLineInFile(string strReplace, string strNew)
{
       ifstream filein("players.txt");
       ofstream fileout("temp.txt");
       if(!filein || !fileout)
       {
           cout << "Error opening files!" << endl;
           return;
       }
       string strTemp;
         while(filein >> strTemp)//it will check line from test to strTemp string
       {
           if(strTemp == strReplace)//if your word found then replace
           {
               strTemp = strNew;
               //found = true;
           }
           strTemp += "\n";
           fileout << strTemp;//output everything to fileout(temp.txt)
           //if(found) break;
       }}
