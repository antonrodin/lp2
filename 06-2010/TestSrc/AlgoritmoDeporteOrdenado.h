#ifndef AlgoritmoDeporteOrdenadoH
#define AlgoritmoDeporteOrdenadoH

#include <iostream>
#include <string>

#include "Algoritmo.h"
#include "MedalleroAbstracto.h"
#include "Random.h"

//Clase abstracta
template <class TMedallero>
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
	TMedallero* _medallero;
	CRandom _random;
};

template <class TMedallero>
CAlgoritmoDeporteOrdenado<TMedallero>::CAlgoritmoDeporteOrdenado() {
	this->_deporte = 0;
}

template <class TMedallero>
std::string CAlgoritmoDeporteOrdenado<TMedallero>::getDescription() {
	return "Deporte Normal Ordenado";
}

template <class TMedallero>
CAlgoritmoDeporteOrdenado<TMedallero>::~CAlgoritmoDeporteOrdenado() {
}

template <class TMedallero>
void CAlgoritmoDeporteOrdenado<TMedallero>::SetUp(int tam) {		
	
	
	this->_tam = tam;
	this->_deporte = new CDeporte[tam];
	_medallero = new TMedallero();
	
	CPais pais1("Espana");
	CPais pais2("Rusia");
	CPais pais3("EEUU");
	CPais vectorPaises[3];
	vectorPaises[0] = pais1;
	vectorPaises[1] = pais2;
	vectorPaises[2] = pais3;
	
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	
	for (int i = 0; i<tam; i++) {
		CDeporte deporte(_random.randomString(16));
		this->_deporte[i] = deporte;
	}
	

	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	for (int i = 0; i<tam; i++) {
		CAtleta atleta1("Pepe", vectorPaises[_random.aleatorio(3)]);
		CAtleta atleta2("Juan", vectorPaises[_random.aleatorio(3)]);
		CAtleta atleta3("Carlos", vectorPaises[_random.aleatorio(3)]);
			
		CSecuencia < CAtleta > sec;
		sec.inserta(atleta1);
		sec.inserta(atleta2);
		sec.inserta(atleta3);
		
		CPrueba prueba(_random.randomString(16), _deporte[i]);

		_medallero->clasificacion(prueba, sec);
	}

}

template <class TMedallero>
void CAlgoritmoDeporteOrdenado<TMedallero>::Execute() {	

	//Aqui lo que hacemos es actualizar el nuevo pais con nuevos atletas que esta en una posicion aleatoria
	CDeporte deporte = this->_deporte[_random.aleatorio(this->_tam)];
	this->_medallero->medalleroDeporteOrdenado(deporte);
	
}

template <class TMedallero>
void CAlgoritmoDeporteOrdenado<TMedallero>::TearDown() {
	delete [] this->_deporte;
	delete this->_medallero;
}


#endif
