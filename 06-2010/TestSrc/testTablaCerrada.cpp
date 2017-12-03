/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "TablaCerrada.h"
#include "TablaCerrada.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;


#define CTabla CTablaCerrada
SUITE(TablaCerrada) {
#include "testTabla.inc"
}
