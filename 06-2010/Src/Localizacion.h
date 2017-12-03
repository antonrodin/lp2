#ifndef LocalizacionH
#define LocalizacionH

#include <iostream>


int num( int n );
int num( char ch );

int num( std::string cad );

template <class TClave>
int num ( const TClave& clave ) {
  return clave.num();
};

#endif