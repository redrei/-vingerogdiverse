
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

void inputAndPrintInteger(){
    cout << "Skriv inn et tall: ";
    int anum;
    cin >> anum;
    cout << "Du skrev: " << anum << endl;
}

int inputInteger(){
    cout << "Skriv inn et tall: ";
    int anum;
    cin >> anum;
    return anum;
}

void inputIntegersAndPrintSum(){
    // Jeg bruker inputinteger ettersom den returner verdien, noe som gjør det enkelt for meg å bruke den, mens inputandprintinteger bare printer den, noe ssom gjør det
    //vanskeligere for meg å få tak i den
    int aint = inputInteger();
    int aintnt = inputInteger();
    cout << "Summen av tallene: " << aint + aintnt << endl;
}

bool isOdd(int n){
    if(n%2){
        return true;
    }
    return false;
}

void printHumanReadableTime(int secs){
    int s = secs%60;
    secs /= 60;
    int m = secs%60;
    secs /= 60;
    int h = secs;
    cout << h << " time(r), " << m << " minutt(er), " << s << " sekund(er)" << endl;
}

void sumFiniteNumberOfIntegers(){
    int n;
    cout << "Hvor mange tall skal du summere? ";
    cin >> n;
    int sum = 0;
    //her bruker jeg for løkke da det er et visst antall tall som skal inn
    for(int i = 1; i<=n;i++){
        int temp;
        cout << "Skriv inn tall nr. " << i << ": ";
        cin >> temp;
        sum += temp;
    }
    cout << "Summen ble... (trommevirvel): " << sum << endl;
}

void sumUnknownNumberOfIntegers(){
    int sum = 0;
    cout << "Skriv inn tall du vil summere, og avslutt med 0! " << endl << "Ditt tall: ";
    int tall;
    cin >> tall;
    //her bruker jeg en while-løkke da det er et uvisst antall tall som skal inn
    while(tall != 0){
        sum += tall;
        cout << "Neste tall: ";
        cin >> tall;
    }
    cout << "Summa summarum: " << sum << endl;;
}

double inputDouble(){
    double num;
    cout << "skriv inn et desimaltall: ";
    cin >> num;
    return num;
}

void nokToEUR(){
    double nok = inputDouble();
    while(nok < 0){
        cout << "Tallet må være positivt" << endl;
        nok = inputDouble();
    }
    double eur = nok / 9.75;
    cout << setprecision(2) << fixed << nok << " NOK tilsvarer " << eur << " EUR\n" ;
}

void timeTable(){
    int b;
    int h;
    cout << "Skriv inn bredde: ";
    cin >> b;
    cout << "Skriv inn høyde: ";
    cin >> h;
    for(int i = 1; i <= h; ++i){
        for(int k = 1; k <= b; ++k){
            cout << setw(4) << k*i;
        }
        cout << endl;    
    }
}

double discriminant(double a, double b, double c){
    return (b*b)-(4*a*c);
}

void printRealRoots(double a, double b, double c){
    int rootvalue = discriminant(a,b,c);
    if(rootvalue > 0){
        cout << "Svarene er " << (-b + sqrt(rootvalue))/2*a << " & " << (-b - sqrt(rootvalue))/2*a;
    } else if(rootvalue == 0){
        cout << "Svaret er " << -b/2*a;
    }else{
        cout << "Det er ingen reelle løsninger, men kanskje du kan forestille deg en?";
    }
    cout << endl;
}

void solveQuadraticEquation(){
    cout << "Skriv a, så i påfølgende linje b, så c" << endl << "a: ";
    int a;
    cin >> a;
    cout << "b: ";
    int b;
    cin >> b;
    cout << "c: ";
    int c;
    cin >> c;
    printRealRoots(a,b,c);
    
}

void pythagoras(){
    Simple_window win{Point{100,100},800,600,"Pythagoras"};
    Polygon rightTriangle;
    rightTriangle.add(Point{250,250}); 
    rightTriangle.add(Point{375,250}); 
    rightTriangle.add(Point{250,375});
    rightTriangle.set_fill_color(Color::red);
    win.attach(rightTriangle);
    Polygon squareOne;
    squareOne.add(Point{250,250});
    squareOne.add(Point{375,250});
    squareOne.add(Point{375,125});
    squareOne.add(Point{250,125});
    squareOne.set_fill_color(Color::dark_cyan);
    win.attach(squareOne);
    Polygon squareTwo;
    squareTwo.add(Point{250,250});
    squareTwo.add(Point{250,375});
    squareTwo.add(Point{125,375});
    squareTwo.add(Point{125,250});
    squareTwo.set_fill_color(Color::green);
    win.attach(squareTwo);
    Polygon squareThree;
    squareThree.add(Point{375,250});
    squareThree.add(Point{250,375});
    squareThree.add(Point{375,500});
    squareThree.add(Point{500,375});
    squareThree.set_fill_color(Color::dark_red);
    win.attach(squareThree);
    win.wait_for_button();
}

vector<int> calculateSeries(int belop, int rente, int aar){
    double avdrag = belop/aar;
    vector<int> betalinger;
    while(belop > 0){
        double rentebetaling = belop*rente/100;
        if(belop < avdrag){
            betalinger.push_back(belop + rentebetaling);
            belop = 0;
        }
        else{
            betalinger.push_back(avdrag + rentebetaling);
            belop -= avdrag;
        }
    }
    return betalinger;
}

vector<int> calculateAnnuity(int belop, int rente, int aar){
    double renteprosent = rente;
    renteprosent /= 100;
    double rentedel = renteprosent/(1-pow(1+renteprosent,-aar));
    double innbetaling = belop*rentedel;
    vector<int> betalinger;
    for(int i = 0; i < aar; ++i){
        betalinger.push_back(innbetaling);
    }
    return betalinger;
}


int main(){
    bool isRunning = true;
    while(isRunning){
        int k;
        cout << "Skriv inn oppgaven du vil se på (1-x): ";
        cin >> k;
        switch(k){
            case 1:
                inputAndPrintInteger();
                break;
            case 2:
                {int number = inputInteger();
                cout << "Du skrev: " << number << endl;
                break;}
            case 3:
                inputIntegersAndPrintSum();
                break;
            case 4:
                for (int i = 1; i <= 15; i++){
                    cout << i << " " << std::boolalpha << isOdd(i) << endl;
                }
                break;
            case 5:
                printHumanReadableTime(10000);
                break;
            case 6:
                sumFiniteNumberOfIntegers();
                break;
            case 7:
                sumUnknownNumberOfIntegers();
                break;
            case 8:
                nokToEUR();
                break;
            case 9:
                timeTable();
                break;
            case 10:
                solveQuadraticEquation();
                break;
            case 11:
                pythagoras();
                break;
            case 12:{
                vector<int> temp = calculateSeries(10000,5,10);
                for(auto x:temp){
                    cout <<x <<endl;
                }
                break;
            }
            case 13:{
                vector<int> temp = calculateAnnuity(10000,5,10);
                for(auto x:temp){
                    cout << x << endl;
                }
                break;
            }
            default:
                isRunning = false;
        }
    }
}