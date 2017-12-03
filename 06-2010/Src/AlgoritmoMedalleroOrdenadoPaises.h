#ifndef AlgoritmoMedalleroOrdenadoPaisH
#define AlgoritmoMedalleroOrdenadoPaisH


#include <iostream>
#include <string>

#include "Algoritmo.h"
#include "MedalleroAbstracto.h"
#include "MedalleroTablaAbierta.h"
#include "Random.h"

template <class TMedallero>
class CAlgoritmoMedalleroOrdenadoPais : public CAlgoritmo {
public:
	CAlgoritmoMedalleroOrdenadoPais();
	virtual std::string getDescription();
	virtual void SetUp(int);
	virtual void Execute();
	virtual void TearDown();
	virtual ~CAlgoritmoMedalleroOrdenadoPais();
private:

	CPais *_datos;
	int _tam;
	TMedallero* _medallero;
	CRandom _random;
};

template <class TMedallero>
CAlgoritmoMedalleroOrdenadoPais<TMedallero>::CAlgoritmoMedalleroOrdenadoPais() {
	this->_datos = 0;
}

template<class TMedallero>
std::string CAlgoritmoMedalleroOrdenadoPais<TMedallero>::getDescription() {
	return "Medallero Ordenado por Pais";
}

template<class TMedallero>
CAlgoritmoMedalleroOrdenadoPais<TMedallero>::~CAlgoritmoMedalleroOrdenadoPais() {
}

template<class TMedallero>
void CAlgoritmoMedalleroOrdenadoPais<TMedallero>::SetUp(int tam) {			
	
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
void CAlgoritmoMedalleroOrdenadoPais<TMedallero>::Execute() {	
	
	this->_medallero->medalleroOrdenado();
}

template<class TMedallero>
void CAlgoritmoMedalleroOrdenadoPais<TMedallero>::TearDown() {
	delete this->_medallero;
}

#endif
