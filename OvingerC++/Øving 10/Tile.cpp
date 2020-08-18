#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };

void Tile::open()
{
	//hvis den er flagget skjer ingenting
	if(hasFlag){
		return;
	}
	static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket paa, tilsvarer aapnet rute
	state = Cell::open;
	//hvis den er en mine blir den markert med en stor rød X
	if(isMine){
		set_label("X");
		set_label_color(Graph_lib::Color::red);
	}
}

void Tile::flag()
{
	//hvis den alt er flagget fjernes flagget
	if(hasFlag){
		state = Cell::closed;
		set_label("");
		hasFlag = false;
	//hvis den ikke er flagget blir den flagget
	}else{
		state = Cell::flagged;
		hasFlag = true;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(Graph_lib::Color::blue);
	}
}

void Tile::setMine(bool mine){
	isMine = mine;
}

bool Tile::getMine() const{
	return isMine;
}

void Tile::setAdjMines(int n){
	//hvis den har noen nabominer, som må være et tall fraogmed 0 tilogmed 8 så skrives dette på tilen, med tilhørende farge. hvis det
	//ikke er noen nabominer så skjer ingenting her
	if(0<n and 9 > n){
		set_label(to_string(n));
		set_label_color(minesToColor.at(n));
	}
}