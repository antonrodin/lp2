#include "Excepciones.h"


EAccesoIndebido::EAccesoIndebido(std::string mensaje):_mensaje(mensaje){}



const std::string EAccesoIndebido::mensaje() const{

    return _mensaje;
}
