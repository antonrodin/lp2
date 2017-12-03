
#include <iostream>

#include "Pareja.h"
#include "Secuencia.h"
#include "Pais.h"
#include "Medallas.h"
#include "Deporte.h"
#include "Atleta.h"
#include "Prueba.h"
#include "Medallero.h"
#include "Algoritmo.h"
#include "AlgoritmoMedalleroPais.h"
#include "AlgoritmoMedalleroOrdenadoPaises.h"
#include "AlgoritmoPaisAleatorio.h"
#include "AlgoritmoPaisPrimero.h"
#include "AlgoritmoPaisUltimo.h"
#include "AlgoritmoDeporteNormal.h"
#include "AlgoritmoDeporteOrdenado.h"
#include "SalidaEstandar.h"
#include "SalidaGNUPlot.h"
#include "MideTiempos.h"
//#include "vld.h"
#include<stdlib.h>
#include<time.h>

using namespace std;


void ayuda (){
	cout << "Medallero.exe -h" << endl;
	cout << "        Muestra esta ayuda" << endl<< endl;
	cout << "Medallero.exe [nInicial][nFinal][incN][repIni][repFin]" << endl;
	cout << "Parametros:" << endl;
	cout << "            [nInicial]: tamaño inicial de los datos." << endl;
	cout << "            [nFinal]: tamaño final." << endl;
	cout << "			 [incN]: incremento del tamaño." << endl;
	cout << "			 [repIni]: numero de repeticiones para el primer tamaño." << endl;
	cout << "			 [repFin]: numero de repeticiones para el segundo tamaño." << endl;

}
bool sintaxOK (const int numarg,string arg ){
     
	if (numarg < 5){
		std::cout << "El comando necesita parametros. Consulte su ayuda con Medallero.exe -h" << std::endl;
			ayuda();
		if ( numarg == 1 && arg == "-h"){
			ayuda();
		}
		return false;
	}
	else {
		if (numarg == 6){
				return true;
		}
		else {
			std::cout << "El comando necesita  solo 5 parametros. Consulte su ayuda con Medallero.exe -h" << std::endl;
			ayuda();
			return false;
		}
	}
}

int main(int argc, const char *argv[]){
	
	if (argc == 1){
		std::cout << "El comando necesita parametros. Consulte su ayuda con Medallero.exe -h" << std::endl<<std::endl;
		ayuda();
	
	}
	else{
		string arg1 = argv[1];
	
		if (sintaxOK(argc,arg1)) {
			
			
			int tamIni = atoi(argv [1]);
			int tamFin = atoi(argv [2]);
			int inctam = atoi(argv [3]);
			int repIni = atoi(argv[4]);
			int repFin = atoi(argv[5]);

			double t1, t2, tiempo;
			std::string nomfich[]= {"Medallero_NPaises.txt","MedalleroOrdenado_NPaises.txt", "MedalleroDeporte.txt", "MedalleroDeporteOrdenado.txt", "Clasif_NPaisesAleatorio.txt", "Clasif_NPaisesPrimero.txt", "Clasif_NPaisesUltimo.txt"};
			CAlgoritmo *algs[] = {new CAlgoritmoMedalleroPais, new CAlgoritmoMedalleroOrdenadoPais, new CAlgoritmoDeporteNormal, new CAlgoritmoDeporteOrdenado, new CAlgoritmoPaisAleatorio, new CAlgoritmoPaisPrimero, new CAlgoritmoPaisUltimo};
			CMideTiempos medicion(tamIni, tamFin, inctam, repIni, repFin);
			CSalidaEstandar * output1 = new CSalidaEstandar();
			CSalidaGNUPlot * output2 = new CSalidaGNUPlot();
	
			t1 = clock();
			for (int i = 0 ; i < 7; i++){

				output2->setFichero(nomfich[i]);
				medicion.LanzaPrueba(algs[i],output1,output2);
		
			}
			t2 = clock();
		
			tiempo = (t2 - t1)/CLOCKS_PER_SEC;
			int hh = ((int)tiempo) /3600;
			int aux =  ((int)tiempo) % 3600;
			int mm =aux/ 60;
			int ss = aux % 60;
			std::cout << "El tiempo empleado es : " << hh << " : " << mm << " : " << ss << "  (HH:MM:SS)" << std::endl; 

			for (int i = 0 ; i < 7; i++)
				delete algs[i];
	
			delete output1;
			delete output2;
		}
	}
		return 0;
}
