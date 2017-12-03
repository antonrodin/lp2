#ifndef RandomH
#define RandomH

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

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
   int aleatoriosqrt(double max) {
	   int num = (int) sqrt(max);
	   return (rand() % num);
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