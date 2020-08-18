//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
#include "Oppg1.h"
#include "iostream"
#include "Matrix.h"
#include "Dummy.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	//tester oppgave 1
	createFibonacci();
	//tester om matrisekonstruktørene funker som forventet
	std::cout << Matrix{5};
	std::cout << Matrix{5,10};
	std::cout << Matrix{};
	dummyTest();
	//lager matrisene for testen
	Matrix a{2,2};
	Matrix b{a};
	Matrix c{a};
	a[0][0] = 1.0;
	a[0][1] = 2.0;
	a[1][0]= 3.0;
	a[1][1]=4.0;
	b[0][0] = 4.0;
	b[0][1] = 3.0;
	b[1][0]= 2.0;
	b[1][1]=1.0;
	c[0][0] = 1.0;
	c[0][1] = 3.0;
	c[1][0]= 1.5;
	c[1][1]=2.0;
	a+=b+c;
	std::cout <<"A"<<std::endl<<a<< "B"<<std::endl<<b << "C"<<std::endl<<c;
	return 0;
}

/* Oppgave 3
a)
 a:4
 b:4
 c:4
 a:5
 b:5
 c:5
b) det stemte, og det skjer på grunn av at int* num er en pointer, og siden c=a kopieres pointeren, og siden b{a} kopieres også pointeren.
Dette medfører at hvis man endrer på verdien til en av dummyenes num så endrer man på alle dummyenes num sin verdi.
programmet krasjet til slutt fordi at når funksjonen var ferdig og prøvde å destruere dummyene så går det fint med den første, mens den andre og tredje prøver
den også å destruere num på, men den er allerede destruert fra destruksjonen av den første dummyen, noe som fører til et krasj. 
c)	a:4,b:4,c:4,a:5,b:3,c:5, den krasjer fordi c prøver å slette num etter a har slettet den
d)a:4,b:4,c:4,a:4,b:3,c:5, nå kopierer programmet dypt, slik at verdiene er uavhengige av hverandre

*/



//------------------------------------------------------------------------------
