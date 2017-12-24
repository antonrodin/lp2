#ifndef caragraficaH
#define caragraficaH

#include <fstream.h>
#include <iostream.h>
using namespace std;

#include "TCara.h"

class CaraGrafica : public TCara {
public:
        //Constructores
        CaraGrafica(int = -1, int = -1, int = -1, int = -1, string = "");
        //pelo, ojos, narizYOrejas, boca, fichero

        //Accedentes y mutadores
        string fichero() const;
        Graphics::TBitmap* imagen() const;
        void fichero(string);

        //Metodos
        Graphics::TBitmap* cargarBMP(AnsiString);
        string getClassName() const;
        bool salvaTXT(ofstream&) const;
        bool cargaTXT(ifstream&) const;
        void dibuja(TCanvas*) const;
        bool mismo(TCara*&) const;
private:
        string _fichero;
        Graphics::TBitmap* _imagen;
};

#endif
 