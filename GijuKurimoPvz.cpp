#include <vector>
#include <iostream>
#include <thread>

// Funkcija, kuri spausdina skaicius (500ms intervalu)
void spausdintiSkaicius() {
	for (int i = 1; i <= 5; ++i) {
		std::cout << "Skaicius : " << i << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}
}

// Funkcija, kuri spausdina statini teksta (500ms intervalu)
void spausdintiTeksta() {
	for (int i = 1; i <= 5; ++i) {
		std::cout << "Zinute"<< "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
	 
void paleistiGijuKurimoPavyzdi() {
	// Sukuriame dvi gijas, kurios vykdo skirtingas uzduotis
	std::thread gija1(spausdintiSkaicius);
	std::thread gija2(spausdintiTeksta);

	// Laukiame, kol abi gijos baigs darba
	gija1.join();
	gija2.join();
}