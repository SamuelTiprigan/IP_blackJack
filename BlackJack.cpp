
#include"BlackJack.h"\


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
    cardSpecifics= card_num[card.number] + card_type[card.color] + card.value;

    return cardSpecifics;
}
