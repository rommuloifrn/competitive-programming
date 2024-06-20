#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    long long lojasQtd, tabacoQtd; cin >> lojasQtd >> tabacoQtd;

    std::vector<long long> distanciasDasLojas[lojasQtd];

    for (long long i; i<lojasQtd; i++) {
        cin >> distanciasDasLojas[i];
    }

    for (long long i; i<lojasQtd; i++) {
        cout << distanciasDasLojas[i];
    }

    return 0;
} 