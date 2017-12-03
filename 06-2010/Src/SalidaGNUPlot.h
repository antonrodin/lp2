#ifndef SalidaGNUPlotH
#define SalidaGNUPlotH

#include "Salida.h"
#include <iostream>
#include <string>
#include <istream>
#include <fstream>

class CSalidaGNUPlot : public CSalida {
public:
	void InitPrueba(const std::string &desc);
	void Muestra(int tam, float tiempo);
	void FinPrueba();
	void setFichero(const std::string nombre) { _fichero = nombre; };
private:
	void dumpFichero(std::ostream &output, int tam, float tiempo);
	
	std::string _desc;
	std::string _fichero;
	std::ofstream _salida;
};

#endif