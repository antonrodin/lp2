#include "SalidaEstandar.h"

void CSalidaEstandar::InitPrueba(const std::string &desc) {
	
	this->_desc = desc;
	std::string descrip = this->_desc;
	std::cout << std::endl;
	std::cout <<  descrip<< std::endl;
	std::cout << "--------------------------------------------------------" << std::endl << std::endl;

}

void CSalidaEstandar::Muestra(int tam, float tiempo) {
	std::cout << tam << ":" << tiempo << std::endl;
}

void CSalidaEstandar::FinPrueba() {
}