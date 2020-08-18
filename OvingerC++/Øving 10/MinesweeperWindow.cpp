#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, (height+1)*cellSize, title}, width{width}, height{height}, mines{mines},gameText{Point{width*cellSize/2,height*cellSize/2},""},minesLeft{mines},mineText{Point{20,(1+height)*cellSize - 10},"Miner igjen: " + to_string(minesLeft)}
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen, jeg utvidet vinduet med en cellsize for å få plass til litt tekst
{
	// Legg til alle tiles paa vinduet
	mineText.set_color(Color::black);
	mineText.set_font_size(20);
	gameText.set_color(Color::black);
	gameText.set_font_size(28);
	//lager et minefelt for å holde på hvilke tiles som inneholder miner, og finner den første minen
	vector<int> mineField{};
	mineField.push_back(rand()%(width*height));
	while(mineField.size() < mines){
		//legger til miner til minefeltet inntil minefeltet er fullt, hvis plassen til minen alt er tatt så finner den en ny en
		int newTile = rand()%(width*height);
		bool add = true;
		for(int x:mineField){
			if(x == newTile){
				add = false;
				break;
			}
		}
		if(add){
			//bekrefter plassen til minen i minefeltet
			mineField.push_back(newTile);
		}
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			bool hasMine = false;
			//sjekker om tilen burde ha en mine
			for(int x:mineField){
				//bruker en nummerering som gir hver av tilene en unik id fra 0 til width*height-1
				hasMine = ((i*width + j) == x);
				if(hasMine) break;
			}
			//bruker de to forskjellige konstruktørene, selv om det er totalt unødvendig, da jeg synes det var rart å ha en defaultverdi 
			// i oppgaven uten å bruke den
			if(hasMine){
				tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click,hasMine});
			}else{
				tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click});
			}
			attach(tiles.back());
		}
	}

	//fester på teksten for minene
	attach(mineText);
	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& currentTile = at(xy);
	if(currentTile.getState() == Cell::closed){
		//markerer minen med antall nabominer
		int neighbourMines = countMines(adjacentPoints(xy));
		currentTile.setAdjMines(neighbourMines);
		currentTile.open();
		//hvis tilen er en mine så er det game over
		if(currentTile.getMine()){
			gameText.set_label("Game Over");
			gameText.move(-gameText.font_size()*3,0);
			attach(gameText);
			//åpner alle tilene, siden da markeres minene med en rød X
			for(auto x:tiles){
				x->open();
			}
		//her skjer den rekursive funksjonen, at hvis ingen av nabotilene er miner, så åpnes de
		}else if(neighbourMines == 0 ){
			for(auto x:adjacentPoints(xy)){
				openTile(x);
			}
		}
		//sjekker om spilleren har vunnet ved at hvis antall uåpnede tiles tilsvarer antall miner, så må alle tilene som ikke er
		//miner være åpnet
		int unopened = 0;
		for(auto x: tiles){
			if(x->getState() == Cell::closed or x->getState() == Cell::flagged){
				unopened++;
			}
		}
		if(unopened == mines){
			//setter spillteksten til å si at spillet er vunnet
			gameText.set_label("Game Won");
			gameText.move(-gameText.font_size()*3,0);
			attach(gameText);
			for(auto x:tiles){
				//flagger alle gjenværende tiles for å markere at de var miner
				if(x->getMine() and x->getState() != Cell::flagged){
					x->flag();
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& currentTile = at(xy);
	if(currentTile.getState() != Cell::open){
		currentTile.flag();
		//oppdaterer verdien for antall miner som er igjen etter man har flagget, siden boolske verdier representeres som 0 og 1 gjør det 
		//det til et enkelt regnestykkes der man trekker fra en hvis den er flagget og legger til en hvis den ikke er flagget lenger
		minesLeft -= (currentTile.getState() == Cell::flagged) - (currentTile.getState() == Cell::closed);
		mineText.set_label("Miner igjen: " + to_string(minesLeft));
		//redrawer for å slippe kaos
		redraw();
	}

}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mines = 0;
	//går igjennom alle tilene, og sjekker om de har en mine, og teller de i summen mines, som returneres.
	for(Point xy:coords){
		const Tile& currentTile = at(xy);
		if(currentTile.getMine()){
			mines++;
		}
	}
	return mines;
}
