#ifndef ARBOL_H
#define ARBOL_H

#include "Secuencia.h"
#include "Excepciones.h"
#include <iostream>


template <class TElem>
class CArbol;

template <class TElem>
class TNodoArbin{
  protected:
	  TElem _elem;
	  TNodoArbin<TElem> * _iz, *_dr;
	  TNodoArbin( const TElem&, TNodoArbin<TElem>*, TNodoArbin<TElem>*);
  public:
	  TNodoArbin() : _iz(0), _dr(0) {}
	  const TElem& elem() const;
	  TNodoArbin<TElem> * iz() const;
	  TNodoArbin<TElem> * dr() const;
	  friend CArbol<TElem>;
};

template <class TElem>
class CArbol{
  public:
	  //Constructor por defecto
	  CArbol ();
	  //Constructor de un árbol hoja. 
	  CArbol (const TElem &e);
	  // Constructor por copia
	  CArbol (const CArbol &);
	  //Destructor que elimina toda la memoria.
 	  ~CArbol ();
	  //Operador de asignacion
	  const CArbol & 	operator= (const CArbol &);

	  bool 	operator== (const CArbol &)const ;
	  void 	carga (std::istream &in);
	  void 	salva (std::ostream &out) const;
	  bool 	esVacio () const;
	  const TElem & 	actual () const;
	  bool 	esFin () const;
	  bool 	esHojaPI () const;
	  void 	reinicia ();
	  void 	bajaIzda ();
	  void 	bajaDcha ();
	  void 	cambiaActual (const TElem &e);
	  void 	anyadeIz (const TElem &e);
	  void 	anyadeDr (const TElem &e);

  private:
	  TNodoArbin<TElem> *_ra;
	  TNodoArbin<TElem> *_pi;
	  void libera();
	  static void liberaAux(TNodoArbin<TElem>*);
	  void copia(const CArbol<TElem>&);
	  static TNodoArbin<TElem>* copiaAux( TNodoArbin<TElem>*, TNodoArbin<TElem> * , TNodoArbin<TElem> * &);
	  static void escribeAux( std::ostream & salida, TNodoArbin<TElem>* p, std::string pref);
	  static TNodoArbin<TElem>* cargaAux(std::istream &);
	  //CArbol(TNodoArbin<TElem>*);
	 // bool igualesAux(TNodoArbin<TElem> *,TNodoArbin<TElem> *,TNodoArbin <TElem>*, TNodoArbin <TElem>*);


};





/*
* =================================================
*			IMPLEMENTACION CLASE DE LOS NODOS 
* =================================================
*/
template <class TElem>
TNodoArbin<TElem>::TNodoArbin( const TElem& elem, TNodoArbin<TElem>* iz=0, TNodoArbin<TElem>* dr=0):
_elem(elem),_iz(iz),_dr(dr){};

template <class TElem>
const TElem& TNodoArbin<TElem>::elem() const{
	return _elem;
}

template <class TElem>
TNodoArbin<TElem> * TNodoArbin<TElem>::iz() const{
	return _iz;
}

template <class TElem>
TNodoArbin<TElem> * TNodoArbin<TElem>::dr() const{
	return _dr;
}





/*
* =================================================
*			IMPLEMENTACION CLASE CARBOL
* =================================================
*/





template <class TElem>
CArbol<TElem>::CArbol( ) {
	_ra = 0;
	_pi=_ra;
}

template <class TElem>
CArbol<TElem>::CArbol (const TElem &e){
	_ra=new TNodoArbin<TElem> (e,0,0);
	_pi=_ra;
	
}


// Constructor por copia


template <class TElem>
CArbol<TElem>::CArbol (const CArbol &arbol){
	copia(arbol);
}

//Destructor que elimina toda la memoria.

template <class TElem>
CArbol<TElem>::~CArbol( ) {
       libera();
 };
 	  





// Operador de asignación

 template <class TElem>
 const CArbol<TElem>& CArbol<TElem>::operator=( const CArbol<TElem>& rhs ) {
       if( this != &rhs ) {
         libera();
         copia(rhs);
       }
       return *this;
     };

