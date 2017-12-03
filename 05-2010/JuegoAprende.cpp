#include "JuegoAprende.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>


std::istream & operator>>(std::istream &in, std::string &cad) {
		getline(in, cad);
		in.putback('\n');
		return in;
}

JuegoAprende::JuegoAprende(){
	_animal = new CArbol<std::string>();
	_vegetal = new CArbol<std::string>();
	_mineral = new CArbol<std::string>();


}
JuegoAprende::~JuegoAprende(){
	delete _animal;
	delete _vegetal;
	delete _mineral;
}
void JuegoAprende::Jugar(int op){
	int i;
	std::string fich;
	switch(op) {
			
			//Jugar
			case 1:
				
				do {
					
					std::cout << "\nEmpecemos el juego.\n" ;
					std::cout << "Piensa en un animal, vegetal o mineral, y pulsa INTRO cuando\n";
					std::cout << "lo hayas pensado.\n\n" ;
					std::cout << "Pulsa 1 si has pensado animal, 2 si has pensado vegetal y 3 si\n";
					std::cout << "es un mineral.\n\n";
					std::cin >> i;
					std::cin.ignore();
				}
				while( i<1 || i>3);
				iniciaJuego(i,_animal,_vegetal,_mineral);
				break;

			//Grabar base de conocimiento
			case 2:
				
				
				break;

			//Cargar base de conocimiento
			case 3:
				do {
					
					
					std::cout << "Elige la base de conocimiento a cargar: "; 
					std::cout << "animal (1), vegetal (2) o mineral (3), y pulsa INTRO\n";
					std::cin >> i;
					std::cin.ignore();
					
				}
				while( i<1 || i>3);

				std::cout << "\nIndica el fichero donde se encuentre almacenada la base \n";
				std::cout <<"de conocimiento de los animales\n";
				std::getline(std::cin,fich);
				std::ifstream f(fich.c_str());
				if (i == 1){
				
					if (f.fail())
						std::cout <<"El fichero no existe" << std::endl;
							
							else {
								_animal->carga(f);
								f.close();
							}
				
				}
				if (i == 2){
					if (f.fail()){
						std::cout <<"El fichero no existe" << std::endl;
							}

							else {
								_vegetal->carga(f);
								f.close();
							}
				
				
				}
				if ( i == 3) {
					if (f.fail()){
						std::cout <<"El fichero no existe" << std::endl;
								f.close();
							}
							else {
								_mineral->carga(f);
								f.close();
							}
				
				
				
				}
/*
				switch (i) {
						case 1:
							
							if (f.fail()){
								cout <<"El fichero no existe" << endl;
								f.close();
							}

							else {
								_animal->carga(f);
								f.close();
							}
							break;

						case 2:
							
							if (f.fail()){
								cout <<"El fichero no existe" << endl;
								f.close();
							}

							else {
								_vegetal->carga(f);
								f.close();
							}
							break;
						case 3:
							
							if (f.fail()){
								cout <<"El fichero no existe" << endl;
								f.close();
							}
							else {
								_mineral->carga(f);
								f.close();
							}
							break;
				}
				break;
*/				

			//Reproducir ultima partida
		/*	case 4:
						
				break;
*/
			
	}
	

};

void JuegoAprende::iniciaJuego(int op,CArbol<std::string>* Animal,CArbol<std::string>* Vegetal,CArbol<std::string>* Mineral){
		
		std::string animal, vegetal, mineral,resp,frase,pregunta;
		//Inicializando los arboles de cada especie
		if (Animal->esVacio() && Vegetal->esVacio() && Mineral->esVacio()){
			

			Animal->cambiaActual("¿Tiene 4 patas?\n");
			Animal->anyadeIz("Delfin");
			Animal->anyadeDr("Tigre");
		
			Vegetal->cambiaActual("¿Es comestible?\n");
			Vegetal->anyadeIz("Pino");
			Vegetal->anyadeDr("Zanahoria");

			Mineral->cambiaActual("¿Es brillante?\n");
			Mineral->anyadeIz("Oro");
			Mineral->anyadeDr("Pizarra");
		}
		else {
			Animal->reinicia();
			Vegetal->reinicia();
			Mineral->reinicia();
		}
		
		switch (op) {
		
		 case 1:
			 
			 frase=Animal->actual();
			 do{
				std::cout << Animal->actual() << " (Si/No) \n";
				std::getline(std::cin,resp);
							 
			 }

			 while ( resp != "si" && resp != "SI" && resp != "Si" && resp != "sI" && 
					resp !="no" && resp != "NO" && resp != "No" && resp != "nO" );
			 
			 if (resp == "Si")	 Animal->bajaDcha();
			 else Animal->bajaIzda();

			 while (!Animal->esFin()){
				 
					if (Animal->esHojaPI()){
						std::cout << "Mmmmmm, dejame que piense.....\n";
						std::cout << "Creo que el animal en que estabas pensando era...: " << Animal->actual() << std::endl;
						do {
							std::cout << "¿¿Acerté? (Si/No)\n"; 
							std::getline(std::cin,resp);
						}
						while (resp != "Si" && resp != "No");

						if (resp == "Si"){
							std::cout << "¡Estupendo! Gracias por jugar conmigo.\n";
							Animal->bajaDcha();
						}
						else {
							std::cout << "Vaaaya. Me rindo. Dime el animal en el que estabas pensando\n";
							std::getline(std::cin,animal);
							
							std::cout << "\n¿Puedes darme una pregunta que distinga " << Animal->actual() << " de " << animal << "?\n";
							std::getline(std::cin,pregunta);
							std::cout <<  "\n¿Y qué responderías ante la pregunta si piensas en " << Animal->actual() << "? (Si/No)\n";
							std::cout << std::endl;
							do {
								std::getline(std::cin,resp);
							}
							while (resp != "Si" && resp != "No");
							std::string aux = Animal->actual();
							Animal->cambiaActual(pregunta);
							if (resp == "Si"){
								Animal->anyadeDr(aux);
								Animal->anyadeIz(animal);
								Animal->bajaIzda();
								Animal->bajaIzda();
							}
							else {
								Animal->anyadeIz(aux);
								Animal->anyadeDr(animal);
								Animal->bajaIzda();
								Animal->bajaIzda();

							}
								
						}

					}
					else {
							//Si no es hoja entonces será otra pregunta 
					
						do{
							std::cout << Animal->actual()<< " (Si/No) \n";
							std::getline(std::cin,resp);
							
						}
						while ( resp != "si" && resp != "SI" && resp != "Si" && resp != "sI" && 
								resp !="no" && resp != "NO" && resp != "No" && resp != "nO" );
			 
						if (resp == "Si")	 Animal->bajaDcha();
						else Animal->bajaIzda();
						
					}
			 }

			 break;

		 case 2:
			
			 frase=Vegetal->actual();
			 do{
			 std::cout << frase << " (Si/No) \n";
			 std::getline(std::cin,resp);
			 }
			 while ( resp!="si" &resp != "SI" & resp != "Si" & resp != "sI" & 
					resp!="no" &resp != "NO" & resp != "No" & resp != "nO" );
			 break;

		 case 3:
			 frase=Mineral->actual();
			 do{
			 std::cout << frase << " (Si/No) \n";
			 std::getline(std::cin,resp);
			 }
			 while ( resp != "si" &resp != "SI" & resp != "Si" & resp != "sI" & 
					resp != "no" &resp != "NO" & resp != "No" & resp != "nO" );
			 break;
		
		};

		
}
void JuegoAprende::Grabar(){}
void JuegoAprende::Cargar(){}
void JuegoAprende::Reproducir(){}