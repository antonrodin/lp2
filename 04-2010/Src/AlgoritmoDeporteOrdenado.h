#ifndef AlgoritmoDeporteOrdenadoH
#define AlgoritmoDeporteOrdenadoH

#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoDeporteOrdenado : public CAlgoritmo {
public:
	CAlgoritmoDeporteOrdenado();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoDeporteOrdenado();
private:

	CDeporte *_deporte;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif