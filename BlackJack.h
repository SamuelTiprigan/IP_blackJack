#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <iostream>
#include <string>
using namespace std;


char *card_num[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char *card_type[] = {"trefla","romb","inima","frunza"};

struct Card {
    int color;
    int number;
    int value;
};

struct Deck {
    bool deck[52];
    int size;
};




#endif // BLACKJACK_H
