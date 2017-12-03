#ifndef TablaAbiertaH
#define TablaAbiertaH

#include <iostream>
#include <String>

#include "Localizacion.h"
#include "Pareja.h"
#include "Secuencia.h"
#include "Excepciones.h"

template <class TClave, class TValor>
class CTablaAbierta;

/**
*	Clase TNodoTabla, por comodidad toda la implementacion se ha incluido aqui.
*/
template <class TClave, class TValor>
class TNodoTabla {
public:
	
	const TClave& clave() const { return _clave; }
	const TValor& valor() const { return _valor; }
	TNodoTabla<TClave, TValor>* sig() const { return _sig; }

	friend CTablaAbierta<TClave, TValor>;

private:

	TNodoTabla(const TClave& clave, const TValor& valor, TNodoTabla<TClave, TValor>* sig = 0) : _clave(clave), _valor(valor), _sig(sig) {};

	TClave _clave;
	TValor _valor;
	TNodoTabla<TClave, TValor>* _sig;
};


/**
*	Clase CTablaAbierta:
*	Maximo 10000 entradas
*/
template <class TClave, class TValor>
class CTablaAbierta {
public:
	
	CTablaAbierta ();
	CTablaAbierta (const CTablaAbierta< TClave, TValor > &c);
	~CTablaAbierta (); 
	
	CTablaAbierta< TClave, TValor > &  operator= (const CTablaAbierta< TClave, TValor > &);
	void  inserta (const TClave &c, const TValor &v);
	void  borra (const TClave &c);
	const TValor &  consulta (const TClave &c) const;
	bool  esta (const TClave &c) const;
	bool  esVacio () const;
	CSecuencia< CPareja< TClave, TValor > >  enumera () const;

	void mostrar() const;

private:

	static const int _longMax = 10000;
	int _aciertos, _fallos, _total;
	TNodoTabla<TClave,TValor>* _espacio[_longMax];

	int localiza(const TClave& clave) const { return num(clave) % _longMax; };
	void busca(	const TClave& clave, 
				TNodoTabla<TClave, TValor>* &act,
				TNodoTabla<TClave, TValor>* &ant) const;

	void libera();
	void copia(const CTablaAbierta< TClave, TValor > &c);

};


/**
*	Implementacion
*/
template <class TClave, class TValor>
CTablaAbierta<TClave, TValor>::CTablaAbierta() {
	for (int i = 0; i < _longMax; i++) {
		_espacio[i] = 0;
	}
	_aciertos = 0;
	_fallos = 0;
	_total = 0;
}

template <class TClave, class TValor>
CTablaAbierta<TClave, TValor>::CTablaAbierta (const CTablaAbierta< TClave, TValor > &c){
	libera();
	copia(c);
}; //Fin CTablaAbierta

template <class TClave, class TValor>
CTablaAbierta<TClave, TValor>::~CTablaAbierta() {
	libera();
}

template <class TClave, class TValor>
CTablaAbierta< TClave, TValor > &  CTablaAbierta<TClave, TValor>::operator= (const CTablaAbierta< TClave, TValor > &c) {
	libera();
	copia(c);
	return this;
}

