/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include <set>

#include "MedalleroSecuencia.h"
#include "MedalleroTablaAbierta.h"
#include "MedalleroTablaAbierta.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;

// Operador de igualdad de parejas de paises y medallas
// Implementado en testMedalleroSecuencia.cpp
bool operator==(const CPareja<CPais, CMedallas> &lhs, const CPareja<CPais, CMedallas> &rhs);

#define CMedallero CMedalleroTAbierta
SUITE(MedalleroTAbierta) {
#include "testMedallero.inc"
}
