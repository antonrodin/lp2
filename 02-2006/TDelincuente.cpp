#include "TDelincuente.h"

TDelincuente::TDelincuente(string nombre, string delitos, TCara cara){
        _nombre = nombre;
        _delitos = delitos;
        _cara = new TCara;
        *_cara = cara;
}

TDelincuente::TDelincuente(const TDelincuente& del) {
        _nombre = del._nombre;
        _delitos = del._delitos;
        _cara = new TCara;
        *_cara = *del._cara;
}

TDelincuente& TDelincuente::operator=(const TDelincuente& del){
        _nombre = del._nombre;
        _delitos = del._delitos;
        *_cara = *del._cara;
        return *this;
}
