#include "Oppg1.h"
#include "iostream"
void fillInFibonacciNumbers(int result[],int length){
    //for de to første feltene er det hardkodet til å være 1 og 0 da de må være der for å bruke den rekursive formelen
    for(int i = 0; i<length;i++){
        if(i<=1){
            result[i] = i;
        }else{
            //den rekursive formelen for fibonacci
            result[i] = result[i-1]+result[i-2];
        }
    }
}
void printArray(int arr[], int length){
    //har importert iostream for å bruke std::cout
    for(int i = 0; i<length; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}

void createFibonacci(){
    //tar cin fra iostream, lager een tom matrise av størrelse n med dynamisk allokering, kjører de to tidligere funksjonene, før jeg firgjør minnet ved å slette fibArr
    std::cout << "Skriv inn antall fibonaccitall: ";
    int n;
    std::cin >> n;
    int * fibArr = new int[n];
    fillInFibonacciNumbers(fibArr,n);
    printArray(fibArr,n);
    delete[] fibArr;
}