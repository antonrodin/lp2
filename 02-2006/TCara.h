//
//      Anton Zekeriev Rodin
//      Alberto Martinez Caretero
//

#ifndef TCaraH
#define TCaraH

#include <iostream.h>
using namespace std;

//forma canonica ortodoxa de clase TCara
class TCara {
public:
        TCara(): _pelo(-1), _ojos(-1), _narizYOrejas(-1), _boca(-1) {}  //Constructor predeterminado
	TCara(int pelo, int ojos, int narizYOrejas, int boca);
        TCara(const TCara& cara);                                       //Constructor de copia
        ~TCara() {}                                                     //Destructor
        TCara& operator=(const TCara& cara);                            //Operador de asignacion
        bool operator==(TCara& cara) const;
        int getBoca() const { return _boca; }
        int getOjos() const { return _ojos; }
        int getNarizYOrejas() const {return _narizYOrejas; }
        int getPelo() const { return _pelo; }
        string dibujaBoca() const;
        string dibujaOjos() const;
        string dibujaNarizYOrejas() const;
        string dibujaPelo() const;
private:
	int _pelo;
        int _ojos;
        int _narizYOrejas;
        int _boca;

};

#endif TCaraH
 
 