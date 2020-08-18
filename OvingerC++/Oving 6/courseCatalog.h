#include "textfunc.h"
#pragma once

class CourseCatalog{
    private:
        map<string,string> courses;
    public:
        friend ostream& operator<<(ostream&, const CourseCatalog&);
        void addCourse(string code, string name);
        void removeCourse(string code);
        string getCourse(string code);
        void writeToFile(string filename);
        void readFromFile(string filename);

};