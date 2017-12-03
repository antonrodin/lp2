#ifndef TablaCerradaH
#define TablaCerradaH

#include <iostream>
#include <String>

#include "Localizacion.h"
#include "Pareja.h"
#include "Secuencia.h"
#include "Excepciones.h"

const int maxLongitudes = 5;
const int longitudes[maxLongitudes] = { 1021, 2029, 4093, 8093, 16831};
//const int longitudes[maxLongitudes] = { 10, 20, 30, 40, 50};
//const int longitudes[maxLongitudes] = { 20, 40, 80, 160, 320};


template <class TClave, class TValor>
class CTablaCerrada;

enum TPosicion {vacia, ocupada, borrada};

template <class TClave, class TValor>
class CNodoTabla {
public:
	const TClave& clave() const { return _clave; }
	const TValor& valor() const { return _valor; }
	const TPosicion& posicion() const { return _pos; }
	friend CTablaCerrada<TClave,TValor>;
private:
	TClave _clave;
	TValor _valor;
	TPosicion _pos;
	CNodoTabla() : _pos(vacia) {};
}; //EndCNodoTabla

template <class TClave, class TValor>
class CTablaCerrada {
public:
	CTablaCerrada() : _total(0), _eliminados(0), _longitud(0), _espacio(new CNodoTabla<TClave, TValor>[longitudes[0]]) {};
	CTablaCerrada(const CTablaCerrada< TClave, TValor > &c) { copia(c); };
	~CTablaCerrada() { libera(); };
	CTablaCerrada<TClave,TValor>& operator=( const CTablaCerrada<TClave,TValor>& c );
	
	void inserta( const TClave& clave, const TValor& valor);
	void  borra (const TClave &c);
	const TValor &  consulta (const TClave &c) const;
	bool  esta (const TClave &c) const;
	bool  esVacio () const { return this->_total == 0; };
	CSecuencia< CPareja< TClave, TValor > >  enumera () const;

	void mostrar() const;
private:
	static const int _ocupacion = 50;
	CNodoTabla<TClave, TValor>* _espacio;
	int _total;
	int _eliminados;
	int _longitud;

	int busca(	const TClave& clave) const;
	void amplia( );
	void libera() { delete [] _espacio; };
	void copia(const CTablaCerrada< TClave, TValor > &c);
}; //End CTablaCerrada


 template <class TClave, class TValor>
 CTablaCerrada<TClave,TValor>& CTablaCerrada<TClave,TValor>::operator=( const CTablaCerrada<TClave,TValor>& c ) {
       if( this != &c ) {
         libera();
         copia(c);
       }
       return *this;
  };


// Inserción
     template <class TClave, class TValor>
     void CTablaCerrada<TClave,TValor>::inserta( const TClave& clave,
                                                 const TValor& valor ) {
       int i, n, d, m;
       bool encontrado;

	   if ( ( (_total + _eliminados) * 100 / longitudes[_longitud] ) > _ocupacion ) {
//         limpia();
         amplia();
	   }
		 
		 
       n = num(clave);
       i = n % longitudes[_longitud];
       d = (n % (longitudes[_longitud]-2)) + 1;
       m = 0; //contabiliza el número de pruebas por si la tabla está llena
       encontrado = false;
       while ( ( ! encontrado ) && (_espacio[i].posicion() == ocupada) && (m < longitudes[_longitud]) ) {
         if ( _espacio[i]._pos == ocupada )
           encontrado = clave == _espacio[i].clave();
         if ( ! encontrado ) {
           m++;
           i = (i + d) % longitudes[_longitud];
         }
       }
	   if ( m == longitudes[_longitud] ) {
		   throw EDesbordamiento();
	   }
       else if ( encontrado )
         _espacio[i]._valor = valor;
	   else if ( _espacio[i].posicion() == vacia ) {
         _espacio[i]._clave = clave;
         _espacio[i]._valor = valor;
         _espacio[i]._pos = ocupada;
         _total++;
       }
       else if ( _espacio[i].posicion() == borrada ) {
         _espacio[i]._clave = clave;
         _espacio[i]._valor = valor;
         _espacio[i]._pos = ocupada;
         _total++;
         _eliminados--;
         m++;
         i = (i + d) % longitudes[_longitud];
         while ( ( ! encontrado ) && (_espacio[i].posicion() != vacia) && (m < longitudes[_longitud]) ) {
           if ( _espacio[i].posicion() == ocupada ) encontrado = clave == _espacio[i].clave();
           if ( ! encontrado ) {
             m++;
             i = (i + d) % longitudes[_longitud];
           }
         }
		 
         if ( encontrado ) {
           _espacio[i]._pos = borrada;
           _eliminados++;
         }
		 
       }
     };

