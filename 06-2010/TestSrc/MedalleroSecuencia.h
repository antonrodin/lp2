#ifndef MedalleroSecuenciaH
#define MedalleroSecuenciaH

#include <iostream>

#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Deporte.h"
#include "Secuencia.h"
#include "Atleta.h"
#include "Prueba.h"
#include "MedalleroAbstracto.h"

typedef CSecuencia < CPareja< CPais, CMedallas > > TInfoMedallasSec;
typedef CSecuencia< CPareja < CDeporte, TInfoMedallasSec* > > PorDeportesSec;

class CMedalleroSecuencia : public CMedalleroAbstracto {
public:
	CMedalleroSecuencia() {
		_medallero = new TInfoMedallasSec;
		_porDeporte = new PorDeportesSec;
	};
	
	~CMedalleroSecuencia ();

	std::string getNombre() { return "Secuencia"; };

	void	clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif);
	CSecuencia< CPareja< CPais, CMedallas > >	medallero ();
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroOrdenado ();
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroDeporte (const CDeporte &dep);
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroDeporteOrdenado (const CDeporte &dep);

	//Metodos observadores
	void mostrarSecuencia(TInfoMedallasSec* secuencia);
	TInfoMedallasSec* getMedallero() const { return _medallero; };

private:
	TInfoMedallasSec* _medallero;
	PorDeportesSec* _porDeporte;

	//Agrega una medalla de tipo "tipo 0, 1, 2" a pais "pais" a la secuencia "secuencia"
	void ponMedalla(int tipo, CPais pais, TInfoMedallasSec* secuencia);
	TInfoMedallasSec* buscaDeporte(bool& existe, CDeporte deporte);
	
	void particion ( CPareja<CPais, CMedallas>  v[], int a, int b, int & p );
	void quickSort( CPareja<CPais, CMedallas> v[], int a, int b );
	void quickSort ( CPareja < CPais, CMedallas > v[], int num );

	//Utilizamos el mergesort para ordenar la secuencia
	//void mergeSort(CPareja< CPais, CMedallas > v[], int num);
	//void mergeSortAux(CPareja< CPais, CMedallas > v[], CPareja< CPais, CMedallas > aux[],int ini, int fin);
};

#endif
