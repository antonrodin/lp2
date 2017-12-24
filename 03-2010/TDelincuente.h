#ifndef TDelincuenteH
#define TDelincuenteH

#include<fstream.h>
#include<iostream>
using namespace std;

#include "TCara.h"
#include "caratexto.h"
#include "caragrafica.h"

class TDelincuente {
public:
        //Constructores y Destructores
        TDelincuente(): _nombre("VACIO"), _delitos("VACIO") { _cara = NULL; }          //Constructor predeterminado
        TDelincuente(string nombre, string delitos, TCara* cara);
        TDelincuente(const TDelincuente& del);                          //Constructor de copia
        ~TDelincuente() {  delete _cara; }
        TDelincuente& operator=(const TDelincuente& del);

        //Accedentes y mutadores
        string getNombre() const { return _nombre; }
        string getDelitos() const { return _delitos; }
        TCara* getCara() const { return _cara;}
        void setNombre(string nombre) { _nombre = nombre ; }
        void setDelitos(string delitos) { _delitos = delitos; }
        void setCara(TCara* cara) { _cara = cara; }

        //Metodos
        string getClassName();
        bool salvaTXT(ofstream&);
        bool cargaTXT(ifstream&);
private:
        string _nombre;
        string _delitos;
        TCara* _cara;
};
#endif
 