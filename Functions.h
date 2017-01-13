
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
    int score;
};

void printPlayerDetails(struct Player *player);

bool validateRegisterInput(std::string name, std::string email, std::string age, std::string password,std::string money);

void registerPlayer(std::string name, std::string email, std::string age, std::string password,std::string money);

void writeIntoFile(struct Player *player);

bool userExists(std::string email);

std::string loginPlayer(std::string username, std::string password);

std::string returnUser(std::string username);

int checkPointsUser(std::string username);

void replaceLineInFile(std::string search_string , std::string replace_string);

#endif // FUNCTIONS_H
