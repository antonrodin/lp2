#include "TDelincuente.h"

TDelincuente::TDelincuente(string nombre, string delitos, TCara* cara){
        _nombre = nombre;
        _delitos = delitos;
        _cara = cara;
}

TDelincuente::TDelincuente(const TDelincuente& del) {
        _nombre = del._nombre;
        _delitos = del._delitos;
        _cara = del._cara;
}

TDelincuente& TDelincuente::operator=(const TDelincuente& del){
        _nombre = del._nombre;
        _delitos = del._delitos;
        _cara = del._cara;
        return *this;
}

string TDelincuente::getClassName(){
        CaraTexto* texto;
        CaraGrafica* grafica;
        if (texto = dynamic_cast<CaraTexto*>(_cara)) {
                return "CaraTexto";
        }
        else    return "CaraGrafica";
}

bool TDelincuente::salvaTXT(ofstream& salida) {
        salida << this->getNombre() << endl;
        salida << this->getDelitos();
        _cara->salvaTXT(salida);
        return salida.good();
}

bool TDelincuente::cargaTXT(ifstream& entrada) {
        string clase;
        char n[500];
        entrada.getline(n, 500);
        _nombre = n;
        entrada.getline(n, 500);
        _delitos = n;
        entrada.getline(n, 500);
        clase = n;
        if (clase == "caragrafica")
                _cara = new CaraGrafica();
        else
                _cara = new CaraTexto();
        return _cara->cargaTXT(entrada) && entrada.good();
}
