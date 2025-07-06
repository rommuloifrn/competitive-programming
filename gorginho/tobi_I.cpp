#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long long nCaixas;
    cin >> nCaixas;

    long long maximoAtingido = 100;
    long long valorAtual = 100;

    for (long long i = 0; i < nCaixas; i++) {
        long long valorCaixa;

        cin >> valorCaixa;
        valorAtual += valorCaixa;

        if (valorAtual > maximoAtingido) 
            maximoAtingido = valorAtual;
    }

    cout << maximoAtingido << "\n";
}