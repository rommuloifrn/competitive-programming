#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
    long long flowersQuantity, gertrudePosition;
    long long flowersQtd = 1000000;
    long long flowers[flowersQtd];

    std::cin >> flowersQuantity >> gertrudePosition;

    clearArray(flowers, flowersQtd);

    for (long long i=0; i<flowersQuantity; i++) { // insere as flores no array
        long long flower;
        std::cin >> flower;
        flowers[flower]++;
    }

    for (long long i=flowersQtd-1; i>=0; i++) {
        ll minus = get_sum_of_digits(i);
        ll result = i - minus;
        if (i == gertrudePosition) { std::cout << minus; break; }
        while (flowers[i] > 0) {
            flowers[result]++;
            flowers[i]--;
        }
    }
    
}