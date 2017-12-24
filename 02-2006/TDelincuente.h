#ifndef TDelincuenteH
#define TDelincuenteH

#include<iostream>
using namespace std;

#include "TCara.h"

class TDelincuente {
public:
        TDelincuente(): _nombre("VACIO"), _delitos("VACIO") { _cara = new TCara(); }          //Constructor predeterminado
        TDelincuente(string nombre, string delitos, TCara cara);
        TDelincuente(const TDelincuente& del);                          //Constructor de copia
        ~TDelincuente() {  delete _cara; }                                              //Destructor
        TDelincuente& operator=(const TDelincuente& del);               //Operador de asignacion
        string getNombre() const { return _nombre; }
        string getDelitos() const { return _delitos; }
        TCara getCara() const { return *_cara;}
        void setNombre(string nombre) { _nombre = nombre ; }
        void setDelitos(string delitos) { _delitos = delitos; }
        void setCara(TCara cara) { *_cara = cara; }
private:
        string _nombre;
        string _delitos;
        TCara* _cara;
};
#endif
 