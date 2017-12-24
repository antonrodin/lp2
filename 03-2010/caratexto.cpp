#include "caratexto.h"

//Constructor
CaraTexto::CaraTexto(int pelo, int ojos, int nyo, int boca) : TCara(pelo, ojos, nyo, boca) {
}

//Metodos
string CaraTexto::getClassName() const {
        return "caratexto";
}

bool CaraTexto::salvaTXT(ofstream& salida) const {
        salida << getClassName() << endl;
        salida << getPelo() << " " << getOjos() << " " <<
                  getNarizYOrejas() << " " << getBoca() << endl;
        return salida.good();
}

bool CaraTexto::cargaTXT(ifstream& entrada) const {
        int pelo, ojos, nariz, boca;
        entrada >> pelo >> ojos >> nariz >> boca;
        char n[500];
        entrada.getline(n, 500);
        this->pelo(pelo);
        this->ojos(ojos);
        this->nariz(nariz);
        this->boca(boca);
        return entrada.good();
}

void CaraTexto::dibuja(TCanvas* canvas) const {
        //canvas->Rectangle(0,0,150,150);
}

bool CaraTexto::mismo(TCara*& cara) const {
        CaraTexto* texto;
        if (mismosRasgos(cara))
                if (texto = dynamic_cast<CaraTexto*>(cara))
                                return true;
        return false;
}