// Sobrecarga del operador de igualdad
 template < class TElem>
 bool 	CArbol<TElem>::operator== (const CArbol<TElem> &rhs)const {

	bool igual= false;
	TNodoArbin<TElem> * ra, * pi;
	ra=this->_ra;
	pi=this->_pi;
	
	
	
	//Compruebo que los arboles a comparar no estén vacios
	if(this->esVacio() && rhs.esVacio()){
		//throw EAccesoIndebido("Alguno de los arboles de la comparacion es vacio");
		return true;
	}
	else{
		igual=igualesAux(ra,rhs._ra,pi,rhs._pi);
	}

	return igual;
 
 }
 
 
 template < class TElem>
 bool igualesAux(TNodoArbin<TElem>* arb1,TNodoArbin<TElem>* arb2,TNodoArbin<TElem>* pIarb1,TNodoArbin<TElem>* pIarb2){

	bool iguales= false,pIigual=true;
	// Comparo nodo a nodo si todos son iguales. Empiezo comparando las raices de los arboles
	//Comparo que los nodos sean los dos distintos de NULL
	if (arb1!=0 && arb2!=0){
		if (arb1->elem() == arb2->elem()){
			if (pIarb1==arb1)
				pIigual = (pIarb2==arb2);

			if(igualesAux(arb1->iz(),arb2->iz(),pIarb1,pIarb2))
					iguales=igualesAux(arb1->dr(),arb2->dr(),pIarb1,pIarb2);
			else return false;

		} 
		else return false;
	}
	else
		if (arb1==0 && arb2==0) {
			if (pIarb1==arb1)
				pIigual = (pIarb2==arb2);
			return (true && pIigual);
		} // Si los dos nodos son null entonces seran iguales
	return iguales&&pIigual;
 }


 template <class TElem>
 TNodoArbin<TElem> * CArbol<TElem>::cargaAux (std::istream &f){
	 std::string linea;
	 TElem elem;// esta variable se usará para almacenar el elemento del nodo. Una vez que tengamos 
	 //el nodo creado entonces se devolvera mediante return. Si el nodo es Nuevo devolveremos NULL o 0.
	TNodoArbin <TElem> * iz, * dr;
		f >> linea;
	//std::getline(f,linea);
	if ( linea == "Cons("){

		//ra=new TNodoArbin<TElem> ( );
		iz =cargaAux(f);
		f >> linea; 
		if (linea == ",") {
			//std::getline(f,linea);
			f >> ra->_elem;
		}
		else {
			throw EFormatoIncorrecto("Se esperaba una coma");
			//Lanza excepcion Formato Incorrecto
		}
		f >> linea; 
		if (linea == ","){
		
			dr=cargaAux(f);
		}
		f >> linea;
		if (linea == ")") {
			ra->_iz=iz;
			ra->_dr=dr;
			//return new TNodoArbin<TElem> (,iz,dr);
			return ra;
		}
		else {
			throw EFormatoIncorrecto("Se esperaba un parentesis )");//Lanza excepcion formato incorrecto
		}
	}
	else
		if (linea=="Nuevo") return new TNodoArbin<TElem> ();
		else {
			// Devuelve excepcion formato incorrecto
		}

	
 }

 template < class TElem>
 void 	CArbol<TElem>::carga (std::istream &in){
	 bool ok = true;
	 TNodoArbin<TElem> * nuevaRaiz;
	 
	 
	// cargaAux(in);
	nuevaRaiz = cargaAux (in);
	 if (ok) {
		 this->liberaAux(_ra);
		 this->_ra = nuevaRaiz;
	 }
	else {
		//Lanza excepcion
	}
	
	/*	if (!in.eof()){
		
		 // Se supone que el formato del fichero no es correcto y debe lanzar una excepción
		}*/

 }
 /*std::istream & CArbol<TElem>::operator>>(std::istream &in, std::string &cad) {
		getline(in, cad);
		in.putback('\n');
		return in;
}*/
 
 template < class TElem>
 void 	CArbol<TElem>::salva (std::ostream &out) const{
 
 
 }
 template < class TElem>
 bool 	CArbol<TElem>::esVacio () const{
	return _ra==0;
 
 }
 template < class TElem>
 const TElem & 	CArbol<TElem>::actual () const{
	 return _pi->_elem; 
 }
 	  
 template <class TElem>
 bool 	CArbol<TElem>::esFin () const{
 
	return _pi==0;
 }
	
 template <class TElem>
 bool 	CArbol<TElem>::esHojaPI () const{
	return ((_pi->_iz==0)&&(_pi->_dr==0));
 }

 template <class TElem>
 void 	CArbol<TElem>::reinicia (){
	_pi=_ra;
 }
 
 template <class TElem>
 void 	CArbol<TElem>::bajaIzda (){
	 if (this->esVacio()){
		 throw EAccesoIndebido("No se puede acceder. Esta vacio");
	 }
	 else {
		 if (!this->esFin()) _pi = _pi->iz();
		 else throw EAccesoIndebido("El punto de interes esta al final");
	 }
 }
 
 template <class TElem>
 void 	CArbol<TElem>::bajaDcha (){
	 if (this->esVacio()) {
		 throw EAccesoIndebido("No se puede acceder. El arbol esta vacio");
	 }
	else {
		if (!this->esFin()) _pi = _pi->dr();
	 	else throw EAccesoIndebido("El punto de interes esta al final");
	 }
 
 }

 template <class TElem>
 void 	CArbol<TElem>::cambiaActual (const TElem &e){
	 if (this->esVacio())	{
		 throw EAccesoIndebido("El arbol esta vacio. No se puede usar cambiaActual");	
	 }
	 else {//El punto de interes no ha llegado al final del arbol
		if(this->esFin()) throw EAccesoIndebido ( "El punto de interes llego al final del arbol");
		else {
			(_pi->_elem ) = e; 
		}
	 }
 }

 template <class TElem>
 void 	CArbol<TElem>::anyadeIz (const TElem &e){
		if (this->esVacio()) throw EAccesoIndebido("El arbol está vacio. Operacion no valida");
		else{
			if(this->esFin()) throw EAccesoIndebido("El punto de int. llego al final del arbol");
			else{
				if (_pi->iz() == 0) {
					TNodoArbin <TElem> * hjiz = new TNodoArbin<TElem> (e,0,0);
					_pi->_iz = hjiz;
				}
				else throw EAccesoIndebido("El punto de interes ya tiene hijo izquierdo"); // Llamar a EAccesoIndebido
			}
		}
		
	
 }

 template <class TElem>
 void 	CArbol<TElem>::anyadeDr (const TElem &e){
	 if (this->esVacio()) throw EAccesoIndebido("El arbol está vacio. Operacion no valida");
		else{
			if(this->esFin()) throw EAccesoIndebido("El punto de int. llego al final del arbol");
			else{
				if (_pi->dr() == 0) {
					TNodoArbin <TElem> * hjdr = new TNodoArbin<TElem> (e,0,0);
					_pi->_dr = hjdr;
				}
				else throw EAccesoIndebido("El punto de interes ya tiene hijo izquierdo"); // Llamar a EAccesoIndebido
			}
		}
		
	

 }
 
 //----------Operaciones privadas arboles -----------------





	/* Metodo auxiliar recursivo.
	* las copias se realizaran en profundidas con sucesivas llamadas recursivas desde en constructor
	* del parametrizado de TNodoArbin
	* que ira profundizando en la rama izquierda y derecha hasta recorrer todos los nodos
	*/

     template <class TElem>
	 TNodoArbin<TElem>* CArbol<TElem>::copiaAux( TNodoArbin<TElem>* p, TNodoArbin<TElem> * pIaux, TNodoArbin<TElem> * & pI ) {
       TNodoArbin<TElem>* r;

	   if ( p == 0 )
         r = 0;
	   else {
		   
			r = new TNodoArbin<TElem>( p->elem(), copiaAux( p->iz(),pIaux,pI), copiaAux( p->dr(),pIaux,pI ) );
			if (pIaux==p) pI = r;
	   }
       return r;
     };

	 // Recibe como parametro un tipo CArbol que será copiado llamando
	 // al metodo auxiliar copiaux, al que se le envia la raiz del arbol
     template <class TElem>
     void CArbol<TElem>::copia(const CArbol<TElem>& arb) {
		 _ra = copiaAux( arb._ra, arb._pi, _pi);
     };

	  // anulación
     template <class TElem>
     void CArbol<TElem>::liberaAux( TNodoArbin<TElem>* p ) {
       if ( p != 0 ){
         liberaAux(p->iz());
         liberaAux(p->dr());
         delete p;
       }
     };

     template <class TElem>
     void CArbol<TElem>::libera() {
       liberaAux( _ra );
     };


#endif