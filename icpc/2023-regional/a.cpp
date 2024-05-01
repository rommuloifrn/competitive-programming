#include <iostream>

int main() {
    int numberOfRides, carlitosHeight, ridesAllowed = 0;

    std::cin >> numberOfRides >> carlitosHeight;

    for(int i=0; i<numberOfRides; i++) {
        int requiredHeight;
        std::cin >> requiredHeight;
        if (requiredHeight <= carlitosHeight) 
            ridesAllowed++;
    }

    std::cout << ridesAllowed << "\n";
}