#include "SalidaGNUPlot.h"

void CSalidaGNUPlot::InitPrueba(const std::string &desc) {
	this->_desc = desc;
	_salida.open(this->_fichero.c_str());
}

void CSalidaGNUPlot::Muestra(int tam, float tiempo) {
	_salida << tam << " " << tiempo << std::endl;
}

void CSalidaGNUPlot::FinPrueba() {
	_salida.close();
}