/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
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
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;

// Operador de igualdad de parejas de paises y medallas
// Implementado en testMedalleroSecuencia.cpp
bool operator==(const CPareja<CPais, CMedallas> &lhs, const CPareja<CPais, CMedallas> &rhs);

#define CMedallero CMedalleroTAbierta
SUITE(MedalleroTAbierta) {
#include "testMedallero.inc"
}
