#include "Blackjack.h"

// Vi har valgt å bruke symboler istedenfor tall for å få en ryddigere kode, slik at det blir lettere å se hva som skal hvor.
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Blackjack jack{};
	jack.printHands();
}

//------------------------------------------------------------------------------
