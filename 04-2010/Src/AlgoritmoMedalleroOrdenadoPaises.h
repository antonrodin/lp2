#ifndef AlgoritmoMedalleroOrdenadoPaisH
#define AlgoritmoMedalleroOrdenadoPaisH


#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoMedalleroOrdenadoPais : public CAlgoritmo {
public:
	CAlgoritmoMedalleroOrdenadoPais();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoMedalleroOrdenadoPais();
private:

	CPais *_pais;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif