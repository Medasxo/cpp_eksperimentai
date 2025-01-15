#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Eksperimentai.h"
#include "Laikmatis.h"

const int DYDIS = 10000;

template <typename Container>
void iterpimoOperacijos(const std::string& container_name) {
    {

        Container konteineris;
        for (int i = 0; i < DYDIS; ++i) {
            konteineris.insert(konteineris.end(), i);
        }

        std::cout << "Iterpimas pradzioje" << std::endl;;

        Laikmatis laikmatis;
        for (int i = 0; i < DYDIS; ++i) {
            konteineris.insert(konteineris.begin(), i);
        }
    }

    {
        Container konteineris;
        for (int i = 0; i < DYDIS; ++i) {
            konteineris.insert(konteineris.end(), i);
        }

        std::cout << "Iterpimas viduryje" << std::endl;;

        Laikmatis laikmatis;
        for (int i = 0; i < DYDIS; ++i) {
            if constexpr (std::is_same<Container, std::list<int>>::value) {
                auto vidurys = std::next(konteineris.begin(), konteineris.size() / 2);
                konteineris.insert(vidurys, i);
            }
            else {
                konteineris.insert(konteineris.begin() + konteineris.size() / 2, i);
            }
        }
    }

    {
        Container konteineris;
        for (int i = 0; i < DYDIS; ++i) {
            konteineris.insert(konteineris.end(), i);
        }

        std::cout << "Iterpimas pabaigoje" << std::endl;;

        Laikmatis laikmatis;
        for (int i = 0; i < DYDIS; ++i) {
            konteineris.insert(konteineris.end(), i);
        }
    }
    std::cout << "\n";
}

void strukturuPalyginimas() {
    // Matavimas std::vector
    std::cout << "Matavimas std::vector: " << std::endl;
    iterpimoOperacijos<std::vector<int>>("std::vector");

    // Matavimas std::deque
    std::cout << "Matavimas std::deque: " << std::endl;
    iterpimoOperacijos<std::deque<int>>("std::deque");

    // Matavimas std::list
    std::cout << "Matavimas std::list: " << std::endl;
    iterpimoOperacijos<std::list<int>>("std::list");
}
