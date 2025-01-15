#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include "Laikmatis.h"

static void skaiciuotiSuma(const std::vector<int>& duomenys, int pradzia, int pabaiga, int& rezultatas)
{
    rezultatas = std::accumulate(duomenys.begin() + pradzia, duomenys.begin() + pabaiga, 0);
}

void tirtiLygiagretuma() {
    const size_t duomenuDydis = 1e8;
    const int reiksme = 1;
    std::vector<int> duomenys(duomenuDydis, reiksme);

    {
        std::cout << "Viengijis skaiciavimas:\n";
        Laikmatis laikmatis;
        volatile int rezultatas = std::accumulate(duomenys.begin(), duomenys.end(), 0);
    }

    {
        std::cout << "Dvigijis skaiciavimas:\n";
        int rezultatas1 = 0, rezultatas2 = 0;
        Laikmatis laikmatis;
        std::thread gija1(skaiciuotiSuma, std::cref(duomenys), 0, duomenys.size() / 2, std::ref(rezultatas1));
        std::thread gija2(skaiciuotiSuma, std::cref(duomenys), duomenys.size() / 2, duomenys.size(), std::ref(rezultatas2));
        gija1.join();
        gija2.join();
        int rezultatas = rezultatas1 + rezultatas2;
    }

    {
        std::cout << "Keturgijis skaiciavimas:\n";
        int rezultatas1 = 0, rezultatas2 = 0, rezultatas3 = 0, rezultatas4 = 0;
        Laikmatis laikmatis;
        std::thread gija1(skaiciuotiSuma, std::cref(duomenys), 0, duomenys.size() / 4, std::ref(rezultatas1));
        std::thread gija2(skaiciuotiSuma, std::cref(duomenys), duomenys.size() / 4, duomenys.size() / 2, std::ref(rezultatas2));
        std::thread gija3(skaiciuotiSuma, std::cref(duomenys), duomenys.size() / 2, 3 * duomenys.size() / 4, std::ref(rezultatas3));
        std::thread gija4(skaiciuotiSuma, std::cref(duomenys), 3 * duomenys.size() / 4, duomenys.size(), std::ref(rezultatas4));
        gija1.join();
        gija2.join();
        gija3.join();
        gija4.join();
        int rezultatas = rezultatas1 + rezultatas2 + rezultatas3 + rezultatas4;
    }
}
