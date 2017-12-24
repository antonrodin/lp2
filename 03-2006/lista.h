#ifndef listaH
#define listaH

#include <fstream.h>
#include <iostream.h>
using namespace std;

#include "nodo.h"
#include "TDelincuente.h"
#include "TCara.h"
#include "caratexto.h"
#include "caragrafica.h"

class Lista {
public:
        Lista();
        ~Lista();

        //Accedentes y Mutadores
        void total(int);
        void indice(int);
        void inicio(Nodo*);
        void actual(Nodo*);
        void fin(Nodo*);
        int total() const;
        int indice() const;
        Nodo* inicio() const;
        Nodo* actual() const;
        Nodo* fin() const;

        //Metodos
        bool agregaDelincuente(TDelincuente*);
        int existe(string nombre);
        bool eliminar(string nombre);
        bool quitaPrimero();
        bool quitaUltimo();
        bool vacia() const;
        TDelincuente* buscarDelincuente(TCara* cara) const; 

        //Ficheros
        bool salvaTXT(string salida);
        bool cargaTXT(string entrada);
private:
        int _total;
        int _indice;
        Nodo* _inicio;
        Nodo* _actual;
        Nodo* _fin;
};

#endif
 