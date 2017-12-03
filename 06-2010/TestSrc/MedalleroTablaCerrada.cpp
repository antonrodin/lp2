#include "MedalleroTablaCerrada.h"

/**
*	IMLEMENTACION OPERACIONES PUBLICAS
*/

CMedalleroTCerrada::CMedalleroTCerrada() {
	_medallero = new TInfoMedallasC;
	_porDeporte = new PorDeportesC;
}

CMedalleroTCerrada::~CMedalleroTCerrada() {
		delete _medallero;

		TInfoMedallasC* aux;
		CPareja < CDeporte, TInfoMedallasC* > pareja;
		CSecuencia< CPareja < CDeporte, TInfoMedallasC* > > secuencia = _porDeporte->enumera();
		
		
		//Destruimos todas las secuencias de la secuencia PorDeportesC
		secuencia.reinicia();
		while (!secuencia.esFin()) {
			pareja= secuencia.actual();
			aux = pareja.v2();
			delete aux;
			secuencia.avanza();
		}

		delete _porDeporte;
	
};

void	CMedalleroTCerrada::clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif) {
	
	CAtleta atleta;
	CPais pais;
	bool existe = false;
	int tipo = 0;
	TInfoMedallasC* aux = 0;
	aux = buscaDeporte(existe, prueba.getDeporte());
	CPareja <CDeporte, TInfoMedallasC* > pareja;

	//Si no existe el deporte tenemos que agregarlo
	if (!existe) {
		aux = new TInfoMedallasC;
	}


	//Actualizamos la clasificacion de medallas general y en la de deportes
	clasif.reinicia();
	while ((!clasif.esFin()) && (tipo < 3)) {
		atleta = clasif.actual();
		pais = atleta.getPais();
		this->ponMedalla(tipo, pais, this->_medallero);
		this->ponMedalla(tipo, pais, aux);
		clasif.avanza();
		tipo++;
	}

	//Finalmente metemos el aux dentro de _porDeporte
	_porDeporte->inserta(prueba.getDeporte(), aux);
}

CSecuencia< CPareja < CPais, CMedallas > >  CMedalleroTCerrada::medallero () {
	return _medallero->enumera();
}

CSecuencia< CPareja < CPais, CMedallas > >   CMedalleroTCerrada::medalleroOrdenado () {
	
	CSecuencia< CPareja < CPais, CMedallas > > aux = _medallero->enumera();
	CSecuencia< CPareja < CPais, CMedallas > > sol;
	CPareja< CPais, CMedallas >* pareja = new CPareja< CPais, CMedallas >[aux.numElems()];
	int cont = 0;
	CPareja< CPais, CMedallas > auxP;
	
	aux.reinicia();
	while (!aux.esFin()) {
		auxP = aux.actual();
		pareja[cont] = auxP;
		cont++;
		aux.avanza();

	}

	this->mergeSort(pareja, aux.numElems());

	sol.reinicia();
	for (int i = aux.numElems()-1; i>=0; i--) {
		sol.inserta(pareja[i]);
	}
	
	delete [] pareja;
	return sol;
};

CSecuencia< CPareja < CPais, CMedallas > >  CMedalleroTCerrada::medalleroDeporte (const CDeporte &dep) {
	
	CSecuencia< CPareja < CPais, CMedallas > > sol;
	TInfoMedallasC* aux;
			
	if (_porDeporte->esta(dep)) {
		aux = _porDeporte->consulta(dep);
		sol = aux->enumera();
	}

	return sol;
};

CSecuencia< CPareja < CPais, CMedallas > >  CMedalleroTCerrada::medalleroDeporteOrdenado (const CDeporte &dep){
	
	CSecuencia< CPareja < CPais, CMedallas > > aux = this->medalleroDeporte(dep);
	CSecuencia< CPareja < CPais, CMedallas > > sol;
	CPareja< CPais, CMedallas >* pareja = new CPareja< CPais, CMedallas >[aux.numElems()];
	int cont = 0;
	CPareja< CPais, CMedallas > auxP;
	
	aux.reinicia();
	while (!aux.esFin()) {
		auxP = aux.actual();
		pareja[cont] = auxP;
		cont++;
		aux.avanza();

	}

	this->mergeSort(pareja, aux.numElems());

	sol.reinicia();
	for (int i = aux.numElems()-1; i>=0; i--) {
		sol.inserta(pareja[i]);
	}
	
	delete [] pareja;
	return sol;
};


/**
*	IMPLEMENTACION OPERACIONES PRIVADAS
*/
void CMedalleroTCerrada::ponMedalla(int tipo, CPais pais, TInfoMedallasC* tabla) {
	
	CMedallas medallas;
	bool esta = false;
	

		
	esta = tabla->esta(pais);
	if (esta) {
		medallas = tabla->consulta(pais);
		if (tipo == 0) medallas.setOros(medallas.getOros() + 1);
		if (tipo == 1) medallas.setPlatas(medallas.getPlatas() + 1);
		if (tipo == 2) medallas.setBronces(medallas.getBronces() + 1);
		tabla->inserta(pais, medallas);
	} 

	if (!esta) {
		if (tipo == 0) medallas.setOros(1);
		if (tipo == 1) medallas.setPlatas(1);
		if (tipo == 2) medallas.setBronces(1);
		tabla->inserta(pais, medallas);
	}
}

TInfoMedallasC* CMedalleroTCerrada::buscaDeporte(bool& existe, CDeporte deporte) {
	
	TInfoMedallasC* aux = 0;
	CPareja < CDeporte, TInfoMedallasC* > pareja;

	existe = _porDeporte->esta(deporte);
	if (existe) aux = _porDeporte->consulta(deporte);

	return aux;
}
