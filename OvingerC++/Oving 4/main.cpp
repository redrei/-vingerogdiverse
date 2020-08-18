

#include "test.h"

//------------------------------------------------------------------------------'

//Oppgave 1a V0 blir skrevet ut som 5 da det er pass by value og ikke pass by reference


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	testCallByValue();
	testCallByReference();
	testVectorSorting();
}

//------------------------------------------------------------------------------
