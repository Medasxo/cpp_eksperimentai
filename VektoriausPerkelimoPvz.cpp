#include <vector>
#include <iostream>

void paleistiVektoriausPerkelimoPavyzdi() {
	// Sukuriame vektoriu
	std::vector<int> skaiciai = { 1, 2, 3 };
	// Perkeliame turini i kita vektoriu naudojant std::move
	skaiciai.push_back(6);
	// Originalus vektorius tampa tuscias, o turinys perkeliamas
}