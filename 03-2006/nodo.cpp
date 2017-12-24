#include "nodo.h"

Nodo::Nodo(TDelincuente* del, Nodo* ant, Nodo* sig): _del(del), _ant(ant), _sig(sig) {
}

Nodo::Nodo(const Nodo& otro) {
        _del = new TDelincuente;
        _ant = new Nodo;
        _sig = new Nodo;
        *_del = *otro._del;
        *_ant = *otro._ant;
        *_sig = *otro._sig;
}

Nodo::~Nodo() {
        delete _del;
}

Nodo& Nodo::operator=(const Nodo& otro) {
        delete _del;
        delete _ant;
        delete _sig;
        _del = new TDelincuente;
        _ant = new Nodo;
        _sig = new Nodo;
        *_del = *otro._del;
        *_ant = *otro._ant;
        *_sig = *otro._sig;
        return *this;
}

void Nodo::del(TDelincuente* del) { _del = del; }

void Nodo::ant(Nodo* ant) { _ant = ant; }

void Nodo::sig(Nodo* sig) { _sig = sig; }

TDelincuente* Nodo::del() { return _del; }

Nodo* Nodo::ant() { return _ant; }

Nodo* Nodo::sig() { return _sig; }
