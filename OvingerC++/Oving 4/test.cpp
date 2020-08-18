# include "utilities.h"
void testCallByValue() { 
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations); 
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference() { 
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations); 
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    randomizeVector(percentages, 40);
    for(int k : percentages){
        cout << k << ", ";
    }
    cout << endl;
    swapNumbers(percentages[0],percentages[1]);
    for(int k : percentages){
        cout << k << ", ";
    }
    cout << endl;
}