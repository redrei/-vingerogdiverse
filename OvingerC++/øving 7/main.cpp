//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Animals.h"
#include "Tests.h"
#include "Emoji.h"
#include "Simple_window.h"
#include "Emojiis.h"

//------------------------------------------------------------------------------'
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 60;
// C++ programs start by executing the function main
int main()
{

	/* Oppgave 1
	Public betyr at metoden eller attributten er tilgjengelig for alle som har tilgang til objektet (eller klassen hvis den er statisk)
	Private betyr at bare dette objektet kan kalle disse metodene eller lese og endre på disse attributtene direkte
	Protected betyr at bare objekter av denne klassen, og objekter av klassen som arver den kan kalle metoden eller lese/endre på attributten

	*/
	cout << "Hello, World!\n";
	testAnimal();

	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/
	WinkingFace wf{100,100,12,emojiRadius};
	SurprisedFace suf{220,100,12,emojiRadius};
	AngryFace af{340,100,12,emojiRadius};
	SadFace saf{100,220,12,emojiRadius};
	SmilingFace sf{220,220,12,emojiRadius};
	EmptyFace ef{340,220,12,emojiRadius};
	Vector_ref<Face> faces{};
	faces.push_back(wf);
	faces.push_back(suf);
	faces.push_back(af);
	faces.push_back(saf);
	faces.push_back(sf);
	faces.push_back(ef);
	for(auto face:faces){
		face->attach_to(win);
	}
	win.wait_for_button();
}

//------------------------------------------------------------------------------
