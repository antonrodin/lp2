#ifndef AlgoritmoPaisAleatorioH
#define AlgoritmoPaisAleatorioH

#include <iostream>
#include <string>

#include "Algoritmo.h"
#include "MedalleroAbstracto.h"
#include "MedalleroTablaAbierta.h"
#include "Random.h"

//Clase abstracta
template <class TMedallero>
class CAlgoritmoPaisAleatorio : public CAlgoritmo{
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
	TMedallero* _medallero;
	CRandom _random;
};


/**
*	Implementacion
*/

template <class TMedallero>
CAlgoritmoPaisAleatorio<TMedallero>::CAlgoritmoPaisAleatorio() {
	this->_datos = 0;
}

template <class TMedallero>
std::string CAlgoritmoPaisAleatorio<TMedallero>::getDescription() {
	return "Pais Aleatorio";
}

template <class TMedallero>
CAlgoritmoPaisAleatorio<TMedallero>::~CAlgoritmoPaisAleatorio() {
}

template <class TMedallero>
void CAlgoritmoPaisAleatorio<TMedallero>::SetUp(int tam) {		
	
	
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

template <class TMedallero>
void CAlgoritmoPaisAleatorio<TMedallero>::Execute() {	

	//Aqui lo que hacemos es actualizar el nuevo pais con nuevos atletas (Medallas) que esta en una posicion aleatoria
	CPais pais = this->_datos[_random.aleatorio(this->_tam)];
	
	CDeporte deporte("Futbol");
	CPrueba prueba(_random.randomString(16), deporte);
	
	CAtleta atleta1("Pepe", pais);
	CAtleta atleta2("Juan", pais);
	CAtleta atleta3("Carlos", pais);
	CSecuencia< CAtleta > sec;

	sec.inserta(atleta1);
	sec.inserta(atleta2);
	sec.inserta(atleta3);

	this->_medallero->clasificacion(prueba, sec);
}

template <class TMedallero>
void CAlgoritmoPaisAleatorio<TMedallero>::TearDown() {
	delete [] this->_datos;
	delete this->_medallero;
}


#endif
