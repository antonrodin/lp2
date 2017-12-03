#ifndef ExcepcionesH
#define ExcepcionesH


#include <iostream>


class EAccesoIndebido {
  public:
	  EAccesoIndebido( std::string mensaje = "" ) : _mensaje(mensaje) { };
	  const std::string & mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};

class EClaveErronea {
  public:
    EClaveErronea( std::string mensaje = "" ) : _mensaje(mensaje) { };
	const std::string & mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};

class EDesbordamiento {
  public:
    EDesbordamiento( std::string mensaje = "" ) : _mensaje(mensaje) { };
	const std::string & mensaje ( ) const {
      return _mensaje;
    };
  private:
    std::string _mensaje;
};
#endif
