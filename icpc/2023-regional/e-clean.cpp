#include <iostream>
     
typedef long long ll;
     
long long getSumOfDigits(long long number) {
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

void assert(bool foo) {
    if (foo) std::cout << "yip\n";
}
 
int main() {
    long long flowersQuantity, gertrudePosition, flowersMaxQtd = 1000000, bees = 0;
    long long flowers[flowersMaxQtd];
 
    std::cin >> flowersQuantity >> gertrudePosition;
    ll tillGertrude = gertrudePosition-1;
 
    clearArray(flowers, flowersMaxQtd);
 
    for (long long i=0; i<flowersQuantity; i++) { // insere as flores no array
        long long flower;
        std::cin >> flower;
        flowers[flower]++;
    }

    assert(true);

    for (ll polen=flowersMaxQtd-1; polen>=0; polen--) {
        ll retrievedPolen = getSumOfDigits(polen);
        ll result = polen - retrievedPolen;
	
        ll actualFlowersQtt = flowers[polen];
        if (actualFlowersQtt > 0) { // caso haja flores com essa quantidade de pólen
        
	        if (actualFlowersQtt>tillGertrude) {
                std::cout << "pegou " << retrievedPolen << " no pólen " << polen << ", até gertrude:" << tillGertrude << "(" << flowers[polen] << " flores) " <<"\n";
                std::cout << retrievedPolen << "\n";
                return 0;
	        } else if (actualFlowersQtt<=tillGertrude) {
                tillGertrude -= actualFlowersQtt; // dimunui das abelhas que faltam até gertrude as flores pegas
                flowers[polen-retrievedPolen] += actualFlowersQtt; // aumenta a quantidade de flores com o pólen que sobrou
                std::cout << "pegou " << retrievedPolen << " no pólen " << polen << ", até gertrude:" << tillGertrude <<"\n";
	        }
        } else if (polen==0)
	    std::cout << 0 << "\n";
    }

}