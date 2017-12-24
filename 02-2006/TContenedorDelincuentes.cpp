#include "TContenedorDelincuentes.h"

TContenedorDelincuentes::TContenedorDelincuentes(int tamanno, int ultimo) {
        _tamanno = tamanno;
        _ultimo = ultimo;
        _vector = new TDelincuente[_tamanno];
}

TContenedorDelincuentes::TContenedorDelincuentes(const TContenedorDelincuentes& otro) {
        _vector = new TDelincuente[otro._tamanno];
        _tamanno = otro._tamanno;
}

TContenedorDelincuentes& TContenedorDelincuentes::operator=(const TContenedorDelincuentes& otro) {
        _vector = new TDelincuente[otro._tamanno];
        _tamanno = otro._tamanno;
        return *this;
}

int TContenedorDelincuentes::getUltimo() const {
        return _ultimo;
}

int TContenedorDelincuentes::getTamanno() const {
        return _tamanno;
}

TDelincuente TContenedorDelincuentes::getDelincuente(int posicion) const {
        return _vector[posicion];
}

void TContenedorDelincuentes::setUltimo(int ultimo) {
        _ultimo = ultimo;
}

void TContenedorDelincuentes::setTamanno(int tamanno) {
        _tamanno = tamanno;
}

bool TContenedorDelincuentes::setDelincuente(TDelincuente del, int actual) {
        if (estaDelincuente(del.getNombre())) {
                return false;
                }
        else    {
                _vector[actual] = del;
                return true;
        }
}

TContenedorDelincuentes::~TContenedorDelincuentes() {
        delete [] _vector;
}

bool TContenedorDelincuentes::estaDelincuente(string nombre) const {
        int i=0;
        bool esta=false;
        while (esta==false && i<=_ultimo){
                TDelincuente del;
                del = _vector[i];
                esta = (nombre == del.getNombre() );
                i++;
        }
        return esta;
}

bool TContenedorDelincuentes::agregaDelincuente(TDelincuente del) {
        if (estaDelincuente(del.getNombre())) {
                return false;
        }
        else {
                _ultimo += 1;
                _vector[_ultimo] = del;
                return true;
        }
}

bool TContenedorDelincuentes::borraDelincuente(string nombre) {
        int i=0;
        int j=0;
        bool esta=false;
        while (esta==false && i<=_ultimo){
                TDelincuente del;
                del = _vector[i];
                esta = (nombre == del.getNombre() );
                if (esta) {
                        for (j=i; j < _ultimo; j++)
                                _vector[j] = _vector[j+1];
                        _ultimo--;
                        return esta;
                        }
                i++;
        }
        return false;
}
