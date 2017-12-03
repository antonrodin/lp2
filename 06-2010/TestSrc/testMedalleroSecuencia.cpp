/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include <set>

#include "MedalleroSecuencia.h"
#include "MedalleroSecuencia.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;

// Operador de igualdad de parejas de paises y medallas
bool operator==(const CPareja<CPais, CMedallas> &lhs, const CPareja<CPais, CMedallas> &rhs) {
	return (lhs.v1() == rhs.v1()) && (lhs.v2() == rhs.v2());
}

#define CMedallero CMedalleroSecuencia
SUITE(MedalleroSecuencia) {
#include "testMedallero.inc"
}
