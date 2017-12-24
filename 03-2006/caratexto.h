#ifndef caratextoH
#define caratextoH

#include <fstream.h>

#include "TCara.h"

class CaraTexto : public TCara {
public:
        //Constructor
        CaraTexto(int = -1, int = -1, int = -1, int = -1);
        //pelo, ojos, narizYOrejas, boca

        //Metodos
        string getClassName() const;
        bool salvaTXT(ofstream& salida) const;
        bool cargaTXT(ifstream&) const;
        void dibuja(TCanvas*) const;
        bool mismo(TCara*&) const;
private:
};

#endif

 