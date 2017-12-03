#include "Medallero.h"

CMedallero::~CMedallero () {
		delete _medallero;

		TInfoMedallas* aux;
		CPareja <CDeporte, TInfoMedallas* > pareja;
		
		//Destruimos todas las secuencias de la secuencia porDeportes
		_porDeporte->reinicia();
		while (!_porDeporte->esFin()) {
			pareja = _porDeporte->actual();
			aux = pareja.v2();
			pareja.ponV2(0);
			delete aux;
			_porDeporte->avanza();
		}

		delete _porDeporte;
	
};

void	CMedallero::clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif) {
	
	CAtleta atleta;
	CPais pais;
	bool existe = false;
	int tipo = 0;
	TInfoMedallas* aux = 0;
	aux = buscaDeporte(existe, prueba.getDeporte());
	CPareja <CDeporte, TInfoMedallas* > pareja;

	//Si no existe el deporte tenemos que agregarlo
	if (!existe) {
		aux = new TInfoMedallas;
		pareja.ponV1(prueba.getDeporte());
		pareja.ponV2(aux);
		_porDeporte->inserta(pareja);
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

}

CSecuencia< CPareja< CPais, CMedallas > >	CMedallero::medallero () {

	CSecuencia< CPareja< CPais, CMedallas > > aux;
	CPareja< CPais, CMedallas > auxP;
	
	_medallero->reinicia();
	while (!_medallero->esFin()) {
		auxP = _medallero->actual();
		aux.inserta(auxP);
		_medallero->avanza();

	}
	return aux;

}

CSecuencia< CPareja< CPais, CMedallas > >	CMedallero::medalleroOrdenado () {

	CSecuencia< CPareja< CPais, CMedallas > > aux;
	CPareja< CPais, CMedallas >* pareja = new CPareja< CPais, CMedallas >[_medallero->numElems()];
	CPareja< CPais, CMedallas > auxP;
	int cont = 0;

	_medallero->reinicia();
	while (!_medallero->esFin()) {
		auxP = _medallero->actual();
		pareja[cont] = auxP;
		cont++;
		_medallero->avanza();

	}

	this->quickSort(pareja, _medallero->numElems());
	
	for (int i = _medallero->numElems()-1; i>=0; i--) {
		aux.inserta(pareja[i]);
	}
	
	delete [] pareja;
	return aux;
}

CSecuencia< CPareja< CPais, CMedallas > >	CMedallero::medalleroDeporte (const CDeporte &dep) {

	CSecuencia< CPareja< CPais, CMedallas > > ret;
	bool existe = false;
	TInfoMedallas* aux = 0;
	aux = buscaDeporte(existe, dep);
	CPareja <CPais, CMedallas > pareja;

	//Si no existe el deporte tenemos que agregarlo
	if (existe) {
		aux->reinicia();
		while (!aux->esFin()) {
			pareja = aux->actual();
			ret.inserta(pareja);
			aux->avanza();
		}
	}
	
	return ret;

}

CSecuencia< CPareja< CPais, CMedallas > >	CMedallero::medalleroDeporteOrdenado (const CDeporte &dep) {
	
	CSecuencia< CPareja< CPais, CMedallas > > ret;
	bool existe = false;
	TInfoMedallas* aux = 0;
	aux = buscaDeporte(existe, dep);
	CPareja <CPais, CMedallas > auxP;
	int cont = 0;
	
	if (existe) {
		
		CPareja< CPais, CMedallas >* pareja = new CPareja< CPais, CMedallas>[aux->numElems()];

		//Copiamos de la secuencia elegida hacia el vector dinamico de parejas
		aux->reinicia();
		while (!aux->esFin()) {
			auxP = aux->actual();
			pareja[cont] = auxP;
			cont++;
			aux->avanza();
		}

		//Ordenamos el vector.
		this->quickSort(pareja, aux->numElems());
		
		//Copiamos elementos del vector ordenado hacia la secuencia de salida
		for (int i = aux->numElems()-1; i>=0; i--) {
		
			ret.inserta(pareja[i]);
		
		}
	
		delete [] pareja;

	}
	
	return ret;

}

/*
	Observadores
*/
void CMedallero::mostrarSecuencia(TInfoMedallas* secuencia) {
	
	CMedallas medallas;
	CPareja < CPais, CMedallas > pareja;
	CPais pais;
	
	secuencia->reinicia();
	while ( !secuencia->esFin() ) {
		pareja = secuencia->actual();
		pais = pareja.v1();
		medallas = pareja.v2();

		//Mostramos
		std::cout << pais.getNombre() << " " << medallas.getOros() << " " << medallas.getPlatas() << " " << medallas.getBronces() << std::endl;
		
		secuencia->avanza();
	}
}

void CMedallero::ponMedalla(int tipo, CPais pais, TInfoMedallas* secuencia) {
	
	CMedallas medallas;
	CPareja< CPais, CMedallas> pareja;
	bool exito = false;

	secuencia->reinicia();
	while ((!secuencia->esFin()) && !exito) {
		
		pareja = secuencia->actual();
		if (pais == pareja.v1()) {
			medallas = pareja.v2();
			if (tipo == 0) medallas.setOros(medallas.getOros() + 1);
			if (tipo == 1) medallas.setPlatas(medallas.getPlatas() + 1);
			if (tipo == 2) medallas.setBronces(medallas.getBronces() + 1);
			
			pareja.ponV2(medallas);
			secuencia->borra();
			secuencia->inserta(pareja);
			exito = true;
		} else {
			secuencia->avanza();
		}
	}

	if (!exito) {
		pareja.ponV1(pais);
		if (tipo == 0) medallas.setOros(1);
		if (tipo == 1) medallas.setPlatas(1);
		if (tipo == 2) medallas.setBronces(1);
		pareja.ponV2(medallas);
		secuencia->inserta(pareja);
	}
}

TInfoMedallas* CMedallero::buscaDeporte(bool& existe, CDeporte deporte) {
	
	TInfoMedallas* aux = 0;
	CPareja < CDeporte, TInfoMedallas* > pareja;

	_porDeporte->reinicia();
	while ((!_porDeporte->esFin()) && (!existe)) {
		pareja = _porDeporte->actual();
		if (deporte == pareja.v1()) {
			existe = true;
			aux = pareja.v2();
		}
		_porDeporte->avanza();
	}

	return aux;

}


/*
*Metodo auxiliar quicksort
*/
void CMedallero::particion ( CPareja<CPais, CMedallas>  v[], int a, int b, int & p ) {

	int i, j;
	CPareja< CPais, CMedallas > aux;
	//= new CPareja< CPais, CMedallas >[num];
	i = a+1;
	j = b;
	while ( i <= j ) {
		if ( (v[i].v2() > v[a].v2()) && (v[j].v2() < v[a].v2()) ) {
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i = i + 1;
			j = j - 1;
		}
		else {
			if ( v[i].v2() < v[a].v2() || v[i].v2() == v[a].v2() )	i = i + 1;
			if ( v[j].v2() > v[a].v2() || v[j].v2() == v[a].v2())	j = j - 1;
		}
	}
	p = j;
	aux = v[a];
	v[a] = v[p];
	v[p] = aux;

}

/*
* Metodo auxiliar quicksort
*/
void CMedallero::quickSort( CPareja<CPais, CMedallas> v[], int a, int b ) {

	int p;
	if ( a <= b ) {
		particion(v, a, b, p);
		quickSort(v, a, p-1);
		quickSort(v, p+1, b);
	}

}

void CMedallero::quickSort ( CPareja<CPais, CMedallas> v[], int num ) {

	quickSort(v, 0, num-1);

}

/*
void CMedallero::mergeSort(CPareja< CPais, CMedallas > v[], int num) {
	CPareja< CPais, CMedallas > * aux = new CPareja< CPais, CMedallas >[num];
	mergeSortAux(v, aux, 0, num-1);
	delete [] aux;
}

void CMedallero::mergeSortAux(CPareja< CPais, CMedallas > v[], CPareja< CPais, CMedallas > aux[],int ini, int fin) {
	if (ini < fin) {
		int med = (ini + fin) / 2;
		mergeSortAux(v, aux, ini, med);
		mergeSortAux(v, aux, med+1, fin);
		
		int i = ini;
		int j = med+1;
		int k = ini;
	
		while ((i <= med) && (j<=fin)) {
			//Mezclamos:
			if (v[i].v2() < v[j].v2()) {
				aux[k] = v[i];
				i++;
				k++;
			} else {
				aux[k] = v[j];
				j++;
				k++;
			}
		}
		
		//Por si queda algo lo metemos tambien:
		for (i;i<=med;i++) {
				aux[k] = v[i];
				k++;
		}
		
		for (j;j<=fin;j++) {
				aux[k] = v[j];
				k++;
		}

		for (int i= ini;i<=fin;i++) {
	 		v[i] = aux[i];
		}
	} 
}*/