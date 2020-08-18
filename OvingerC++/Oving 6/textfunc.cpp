#include "textfunc.h"
void readtofile(){
    cout << "Skriv noe" << endl;
	string in;
	ofstream ofs{};
	ofs.open("./out/1a.txt");
	getline(cin,in);
	while(!(in == "") and !in.empty()){
		string word;
		string tempin = in;
		for(char ch : in){
			tempin.erase(0,1);
			if(ch == ' '){
				break;
			}
			word += ch;
		}
		in = tempin;
        if(word == "quit"){
            return;
        }
		ofs << word << endl;	
	}
	ofs.close();
}

void fileToFile(string inFile){
    ifstream ifs{};
    ofstream ofs{};
    ifs.open(inFile);
    ofs.open("./out/1b.txt");
    string in;
    int i = 0;
    while(getline(ifs,in)){
        i++;
        ofs << i << " " << in << endl; 
    }
    ofs.close();
}

map<char,int> readStats(string inFile){
    ifstream ifs{};
    ifs.open(inFile);
    map<char,int> omap;
    string intext;
    while(getline(ifs,intext)){
        for(char ch:intext){
            if((ch >= 65 and ch <= 90) or (ch >=97 and ch <= 122)){
                omap[ch] += 1;
            }
        }
    }
    ifs.close();
    return omap;
}