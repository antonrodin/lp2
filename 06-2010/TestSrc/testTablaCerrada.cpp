/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "TablaCerrada.h"
#include "TablaCerrada.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;


#define CTabla CTablaCerrada
SUITE(TablaCerrada) {
#include "testTabla.inc"
}
