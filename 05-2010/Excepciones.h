#ifndef Excepciones_h
#define Excepciones_h

#include <string>

class EAccesoIndebido{
public:
    EAccesoIndebido ( std::string mensaje = "" ):_mensaje (mensaje) {};  //Constructor.
    const std::string mensaje () const{ return _mensaje ;};
private:
    std::string _mensaje;
};

class EFormatoIncorrecto{
public:
    EFormatoIncorrecto ( std::string mensaje = "" ):_mensaje (mensaje) {};  //Constructor.
    const std::string mensaje () const{ return _mensaje ;};
private:
    std::string _mensaje;
};





#endif