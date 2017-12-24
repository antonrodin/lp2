//
//      Anton Zekeriev Rodin
//      Alberto Martinez Caretero
//

#include "TCara.h"


TCara::TCara(int pelo, int ojos, int narizYOrejas, int boca) {
	_pelo = pelo;
        _ojos = ojos;
        _narizYOrejas = narizYOrejas;
        _boca = boca;
}

TCara::TCara(const TCara& cara){
        _pelo = cara._pelo;
        _ojos = cara._ojos;
        _narizYOrejas = cara._narizYOrejas;
        _boca = cara._boca;
}

TCara& TCara::operator=(const TCara& cara) {
        _pelo = cara._pelo;
        _ojos = cara._ojos;
        _narizYOrejas = cara._narizYOrejas;
        _boca = cara._boca;
        return *this;
}

bool TCara::operator==(TCara& cara) const {
        if ((_pelo == cara._pelo) &&
           (_ojos == cara._ojos) &&
           (_narizYOrejas == cara._narizYOrejas) &&
           (_boca == cara._boca))  return true;
        else
                return false;
}

string TCara::dibujaBoca() const {
	switch (_boca) {
    	case 0:
       		return "|  ===  |";
 		case 1:
       		return "|   -   |";
 		case 2:
       		return "|  ---  |";
 		default:
       return "--------";
}
}

string TCara::dibujaOjos() const {

	switch (_ojos) {
  		case 0:
        	return "|  O O  |";
        case 1:
      	  return "|-(. .)-|";
        case 2:
        	return "|  \\ /  |";
  		default:
        	return "--------";
}
}

string TCara::dibujaNarizYOrejas() const {
   switch (_narizYOrejas) {
		case 0:
        	return "@   J   @";
 		case 1:
        	return "\¿   o   \¿";
 		case 2:
        	return "<   -   >";
 		default:
        	return "--------";
   }
}

string TCara::dibujaPelo() const {
	switch (_pelo) {
  		case 0:
        	return "WWWWWWWWW";
  		case 1:
        	return "\\\\\\//////";
  		case 2:
        	return "|'''''''|";
  		default:
        	return "--------";
	}
}
