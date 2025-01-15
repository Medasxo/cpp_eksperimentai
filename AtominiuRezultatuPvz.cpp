// Atominis rezultatas, naudojamas keliose gijose
#include <thread>

std::atomic<int> rezultatas = 0;

// Funkcija, kuri padidina rezultato reiksme vienetu
void padidinti() {
	rezultatas++;	
}

void paleistiAtominiuRezultatuPavyzdi() {
	// Sukuriame kelias gijas, kurios naudoja ta pati rezultata
	std::thread gija1(padidinti);
	std::thread gija2(padidinti);
	gija1.join();
	gija2.join();
}