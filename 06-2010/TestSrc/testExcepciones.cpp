/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "Excepciones.h"
#include "Excepciones.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;

// Comprueba que est�n implementadas las clases
// de excepciones pedidas.
SUITE(Excepciones) {

TEST(ExisteClase) {
	EAccesoIndebido excepcion("mensaje");
}

TEST(GetConst) {
	const EAccesoIndebido excepcion("aa");
	// Si la l�nea siguiente no compila, no has
	// hecho el m�todo const.
	excepcion.mensaje();
}

TEST(ConstructorYGet) {
	EAccesoIndebido excepcion("Mensaje de error");
	CHECK_EQUAL("Mensaje de error", excepcion.mensaje());
}

}
