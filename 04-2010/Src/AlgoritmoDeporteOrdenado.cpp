#include "AlgoritmoDeporteOrdenado.h"


CAlgoritmoDeporteOrdenado::CAlgoritmoDeporteOrdenado() {
	this->_deporte = 0;
}

std::string CAlgoritmoDeporteOrdenado::getDescription() {
	return "Deporte Ordenado";
}

CAlgoritmoDeporteOrdenado::~CAlgoritmoDeporteOrdenado() {
}

//Esto realmente es un constructor? No seria mejor crear directmente un constructor? en vez de esta funcion?
void CAlgoritmoDeporteOrdenado::SetUp(int tam) {		
	
	
	this->_tam = tam;
	this->_deporte = new CDeporte[tam];
	_medallero = new CMedallero();
	
	
	//6 Paises en vez de 3 anadidos
	CPais pais1("Espana");
	CPais pais2("Rusia");
	CPais pais3("EEUU");
	CPais pais4("Jamaika");
	CPais pais5("Burundi");
	CPais pais6("Uruguay");
	
	CPais vectorPaises[6];
	vectorPaises[0] = pais1;
	vectorPaises[1] = pais2;
	vectorPaises[2] = pais3;
	vectorPaises[3] = pais4;
	vectorPaises[4] = pais5;
	vectorPaises[5] = pais6;
	
	
	CSecuencia < CAtleta > sec;
	CPareja <CPais, CSecuencia < CAtleta> > pareja;
	
	

	//Generamos N paises con el randomString y lo guardamos en la secuencia y en el vector
	for (int i = 0; i<tam; i++) {
		
		CDeporte deporte(_random.randomString(16));
		CPrueba prueba(_random.randomString(16), deporte);

		this->_deporte[i] = deporte;

		CAtleta atleta1("Pepe", vectorPaises[_random.aleatorio(6)]);
		CAtleta atleta2("Juan", vectorPaises[_random.aleatorio(3)]);
		CAtleta atleta3("Carlos", vectorPaises[_random.aleatorio(5)]);
			
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

void CAlgoritmoDeporteOrdenado::Execute() {	

	//Aqui lo que hacemos es actualizar el nuevo pais con nuevos atletas que esta en una posicion aleatoria
	CDeporte deporte = this->_deporte[_random.aleatorio(this->_tam)];
	CSecuencia< CPareja< CPais, CMedallas > > sec;

	sec =_medallero->medalleroDeporteOrdenado(deporte);

	

}

void CAlgoritmoDeporteOrdenado::TearDown() {

	delete [] this->_deporte;
	delete this->_medallero;
}