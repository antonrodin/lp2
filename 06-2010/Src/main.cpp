/**
*	@autor Anton Zekeriev Rodin Carlos Yañez Carrasco 
*	@date Mayo 2010
*	@tool Visual Studio 2008
*/


//Bibliotecas especificas
#include <iostream>

//Bibliotecas propias
#include "TablaAbierta.h"
#include "TablaCerrada.h"
#include "MedalleroAbstracto.h"
#include "MedalleroTablaAbierta.h"
#include "MedalleroTablaCerrada.h"
#include "MedalleroSecuencia.h"
#include "Algoritmo.h"
#include "AlgoritmoPaisPrimero.h"
#include "AlgoritmoPaisAleatorio.h"
#include "AlgoritmoPaisUltimo.h"
#include "AlgoritmoPaises.h"
#include "AlgoritmoMedalleroOrdenadoPaises.h"
#include "AlgoritmoDeporteNormal.h"
#include "AlgoritmoDeporteOrdenado.h"
#include "Random.h"
#include "Pais.h"
#include "Atleta.h"
#include "Deporte.h"
#include "Prueba.h"
#include "Secuencia.h"
//#include "vld.h"
#include "SalidaEstandar.h"
#include "SalidaGNUPlot.h"
#include "MideTiempos.h"

//Bibliotecas para borrad
#include "Random.h"



void ayuda (){
	std::cout << "Medallero.exe -h" << std::endl;
	std::cout << "        Muestra esta ayuda" << std::endl<< std::endl;
	std::cout << "Medallero.exe [nInicial][nFinal][incN][repIni][repFin]" << std::endl;
	std::cout << "Parametros:" << std::endl;
	std::cout << "            [nInicial]: tamaño inicial de los datos." << std::endl;
	std::cout << "            [nFinal]: tamaño final." << std::endl;
	std::cout << "            [incN]: incremento del tamaño." << std::endl;
	std::cout << "            [repIni]: numero de repeticiones para el primer tamaño." << std::endl;
	std::cout << "            [repFin]: numero de repeticiones para el segundo tamaño." << std::endl;

}
bool sintaxOK (const int numarg,std::string arg ){
     
	if (numarg < 5){
		std::cout << "El comando necesita parametros. Consulte la ayuda con Medallero.exe -h" << std::endl;
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
			std::cout << "El comando necesita  5 parametros. Consulte la ayuda con Medallero.exe -h" << std::endl;
			ayuda();
			return false;
		}
	}
}
int main(int argc, const char *argv[]) {


	int tamIni;
	int tamFin;
	int inctam;
	int repIni;
	int repFin;

	double t1, t2, tiempo;
	std::string nomfich[]= {
		"Clasif_NPaisesPrimeroSecuencia.txt", 
		"Clasif_NPaisesAleatorioSecuencia.txt",
		"Clasif_NPaisesUltimoSecuencia.txt",
		"Medallero_NPaisesSecuencia.txt",
		"MedalleroOrdenado_NPaisesSecuencia.txt",
		"MedalleroDeporte_DeporteAleatorioSecuencia.txt",
		"MedalleroDeporteOrdenado_DeporteAleatorioSecuencia.txt",
		"Clasif_NPaisesPrimeroTAbierta.txt", 
		"Clasif_NPaisesAleatorioTAbierta.txt",
		"Clasif_NPaisesUltimoTAbierta.txt",
		"Medallero_NPaisesTAbierta.txt",
		"MedalleroOrdenado_NPaisesTAbierta.txt",
		"MedalleroDeporte_DeporteAleatorioTAbierta.txt",
		"MedalleroDeporteOrdenado_DeporteAleatorioTAbierta.txt",
		"Clasif_NPaisesPrimeroTCerrada.txt", 
		"Clasif_NPaisesAleatorioTCerrada.txt",
		"Clasif_NPaisesUltimoTCerrada.txt",
		"Medallero_NPaisesTCerrada.txt",
		"MedalleroOrdenado_NPaisesTCerrada.txt",
		"MedalleroDeporte_DeporteAleatorioTCerrada.txt",
		"MedalleroDeporteOrdenado_DeporteAleatorioTCerrada.txt"
	};
	
	CAlgoritmo* algs[] = {
		new CAlgoritmoPaisPrimero<CMedalleroSecuencia>,
		new CAlgoritmoPaisAleatorio<CMedalleroSecuencia>, 
		new CAlgoritmoPaisUltimo<CMedalleroSecuencia>,
		new CAlgoritmoPaises<CMedalleroSecuencia>,
		new CAlgoritmoMedalleroOrdenadoPais<CMedalleroSecuencia>,
		new CAlgoritmoDeporteNormal<CMedalleroSecuencia>,
		new CAlgoritmoDeporteOrdenado<CMedalleroSecuencia>,
		new CAlgoritmoPaisPrimero<CMedalleroTAbierta>,
		new CAlgoritmoPaisAleatorio<CMedalleroTAbierta>,
		new CAlgoritmoPaisUltimo<CMedalleroTAbierta>,
		new CAlgoritmoPaises<CMedalleroTAbierta>,
		new CAlgoritmoMedalleroOrdenadoPais<CMedalleroTAbierta>,
		new CAlgoritmoDeporteNormal<CMedalleroTAbierta>,
		new CAlgoritmoDeporteOrdenado<CMedalleroTAbierta>,
		new CAlgoritmoPaisPrimero<CMedalleroTCerrada>,
		new CAlgoritmoPaisAleatorio<CMedalleroTCerrada>,
		new CAlgoritmoPaisUltimo<CMedalleroTCerrada>,
		new CAlgoritmoPaises<CMedalleroTCerrada>,
		new CAlgoritmoMedalleroOrdenadoPais<CMedalleroTCerrada>,
		new CAlgoritmoDeporteNormal<CMedalleroTCerrada>,
		new CAlgoritmoDeporteOrdenado<CMedalleroTCerrada>
	};
	if (argc == 1){
		std::cout << "El comando necesita parametros. Consulte su ayuda con Medallero.exe -h" << std::endl<<std::endl;
		ayuda();
	
	}
	else{
		std::string arg1 = argv[1];
	
		if (sintaxOK(argc,arg1)) {
			tamIni = atoi(argv [1]);
			tamFin = atoi(argv [2]);
			inctam = atoi(argv [3]);
			repIni = atoi(argv[4]);
			repFin = atoi(argv[5]);

			CMideTiempos medicion(tamIni, tamFin, inctam, repIni, repFin);
			CSalidaEstandar * output1 = new CSalidaEstandar();
			CSalidaGNUPlot * output2 = new CSalidaGNUPlot();
	
			t1 = clock();
			for (int i = 0 ; i < 21; i++){

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

			for (int i = 0 ; i < 21; i++)
				delete algs[i];
	
			delete output1;
			delete output2;
		}
	}

	return 0;
}
