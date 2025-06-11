#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int qtdFrango, qtdBife, qtdMassa;
    int pedFrango, pedBife, pedMassa, resultado = 0;

    cin >> qtdFrango >> qtdBife >> qtdMassa;
    cin >> pedFrango >> pedBife >> pedMassa;

    if (pedFrango > qtdFrango) resultado += pedFrango - qtdFrango;
    if (pedBife > qtdBife) resultado += pedBife - qtdBife;
    if (pedMassa > qtdMassa) resultado += pedMassa - qtdMassa;

    cout << resultado << "\n";
}