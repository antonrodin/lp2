#ifndef secuencia_dinamicaH
#define secuencia_dinamicaH


#include <iostream>
#include "Excepciones.h"

template <class TElem>
class CSecuencia;

template <class TElem>
class TNodoSecuencia {
  private:
    TElem _elem;
    TNodoSecuencia<TElem>* _sig;
    TNodoSecuencia( );
    TNodoSecuencia( const TElem&, TNodoSecuencia<TElem>* = 0);
  public:
    const TElem& elem() const;
    TNodoSecuencia<TElem> * sig() const;
    friend CSecuencia<TElem>;
};

template <class TElem>
class CSecuencia {
  public:

  // Constructoras, destructora y operador de asignación
     CSecuencia( );
     // O( TElem::TElem() ), O(1) sobre tipos predefinidos
     
     CSecuencia( const CSecuencia<TElem>& );
     // O( n' * TElem::TElem(TElem&) ), O(n') sobre tipos predefinidos
     // siendo n' el número de elementos de la secuencia a copiar

     ~CSecuencia( );
     // O( n * TElem::~TElem() ), O(n) sobre tipos predefinidos

     CSecuencia<TElem>& operator=( const CSecuencia<TElem>& );
     // O( n * TElem::~TElem() + n' * TElem::TElem(TElem&) ),
     // O( n + n' ) sobre tipos predefinidos
     // siendo n' el número de elementos de la secuencia a asignar

  // Operaciones de las secuencias
     void inserta(const TElem&);
     // Pre: true
     // Post: Se añade un elemento a la secuencia, delante del punto de interés
     // O( TElem::TElem(TElem&) ), O(1) sobre tipos predefinidos

     void borra( );
     // Pre: ! esFin( )
     // Post: Elimina el elemento que está detrás del punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O( TElem::~TElem() ), O(1) sobre tipos predefinidos

     const TElem& actual( ) const;
     // Pre: ! esFin( )
     // Post: Devuelve el elemento a continuación del punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O(1)

     void avanza( );
     // Pre: ! esFin( )
     // Post: Avanza una posición el punto de interés
     // Lanza la excepción EAccesoIndebido si el punto de interés está al final
     // O(1)

     void reinicia( );
     // Pre: true
     // Post: Coloca el punto de interés al principio de la secuencia
     // O(1)

     bool esFin( ) const;
     // Pre: true
     // Post: Determina si el punto de interés está al final de la secuencia
     // O(1)

     bool esVacio( ) const;
     // Pre: true
     // Post: Determina si la secuencia está vacía
     // O(1)
	 int 	numElems () const;

  private:
  // Variables privadas
     TNodoSecuencia<TElem> *_pri, *_ant;
	 int _total;

  // Operaciones privadas
     void libera();
     void copia( const CSecuencia<TElem>& );
};

//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Clase de los nodos

    // Es necesaria una constructora sin parámetros (sin elem) para poder
    // construir el nodo fantasma. El campo _elem de ese nodo contendrá
    // basura si se trata de un tipo primitivo o el resultado de llamar
    // a la constructora por defecto si no lo es.
    template <class TElem>
    TNodoSecuencia<TElem>::TNodoSecuencia( ) : _sig(0) {
    };

    template <class TElem>
    TNodoSecuencia<TElem>::TNodoSecuencia( const TElem& elem,
                                           TNodoSecuencia<TElem>* sig ) :
      _elem(elem), _sig(sig) {
    };

    template <class TElem>
    const TElem& TNodoSecuencia<TElem>::elem() const {
      return _elem;
    }

    template <class TElem>
    TNodoSecuencia<TElem>* TNodoSecuencia<TElem>::sig() const {
      return _sig;
    }


  // Constructoras, destructora y operador de asignación

     template <class TElem>
     CSecuencia<TElem>::CSecuencia( ) {
       _pri = _ant = new TNodoSecuencia<TElem>();
	   _total = 0;
     };

     template <class TElem>
     CSecuencia<TElem>::CSecuencia( const CSecuencia<TElem>& secuencia ) {
        copia(secuencia);
     };

     template <class TElem>
     CSecuencia<TElem>::~CSecuencia( ) {
       libera();
     };

     template <class TElem>
     CSecuencia<TElem>&
     CSecuencia<TElem>::operator=( const CSecuencia<TElem>& secuencia ) {
       if( this != &secuencia ) {
         libera();
         copia(secuencia);
       }
       return *this;
     };


  // Operaciones de las secuencias

     template <class TElem>
     void CSecuencia<TElem>::inserta(const TElem& elem) {
       TNodoSecuencia<TElem>* nuevo = new TNodoSecuencia<TElem> ( elem, _ant->sig() );
       _ant->_sig = nuevo;
       _ant = nuevo;
	   _total++;
     };

     template <class TElem>
     const TElem& CSecuencia<TElem>::actual( ) const {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       return _ant->sig()->elem();
     };

     template <class TElem>
     void CSecuencia<TElem>::borra( ) {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       TNodoSecuencia<TElem>* act = _ant->sig();
       _ant->_sig = act->sig();
       delete act;
	   _total--;
     };

     template <class TElem>
     void CSecuencia<TElem>::avanza( ) {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       _ant = _ant->sig();
     };

     template <class TElem>
     void CSecuencia<TElem>::reinicia( ) {
       _ant = _pri;
     };

     template <class TElem>
     bool CSecuencia<TElem>::esFin( ) const {
       return _ant->sig() == 0;
     };

     template <class TElem>
     bool CSecuencia<TElem>::esVacio( ) const {
       return _pri->sig() == 0;
     };

template <class TElem>
int	CSecuencia<TElem>::numElems () const {
	return this->_total;
}

  // Operaciones privadas

     template <class TElem>
     void CSecuencia<TElem>::libera() {
       while ( _pri != 0 ){
         _ant = _pri;
         _pri = _pri->sig();
         delete _ant;
       }
	   _total = 0;
     };

     template <class TElem>
     void CSecuencia<TElem>::copia(const CSecuencia<TElem>& secuencia) {
       TNodoSecuencia<TElem> *antCopia, *actCopia, *act;
       act = secuencia._pri;
       actCopia = _ant = _pri = new TNodoSecuencia<TElem>( );
       while ( act->sig() != 0 ) {
         act = act->sig();
         antCopia = actCopia;
         actCopia = new TNodoSecuencia<TElem>( act->elem(), 0 );
         if ( secuencia._ant == act ) _ant = actCopia;
         antCopia->_sig = actCopia;
       }
	   _total = secuencia.numElems();
     };

#endif

