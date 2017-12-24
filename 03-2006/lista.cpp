#include "lista.h"

//Constructores, destructores y operadores
Lista::Lista(): _total(0), _inicio(NULL), _actual(NULL), _fin(NULL) {}

Lista::~Lista() {
        while ( _inicio != NULL) {
                Nodo* temp = _inicio;
                _inicio = _inicio->_sig;
                delete temp;
        }
}

//Accedentes y Mutadores
void Lista::total(int total) { _total = total; }

void Lista::indice(int indice) { _indice = indice; }

void Lista::inicio(Nodo* inicio) { _inicio = inicio; }

void Lista::actual(Nodo* actual) { _actual = actual; }

void Lista::fin(Nodo* fin) { _fin = fin; }

int Lista::total() const { return _total; }

int Lista::indice() const { return _indice; }

Nodo* Lista::inicio() const { return _inicio; }

Nodo* Lista::actual() const { return _actual; }

Nodo* Lista::fin() const { return _fin; }

//Metodos
bool Lista::agregaDelincuente(TDelincuente* del) {
   Nodo* p = new Nodo();
   p->_del = del;
   //if (!existe(del->getNombre())) {
        if (vacia()) {
                _inicio = _fin = _actual = p;
                _indice = 0;
               }
        else {
                _fin->_sig = _actual = p;
                p->_ant = _fin;
                _fin = p;
                _indice = _total;
        }
        _total +=1;
        return true;
   //} else
        //return false;
}

int Lista::existe(string nombre) {
        if (vacia()) return -1;
        else {
                _actual = _inicio;
                _indice = 0;
                while (_actual != NULL) {
                        TDelincuente* del = _actual->_del;
                        if (del->getNombre() == nombre) return _indice;
                        else {
                                _actual = _actual->_sig;
                                _indice +=1;
                        }
                }
        }
        return -1;
}

bool Lista::eliminar(string nombre) {
        int pos;
        pos = existe(nombre);
        if (pos == -1) return false;
        else if (_actual == _inicio) { quitaPrimero(); _indice -= 1; }
             else if (_actual == _fin) { quitaUltimo(); _indice -= 1; }
                  else {
                        Nodo* temp1 = _actual->_ant;
                        Nodo* temp2 = _actual->_sig;
                        Nodo* temp3 = _actual;
                        temp1->_sig = temp2;
                        temp2->_ant = temp1;
                        delete temp3;
                        _indice -=1;
                        }
        _actual = _inicio;
        _total -= 1;
        return true;
}

bool Lista::quitaPrimero() {
        if (vacia())
                return false;
        else {
                Nodo* temp = _inicio;
                _inicio = _inicio->_sig;
                if (_inicio == NULL)
                        _fin = NULL;
                else
                        _inicio->_ant = NULL;
                delete temp;
        }
        return true;
}

bool Lista::quitaUltimo() {
        if (vacia()) return false;
        else {
                Nodo* temp = _fin;
                _fin = _fin->_ant;
                if (_fin == NULL)
                        _inicio = NULL;
                else
                        _fin->_sig = NULL;
        delete temp;
        }
        return true;
}

bool Lista::vacia() const {
        return _total==0;
}

//Ficheros
bool Lista::salvaTXT(string salida) {
        ofstream fichero;
        fichero.open(salida.c_str(), ios::out);
        Nodo* temp;
        temp = _inicio;
        while (temp != NULL) {
                temp->del()->salvaTXT(fichero);
                temp = temp->_sig;
        }
        fichero.close();
}

bool Lista::cargaTXT(string entrada) {
        ifstream fichero;
        fichero.open(entrada.c_str(), ios::in);
        while (!fichero.eof()) {
                TDelincuente* del = new TDelincuente();
                del->cargaTXT(fichero);
                agregaDelincuente(del);
        }
        fichero.close();
}

TDelincuente* Lista::buscarDelincuente(TCara* cara) const {
        Nodo* temp;
        temp = _inicio;
        while ((temp != NULL)) {
                if (cara->mismo(temp->del()->getCara()))
                        return temp->del();
                else
                        temp = temp->_sig;
        }
        return NULL;
}
