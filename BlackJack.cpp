#include <iostream>
#include <string>
#include <stdlib.h>
#include "stdio.h"


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

struct Deck InitializeDeck();
std::string PrintOnScreenCard(struct Card &card);
struct Card GiveMeACard(struct Deck &deck);

struct Deck InitializeDeck()
{
    struct Deck deck;
    deck.size=52;
    int i=0;
    for(i=0;i<52;++i)
    {
        deck.deck[i] = true;
    }
    return deck;
}

std::string PrintOnScreenCard(struct Card &card) {
    std::string cardSpecifics;
    //cardSpecifics= card_num[card.number] + card_type[card.color] + card.value;

    return cardSpecifics;
}



struct Card GiveMeACard(struct Deck &deck) {
    struct Card card;
    int randomCard = (int) (1.0 * rand() / (13 + 1) * deck.size);
    int counter = 0;
    int i;


    for (i=0; i<52; ++i) {
        if (deck.deck[i] == true) {
            ++counter;
        }
        if (counter == randomCard+1) {
            break;
        }
    }

     card.value = 10;
     card.number = 8 / 4;
     card.color = 8 % 4;
     deck.deck[i]= false;


    return card;
}


