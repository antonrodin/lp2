#ifndef AlgoritmoPaisAleatorioH
#define AlgoritmoPaisAleatorioH

#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoPaisAleatorio : public CAlgoritmo {
public:
	CAlgoritmoPaisAleatorio();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoPaisAleatorio();
private:
	CPais *_datos;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif