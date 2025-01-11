#include <iostream>
#include "Eksperimentai.h"

static void rodytiMeniu() {
    std::cout << "\nPasirinkite eksperimenta:\n";
    std::cout << "1. Kopijavimo ir perkelimo efektyvumo tyrimas\n";
    std::cout << "2. Iprastu ir iterptiniu funkciju palyginimas\n";
    std::cout << "3. Raw, unikaliu ir bendrintu rodykliu tyrimas\n";
    std::cout << "Pasirinkite:";
}

int main() {
    int pasirinkimas;

    do {
        rodytiMeniu();
        std::cin >> pasirinkimas;
        std::cout << "\n";

        switch (pasirinkimas) {
        case 1:
            tirtiKopijavimaIrPerkelima();
            break;
        case 2:
            tirtiIterptinesIrPaprastasFunkcijas();
            break;
        case 3:
            tirtiRodykles();
        default:
            std::cout << "\nNetinkamas pasirinkimas. Bandykite dar karta.\n";
        }

    } while (pasirinkimas != 0);


    return 0;
}