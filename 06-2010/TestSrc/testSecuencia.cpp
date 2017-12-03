/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "Secuencia.h"
#include "Secuencia.h"

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
SUITE(Secuencia) {

TEST(Existe) {
	CSecuencia<int> xs;
}

TEST(VacioInicial) {
	CSecuencia<int> xs;
	CSecuencia<int> xs2(xs);

	CHECK(xs.esVacio());
	CHECK(xs2.esVacio());
	CHECK(xs.esFin());
	CHECK(xs2.esFin());
}

TEST(ActualYBorraFallaAnteVacio) {
	CSecuencia<int> xs;

	CHECK_THROW(xs.actual(), EAccesoIndebido);
	CHECK_THROW(xs.borra(), EAccesoIndebido);
}

TEST(Inserta) {
	CSecuencia<int> xs;

	xs.inserta(3);
	// Inserta no mueve el punto de interés
	CHECK(xs.esFin());
	CHECK(!xs.esVacio());
	CHECK_EQUAL(1, xs.numElems());
}

TEST(Recorrido) {
	CSecuencia<int> xs;

	xs.inserta(3);
	xs.inserta(4);
	xs.inserta(5);
	CHECK_EQUAL(3, xs.numElems());
	xs.reinicia();
	CHECK_EQUAL(3, xs.actual());
	CHECK_EQUAL(3, xs.actual());
	xs.avanza();
	CHECK_EQUAL(4, xs.actual());
	CHECK_EQUAL(4, xs.actual());
	xs.avanza();
	CHECK_EQUAL(5, xs.actual());
	CHECK_EQUAL(5, xs.actual());
	xs.avanza();
	CHECK(xs.esFin());
	CHECK_THROW(xs.actual(), EAccesoIndebido);
	CHECK_THROW(xs.avanza(), EAccesoIndebido);
}

TEST(Borrado) {

	CSecuencia<int> xs;

	CHECK_THROW(xs.borra(), EAccesoIndebido);
	xs.inserta(3);
	CHECK_THROW(xs.borra(), EAccesoIndebido);
	xs.inserta(6);
	CHECK_EQUAL(2, xs.numElems());
	xs.reinicia();
	CHECK_EQUAL(3, xs.actual());
	xs.borra();
	CHECK_EQUAL(6, xs.actual());
	CHECK_EQUAL(1, xs.numElems());
	xs.borra();
	CHECK_EQUAL(0, xs.numElems());
	CHECK(xs.esVacio());
}

TEST(GetsConsts) {
	const CSecuencia<int> xs;
	xs.esVacio();
	xs.numElems();
	CHECK_THROW(xs.actual(), EAccesoIndebido);
}

TEST(GetReferenciaConstante) {
	CSecuencia<CSinCtorCopia> xs;

	CHECK_THROW(xs.actual(), EAccesoIndebido);
}

TEST(CtorCopia) {
	CSecuencia<int> xs;
	CSecuencia<int> xs2(xs);

	CHECK(xs.esVacio());
	CHECK(xs2.esVacio());
	xs.inserta(3);
	CHECK(!xs.esVacio());
	CHECK(xs2.esVacio());
}

TEST(CtorCopiaConElementos) {
	CSecuencia<int> xs;
	xs.inserta(2);
	CSecuencia<int> xs2(xs);

	CHECK_EQUAL(1, xs.numElems());
	CHECK_EQUAL(1, xs2.numElems());
	xs.inserta(3);
	CHECK_EQUAL(2, xs.numElems());
	CHECK_EQUAL(1, xs2.numElems());
}

TEST(Asignacion) {
	CSecuencia<int> xs;
	CSecuencia<int> xs2;

	xs2 = xs;

	CHECK(xs.esVacio());
	CHECK(xs2.esVacio());
	xs.inserta(3);
	CHECK(!xs.esVacio());
	CHECK(xs2.esVacio());
}

TEST(AsignacionConElementos) {
	CSecuencia<int> xs;
	CSecuencia<int> xs2;
	xs.inserta(2);
	xs2 = xs;

	CHECK_EQUAL(1, xs.numElems());
	CHECK_EQUAL(1, xs2.numElems());
	xs.inserta(3);
	CHECK_EQUAL(2, xs.numElems());
	CHECK_EQUAL(1, xs2.numElems());
}

}
