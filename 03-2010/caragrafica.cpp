#include "caragrafica.h"

//Constructor
CaraGrafica::CaraGrafica(int pelo, int ojos, int nyo, int boca, string fichero) :
TCara(pelo, ojos, nyo, boca), _fichero(fichero) {
        if (fichero != "") _imagen = cargarBMP(_fichero.c_str());
}

//Accedentes y mutadores
string CaraGrafica::fichero() const {
        return _fichero;
}

Graphics::TBitmap* CaraGrafica::imagen() const {
        return _imagen;
}

void CaraGrafica::fichero(string fichero) {
        _fichero = fichero;
        _imagen = cargarBMP(_fichero.c_str());
}

//Metodos
Graphics::TBitmap* CaraGrafica::cargarBMP(AnsiString bmp) {
        Graphics::TBitmap* BMP = &Graphics::TBitmap();
        BMP->LoadFromFile(bmp);
        return BMP;
}

string CaraGrafica::getClassName() const {
        return "caragrafica";
}

bool CaraGrafica::salvaTXT(ofstream& salida) const {
        salida << getClassName() << endl;
        salida << getPelo() << " " << getOjos() << " " <<
                  getNarizYOrejas() << " " << getBoca() << endl;
        salida << fichero() << endl;
        return salida.good();
}

bool CaraGrafica::cargaTXT(ifstream& entrada) const {
        int pelo, ojos, nariz, boca;
        string fichero;
        entrada >> pelo >> ojos >> nariz >> boca;
        this->pelo(pelo);
        this->ojos(ojos);
        this->nariz(nariz);
        this->boca(boca);
        char n[500];
        entrada.getline(n, 500);
        entrada.getline(n, 500);
        this->fichero(n);
        return entrada.good();
}

void CaraGrafica::dibuja(TCanvas* canvas) const {
        canvas->Draw(0,0,_imagen);
}

bool CaraGrafica::mismo(TCara*& cara) const {
        CaraGrafica* grafica;
        if (mismosRasgos(cara))
                if (grafica = dynamic_cast<CaraGrafica*>(cara))
                        if (grafica->fichero() == _fichero)
                                return true;
        return false;
}
