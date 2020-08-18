#include "std_lib_facilities.h"
#pragma once

enum Suit {clubs,diamonds,hearts,spades};
enum Rank {two = 2, three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace};
string suitToString(Suit card);
string rankToString(Rank card);

class Card{
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        string toString();
        string toStringShort();
};