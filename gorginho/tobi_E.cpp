#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    float x, y;
    string resultado;

    cin >> x >> y;

    if (x == 0) {
        if (y == 0) resultado = "Origem";
        else resultado = "Eixo Y";
    } else if (y == 0) {
        resultado = "Eixo X";
    }

    else if (x>0) {
        if (y>0) resultado = "Q1";
        else resultado = "Q4";
    } else {
        if (y>0) resultado = "Q2";
        else resultado = "Q3";
    }

    //cout << "x: " << x << " " << "y: " << y << "\n";
    cout << resultado << "\n";
}