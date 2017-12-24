#ifndef nodoH
#define nodoH

#include "TDelincuente.h"

class Nodo {
public:
        friend class Lista;
        Nodo(TDelincuente* = NULL, Nodo* = NULL, Nodo* = NULL);
        //Delincuente, Anterior, Siguiente
        Nodo(const Nodo&);
        ~Nodo();
        Nodo& operator=(const Nodo&);
        void del(TDelincuente*);
        void ant(Nodo*);
        void sig(Nodo*);
        TDelincuente* del();
        Nodo* ant();
        Nodo* sig();
private:
        TDelincuente* _del;
        Nodo* _ant;
        Nodo* _sig;
};

#endif
