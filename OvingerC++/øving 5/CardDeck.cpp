#include "CardDeck.h"
void CardDeck::swap(int card1, int card2){
    Card temp1 = CardDeck::cards.at(card1);
    CardDeck::cards[card1] = CardDeck::cards[card2];
    CardDeck::cards[card2] = temp1;
}

void CardDeck::print(){
    for(Card card:CardDeck::cards){
        cout << card.toString() << endl;
    }
}
void CardDeck::printShort(){
    for(Card card:CardDeck::cards){
        cout << card.toStringShort() << endl;
    }
}
void CardDeck::shuffle(){
    for(int i = 0; i < 1200; i++){
        int tilfeldig_tall1;
        tilfeldig_tall1 = (rand() % (52));
        int tilfeldig_tall2;
        tilfeldig_tall2 = (rand() % (52));
        CardDeck::swap(tilfeldig_tall1,tilfeldig_tall2);
    }
}
Card CardDeck::drawCard(){
    Card card = CardDeck::cards.back();
    CardDeck::cards.pop_back();
    return card;
}
