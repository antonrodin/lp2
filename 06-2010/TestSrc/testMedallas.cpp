/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "Medallas.h"
#include "Medallas.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;

#include <iostream>

// Comprueba que está implementada la clase CPareja
SUITE(Medallas) {

TEST(ExisteClase) {
	CMedallas m;
	CMedallas m2(1, 2, 3);
}

TEST(SoloGuardaTresInts) {

	CHECK_EQUAL(sizeof(CMedallas), 3 * sizeof(int));
}

TEST(SinParametrosTodoACero) {
	CMedallas m;
	CHECK_EQUAL(0, m.getOros());
	CHECK_EQUAL(0, m.getPlatas());
	CHECK_EQUAL(0, m.getBronces());
}

TEST(CtorConParamsYGet) {
	CMedallas m(4, 5, 6);
	CHECK_EQUAL(4, m.getOros());
	CHECK_EQUAL(5, m.getPlatas());
	CHECK_EQUAL(6, m.getBronces());
}

TEST(GetConstantes) {
	const CMedallas m(4, 5, 6);

	// Si las líneas siguientes no compilan, no has
	// hecho el método const.
	CHECK_EQUAL(4, m.getOros());
	CHECK_EQUAL(5, m.getPlatas());
	CHECK_EQUAL(6, m.getBronces());
}

TEST(MenorQue) {

	CHECK(CMedallas(1, 2, 3) < CMedallas(2, 2, 3));
	CHECK(CMedallas(1, 2, 3) < CMedallas(1, 3, 3));
	CHECK(CMedallas(1, 2, 3) < CMedallas(1, 2, 4));

	CHECK(!(CMedallas(2, 2, 3) < CMedallas(1, 2, 3)));
	CHECK(!(CMedallas(1, 3, 3) < CMedallas(1, 2, 3)));
	CHECK(!(CMedallas(1, 2, 4) < CMedallas(1, 2, 3)));

	CHECK(!(CMedallas(1, 2, 3) < CMedallas(1, 2, 3)));
}

TEST(MayorQue) {

	CHECK(CMedallas(2, 2, 3) > CMedallas(1, 2, 3));
	CHECK(CMedallas(1, 3, 3) > CMedallas(1, 2, 3));
	CHECK(CMedallas(1, 2, 4) > CMedallas(1, 2, 3));

	CHECK(!(CMedallas(1, 2, 3) > CMedallas(2, 2, 3)));
	CHECK(!(CMedallas(1, 2, 3) > CMedallas(1, 3, 3)));
	CHECK(!(CMedallas(1, 2, 3) > CMedallas(1, 2, 4)));

	CHECK(!(CMedallas(1, 2, 3) > CMedallas(1, 2, 3)));
}

TEST(Igual) {

	CHECK(CMedallas(1, 2, 3) == CMedallas(1, 2, 3));
	CHECK(!(CMedallas(2, 2, 3) == CMedallas(1, 2, 3)));
	CHECK(!(CMedallas(1, 1, 3) == CMedallas(1, 2, 3)));
	CHECK(!(CMedallas(1, 2, 4) == CMedallas(1, 2, 3)));
}

TEST(ComparacionesConstantes) {
	const CMedallas m1(4, 5, 6);
	const CMedallas m2(4, 5, 6);

	// Si las líneas siguientes no compilan, no has
	// hecho el método const.
	m1 < m2;
	m2 == m2;
	m1 > m2;
}
}
