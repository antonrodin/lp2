//
//      Anton Zekeriev Rodin
//      Alberto Martinez Caretero
//

#ifndef TCaraH
#define TCaraH

#include <vcl.h>
#include <iostream.h>
using namespace std;

//forma canonica ortodoxa de clase TCara
class TCara {
public:
        //Constructores, operadores y destructor
        TCara(): _pelo(-1), _ojos(-1), _narizYOrejas(-1), _boca(-1) {}  //Constructor predeterminado
	TCara(int pelo, int ojos, int narizYOrejas, int boca);
        TCara(const TCara& cara);                                       //Constructor de copia
        virtual ~TCara() {}                                                     //Destructor
        TCara& operator=(const TCara& cara);                            //Operador de asignacion
        bool operator==(TCara& cara) const;

        //Accedentes
        int getBoca() const { return _boca; }
        int getOjos() const { return _ojos; }
        int getNarizYOrejas() const {return _narizYOrejas; }
        int getPelo() const { return _pelo; }
        void boca(int boca) { _boca = boca; }
        void ojos(int ojos) { _ojos = ojos; }
        void nariz(int nariz) { _narizYOrejas = nariz; }
        void pelo(int pelo) { _pelo = pelo; }

        //Metodos
        string dibujaBoca() const;
        string dibujaOjos() const;
        string dibujaNarizYOrejas() const;
        string dibujaPelo() const;
        virtual void dibuja(TCanvas*) const = 0;
        virtual string getClassName() const = 0;
        virtual bool salvaTXT(ofstream&) const = 0;
        virtual bool cargaTXT(ifstream&) const = 0;
        virtual bool mismo(TCara*&) const = 0;
        bool mismosRasgos(const TCara*&) const;
private:
	int _pelo;
        int _ojos;
        int _narizYOrejas;
        int _boca;
};

#endif TCaraH
 
 