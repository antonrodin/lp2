/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "Localizacion.h"
#include "Localizacion.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;

namespace {
	class CMockClass {
	public:
		CMockClass() : _numNums(0) {}
		int num() const { _numNums++; return 0; }
		mutable int _numNums;
	};
};

// Comprueba que est�n implementadas las clases
// de excepciones pedidas.
SUITE(Num) {

TEST(Existen) {
	num(3);
	num('c');
	num(std::string("Cadena"));
	num(CMockClass());
}

TEST(ValoresCorrectos) {
	for (int i = -5000; i < 5000; ++i)
		CHECK_EQUAL(i, num(i));

	for (char c = '\0'; c < '\255'; ++c)
		CHECK_EQUAL((int)c, num(c));

	CHECK_EQUAL(0, num(std::string("")));
}

}
