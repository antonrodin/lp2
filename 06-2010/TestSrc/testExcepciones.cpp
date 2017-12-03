/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "Excepciones.h"
#include "Excepciones.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;

// Comprueba que están implementadas las clases
// de excepciones pedidas.
SUITE(Excepciones) {

TEST(ExisteClase) {
	EAccesoIndebido excepcion("mensaje");
}

TEST(GetConst) {
	const EAccesoIndebido excepcion("aa");
	// Si la línea siguiente no compila, no has
	// hecho el método const.
	excepcion.mensaje();
}

TEST(ConstructorYGet) {
	EAccesoIndebido excepcion("Mensaje de error");
	CHECK_EQUAL("Mensaje de error", excepcion.mensaje());
}

}
