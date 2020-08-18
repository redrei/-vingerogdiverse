#include "std_lib_facilities.h"

double maxOfTwo(double a, double b){
    if(a>b){
        cout << "A is greater than B\n";
        return a;
    }else{
        cout << "B is greater than or equal to A\n";
        return b;
    }
}

int fibonacci(int n){
    int a = 0;
    int b = 1;
    for(int x = 1; x<=n;x++){
        cout << x << " " << b << "\n";
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----\n";
    return b;
}

int squareNumberSum(int n){
    int totalSum = 0;
    for(int i =0;i<n;i++){
        totalSum += i*i;
        cout << i*i << "\n";
    }
    cout << totalSum << "\n";
    return totalSum;
}

void triangleNumbersBelow(int n){
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":\n"; 
    while (acc < n){
        cout << acc << endl; 
        acc += num;
        num += 1;
    }
    cout << endl;
    return;
}

bool isPrime(int n){
    for(int j = 2; j<n;j++){
        if(n%j == 0){ 
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n){ 
    for(int i = 2; i<n; i++){
        if (isPrime(i)){
            cout << i << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n){
    for(int i = n-1; i > 0; i--){
        if(!(n%i)){ 
            return i;
        }
    }
    return -1;
}


int main(){
    cout << "Oppgave b\n";
    cout << maxOfTwo(5,6) <<'\n';
    cout << "Oppgave c\n";
    cout << fibonacci(8) << "\n";
    cout << "Oppgave d\n";
    cout << squareNumberSum(5) << "\n";
    cout << "Oppgave e\n";
    triangleNumbersBelow(5);
    cout << "Oppgave f\n";
    cout << std::boolalpha << isPrime(5) << endl << std::boolalpha << isPrime(6) << endl;
    cout << "Oppgave g\n";
    naivePrimeNumberSearch(8);
    cout << "Oppgave h\n";
    cout << findGreatestDivisor(12) << endl;
}