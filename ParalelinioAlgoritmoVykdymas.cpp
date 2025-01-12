#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <execution>
#include "Laikmatis.h"

void tirtiparaleliniAlgoritma() {

    const size_t duomenuDydis = 10000000;

    // Sukuriamas dideliu duomenu vektorius
    std::vector<int> duomenys(duomenuDydis);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000000);

    for (size_t i = 0; i < duomenuDydis; ++i) {
        duomenys[i] = dis(gen);
    }

    std::vector<int> duomenysSekvenciniam = duomenys;

    // Sekvencinis rikiavimas ir laiko matavimas
    {
        std::cout << "Sekvencinis rikiavimas" << std::endl;
        Laikmatis laikmatis;
        std::sort(duomenysSekvenciniam.begin(), duomenysSekvenciniam.end());
    }
    
    // Paralelinis rikiavimas ir laiko matavimas
    {
        std::cout << "Paralelinis rikiavimas" << std::endl;
        Laikmatis laikmatis;
        std::sort(std::execution::par, duomenys.begin(), duomenys.end());
    }
}
