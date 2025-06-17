#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long long nJogos;
    cin >> nJogos;
    long long nVitorias = 0;

    for (long long i = 0; i<nJogos; i++) {
        long long porta;
        cin >> porta;

        if (porta != 1) nVitorias++;
    }

    cout << nVitorias << "\n";


}