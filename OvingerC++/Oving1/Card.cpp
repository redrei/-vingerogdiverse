#include "Card.h"
string suitToString(Suit card){
    map<Suit,string> sToS;
    sToS[Suit::clubs] = "Clubs";
    sToS[Suit::diamonds] = "Diamonds";
    sToS[Suit::hearts] = "Hearts";
    sToS[Suit::spades] = "Spades";
    return sToS[card];
}
string rankToString(Rank card){
    map<Rank,string> rToS;
    rToS[Rank::two] = "Two";
    rToS[Rank::three] = "Three";
    rToS[Rank::four] = "Four";
    rToS[Rank::five] = "Five";
    rToS[Rank::six] = "Six";
    rToS[Rank::seven] = "Seven";
    rToS[Rank::eight] = "Eight";
    rToS[Rank::nine] = "Nine";
    rToS[Rank::ten] = "Ten";
    rToS[Rank::jack] = "Jack";
    rToS[Rank::queen] = "Queen";
    rToS[Rank::king] = "King";
    rToS[Rank::ace] = "Ace";
    return rToS[card];
}

class Card{
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank): s{suit},r{rank}{} 
        Suit getSuit() {return s;}
        Rank getRank(){return r;}
        string toString(){return suitToString(s) + " of " + rankToString(r);}
        string toStringShort(){
            return suitToString(s)[0] + to_string(r);
        }
};

