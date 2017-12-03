#ifndef AlgoritmoPaisPrimeroH
#define AlgoritmoPaisPrimeroH

#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoPaisPrimero : public CAlgoritmo {
public:
	CAlgoritmoPaisPrimero();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoPaisPrimero();
private:
	CPais *_datos;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif