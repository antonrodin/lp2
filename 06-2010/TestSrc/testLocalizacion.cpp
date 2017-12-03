/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "Localizacion.h"
#include "Localizacion.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;

namespace {
	class CMockClass {
	public:
		CMockClass() : _numNums(0) {}
		int num() const { _numNums++; return 0; }
		mutable int _numNums;
	};
};

// Comprueba que están implementadas las clases
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
