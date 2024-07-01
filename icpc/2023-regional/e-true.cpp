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
    for (ll i=0; i<size; i++)
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

    ll tillGertrude = gertrudePosition-1;

    for (long long i=flowersMaxQtd-1; i>=0; i--) {

        ll minus = get_sum_of_digits(i);
        ll result = i - minus;

        
        if (flowers[i] > tillGertrude || ((tillGertrude == 0) && (flowers[i]>0)) ) { 
            /* BASICAMENTE EU NÃO POSSO RETORNAR SÓ POR TILLGERTRUDE SER 0 POIS SE NAO ELE VAI RETORNAR SEM TER NENHUMA FLOR
            (A PROXIMA POSIÇAO INDEPENDENTE DAS VARIAVEIS, NO CASO DO 1 EXEMPLO EH NA POSIÇÃO 17 (DPS DA 18, QUE EH UMA FLOR QUE EXISTE)) */
            printArray(flowers, 26);
            std::cout << "gertrude menos " << flowers[i] << ", qtd: " << flowers[i] << ", tillGertrude = " << tillGertrude << ", i = " << i << "\n";
            std::cout << minus << "\n"; break; return 0;
        }
        tillGertrude -= flowers[i];
        if (flowers[i]>0) {
            printArray(flowers, 26);
            std::cout << "gertrude menos " << flowers[i] << ", qtd: " << flowers[i] << ", tillGertrude = " << tillGertrude << ", i = " << i << "\n";
        }
        flowers[result] += flowers[i];
        flowers[i] = 0;
        

        // if ((flowers[i] >= tillGertrude) || (tillGertrude == 1)) {
        //     //std::cout << "qtd de flores com polen i maior que qtd de abelhas até gertrude\n";
        //     flowers[i] -= tillGertrude; // simbólico
        //     std::cout << minus <<"\n";
        //     std::cout << "i = " << i << ", minus = " << minus << ", qtd: " << flowers[i] << " GERTRUDE UAI TCHÊ MÊO\n";
        //     break;
        // } else 
        // if ((flowers[i] < tillGertrude) && flowers[i]>0) { // caso haja mais flores até gertrude do que flores com o tanto de pólen atual..
        //     //std::cout << "posição de gertrude maior que a qtd de flores\n";
        //     tillGertrude -= flowers[i];
        //     std::cout << "gertrude menos " << flowers[i] << ", qtd: " << flowers[i] << ", gertrude = " << tillGertrude << "\n";
        //     flowers[result] + flowers[i];
        //     flowers[i] = 0;
        // }

        // while (flowers[i] > 0) { //caso o pólen da flor atual seja maior que zero
        //     flowers[result]++; // aumenta a quantidade de flores com o pólen restante
        //     flowers[i]--; // diminui a quantidade de flores com o pólen da flor atual
        //     bees++;
        //     if (bees == gertrudePosition) { std::cout << minus <<"\n"; return 0; }
        //     //std::cout << "sum of digits: " << minus << "i: " << i << "\n";
        // }
    }
}