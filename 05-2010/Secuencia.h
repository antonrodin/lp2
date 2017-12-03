// secuencia_dinamica.h: implementación dinámica del TAD Secuencia
//---------------------------------------------------------------------------
#ifndef secuencia_H
#define secuencia_H
//---------------------------------------------------------------------------


#include <iostream>
#include <ostream>
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
     
     
     CSecuencia( const CSecuencia<TElem>& );
     

     ~CSecuencia( );
     

     CSecuencia<TElem>& operator=( const CSecuencia<TElem>& );
     

  // Operaciones de las secuencias
     void inserta(const TElem&);
     

     void borra( ) ;
     
     const TElem& actual( ) const ;
     

     void avanza( ) ;
     
     void reinicia( );
     

     bool esFin( ) const;
     

     bool esVacio( ) const;
     

	 int  numElems () const;  



  // Escritura
     void escribe( std::ostream& salida ) const;
     void escribeLn( std::ostream& salida ) const;

  private:
  // Variables privadas
     TNodoSecuencia<TElem> *_pri, *_ant;
	 int _numelemts;

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
	   this->_numelemts = 0;
     };

     template <class TElem>
     CSecuencia<TElem>::CSecuencia( const CSecuencia<TElem>& other ) {
        copia(other);
	     };

     template <class TElem>
     CSecuencia<TElem>::~CSecuencia( ) {
       libera();
	   _numelemts = 0;
     };

     template <class TElem>
     CSecuencia<TElem>&
     CSecuencia<TElem>::operator=( const CSecuencia<TElem>& rhs ) {
       if( this != &rhs ) {
         libera();
         copia(rhs);
       }
       return *this;
     };


  // Operaciones de las secuencias

     template <class TElem>
     void CSecuencia<TElem>::inserta(const TElem& e) {
       TNodoSecuencia<TElem>* nuevo = new TNodoSecuencia<TElem> ( e, _ant->sig() );
       _ant->_sig = nuevo;
       _ant = nuevo;
	   _numelemts++;
     };

     template <class TElem>
     const TElem& CSecuencia<TElem>::actual( ) const  {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       return _ant->sig()->elem();
     };

     template <class TElem>
     void CSecuencia<TElem>::borra( )  {
       if( esFin() )
         throw EAccesoIndebido("Error: el punto de interés está al final");
       TNodoSecuencia<TElem>* act = _ant->sig();
       _ant->_sig = act->sig();
       delete act;
	   _numelemts--;
     };

     template <class TElem>
     void CSecuencia<TElem>::avanza( )  {
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
	 int CSecuencia<TElem>::numElems () const{
	 
		return _numelemts;
	 
	 }

  // Operaciones de entrada/salida

     template <class TElem>
     void CSecuencia<TElem>::escribe( std::ostream & salida ) const {
       if ( _pri == _ant ) salida << "<--" << endl;
       TNodoSecuencia<TElem>* tmp = _pri->sig();
       while ( tmp != 0 ) {
         salida << tmp->elem() << endl;
         if ( tmp == _ant ) salida << "<--" << endl;
         tmp = tmp->sig();
       }
     };

     template <class TElem>
     void CSecuencia<TElem>::escribeLn( std::ostream & salida ) const {
       escribe(salida);
     }

     template <class TElem>
     std::ostream& operator<<( std::ostream& salida, const CSecuencia<TElem>& sec ) {
       sec.escribe(salida);
       return salida;
     };

	 
  // Operaciones privadas

     template <class TElem>
     void CSecuencia<TElem>::libera() {
       while ( _pri != 0 ){
         _ant = _pri;
         _pri = _pri->sig();
         delete _ant;
       }
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
	   _numelemts = secuencia._numelemts;
     };

#endif
