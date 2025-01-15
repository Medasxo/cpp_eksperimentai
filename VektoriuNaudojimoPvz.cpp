#include <vector>
#include <iostream>

void paleistiVektoriuNaudojimoPavyzdi() {
	// Sukuriame vektoriu, kuriame laikomi skaiciai
	std::vector<int> skaiciai = { 1, 2, 3, 4, 5 };
	// Pridedame skaiciu 6 i vektoriu (atminties valdymas atliekamas automatiskai)
	skaiciai.push_back(6);
	// Isvedame visus elementus naudojant iteratoriu
	for (std::vector<int>::iterator it = skaiciai.begin(); it != skaiciai.end(); ++it) {
		std::cout << *it << "";
	}
}