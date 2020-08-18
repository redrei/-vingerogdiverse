#include "Blackjack.h"
Blackjack::Blackjack(){
    Blackjack::game = true;
    Blackjack::deck = CardDeck{};
    Blackjack::deck.printShort();
    Blackjack::deck.shuffle();
    Blackjack::deck.printShort();
    Blackjack::pHand.push_back(Blackjack::deck.drawCard());
    Blackjack::dHand.push_back(Blackjack::deck.drawCard());
    Blackjack::pHand.push_back(Blackjack::deck.drawCard());
    Blackjack::dHand.push_back(Blackjack::deck.drawCard());
    Blackjack::printHands();
    if(Blackjack::hasBlackjack(Blackjack::pHand) and Blackjack::hasBlackjack(Blackjack::dHand)){
        cout << "Begge fikk ekte blackjack, uavgjort" << endl;
        Blackjack::game = false;
        return;
    }else if(Blackjack::hasBlackjack(Blackjack::pHand)){
        cout << "Du fikk ekte blackjack og vant! Gratulerer!" << endl;
        Blackjack::game = false;
        return;
    }else if(Blackjack::hasBlackjack(Blackjack::dHand)){
        cout << "Dealeren fikk ekte blackjack, og du tapte..." << endl;
        Blackjack::game = false;
        return;
    }
}

bool Blackjack::hasBlackjack(vector<Card> hand){
    return ((hand[0].getRank()<14 and hand[0].getRank() >= 11 and hand[1].getRank()==14) or (hand[1].getRank()<14 && hand[1].getRank() >= 11 && hand[0].getRank()==14));
}

int Blackjack::countPoints(vector<Card> hand){
    int sum = 0;
    int aces = 0;
    for(Card card:hand){
        if(card.getRank() < 11){
            sum += card.getRank();
            continue;
        }
        if(card.getRank() >= 11 and card.getRank() < 14){
            sum += 10;
            continue;
        }
        if(card.getRank() == 14){
            aces++;
            continue;
        }
    }
    while(aces > 0){
        if(sum <= 10){
            sum += 11;
        }else{
            sum += 1;
        }
        aces--;
    }
    return sum;
}

void Blackjack::hit(){
    Blackjack::pHand.push_back(Blackjack::deck.drawCard());
    if(Blackjack::countPoints(Blackjack::pHand) > 21){
        Blackjack::printHands();
        cout << "Du fikk mer enn 21 poeng... du tapte..." << endl;
        Blackjack::game = false;
        return;
    }else if(Blackjack::countPoints(Blackjack::dHand) < 17){
        Blackjack::dHand.push_back(Blackjack::deck.drawCard());
        Blackjack::printHands();
        if(Blackjack::countPoints(Blackjack::dHand) > 21){
            cout << "Dealeren fikk mer enn 21 poeng. Du Vant!" << endl;
            Blackjack::game = false;
            return;
        }
    }
    if(Blackjack::countPoints(Blackjack::dHand) > 17 and Blackjack::countPoints(Blackjack::pHand) > Blackjack::countPoints(Blackjack::dHand)){
        cout << "Du fikk mer poeng enn dealeren etter at dealeren har fått 17 poeng. Du Vant!" << endl;
        Blackjack::game = false;
    }
}

void Blackjack::stand(){
    while(Blackjack::countPoints(Blackjack::dHand) < 17){
        Blackjack::dHand.push_back(Blackjack::deck.drawCard());
        Blackjack::printHands();
    }
    if(Blackjack::countPoints(Blackjack::dHand) > 21 ){
        cout << "Dealeren fikk mer enn 21 poeng og du Vant!" << endl;
        Blackjack::game = false;
        return;
    }

    if(Blackjack::countPoints(Blackjack::pHand) > Blackjack::countPoints(Blackjack::dHand)){
        cout << "Du fikk mer poeng enn dealeren etter at dealeren har fått 17 poeng. Du Vant!" << endl;
        Blackjack::game = false;
        return;
    }else{
        cout << "Du fikk ikke mer poeng enn dealeren og tapte..." << endl;
        Blackjack::game = false;
    }

}

void Blackjack::printHands(){
    cout << "Dealer: ";
    for(Card card:Blackjack::dHand){
        cout << " " << card.toStringShort();
    }
    cout << endl << "Player: ";
    for(Card card:Blackjack::pHand){
        cout << " " << card.toStringShort();
    }
    cout << endl;

}

bool Blackjack::getGame(){
    return Blackjack::game;
}