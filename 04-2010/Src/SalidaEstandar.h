#ifndef SalidaEstandarH
#define SalidaEstandarH

#include "Salida.h"
#include <iostream>
#include <string>

class CSalidaEstandar : public CSalida {
public:
	void InitPrueba(const std::string &desc);
	void Muestra(int tam, float tiempo);
	void FinPrueba();
private:
	std::string _desc;
};

#endif