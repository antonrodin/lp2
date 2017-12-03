#include <iostream>
#include "Arbol.h"
#include "JuegoAprende.h"



void Menu() {
	std::cout << "\nMenu principal: \n";
	std::cout << "***************\n";
	std::cout << std::endl;
	std::cout << "1.- Jugar \n" ;
	std::cout << std::endl;
	std::cout << "2.- Grabar base de conocimiento\n";
	std::cout << std::endl;
	std::cout << "3.- Cargar base de conocimiento\n";
	std::cout << std::endl;
	std::cout << "4.- Reproducir ultima partida\n";
	std::cout << std::endl;
	std::cout << "5.- Salir\n";
	std::cout << std::endl;
	
}




int main(){

	bool fin=false;
	int opc;
	Juego * j = new JuegoAprende();

	
	do {
		Menu();
		std::cout << "Introduzca una opcion: ";
		std::cin >>opc;
		std::cin.ignore();
		if (opc == 5) fin= true;
		else j->Jugar(opc);

	}
	while (!fin);
	

	CArbol<int>  arb1(5);
	CArbol<int>  arb2(5);
	
	
	if ( (arb1== arb2)) std::cout << "Los dos arboles son iguales" << std::endl;
	
	arb1.cambiaActual(7);
	if ( (arb1== arb2)) std::cout << "Los dos arboles son iguales" << std::endl;
	else std::cout << "Los dos arboles son distintos" << std::endl;
	arb2.cambiaActual(7);
	if ( (arb1== arb2)) std::cout << "Los dos arboles son iguales" << std::endl;
	else std::cout << "Los dos arboles son distintos" << std::endl;
	arb2.anyadeIz(5);
	arb2.anyadeDr(6);
	arb1.anyadeIz(5);
	arb1.anyadeDr(6);
	arb1.bajaIzda();
	arb2.bajaIzda();
	arb1.cambiaActual(4);
	//arb2.cambiaActual(4);
	//arb1.bajaIzda();
	//arb2.bajaDcha();
	CArbol<int> arb3(arb1);
	CArbol<int> arb4(arb3);
	if(arb1.esHojaPI()) std::cout << "El punto de interes es un nodo hoja" << std::endl;
	else std::cout << "El punto de interes no es nodo hoja" << std::endl;
	arb1.reinicia();
	if(arb1.esHojaPI()) std::cout << "El punto de interes es un nodo hoja" << std::endl;
	else std::cout << "El punto de interes no es nodo hoja" << std::endl;

	
	if ( (arb4== arb3)) std::cout << "Los dos arboles (arb1 arb3)son iguales" << std::endl;
	else std::cout << "Los dos arboles (arb1 y arb3)son distintos" << std::endl;
	
	return 0;
	
}

