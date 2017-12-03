/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "TablaAbierta.h"
#include "TablaAbierta.h"

namespace {
class string {
};
}
// Si la línea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deberías hacer.
string a;


#define CTabla CTablaAbierta
SUITE(TablaAbierta) {
#include "testTabla.inc"
}
