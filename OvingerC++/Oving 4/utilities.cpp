#include "std_lib_facilities.h"
int incrementByValueNumTimes(int startValue, int increment, int numTimes) { 
    for (int i = 0; i < numTimes; i++) {
        startValue += increment; 
    }
    return startValue; 
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) { 
    for (int i = 0; i < numTimes; i++) {
        startValue += increment; 
    }
    return startValue; 
}

//swapnumbers bør bruke referanser slik at funksjonen kan bytte om på variabelverdiene uten at main må bruke verdier fra swapNumbers for å endre tallverdiene
void swapNumbers(int& int1, int& int2){
    int temp = int1;
    int1 = int2;
    int2 = temp;
}

void randomizeVector(vector<int>& vect, int n){
    for(int i = 0; i < n; i++){
         vect.push_back(rand());
    }
}
