#include "Card.h"
#pragma once
class CardDeck{
    private:
        vector<Card> cards;
        void swap(int card1, int card2);
    public:
        CardDeck();
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};