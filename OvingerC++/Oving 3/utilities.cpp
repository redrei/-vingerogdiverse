#include "std_lib_facilities.h"
int randomWithLimits(int low, int high){
    if(high < low) throw invalid_argument{"High må være større enn low..."};
    int tilfeldig_tall;
    tilfeldig_tall = (rand() % (high-low))+low;
    return tilfeldig_tall;
}
