/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "TablaAbierta.h"
#include "TablaAbierta.h"

namespace {
class string {
};
}
// Si la l�nea siguiente da error, has utilizado
// el using namespace std en un .h, algo que
// nunca deber�as hacer.
string a;


#define CTabla CTablaAbierta
SUITE(TablaAbierta) {
#include "testTabla.inc"
}
