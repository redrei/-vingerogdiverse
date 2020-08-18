#include "CardDeck.h"
#pragma once
class Blackjack{
    private:
        CardDeck deck;
        vector<Card> dHand;
        vector<Card> pHand;
    public:
        Blackjack();
        void printHands();
};