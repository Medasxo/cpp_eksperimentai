#include <iostream>
#include <vector>
#include <chrono>;
#include "Laikmatis.h"


void testCopy(const std::vetor<int>& data) {
    Laikmatis laikmatis;
    std::vector<int> copy = data; // Kopijavimas
}

void testMove(std::vector<int>&& data) {
    Laikmatis laikmatis;
    std::vector<int> moved = std::move(data); // Perkėlimas
}

int main() {
    const size_t dataSize = 1e8;
    std::vector<int> data(dataSize, 42);

    std::cout << "Testing Copy:\n";
    testCopy(data);

    data.assign(dataSize, 42); // Atstatykite pradinę būseną

    std::cout << "Testing Move:\n";
    testMove(std::move(data));

    return 0;
}
