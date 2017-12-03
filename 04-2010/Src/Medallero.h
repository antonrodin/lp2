#ifndef MedalleroH
#define MedalleroH

#include <iostream>

#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Deporte.h"
#include "Secuencia.h"
#include "Atleta.h"
#include "Prueba.h"

typedef CSecuencia < CPareja< CPais, CMedallas > > TInfoMedallas;
typedef CSecuencia< CPareja < CDeporte, TInfoMedallas* > > PorDeportes;

class CMedallero {
public:
	CMedallero() {
		_medallero = new TInfoMedallas;
		_porDeporte = new PorDeportes;
	};
	
	~CMedallero ();

	void	clasificacion (const CPrueba &prueba, CSecuencia< CAtleta > &clasif);
	CSecuencia< CPareja< CPais, CMedallas > >	medallero ();
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroOrdenado ();
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroDeporte (const CDeporte &dep);
	CSecuencia< CPareja< CPais, CMedallas > >	medalleroDeporteOrdenado (const CDeporte &dep);

	//Metodos observadores
	void mostrarSecuencia(TInfoMedallas* secuencia);
	TInfoMedallas* getMedallero() const { return _medallero; };

private:
	TInfoMedallas* _medallero;
	PorDeportes* _porDeporte;

	//Agrega una medalla de tipo "tipo 0, 1, 2" a pais "pais" a la secuencia "secuencia"
	void ponMedalla(int tipo, CPais pais, TInfoMedallas* secuencia);
	TInfoMedallas* buscaDeporte(bool& existe, CDeporte deporte);
	
	void particion ( CPareja<CPais, CMedallas>  v[], int a, int b, int & p );
	void quickSort( CPareja<CPais, CMedallas> v[], int a, int b );
	void quickSort ( CPareja < CPais, CMedallas > v[], int num );

	//Utilizamos el mergesort para ordenar la secuencia
	//void mergeSort(CPareja< CPais, CMedallas > v[], int num);
	//void mergeSortAux(CPareja< CPais, CMedallas > v[], CPareja< CPais, CMedallas > aux[],int ini, int fin);
};

#endif