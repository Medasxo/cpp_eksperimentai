#include <iostream>
#include "Laikmatis.h" 
#include "Eksperimentai.h"

static int pakeltiKubu(int x) {
    return x * x * x;
}

inline static int iterptinaiPakeltiKubu(int x) {
    return x * x * x;
}

void tirtiIterptinesIrPaprastasFunkcijas() {
    const int iteracijos = 1e9;

    {
        std::cout << "Iprasta funkcija:\n";
        volatile int rezultatas = 0;
        Laikmatis laikmatis;
        for (int i = 0; i < iteracijos; ++i) {
            rezultatas += pakeltiKubu(i);
        }
    }

    {
        std::cout << "Iterptine funkcija:\n";
        volatile int rezultatas = 0;
        Laikmatis laikmatis;
        for (int i = 0; i < iteracijos; ++i) {
            rezultatas += iterptinaiPakeltiKubu(i);
        }
    }
}
