#include <vector>
#include <iostream>
#include <execution>

void paleistiLygiagreciuAlgoritmuPavyzdi() {
	// Sukuriame masyva, kuri norime rusiuoti
	std::vector<int> duomenys = { 8, 3, 7, 1, 4, 2, 6, 5 };

	// Rūšiuojame masyva naudojant lygiagretu algoritma
	std::sort(std::execution::par, duomenys.begin(), duomenys.end());
}