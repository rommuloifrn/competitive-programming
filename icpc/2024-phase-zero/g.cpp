#include <iostream>
#include <algorithm>
#include <vector>
//using namespace std;

int main(){
    
    long long lojasQtd, tabacoQtd; std::cin >> lojasQtd >> tabacoQtd;

    std::vector<long long> distanciasDasLojas;
    std::vector<long long> tabacoDasLojas;

    for (long long i=0; i<lojasQtd; i++){
        long long distancia; std::cin >> distancia;
        distanciasDasLojas.push_back(distancia);
    }

    for (long long i=0; i<lojasQtd; i++) {
        long long tabaco; std::cin >> tabaco;
        tabacoDasLojas.push_back(tabaco);
    }
    
    if (tabacoQtd > distanciasDasLojas.at(lojasQtd-1))
        std::cout << 0 << "\n";

    return 0;
} 