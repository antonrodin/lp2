#ifndef Juego_h
#define Juego_h

class Juego {

public:
	virtual void Jugar(int)=0;
	virtual void Grabar()=0;
	virtual void Cargar()=0;
	virtual void Reproducir()=0;

};
#endif
