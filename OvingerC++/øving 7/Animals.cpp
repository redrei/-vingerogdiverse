#include "Animals.h"

string Dog::toString(){
    return "Dog: " + name + ", " + to_string(age);
}

string Cat::toString(){
    return "Cat: " + name + ", " + to_string(age);
}