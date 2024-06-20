#include <iostream>
#include <vector>
#include <algorithm>

long long get_sum_of_digits(long long number) {
    long long sum=0;
    for(int i=0; i<7; i++) {
        sum += number%10;
        number /= 10;
    }
    return sum;
}

int main() {
    long long flowersQuantity, gertrudePosition, orderedFlowersIndex = 0;
    std::vector<long long> flowers;
    std::vector<long long> orderedFlowers;

    std::cin >> flowersQuantity >> gertrudePosition;

    for (long long i=0; i<flowersQuantity; i++) { // armazena pólen das flores
        long long flower;
        std::cin >> flower;
        flowers.push_back(flower);
        std::push_heap(flowers.begin(), flowers.end());
    }

    for (long long i=0; i<flowersQuantity; i++) { // ordena pólens do maior para o menor em orderedFlowers
        std::pop_heap(flowers.begin(), flowers.end());
        orderedFlowers.push_back(flowers.back());
        flowers.pop_back();
    }

    // orderedFlowers agora tem uma lista do maior pólen para o menor...

    for (long long i=1; i<=gertrudePosition; i++) { // pra cada abelha até gertrude
        // achar a flor com mais pólen
        // tirar polen dela
        // printar a quantidade de polen que gertrude vai pegar

        long long * flower = &orderedFlowers[orderedFlowersIndex]; // ponteiro para a flor atual
        long long pollenQuantityToCollect = get_sum_of_digits(*flower); // calcula quantidade de polen a ser coletada
        *flower -= pollenQuantityToCollect; // retira o pólen da flor
        if (orderedFlowersIndex == flowersQuantity-1) orderedFlowersIndex = 0; // caso tenha chegado no fim do array, volta para o inicio
        else if (*flower < orderedFlowers[orderedFlowersIndex+1]) orderedFlowersIndex++; // caso o pólen da flor atual esteja menor do que o da próxima flor, passa para a flor seguinte
        
        if (i == gertrudePosition) {
            std::cout << "eh a GERTRUDE! (" << i << ") abelha!" << "\n";
            std::cout << pollenQuantityToCollect << "\n";
        } else {
            std::cout << "eh a " << i << " abelha!" << "\n";
        }

        
        for (long long k=0; k<orderedFlowers.size(); k++) std::cout << orderedFlowers.at(k) << " ";
        std:: cout << "\n";

        
            
    }



    
        
}