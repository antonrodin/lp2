#include "AlgoritmoPaisPrimero.h"


CAlgoritmoPaisPrimero::CAlgoritmoPaisPrimero() {
	this->_datos = 0;
}

std::string CAlgoritmoPaisPrimero::getDescription() {
	return "Pais Primero";
}

CAlgoritmoPaisPrimero::~CAlgoritmoPaisPrimero() {
}

//Esto realmente es un constructor? No seria mejor crear directmente un constructor? en vez de esta funcion?
void CAlgoritmoPaisPrimero::SetUp(int tam) {		
	
	
	this->_tam = tam;
	this->_datos = new CPais[tam];
	
	CPais pais;
	CSecuencia < CAtleta > sec;
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	CDeporte deporte(_random.randomString(16));
	CPrueba prueba(_random.randomString(16), deporte);
	_medallero = new CMedallero();

	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	for (int i = 0; i<tam; i++) {
		
		pais.setNombre(_random.randomString(16));
		
		_datos[i] = pais;

		CAtleta atleta1("Pepe", _datos[i]);
		CAtleta atleta2("Juan", _datos[i]);
		CAtleta atleta3("Carlos", _datos[i]);
		
		sec.inserta(atleta1);
		sec.inserta(atleta2);
		sec.inserta(atleta3);
	
		_medallero->clasificacion(prueba, sec);
		
		sec.reinicia();
		sec.borra();
		sec.borra();
		sec.borra();
	}

}

void CAlgoritmoPaisPrimero::Execute() {	

	//Aqui lo que hacemos es actualizar el nuevo pais con nuevos atletas que esta en una posicion aleatoria
	CPais pais = this->_datos[0];
	
	CDeporte deporte(_random.randomString(16));
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

void CAlgoritmoPaisPrimero::TearDown() {
	delete [] this->_datos;
	delete this->_medallero;
}