/*
template <class TClave, class TValor>
void CTablaCerrada<TClave, TValor>::inserta( const TClave& clave, const TValor& valor) {
	
	// Ampliar si hay problemas de espacio si los elementos superan el 50%
	if ((((_total + _eliminados) * 100) / longitudes[_longitud] ) > _ocupacion ) {
		this->amplia();
		std::cout << "AMPLIADO" << std::endl;
	}

	//Inicializar variables:
	int loc = num(clave);
	int pos = loc % longitudes[_longitud];
	int dis = ( loc % (longitudes[_longitud] - 2) ) + 1;
	int fallos = 0;
	bool encontrado = false;

	//localizar posicion para ls insercion
	while	(
				(!encontrado) &&
				(_espacio[pos].posicion() == ocupada) &&
				(fallos < longitudes[_longitud])
			 ) {
	
				 if (_espacio[pos].posicion() == ocupada) {
					 encontrado = (_espacio[pos].clave() == clave);
				 }

				 if (!encontrado) {
					fallos++;
					pos = (pos + dis) % longitudes[_longitud];
				 }

	} //endwhile

	//Insercion en si, en la posicion encontrada o no
	if (fallos == longitudes[_longitud]) {
		//std::cout << " DESBORDAMIENTO " << std::endl;
	} else {
			
		if (encontrado) {
			_espacio[pos]._valor = valor;
		} else {
			if (_espacio[pos].posicion() == vacia) {
				_espacio[pos]._clave = clave;
				_espacio[pos]._valor = valor;
				_espacio[pos]._pos = ocupada;
				_total++;
			} else {
				if (_espacio[pos].posicion() == borrada) {
					_espacio[pos]._clave = clave;
					_espacio[pos]._valor = valor;
					_espacio[pos]._pos = ocupada;
					_total++;
					_eliminados--;
					fallos++;
					pos = (pos + dis) % longitudes[_longitud];

					while (	(!encontrado) &&
							(_espacio[pos].posicion() == vacia) &&
							(fallos < longitudes[_longitud])
						) {
						
							if (_espacio[pos].posicion() == ocupada) {
								encontrado = (clave == _espacio[pos].clave());
							}
							if (!encontrado) {
								fallos++;
								pos = (pos + dis) % longitudes[_longitud];
							}
					}//endwhile

					if (encontrado) {
						_espacio[pos]._pos = borrada;
						_eliminados++;
					}
				}
			} //endif
		
		} //endif

	} //endif

}; //EndInsercion
*/


template <class TClave, class TValor>
void CTablaCerrada<TClave, TValor>::borra (const TClave &c){

	int i;

    i = busca(clave);
	if ( i != longitudes[_longitud] ) {
		_espacio[i]._posicion = borrada;
		_total--;
		_eliminados++;
	}

}; //Borra


template <class TClave, class TValor>
const TValor&  CTablaCerrada<TClave, TValor>::consulta (const TClave &c) const {
	int pos = 0;
	pos = busca(c);
	if (pos != longitudes[_longitud]) {
		return _espacio[pos].valor();
	} else {
		throw EClaveErronea();
	}
};

