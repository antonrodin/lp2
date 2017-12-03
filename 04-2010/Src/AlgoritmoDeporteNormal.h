#ifndef AlgoritmoDeporteNormalH
#define AlgoritmoDeporteNormalH

#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoDeporteNormal : public CAlgoritmo {
public:
	CAlgoritmoDeporteNormal();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoDeporteNormal();
private:

	CDeporte *_deporte;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif