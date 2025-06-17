#include <stdio.h>
#include <iostream>
using namespace std;

bool ehPrimo(long long n) {
    for (int i = n-1; i>1; i--)
        if (n%i == 0) return false;
    
    return true;
}

int main() {
    long long n;
    cin >> n;

    long long possivelPrimo = n+1;
    while (true) {
        if (ehPrimo(possivelPrimo)) {
            cout << possivelPrimo;
            return 0;
        }

        possivelPrimo++;
    }
}