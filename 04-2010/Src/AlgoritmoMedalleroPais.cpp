#include "AlgoritmoMedalleroPais.h"



CAlgoritmoMedalleroPais::CAlgoritmoMedalleroPais() {
	this->_pais = 0;
}

std::string CAlgoritmoMedalleroPais::getDescription() {
	return "Medallero por Pais";
}

CAlgoritmoMedalleroPais::~CAlgoritmoMedalleroPais() {
}

//Esto realmente es un constructor? No seria mejor crear directmente un constructor? en vez de esta funcion?
void CAlgoritmoMedalleroPais::SetUp(int tam) {		
	
	
	this->_tam = tam;
	this->_pais = new CPais[tam];
	_medallero = new CMedallero();
	
	CDeporte squash("squash");
	CDeporte natacion("natacion");
	CDeporte tenis("tenis");

	CDeporte vectorDeporte[3];
	vectorDeporte[0] = squash;
	vectorDeporte[1] = natacion;
	vectorDeporte[2] = tenis;


	CSecuencia < CAtleta > sec;
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	
	

	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	//std::string nomprueba = _random.randomString(16);

	
	CPais pais1, pais2, pais3;
	for (int i = 0; i<tam; i++) {
		
		CPrueba prueba(_random.randomString(16), vectorDeporte[_random.aleatorio(3)]);

		pais1.setNombre(_random.randomString(16));
		pais2.setNombre(_random.randomString(16));
		pais3.setNombre(_random.randomString(16));

		CAtleta atleta1("Pepe", pais1);
		CAtleta atleta2("Juan", pais2);
		CAtleta atleta3("Carlos", pais3);
			
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

void CAlgoritmoMedalleroPais::Execute() {	
	this->_medallero->medallero();
	
}

void CAlgoritmoMedalleroPais::TearDown() {
	delete [] this->_pais;
	delete this->_medallero;
}


