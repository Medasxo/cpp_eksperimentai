#include <string>
#include <memory>

void paleistiSharedPtrPavyzdi() {
	auto ptr1 = std::make_shared<std::string>("Labas, pasauli!");

	{
	 auto ptr2 = ptr1; // Dalinamasis objektu
	} // ptr2 sunaikinamas
}