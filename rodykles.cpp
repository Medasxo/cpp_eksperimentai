#include <iostream>
#include <memory>
#include <vector>
#include "Laikmatis.h"
#include "Eksperimentai.h"

static void neapdorotosRodyklesTestas(size_t numAllocations) {
    Laikmatis laikmatis;
    for (size_t i = 0; i < numAllocations; ++i) {
        int* ptr = new int(i);
        delete ptr;
    }
}

static void unikaliosRodyklesTestas(size_t numAllocations) {
    Laikmatis laikmatis;
    for (size_t i = 0; i < numAllocations; ++i) {
        std::unique_ptr<int> ptr = std::make_unique<int>(i);
    }
}

static void bendrintosRodyklesTestas(size_t numAllocations) {
    Laikmatis laikmatis;
    for (size_t i = 0; i < numAllocations; ++i) {
        std::shared_ptr<int> ptr = std::make_shared<int>(i);
    }
}

void tirtiRodykles() {
    const size_t numAllocations = 1e6;

    std::cout << "Neapdorotos rodykles greitis:" << std::endl;
    neapdorotosRodyklesTestas(numAllocations);

    std::cout << "Unikalios rodykles greitis:" << std::endl;
    unikaliosRodyklesTestas(numAllocations);

    std::cout << "Bendrinamos rodykles greitis:" << std::endl;
    bendrintosRodyklesTestas(numAllocations);

}
