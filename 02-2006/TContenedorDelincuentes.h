#ifndef TContenedorDelincuentesH
#define TContenedorDelincuentesH

#include "TDelincuente.h"

class TContenedorDelincuentes {
public:
        TContenedorDelincuentes(int tamanno = 0, int ultimo = 0);
        TContenedorDelincuentes(const TContenedorDelincuentes& otro);
        TContenedorDelincuentes& operator=(const TContenedorDelincuentes& otro);
        ~TContenedorDelincuentes();
        int getUltimo() const;
        int getTamanno()const;
        TDelincuente getDelincuente(int posicion) const;
        void setUltimo(int);
        void setTamanno(int);
        bool setDelincuente(TDelincuente del, int actual);
        bool estaDelincuente(string nombre) const;
        bool agregaDelincuente(TDelincuente del);
        bool borraDelincuente(string nombre);
private:
        TDelincuente* _vector;
        int _tamanno;
        int _ultimo;
};

#endif
 