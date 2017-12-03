#ifndef AlgoritmoPaisesH
#define AlgoritmoPaisesH

#include <iostream>
#include <string>

#include "Algoritmo.h"
#include "MedalleroAbstracto.h"
#include "Random.h"

template <class TMedallero>
class CAlgoritmoPaises : public CAlgoritmo {

public:
	CAlgoritmoPaises();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoPaises();

private:
	CPais *_datos;
	int _tam;
	TMedallero* _medallero;
	CRandom _random;
};

template <class TMedallero>
CAlgoritmoPaises<TMedallero>::CAlgoritmoPaises() {
	this->_datos= 0;
}

template<class TMedallero>
std::string CAlgoritmoPaises<TMedallero>::getDescription() {
	return "Algoritmo de actualizar Pais";
}

template<class TMedallero>
CAlgoritmoPaises<TMedallero>::~CAlgoritmoPaises() {
}

template<class TMedallero>
void CAlgoritmoPaises<TMedallero>::SetUp(int tam) {			
	
	this->_tam = tam;
	this->_datos = new CPais[tam];
	
	CPais pais;
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	CDeporte deporte(_random.randomString(16));
	CPrueba prueba(_random.randomString(16), deporte);
	_medallero = new TMedallero();
	
	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	for (int i = 0; i<tam; i++) {
		pais.setNombre(_random.randomString(16));
		_datos[i] = pais;
	}

	//Sacamos el pais Random
	for (int i = 0; i<tam; i++) {
		
		CAtleta atleta1("Pepe", _datos[i]);
		CAtleta atleta2("Juan", _datos[i]);
		CAtleta atleta3("Carlos", _datos[i]);
		
		CSecuencia < CAtleta > sec;
		sec.inserta(atleta1);
		sec.inserta(atleta2);
		sec.inserta(atleta3);
	
		_medallero->clasificacion(prueba, sec);
	}
}

template<class TMedallero>
void CAlgoritmoPaises<TMedallero>::Execute() {	
	
	this->_medallero->medallero();
}

template<class TMedallero>
void CAlgoritmoPaises<TMedallero>::TearDown() {
	delete this->_medallero;
}

#endif
