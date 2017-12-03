#include "AlgoritmoMedalleroOrdenadoPaises.h"



CAlgoritmoMedalleroOrdenadoPais::CAlgoritmoMedalleroOrdenadoPais() {
	this->_pais = 0;
}

std::string CAlgoritmoMedalleroOrdenadoPais::getDescription() {
	return "Medallero Ordenado por Pais";
}

CAlgoritmoMedalleroOrdenadoPais::~CAlgoritmoMedalleroOrdenadoPais() {
}

//Esto realmente es un constructor? No seria mejor crear directmente un constructor? en vez de esta funcion?
void CAlgoritmoMedalleroOrdenadoPais::SetUp(int tam) {		
	
		
	this->_tam = tam;
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

	for (int i = 0; i<tam; i++) {
		
		CPrueba prueba(_random.randomString(16), vectorDeporte[_random.aleatorio(3)]);
		CPais pais1, pais2;


		pais1.setNombre(_random.randomString(16));
		pais2.setNombre(_random.randomString(16));

		CAtleta atleta1("Pepe", pais1);
		CAtleta atleta2("Juan", pais1);
		CAtleta atleta3("Carlos", pais2);
			
		sec.inserta(atleta1);
		sec.inserta(atleta2);
		sec.inserta(atleta3);
		
		int cont = _random.aleatorio(tam) ;
		for (int j = 0; j < cont; j++) {
				
			_medallero->clasificacion(prueba, sec);
		
		}
		sec.reinicia();
		sec.borra();
		sec.borra();
		sec.borra();
	}


}

void CAlgoritmoMedalleroOrdenadoPais::Execute() {	
	
	this->_medallero->medalleroOrdenado();
}

void CAlgoritmoMedalleroOrdenadoPais::TearDown() {
	delete this->_medallero;
}


