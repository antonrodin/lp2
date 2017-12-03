#ifndef JuegoAprende_h
#define JuegoAprende_h

#include "Juego.h"
#include "Arbol.h"

class JuegoAprende :public Juego{

public:
	JuegoAprende();
	~JuegoAprende();
	void Jugar(int );
	void Grabar();
	void Cargar();
	void Reproducir();
private:
	CArbol<std::string> * _animal, * _vegetal, * _mineral;
	void iniciaJuego(int op,CArbol<std::string>* ,CArbol<std::string>* ,CArbol<std::string>* );
};
#endif
