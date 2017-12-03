#include "Localizacion.h"

int num( int n ) {
  return n;
};

int num( char ch ) {
  return ch;
};

int num( std::string cad ) {
  int res = 0;
  for ( unsigned int i = 0; i < cad.length(); i++ )
    res += cad[i];
  return res;
};