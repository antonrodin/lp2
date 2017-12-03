#include "AlgoritmoDeporteNormal.h"


CAlgoritmoDeporteNormal::CAlgoritmoDeporteNormal() {
	this->_deporte = 0;
}

std::string CAlgoritmoDeporteNormal::getDescription() {
	return "Deporte Normal";
}

CAlgoritmoDeporteNormal::~CAlgoritmoDeporteNormal() {
}

//Esto realmente es un constructor? No seria mejor crear directmente un constructor? en vez de esta funcion?
void CAlgoritmoDeporteNormal::SetUp(int tam) {		
	
	
	this->_tam = tam;
	this->_deporte = new CDeporte[tam];
	_medallero = new CMedallero();
	
	CPais pais1("Espana");
	CPais pais2("Rusia");
	CPais pais3("EEUU");
	CPais vectorPaises[3];
	vectorPaises[0] = pais1;
	vectorPaises[1] = pais2;
	vectorPaises[2] = pais3;
	
	CSecuencia < CAtleta > sec;
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	
	

	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	for (int i = 0; i<tam; i++) {
		
		CDeporte deporte(_random.randomString(16));
		CPrueba prueba(_random.randomString(16), deporte);

		this->_deporte[i] = deporte;
		CAtleta atleta1("Pepe", vectorPaises[_random.aleatorio(3)]);
		CAtleta atleta2("Juan", vectorPaises[_random.aleatorio(3)]);
		CAtleta atleta3("Carlos", vectorPaises[_random.aleatorio(3)]);
			
		sec.inserta(atleta1);
		sec.inserta(atleta2);
		sec.inserta(atleta3);
		int cont = _random.aleatoriosqrt(tam) ;

		for (int j = 0; j < cont; j++) {
			_medallero->clasificacion(prueba, sec);
		}
		sec.reinicia();
		sec.borra();
		sec.borra();
		sec.borra();
	}

}

void CAlgoritmoDeporteNormal::Execute() {	

	//Aqui lo que hacemos es actualizar el nuevo pais con nuevos atletas que esta en una posicion aleatoria
	CDeporte deporte = this->_deporte[_random.aleatorio(this->_tam)];
	this->_medallero->medalleroDeporte(deporte);
	
}

void CAlgoritmoDeporteNormal::TearDown() {
	delete [] this->_deporte;
	delete this->_medallero;
}
