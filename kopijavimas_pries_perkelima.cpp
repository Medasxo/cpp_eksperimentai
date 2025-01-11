#include <iostream>
#include <vector>
#include "Laikmatis.h"


int main() {
    const size_t duomenuDydis = 1e8;
    const int reiksme = 1;

    {
        std::cout << "Kopijavimas:\n";
        std::vector<int> duomenys(duomenuDydis, reiksme);
        Laikmatis laikmatis;
        std::vector<int> nukopijuotiDuomenys = duomenys;
    }

    {
        std::cout << "Perkelimas:\n";
        std::vector<int> duomenys(duomenuDydis, reiksme);
        Laikmatis laikmatis;
        std::vector<int> perkeltiDuomenys = std::move(duomenys);
    }
}
