#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "Laikmatis.h"
#include <iterator>

template <typename Container>
void duomenuStrukturosMatavimas(size_t data_size) {
    Container konteineris(data_size, 0);

    {
        std::cout << "Iterpimas pradzioje\n";
        Laikmatis laikmatis;
        for (size_t i = 0; i < 10000; ++i) {
            konteineris.insert(konteineris.begin(), i);
        }
    }

    {
        std::cout << "Iterpimas viduryje\n";
        Laikmatis laikmatis;
        for (size_t i = 0; i < 10000; ++i) {
            auto mid = konteineris.begin();
            std::advance(mid, konteineris.size() / 2);
            konteineris.insert(mid, i);
        }
    }

    {
        std::cout << "Iterpimas pabaigoje\n";
        Laikmatis laikmatis;
        for (size_t i = 0; i < 10000; ++i) {
            konteineris.push_back(i);
        }
    }

    {
        std::cout << "Trinimas pradzioje\n";
        Laikmatis laikmatis;
        for (size_t i = 0; i < 10000; ++i) {
            konteineris.erase(konteineris.begin());
        }
    }

    {
        std::cout << "Paieska\n";
        Laikmatis laikmatis;
        for (size_t i = 0; i < 10000; ++i) {
            auto it = std::find(konteineris.begin(), konteineris.end(), i);
        }
    }
}

void tirtiDuomenuStrukturas() {
    size_t duomenuDydis = 1e6;

    std::cout << "Matavimas std::vector: " << std::endl;
    duomenuStrukturosMatavimas<std::vector<int>>(duomenuDydis);

    std::cout << "Matavimas std::deque: " << std::endl;
    duomenuStrukturosMatavimas<std::deque<int>>(duomenuDydis);

    std::cout << "Matavimas std::list: " << std::endl;
    duomenuStrukturosMatavimas<std::list<int>>(duomenuDydis);
}