
//---------------------------------------------------------------------------
#ifndef secuencia_dH
#define secuencia_dH
//---------------------------------------------------------------------------


#include <iostream>
#include "AccesoIndebido.h"

using namespace std;

template <class TElem>
class TSecuenciaDinamica;

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
    friend TSecuenciaDinamica<TElem>;
};

template <class TElem>
class TSecuenciaDinamica {
  public:

  // Constructoras, destructora y operador de asignación
     TSecuenciaDinamica( );
    
     
     TSecuenciaDinamica( const TSecuenciaDinamica<TElem>& );
     
     ~TSecuenciaDinamica( );
    

     TSecuenciaDinamica<TElem>& operator=( const TSecuenciaDinamica<TElem>& );
      
     void inserta(const TElem&);
    
     void borra( );
    

     const TElem& actual( ) const;
    

     void avanza( );
    
     void reinicia( );
     

     bool esFin( ) const;
     

     bool esVacio( ) const;
     

  // Escritura
     void escribe( ostream& salida ) const;
     void escribeLn( ostream& salida ) const;

  private:
  // Variables privadas
     TNodoSecuencia<TElem> *_pri, *_ant;

  // Operaciones privadas
     void libera();
     void copia( const TSecuenciaDinamica<TElem>& );
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
     TSecuenciaDinamica<TElem>::TSecuenciaDinamica( ) {
       _pri = _ant = new TNodoSecuencia<TElem>();
     };

     template <class TElem>
     TSecuenciaDinamica<TElem>::TSecuenciaDinamica( const TSecuenciaDinamica<TElem>& secuencia ) {
        copia(secuencia);
     };

     template <class TElem>
     TSecuenciaDinamica<TElem>::~TSecuenciaDinamica( ) {
       libera();
     };

     template <class TElem>
     TSecuenciaDinamica<TElem>&
     TSecuenciaDinamica<TElem>::operator=( const TSecuenciaDinamica<TElem>& secuencia ) {
       if( this != &secuencia ) {
         libera();
         copia(secuencia);
       }
       return *this;
     };


  // Operaciones de las secuencias

     template <class TElem>
     void TSecuenciaDinamica<TElem>::inserta(const TElem& elem) {
       TNodoSecuencia<TElem>* nuevo = new TNodoSecuencia<TElem> ( elem, _ant->sig() );
       _ant->_sig = nuevo;
       _ant = nuevo;
     };

     template <class TElem>
     const TElem& TSecuenciaDinamica<TElem>::actual( ) const {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       return _ant->sig()->elem();
     };

     template <class TElem>
     void TSecuenciaDinamica<TElem>::borra( ){
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       TNodoSecuencia<TElem>* act = _ant->sig();
       _ant->_sig = act->sig();
       delete act;
     };

     template <class TElem>
     void TSecuenciaDinamica<TElem>::avanza( ){
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       _ant = _ant->sig();
     };

     template <class TElem>
     void TSecuenciaDinamica<TElem>::reinicia( ) {
       _ant = _pri;
     };

     template <class TElem>
     bool TSecuenciaDinamica<TElem>::esFin( ) const {
       return _ant->sig() == 0;
     };

     template <class TElem>
     bool TSecuenciaDinamica<TElem>::esVacio( ) const {
       return _pri->sig() == 0;
     };

  // Operaciones de entrada/salida

     template <class TElem>
     void TSecuenciaDinamica<TElem>::escribe( ostream & salida ) const {
       if ( _pri == _ant ) salida << "<--" << endl;
       TNodoSecuencia<TElem>* tmp = _pri->sig();
       while ( tmp != 0 ) {
         salida << tmp->elem() << endl;
         if ( tmp == _ant ) salida << "<--" << endl;
         tmp = tmp->sig();
       }
     };

     template <class TElem>
     void TSecuenciaDinamica<TElem>::escribeLn( ostream & salida ) const {
       escribe(salida);
     }

     template <class TElem>
     ostream& operator<<( ostream& salida, const TSecuenciaDinamica<TElem>& sec ) {
       sec.escribe(salida);
       return salida;
     };

  // Operaciones privadas

     template <class TElem>
     void TSecuenciaDinamica<TElem>::libera() {
       while ( _pri != 0 ){
         _ant = _pri;
         _pri = _pri->sig();
         delete _ant;
       }
     };

     template <class TElem>
     void TSecuenciaDinamica<TElem>::copia(const TSecuenciaDinamica<TElem>& secuencia) {
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
     };

#endif
