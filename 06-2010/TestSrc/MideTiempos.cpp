#include "MideTiempos.h"
#include <ctime>
#include <string>
using namespace std;

double CMideTiempos::tiempos(const int t1, const int t2,const int repet, const float ratio){

	double tiempo = (double(t2-t1)/CLOCKS_PER_SEC) / (repet/ratio);
	return tiempo;


};


CMideTiempos::CMideTiempos(int tamIni, 
				int tamFin, 
				int intervalo, 
				int numEjeIni, 
				int numEjeFin
			): 	_tamIni(tamIni),
				_tamFin ( tamFin), 
				_intervalo(intervalo),
				_numEjeIni(numEjeIni),
				_numEjeFin(numEjeFin) 
{
	
	_intervalorepet = 0;
};

void CMideTiempos::LanzaPrueba(CAlgoritmo *alg, CSalida *output1, CSalida *output2){

	


	clock_t t1, t2;
	float ratio=1.0;
	float tiempo= 0.0;
	int aux;
	int repet = 0;
	repet = _numEjeIni;

	if ((_intervalo == 0)&& (_tamIni != _tamFin)){
		cout << "Fin de lanza prueba" << endl;
	} else {
		/*
		* Caso 1 _intervalo == 0 y tamIni == tamFin
		*/
		if ((_intervalo == 0) && (_tamIni == _tamFin)){
			repet = 1;
			_intervalorepet = 0;
		} else  
			
		/*
		* Caso 2
		* Intervalo !=0  y ( tamIni>tamFin, tamIni<tamFin, tamIni == tamFin )
		*/

		if (_intervalo!=0){
		
			if (_tamIni > _tamFin){
				aux = _tamIni;
				_tamIni = _tamFin;
				_tamFin = aux;
				// Puede ocurrir que la division entera entre (((_tamFin-_tamIni)/_intervalo)!=0) sea 0.( 2/4-->0)
				if (((_tamFin-_tamIni)/_intervalo)!=0) _intervalorepet = (_numEjeIni-_numEjeFin)/((_tamFin-_tamIni)/_intervalo);
			}else 	// Caso en que el _tamFin > _tamIni
				if ((_tamIni == _tamFin)&& _tamIni ==0){
					repet = 1;
					_intervalorepet = 0;
				}else
					if ((_tamIni == _tamFin) && _tamIni !=0)
									_intervalorepet = 0;
					else
						if (((_tamFin-_tamIni)/_intervalo)!=0) _intervalorepet = (_numEjeIni-_numEjeFin)/((_tamFin-_tamIni)/_intervalo);	
		}
		
		
		//
	

	if ( output1 != NULL) output1->InitPrueba(alg->getDescription());
	if ( output2 != NULL) output2->InitPrueba(alg->getDescription());

	/**
	*	Aqui empezamos a medir realmente
	*/	
	for ( int tam = _tamIni; tam <=_tamFin; tam += _intervalo){
		
		//Ejecutamos
		alg->SetUp(tam);
		t1 = clock();
		for (int i = 0; i < repet; i++){
			alg->Execute();
		};
		t2 = clock();
		alg->TearDown();
		
		//Calculamos tiempo
		tiempo = (float(t2-t1)/CLOCKS_PER_SEC);
	
		if ( output1 != NULL) output1->Muestra(tam,tiempo/repet);
		if ( output2 != NULL) output2->Muestra(tam,tiempo/repet);

		//Dependiendo del tiempo escogemos el nuevo intervalo
		if (tiempo > 5) {
					
			ratio*=2;
			repet = repet / ratio;
			
			if (repet ==0 ) repet = 1;
			
			_intervalorepet = (repet-_numEjeFin/ratio)/((_tamFin-tam)/_intervalo);
			repet -= _intervalorepet;
	
		} else {					
			repet -= _intervalorepet;
			if ((repet/ratio) ==0 ) repet= 1;
		}

	}
	}
	if ( output1 != NULL)output1->FinPrueba();
	if ( output2 != NULL)output2->FinPrueba();
};


