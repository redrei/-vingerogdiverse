//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "textfunc.h"
#include "courseCatalog.h"
#include "temps.h"
#include "Graph.h"
#include "Window.h"
#include "Simple_window.h"
#include "fltk.h"
#include "Point.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	fileToFile("./out/1a.txt");
	map<char,int> amap = readStats("./tekst/grunnlov.txt"); 
	for(auto elem : amap){
   		std::cout << elem.first << " " << elem.second << "\n";
	}
	CourseCatalog ctl{};
	ctl.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	ctl.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	ctl.addCourse("TMA4100","Matematikk 1");
	cout << (ctl.getCourse("TDT4102"))<< endl;
	cout << ctl << endl;
	ctl.addCourse("TDT4102","C++");
	cout << ctl << endl;
	ctl.writeToFile("./out/3e.txt");
	ctl.removeCourse("TDT4102");
	cout << ctl << endl;
	CourseCatalog ctl2{};
	ctl2.readFromFile("./out/3e.txt");
	cout << ctl2 << endl;
	vector<Temps> tempvector{};
	ifstream ifs{};
	ifs.open("./tekst/temperatur.txt");
	while(!ifs.eof()){
		Temps temperatures{};
		ifs >> temperatures;
		tempvector.push_back(temperatures);
	}
	for(Temps i:tempvector){
		cout << i.max << ", " << i.min << endl;
	}
	ifs.close();
	int a=5;
	cout << 10/a;


// Shitty graphics

	Simple_window win{Graph_lib::Point{0,0},830,500,"graphwin"};	
	Graph_lib::Axis xax{Graph_lib::Axis::x,Graph_lib::Point{15,260},732,12,""};
	xax.set_color(Color::black);
	Graph_lib::Axis yax{Graph_lib::Axis::y,Graph_lib::Point{15,460}, 400,5,""};
	yax.notches.move(0,220-540/3);
	yax.set_color(Color::black);
	Graph_lib::Open_polyline maxg{};
	maxg.set_color(Color::red);
	Graph_lib::Open_polyline ming{};
	ming.set_color(Color::blue);
	for(int i = 0; i< tempvector.size(); i++){
		cout << i;
		maxg.add(Graph_lib::Point{2*i+15,-int(tempvector[i].max)*(500/3)/20+260});
		ming.add(Graph_lib::Point{2*i+15,-int(tempvector[i].min)*(500/3)/20+260});
	}
	int basis = 30;
	int multiplier = 60;
	Text februar{Graph_lib::Point{basis,280},"Februar"};
	Text mars{Graph_lib::Point{basis+multiplier,280},"Mars"};
	Text april{Graph_lib::Point{basis+multiplier*2,280},"April"};
	Text mai{Graph_lib::Point{basis+multiplier*3,280},"Mai"};
	Text juni{Graph_lib::Point{basis+multiplier*4,280},"Juni"};
	Text juli{Graph_lib::Point{basis+multiplier*5,280},"Juli"};
	Text august{Graph_lib::Point{basis+multiplier*6,280},"August"};
	Text september{Graph_lib::Point{basis+multiplier*7,280},"Sept"};
	Text oktober{Graph_lib::Point{basis+multiplier*8,280},"Okt"};
	Text november{Graph_lib::Point{basis+multiplier*9,280},"Nov"};
	Text desember{Graph_lib::Point{basis+multiplier*10,280},"Des"};
	Text januar{Graph_lib::Point{basis+multiplier*11,280},"januar"};
	februar.set_color(Color::black);
	mars.set_color(Color::black);
	april.set_color(Color::black);
	mai.set_color(Color::black);
	juni.set_color(Color::black);
	juli.set_color(Color::black);
	august.set_color(Color::black);
	oktober.set_color(Color::black);
	november.set_color(Color::black);
	september.set_color(Color::black);
	desember.set_color(Color::black);
	januar.set_color(Color::black);
	Text minustjue{Graph_lib::Point{0,260+500/3},"-20"};
	Text minusti{Graph_lib::Point{0,260+500/6},"-10"};
	Text nulltxt{Graph_lib::Point{0,260},"0"};
	Text plussti{Graph_lib::Point{0,260-500/6},"10"};
	Text plusstjue{Graph_lib::Point{0,260-500/3},"20"};
	minustjue.set_color(Color::black);
	minusti.set_color(Color::black);
	nulltxt.set_color(Color::black);
	plussti.set_color(Color::black);
	plusstjue.set_color(Color::black);
	cout << "test";
	xax.draw_lines();
	yax.draw_lines();
	maxg.draw_lines();
	ming.draw_lines();
	win.attach(minusti);
	win.attach(minustjue);
	win.attach(nulltxt);
	win.attach(plusstjue);
	win.attach(plussti);
	win.attach(februar);
	win.attach(mars);
	win.attach(april);
	win.attach(mai);
	win.attach(juni);
	win.attach(juli);
	win.attach(august);
	win.attach(september);
	win.attach(oktober);
	win.attach(november);
	win.attach(desember);
	win.attach(januar);
	win.attach(xax);
	win.attach(yax);
	win.attach(maxg);
	win.attach(ming);
	win.wait_for_button();
}

//------------------------------------------------------------------------------
