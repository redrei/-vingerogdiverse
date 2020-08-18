#include "Blackjack.h"
class Blackjack{
    private:
        CardDeck deck;
        vector<Card> dHand;
        vector<Card> pHand;
    public:
        Blackjack(){
            deck = CardDeck{};
            deck.shuffle();
            pHand.push_back(deck.drawCard());
            dHand.push_back(deck.drawCard);
            pHand.push_back(deck.drawCard);
            dHand.push_back(deck.drawCard);
        }
        void printHands(){
            cout << "Dealer: ";
            for(Card card:dHand){
                cout << " " << card.toStringShort();
            }
            cout << endl << "Player: ";
            for(Card card:pHand){
                cout << " " << card.toStringShort();
            }
            cout << endl;

        }
};