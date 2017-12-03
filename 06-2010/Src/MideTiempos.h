#ifndef _MideTiempos_h
#define _MideTiempos_h
#include "Algoritmo.h"

#include "Salida.h"
#include <iostream>
class CMideTiempos{

	public:
		CMideTiempos(int,int,int,int,int);
		void LanzaPrueba(CAlgoritmo *,CSalida *, CSalida *);
	private:
	
	int _tamIni,_tamFin,_intervalo,_numEjeIni,_numEjeFin,_intervalorepet;
	CAlgoritmo * alg;
	double tiempos(const int,const int,const int, const float);
	
};




#endif