template <class TClave, class TValor>
void CTablaAbierta<TClave, TValor>::mostrar() const {
	TNodoTabla<TClave, TValor> *aux;

	for (int i = 0; i<_longMax;i++) {	

		if (_espacio[i] != 0) {
			aux=_espacio[i];
			std::cout << "Para esta CLAVE -> " << i << " : ";
			while (aux != 0) {
				std::cout << " Valor: " << aux->valor() << " - ";
				aux = aux->sig();
			}	
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Aciertos: " << _aciertos << " Fallos: " << _fallos << " Total: " << _fallos << std::endl;

}; //Fin mostrar



template <class TClave, class TValor>
void	CTablaAbierta<TClave, TValor>::inserta(const TClave &c, const TValor &v) {
	int pos = localiza(c);
	TNodoTabla<TClave, TValor>	*act, *ant;

	act = _espacio[pos];
	busca(c, act, ant);
	if ( act != 0 ) {
		act->_valor = v;
		_aciertos++;
	} else {
		act = new TNodoTabla<TClave, TValor>(c, v, _espacio[pos]);
		_espacio[pos] = act;
		_fallos++;
		_total++;
	}

}; //Inserta

template <class TClave, class TValor>
void CTablaAbierta<TClave, TValor>::borra (const TClave &c){
		
	TNodoTabla <TClave,TValor> * act, * ant;
	int i = localiza(c._clave);
	act = _espacio[i];
	busca(c._clave,act,ant);
	if ( act != 0 ) {
		if ( ant != 0)
			ant->_sig = act->_sig;
		else 
			_espacio[i] = act->_sig; 
		delete act;
	}
	

}

template <class TClave, class TValor>
const TValor &  CTablaAbierta<TClave, TValor>::consulta (const TClave &c) const {
	int i = localiza(c);
	TNodoTabla<TClave, TValor>* act, *ant;
	
	act = _espacio[i];
	busca(c, act, ant);
	if (act == 0) 
		throw EClaveErronea(); 
	return act->valor();	
};

template <class TClave, class TValor>
bool  CTablaAbierta<TClave, TValor>::esta (const TClave &c) const {
	int i = localiza(c);
	TNodoTabla<TClave, TValor>* act, *ant;
	
	act = _espacio[i];
	busca(c, act, ant);
	return (act != 0);
};

template <class TClave, class TValor>
bool  CTablaAbierta<TClave, TValor>::esVacio () const {
	bool encontrado = false;
	int i = 0; 
	while ((!encontrado) && (i < this->_longMax)) {
		if ( this->_espacio[i] != 0 ) encontrado = true;
		i++;
	}
	return !encontrado;
}

template <class TClave, class TValor>
CSecuencia< CPareja< TClave, TValor > >  CTablaAbierta<TClave, TValor>::enumera () const {
	
	CSecuencia< CPareja < TClave, TValor > > aux;
	CPareja<TClave, TValor> pareja;
	TNodoTabla<TClave, TValor>* act = 0;

	for (int i = 0; i < _longMax; i++) {
		act = _espacio[i];
		while (act != 0) {
			pareja.ponV1(act->clave());
			pareja.ponV2(act->valor());
			aux.inserta(pareja);
			act = act->sig();
		}
	}
	
	return aux;
}

/**
*	Implementacion operaciones privadas
*/
template <class TClave, class TValor>
void	CTablaAbierta<TClave, TValor>::busca(const TClave& clave, TNodoTabla<TClave, TValor>* &act, TNodoTabla<TClave, TValor>* &ant) const {
	
	bool encontrado = false;
	ant = 0;
	while ((!encontrado) && (act != 0)) {
			encontrado = clave == act->clave();
			if ( ! encontrado ) {
				ant = act;
				act = act->sig();
			}
	}

};

template <class TClave, class TValor>
void	CTablaAbierta<TClave, TValor>::libera() {

	TNodoTabla<TClave, TValor> *act, *ant;
	for (int i = 0; i<_longMax;i++) {
		if (_espacio[i] != 0) {
			act = _espacio[i];
			while (act != 0) {
				ant = act;
				act = act->sig();
				delete ant;
			}
		}
	}
}; //Fin libera


template <class TClave, class TValor>
void CTablaAbierta <TClave,TValor>::copia(const CTablaAbierta< TClave, TValor > &c){
	
	
	TNodoTabla<TClave,TValor> *act, *actCopia, *antCopia;
	
	for ( int i = 0; i < _longMax; i++ ) {
	if ( tabla._espacio[i] != 0 ) {
		act = tabla._espacio[i];
		actCopia = new TNodoTabla<TClave,TValor>(act->clave(), act->valor());
		_espacio[i] = actCopia;
		
		while ( act->sig() != 0 ) {
			act = act->sig();
			antCopia = actCopia;
			actCopia = new TNodoTabla<TClave,TValor>(act->clave(), act->valor());
			antCopia->_sig = actCopia;
		} //end While
	} else
           _espacio[i] = 0;
	}	//end if
}; //Fin Copia

#endif