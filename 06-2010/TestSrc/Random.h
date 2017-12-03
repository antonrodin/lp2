#ifndef RandomH
#define RandomH

#include <iostream>
#include <stdlib.h>
#include <time.h>

class CRandom {
public:
   CRandom() {
      time_t t;
      srand((unsigned) time(&t)); 
   }

   ~CRandom() {}

   int aleatorio(int max) {
		return (rand() % max);
   }

   std::string randomString(int longitud){
		
	   std::string cadena="";
		for(int i=0; i<longitud; i++) {
			char c=( 'A'+ ( rand() % ('Z' - 'A') ));
			cadena=cadena+c;
		}
		return cadena;
	
   }
};

#endif