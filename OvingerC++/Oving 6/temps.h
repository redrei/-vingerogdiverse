#include "std_lib_facilities.h"
#pragma once
class Temps{

    public:
    double max;
    double min;
    friend istream& operator>>(istream& is, Temps& t);
};