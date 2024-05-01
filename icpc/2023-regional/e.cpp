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
    long long flowersQuantity, gertrudePosition;
    std::vector<long long> flowers;

    std::cin >> flowersQuantity >> gertrudePosition;

    for (long long i=0; i<flowersQuantity; i++) {
        long long flower;
        std::cin >> flower;
        flowers.push_back(flower);
        std::push_heap(flowers.begin(), flowers.end());
    }

    // std::pop_heap(flowers.begin(), flowers.end());
    // flowers.pop_back();

    for (long long i=1; i<=gertrudePosition; i++) {
        std::pop_heap(flowers.begin(), flowers.end()); // move o maior elemento para o final
        
        long long pollenQuantityToCollect = get_sum_of_digits(flowers.back());
        flowers.back() -= pollenQuantityToCollect; // faz operação
        std::push_heap(flowers.begin(), flowers.end()); // insere o último elemento na heap

        if (i == gertrudePosition)
            std::cout << pollenQuantityToCollect << "\n";
    }



    
        
}