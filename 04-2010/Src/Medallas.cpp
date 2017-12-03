#include "Medallas.h"

bool	CMedallas::operator< (const CMedallas &rhs) const {
	if (this->_oro < rhs.getOros()) {
		return true;
	}

	if ( (this->_oro == rhs.getOros()) && (this->_plata < rhs.getPlatas())) {
		return true;
	}

	if ((this->_oro == rhs.getOros()) && (this->_plata == rhs.getPlatas()) && ( this->_bronce < rhs.getBronces()) ) {
		return true;
	}

	return false;
}

bool	CMedallas::operator== (const CMedallas &rhs) const {
	return ((this->_oro == rhs.getOros()) && (this->_plata == rhs.getPlatas()) && ( this->_bronce == rhs.getBronces()));
}
bool	CMedallas::operator> (const CMedallas &rhs) const {

	if (this->_oro > rhs.getOros()) {
		return true;
	}

	if ( (this->_oro == rhs.getOros()) && (this->_plata > rhs.getPlatas())) {
		return true;
	}

	if ((this->_oro == rhs.getOros()) && (this->_plata == rhs.getPlatas()) && ( this->_bronce > rhs.getBronces()) ) {
		return true;
	}

	return false;

}