#include <iostream>

typedef long long ll;

long long get_sum_of_digits(long long number) {
    long long sum=0;
    for(int i=0; i<7; i++) {
        sum += number%10;
        number /= 10;
    }
    return sum;
}

void clearArray(long long arr[], long long size) {
    for (long long i=0; i<size; i++)
        arr[i] = 0;
}

void printArray(long long arr[], long long size) {
    std::cout << "[ ";
    for (ll i=0; i<size-1; i++)
        std::cout << arr[i] << ", " ;
    std::cout << arr[size-1] << " ]\n";
}

void printBirdBox(long long arr[], long long size, ll i) {
    std::cout << "[ ";
    for (ll i=size-1; i>=0; i--)
        if (arr[i] > 0)
            for (ll k = arr[i]; k>0; k--)
                std::cout << i << ", " ;
        
    std::cout << arr[size-1] << " ], " << "i = " << i << "\n";
}

int main() {
    long long flowersQuantity, gertrudePosition, flowersMaxQtd = 1000000, bees = 0;
    long long flowers[flowersMaxQtd];

    std::cin >> flowersQuantity >> gertrudePosition;

    clearArray(flowers, flowersMaxQtd);

    for (long long i=0; i<flowersQuantity; i++) { // insere as flores no array
        long long flower;
        std::cin >> flower;
        flowers[flower]++;
    }

    for (long long i=flowersMaxQtd-1; i>=0; i--) {
        //if (i<40)
        //    printBirdBox(flowers, 40, i);

        ll minus = get_sum_of_digits(i);
        ll result = i - minus;

        while (flowers[i] > 0) { //caso o pólen da flor atual seja maior que zero
            flowers[result]++; // aumenta a quantidade de flores com o pólen restante
            flowers[i]--; // diminui a quantidade de flores com o pólen da flor atual
            bees++;
            if (bees == gertrudePosition) { std::cout << minus <<"\n"; return 0; }
            //std::cout << "sum of digits: " << minus << "i: " << i << "\n";
        }
    }
    
}