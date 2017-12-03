/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "Pareja.h"
#include "Pareja.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;

class CSinCtorCopia {
public:
	CSinCtorCopia() {};
private:
	CSinCtorCopia(const CSinCtorCopia&) {};
};

// Comprueba que est� implementada la clase CPareja
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
	// Si las l�neas siguientes no compilan, no has
	// hecho el m�todo const.
	CHECK_EQUAL(p.v1(), 3);
	CHECK_EQUAL(p.v2(), 4);
}

TEST(GetRefsConstantes) {
	CPareja<CSinCtorCopia, CSinCtorCopia> p;
	// Los get deber�an devolver referencias constantes
	// para mejorar la eficiencia (evitar copias).
	p.v1();
	p.v2();
}

}