template <class TClave, class TValor>
bool  CTablaCerrada<TClave, TValor>::esta (const TClave &c) const {
	int pos = 0;
	pos = busca(c);
	return (pos != longitudes[_longitud]);
};

template <class TClave, class TValor>
CSecuencia< CPareja< TClave, TValor > >  CTablaCerrada<TClave, TValor>::enumera () const {
	
	CSecuencia< CPareja< TClave, TValor > > secuencia;
	CPareja< TClave, TValor > pareja;
	
	for (int i = 0; i < longitudes[_longitud]; i++ ) {
		if (_espacio[i].posicion() == ocupada) {
			pareja.ponV1(_espacio[i].clave());
			pareja.ponV2(_espacio[i].valor());
			secuencia.inserta(pareja);
		}
	}

	return secuencia;

}; //Enumera

template <class TClave, class TValor>
void CTablaCerrada<TClave, TValor>::mostrar() const {
	
	for (int i = 0; i < longitudes[_longitud]; i++) {
		
		if (_espacio[i].posicion() == vacia) {
			std::cout << "VACIA" << std::endl;
		}
		
		if (_espacio[i].posicion() == borrada) {
			std::cout << "BORRADA" << std::endl;
		}

		if (_espacio[i].posicion() == ocupada) {
			std::cout << i << " : " << _espacio[i].clave() << "-" << _espacio[i].valor() << std::endl;
		}
		
	}

}; //Mostrar


/**
*	OPERACIONES PRIVADAS
*/
template <class TClave, class TValor>
int CTablaCerrada<TClave, TValor>::busca(	const TClave& clave) const {
	//Inicializar variables:
	int loc = num(clave);
	int pos = loc % longitudes[_longitud];
	int dis = ( loc % (longitudes[_longitud] - 2) ) + 1;
	int fallos = 0;
	bool encontrado = false;

	//localizar posicion para ls insercion
	while	(
				(!encontrado) &&
				(_espacio[pos].posicion() == ocupada) &&
				(fallos < longitudes[_longitud])
			 ) {
	
				 if (_espacio[pos].posicion() == ocupada) {
					 encontrado = (_espacio[pos].clave() == clave);
				 }

				 if (!encontrado) {
					fallos++;
					pos = (pos + dis) % longitudes[_longitud];
				 }

	} //endwhile

	//Si no lo encontramos devolvemos el la longitud maxima donde no hay nada
	if (!encontrado) {
		pos = longitudes[_longitud];
	}
	return pos;
};

template <class TClave, class TValor>
void CTablaCerrada<TClave,TValor>::amplia( ) {
	
	if ( _longitud < (maxLongitudes - 1) ) {
		_longitud++;
		CNodoTabla<TClave,TValor> *aux = _espacio;
		_espacio = new CNodoTabla<TClave,TValor>[longitudes[_longitud]];
		_eliminados = _total = 0;
		for ( int i = 0; i < longitudes[_longitud-1]; i++ ) {
			if ( aux[i].posicion() == ocupada )
				inserta(aux[i].clave(), aux[i].valor());
		}
		delete [] aux;
      }

}; //fin amplia

template <class TClave, class TValor>
void CTablaCerrada<TClave,TValor>::copia(const CTablaCerrada< TClave, TValor > &c) {
	
	this->_eliminados = c._eliminados;
	this->_longitud = c._longitud;
	this->_total = c._total;

	_espacio = new CNodoTabla<TClave,TValor>[longitudes[_longitud]];
	
	for (int i = 0; i < longitudes[_longitud]; i++) {
		_espacio[i].posicion = c._espacio[i].posicion;
		if (c._espacio[i].posicion == ocupada) {
			_espacio[i]._clave = c._espacio[i]._clave;
			_espacio[i]._valor = c._espacio[i]._valor;
		}
	}

} //Fin Copia

#endif