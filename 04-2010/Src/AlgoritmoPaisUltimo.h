#ifndef AlgoritmoPaisUltimoH
#define AlgoritmoPaisUltimoH

#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoPaisUltimo : public CAlgoritmo {
public:
	CAlgoritmoPaisUltimo();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoPaisUltimo();
private:
	CPais *_datos;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif