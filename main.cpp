#include <iostream>
#include "Eksperimentai.h"
#include "Pavyzdziai.h"

static void rodytiMeniu() {
    std::cout << "\nPasirinkite eksperimenta:\n";
    std::cout << "1. Kopijavimo ir perkelimo efektyvumo tyrimas\n";
    std::cout << "2. Iprastu ir iterptiniu funkciju palyginimas\n";
    std::cout << "3. Raw, unikaliu ir bendrintu rodykliu tyrimas\n";
    std::cout << "4. Lygiagretumo tyrimas\n";
    std::cout << "5. Paralelinio algoritmo tyrimas\n";
    std::cout << "6. Duomenu strukturu (vector, deque, list) palyginimas\n";
    std::cout << "\nPasirinkite pavyzdi:\n";
    std::cout << "7. Vektoriu naudojimo pavyzdys\n";
    std::cout << "8. Vektoriaus perkelimo pavyzdys\n";
    std::cout << "9. Giju kurimo pavyzdys\n";
    std::cout << "10. Asinchroninio vykdymo pavyzdys\n";
    std::cout << "11. Lygiagreciu algoritmu pavyzdys\n";
    std::cout << "12. Atominiu rezultatu pavyzdys\n";
    std::cout << "13. Shared_ptr pavyzdys\n";
    std::cout << "14. Iterptines funkcijos pavyzdys\n";
    std::cout << "15. Didelio masyvo padalijimo pavyzdys\n";
    std::cout << "\nPasirinkite:";
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
            break;
        case 4:
            tirtiLygiagretuma();
            break;
        case 5:
            tirtiparaleliniAlgoritma();
            break;
        case 6:
            strukturuPalyginimas();
            break; 
        case 7:
            paleistiVektoriuNaudojimoPavyzdi();
            break;
        case 8:
            paleistiVektoriausPerkelimoPavyzdi();
            break;
        case 9:
            paleistiGijuKurimoPavyzdi();
            break;
        case 10:
            paleistiAsinchroninioVykdymoPavyzdi();
            break;
        case 11:
            paleistiLygiagreciuAlgoritmuPavyzdi();
            break;
        case 12:
            paleistiAtominiuRezultatuPavyzdi();
            break;
        case 13:
            paleistiSharedPtrPavyzdi();
            break;
        case 14:
            paleistiIterptinesFunkcijosPavyzdi();
            break;
        case 15:
            paleistiDidelioMasyvoPadalijimoPavyzdi();
            break;
        default:
            std::cout << "\nNetinkamas pasirinkimas. Bandykite dar karta.\n";
        }

    } while (pasirinkimas != 0);


    return 0;
}