#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include "Laikmatis.h"

static void sumuoti(const std::vector<int>& duomenys, size_t start, size_t end, int& rezultatas) {
    rezultatas = std::accumulate(duomenys.begin() + start, duomenys.begin() + end, 0);
}

void tirtiLygiagretuma() {
    const size_t duomenuDydis = 1e9;
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
        std::thread gija1(sumuoti, std::cref(duomenys), 0, duomenys.size() / 2, std::ref(rezultatas1));
        std::thread gija2(sumuoti, std::cref(duomenys), duomenys.size() / 2, duomenys.size(), std::ref(rezultatas2));
        gija1.join();
        gija2.join();
        int rezultatas = rezultatas1 + rezultatas2;
    }

    {
        std::cout << "Keturgijis skaiciavimas:\n";
        int rezultatas1 = 0, rezultatas2 = 0, rezultatas3 = 0, rezultatas4 = 0;
        Laikmatis laikmatis;
        std::thread gija1(sumuoti, std::cref(duomenys), 0, duomenys.size() / 4, std::ref(rezultatas1));
        std::thread gija2(sumuoti, std::cref(duomenys), duomenys.size() / 4, duomenys.size() / 2, std::ref(rezultatas2));
        std::thread gija3(sumuoti, std::cref(duomenys), duomenys.size() / 2, 3 * duomenys.size() / 4, std::ref(rezultatas3));
        std::thread gija4(sumuoti, std::cref(duomenys), 3 * duomenys.size() / 4, duomenys.size(), std::ref(rezultatas4));
        gija1.join();
        gija2.join();
        gija3.join();
        gija4.join();
        int rezultatas = rezultatas1 + rezultatas2 + rezultatas3 + rezultatas4;
    }
}
