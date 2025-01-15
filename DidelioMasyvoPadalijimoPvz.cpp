#include <vector>
#include <thread>
#include <execution>

void skaiciuotiSuma(const std::vector<int>&duomenys, int pradzia, int pabaiga, int& rezultatas)
{
	rezultatas = std::accumulate(duomenys.begin() + pradzia, duomenys.begin() + pabaiga, 0);
}

void paleistiDidelioMasyvoPadalijimoPavyzdi() {
	// Sukuriame dideli masyva su 10000 vienetu
	std::vector<int> duomenys(10000, 1);

	// Sukuriame kiekvienos masyvo dalies rezultatus ir nustatome pradines reiksmes
	int suma1 = 0, suma2 = 0;

	// Sukuriame dvi gijas skaiciavimams skeldami skaicių masyva pusiau
	std::thread gija1(skaiciuotiSuma, std::cref(duomenys), 0, duomenys.size() / 2, std::ref(suma1));
	std::thread gija2(skaiciuotiSuma, std::cref(duomenys), duomenys.size() / 2, duomenys.size(), std::ref(suma2));

	// Laukiame, kol abi gijos baigs darba
	gija1.join();
	gija2.join();

	// Susumuojame rezultatus
	int bendraSuma = suma1 + suma2;
}