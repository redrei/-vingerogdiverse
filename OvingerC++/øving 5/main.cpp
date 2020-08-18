#include "Blackjack.h"

// Vi har valgt å bruke symboler istedenfor tall for å få en ryddigere kode, slik at det blir lettere å se hva som skal hvor.
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Blackjack jack{};
	while(jack.getGame()){
		int valg;
		cin >> valg;
		switch(valg){
			case 1: jack.hit(); break;
			case 2: jack.stand(); break;
			default: cout << "ugyldig input" << endl;
		}
	}
}

//------------------------------------------------------------------------------
