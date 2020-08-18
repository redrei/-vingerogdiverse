#include "CardDeck.h"
#pragma once
class CardDeck{
    private:
        vector<Card> cards;
        void swap(int card1, int card2){
            Card& temp1 = cards.at(card1);
            cards[card1] = cards.at(card2);
            cards[card2] = temp1;
        }
    public:
        CardDeck(){
            for(int i = Suit::clubs; i<= Suit::spades; i++){
                for(int j = Rank::two; j <= Rank::ace; j++){
                    cards.push_back(Card{Suit(i),Rank(j)});
                }
            }
        }
        void print(){
            for(Card card:cards){
                cout << card.toString() << endl;
            }
        }
        void printShort(){
            for(Card card:cards){
                cout << card.toStringShort() << endl;
            }
        }
        void shuffle(){
            for(int i = 0; i < 1200; i++){
                int tilfeldig_tall1;
                tilfeldig_tall1 = (rand() % (52));
                int tilfeldig_tall2;
                tilfeldig_tall2 = (rand() % (52));
                swap(tilfeldig_tall1,tilfeldig_tall2);
            }
        }
        Card drawCard(){
            Card card = cards.back();
            cards.pop_back();
            return card;
        }
};