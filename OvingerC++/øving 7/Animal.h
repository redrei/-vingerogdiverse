#include "std_lib_facilities.h"
#pragma once
class Animal{
    protected: 
        string name;
        int age;
    public:
        Animal(string n, int a):name{n},age{a}{};
        virtual string toString() = 0;
};