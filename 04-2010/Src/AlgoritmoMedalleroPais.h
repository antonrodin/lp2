#ifndef AlgoritmoMedalleroPaisH
#define AlgoritmoMedalleroPaisH


#include <iostream>

#include "Algoritmo.h"
#include "Medallero.h"
#include "Random.h"

//Clase abstracta
class CAlgoritmoMedalleroPais : public CAlgoritmo {
public:
	CAlgoritmoMedalleroPais();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoMedalleroPais();
private:

	CPais *_pais;
	int _tam;
	CMedallero* _medallero;
	CRandom _random;
};

#endif