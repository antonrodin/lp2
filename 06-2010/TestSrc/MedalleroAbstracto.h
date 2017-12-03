#ifndef MedalleroAbstractoH
#define MedalleroAbstractoH

#include <iostream>

#include "Pareja.h"
#include "Pais.h"
#include "Medallas.h"
#include "Deporte.h"
#include "Secuencia.h"
#include "Atleta.h"
#include "Prueba.h"


class CMedalleroAbstracto {
public:
	CMedalleroAbstracto() {};
	virtual  ~CMedalleroAbstracto() {};
	virtual std::string getNombre() = 0;
	virtual void  clasificacion(const CPrueba &prueba, CSecuencia< CAtleta > &clasif) = 0;
	virtual CSecuencia< CPareja < CPais, CMedallas > >  medallero () = 0;
	virtual CSecuencia< CPareja < CPais, CMedallas > >  medalleroOrdenado () = 0;
	virtual CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep) = 0;
	virtual CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep) = 0; 
protected:
	//Utilizamos el mergesort para ordenar la secuencia
	void mergeSort(CPareja< CPais, CMedallas > v[], int num);
	void mergeSortAux(CPareja< CPais, CMedallas > v[], CPareja< CPais, CMedallas > aux[],int ini, int fin);
private:
};

#endif
