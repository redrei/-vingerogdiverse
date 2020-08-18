#include "Card.h"
#pragma once
class CardDeck{
    private:
        vector<Card> cards;
        void swap(int card1, int card2);
    public:
        CardDeck(){
            for(int i = Suit::clubs; i<= Suit::spades; i++){
                for(int j = Rank::two; j <= Rank::ace; j++){
                    cards.push_back(Card{Suit(i),Rank(j)});
                }
            }
        }
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};