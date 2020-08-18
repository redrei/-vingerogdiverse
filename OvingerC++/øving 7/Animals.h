#include "Animal.h"
#pragma once
class Cat:public Animal{
    public:
        Cat(string n, int a):Animal{n,a}{};
        string toString();
};

class Dog:public Animal{
    public:
        Dog(string n, int a):Animal{n,a}{};
        string toString();
};