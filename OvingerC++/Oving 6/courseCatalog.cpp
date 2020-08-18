#include "courseCatalog.h"

void CourseCatalog::addCourse(string code, string name){
    courses[code] = name;
    /*courses.insert(pair<string,string>{code,name});
    Med insert oppdaterer ikke mapen seg, sannsynligvis fordi insert sjekker om det allerede finnes noe med et navn, slik at det kun tillater
    å sette inn nye pairs, og ikke oppdatere gamle
    */

}

void CourseCatalog::removeCourse(string code){
    if(!CourseCatalog::courses[code].empty()){
        courses.erase(code);
    }
}

string CourseCatalog::getCourse(string code){
    return courses[code];
}

ostream& operator<<(ostream &out,const CourseCatalog &CourseCatalog){
    for(pair<string,string> course:CourseCatalog.courses){
        out << course.first << "," << course.second << "\n";
    }
    return out;
}

void CourseCatalog::writeToFile(string filename){
    ofstream ofs{};
    ofs.open(filename);
    ofs << *this;
    ofs.close();
}

void CourseCatalog::readFromFile(string filename){
    ifstream ifs{};
    ifs.open(filename);
    string in;
    while(getline(ifs,in)){
        bool i = true;
        vector<string> course{2};
        while(!in.empty()){
            if(i){
                course[0] += in[0];
                in.erase(in.begin());
                if(in[0] == ','){
                    i = false;
                }
            }else{
                course[1] += in[0];
                in.erase(in.begin());
            }
        }
        CourseCatalog::addCourse(course[0],course[1]);
    }
    ifs.close();
}
