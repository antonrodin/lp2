/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "Pareja.h"
#include "Pareja.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;

class CSinCtorCopia {
public:
	CSinCtorCopia() {};
private:
	CSinCtorCopia(const CSinCtorCopia&) {};
};

// Comprueba que está implementada la clase CPareja
SUITE(Pareja) {

TEST(ExisteClase) {
	CPareja<int, int> p;
}

TEST(CtorDosParams) {
	CPareja<int, int> p(3, 4);
	CHECK_EQUAL(p.v1(), 3);
	CHECK_EQUAL(p.v2(), 4);
}

TEST(GetYSets) {
	CPareja<int, int> p(3, 4);
	p.ponV1(13);
	p.ponV2(14);
	CHECK_EQUAL(p.v1(), 13);
	CHECK_EQUAL(p.v2(), 14);
}

TEST(GetConstantes) {
	const CPareja<int, int> p(3, 4);
	// Si las líneas siguientes no compilan, no has
	// hecho el método const.
	CHECK_EQUAL(p.v1(), 3);
	CHECK_EQUAL(p.v2(), 4);
}

TEST(GetRefsConstantes) {
	CPareja<CSinCtorCopia, CSinCtorCopia> p;
	// Los get deberían devolver referencias constantes
	// para mejorar la eficiencia (evitar copias).
	p.v1();
	p.v2();
}

}
