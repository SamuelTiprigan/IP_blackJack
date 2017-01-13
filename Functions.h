
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QtCore/QCoreApplication>
#include"stdio.h"
#include"stdlib.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

#include <fstream>
#include "QMessageBox"


using namespace std;


struct Player
{
    std::string name;
    std::string email;
    int age;
    std::string password;
    int money;
};



void printPlayerDetails(struct Player *player);

bool validateRegisterInput(std::string name, std::string email, std::string age, std::string password,std::string money);

void registerPlayer(std::string name, std::string email, std::string age, std::string password,std::string money);

void writeIntoFile(struct Player *player);

#endif // FUNCTIONS_H