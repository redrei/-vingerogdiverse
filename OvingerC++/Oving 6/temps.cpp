#include "temps.h"
istream& operator>>(istream& is, Temps& t){
    string in;
    getline(is,in);
    double max = 0;
    double min = 0;
    int decimal = -1;
    bool maxb = true;
    int negative = 1;
    bool point = false;
    for(char ch:in){
        if(ch == '-'){
            negative = -1;
        }
        else if(ch == '.'){
            point = true;
        }
        else if(ch == ' ' or ch =='\t'){
            maxb = false;
            negative = 1;
            decimal = -1;
            point = false;
        }
        else if(ch >= '0' and ch <= '9' and maxb and !point){
            max *= 10;
            max += negative*(ch-'0');
        }
        else if(ch >= '0' and ch <= '9' and maxb and point){
            max += negative*(ch-'0')*pow(10,decimal);
            decimal--;
        }
        else if(ch >= '0' and ch <= '9' and !maxb and !point){
            min *= 10;
            min += negative*(ch-'0');
        }
        else if(ch >= '0' and ch <= '9' and !maxb and point){
            min += negative*(ch-'0')*pow(10,decimal);
            decimal--;
        }
    }
    t.max = max;
    t.min = min;
    return is;
}