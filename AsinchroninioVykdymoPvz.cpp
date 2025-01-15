#include <future>

int atliktiIlgaSkaiciavima() {
	// Atliekame sudetingus skaiciavimus

	return 0; // Graziname ilgo skaiciavimo rezultata
}

void paleistiAsinchroninioVykdymoPavyzdi() {
	// Paleidziame ilgo skaiciavimo funkcija asinchroniskai
	std::future<int> asyncRezultatas = std::async(std::launch::async, atliktiIlgaSkaiciavima);

	// Toliau atliekame uzduotis nepriklausancias nuo funkcijos rezultato
	// 
	// 
	// Laukiame rezultato ir ji gauname
	int galutinisRezultatas = asyncRezultatas.get();
}
