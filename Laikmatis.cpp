#include "Laikmatis.h"

Laikmatis::Laikmatis() {
    pradziosLaikas = std::chrono::high_resolution_clock::now();
}

Laikmatis::~Laikmatis() {
    Sustabdyti();
}

void Laikmatis::Sustabdyti() const {
    auto pabaigosLaikas = std::chrono::high_resolution_clock::now();
    auto trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigosLaikas - pradziosLaikas).count();
    std::cout << "Trukme: " << trukme << " ms\n";
}
