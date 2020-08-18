#include "CardDeck.h"
#pragma once
class Blackjack{
    private:
        CardDeck deck;
        vector<Card> dHand;
        vector<Card> pHand;
        bool game;
        bool hasBlackjack(vector<Card> hand);
        int countPoints(vector<Card> hand); 
    public:
        Blackjack();
        void printHands();
        void hit();
        void stand();
        bool getGame();
};