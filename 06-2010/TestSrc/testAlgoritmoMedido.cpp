/*
 Tests de la pr�ctica de LP2
 (c) Marco Antonio G�mez Mart�n
*/
#include "UnitTest++.h"

#include "MideTiempos.h"
#include "Algoritmo.h"
#include "Algoritmo.h"

class CMockAlgoritmo : public CAlgoritmo {
public: 
	virtual std::string getDescription() { return "MockAlg"; }

	virtual void SetUp(int N) {
		if (inExecution) error = true;
		inExecution = true;
		setUpNParam += N;
		lastN = N;
	}

	/**
	 Ejecuci�n concreta del algoritmo. S�lo lo ejecuta una vez
	 (por ejemplo se invocar� s�lo una vez a ordenaInsercion).
	 Es trabajo del gestor de las pruebas el invocar el n�mero de
	 veces que considere conveniente a este m�todo.
	 Nosotros simplemente garantizaremos que en todas las
	 invocaciones _se ejecuta lo mismo_ es decir, se 
	 ordena el vector siempre con los mismos datos iniciales.
	 */
	virtual void Execute() { numExecuteInvocations++; }

	/// Invocado tras la ejecuci�n del algoritmo, para que
	/// se puedan liberar los datos, etc. El objeto puede volver
	/// a utilizarse para otra prueba, si despu�s se llama al SetUp.
	virtual void TearDown() {
		if (!inExecution) error = true;
		inExecution = false;
	}

	CMockAlgoritmo() : error(false), inExecution(false),
					setUpNParam(0), 
					numExecuteInvocations(0), lastN(-1){}

	// Atributos que registran las llamadas a los m�todos

	bool error;	// De protocolo

	bool inExecution;

	int setUpNParam;
	int numExecuteInvocations;
	int lastN;
};

TEST(AlgoritmoTodoCeros) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(0, 0, 10, 0, 0);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado configurado el algoritmo
	// para tama�o 0, y ejecutarlo una vez, pues
	// CMideTiempos debe garantizar que todos los tama�os
	// solicitados son ejecutados al menos una vez!
	CHECK(!alg.error);
	CHECK_EQUAL(0, alg.setUpNParam);
	CHECK_EQUAL(1, alg.numExecuteInvocations);
	CHECK_EQUAL(0, alg.lastN);
}

TEST(AlgoritmoTama�o1CienVeces) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(1, 1, 1, 100, 100);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado configurado el algoritmo
	// para tama�o 1, 100 veces.
	CHECK(!alg.error);
	CHECK_EQUAL(1, alg.setUpNParam);
	CHECK_EQUAL(100, alg.numExecuteInvocations);
	CHECK_EQUAL(1, alg.lastN);
}

TEST(Algoritmo1A10) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(1, 10, 1, 1, 1);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado el algoritmo
	// para tama�o 1..10, una vez cada uno.
	CHECK(!alg.error);
	CHECK_EQUAL(55, alg.setUpNParam);
	CHECK_EQUAL(10, alg.numExecuteInvocations);
	CHECK_EQUAL(10, alg.lastN);
}

TEST(Algoritmo1A10DecrementandoPruebas) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(1, 10, 1, 20, 11);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado el algoritmo para tama�os
	// 1..10 ejecutandolo 20 veces, luego 19, etc., hasta 11.
	CHECK(!alg.error);
	CHECK_EQUAL(55, alg.setUpNParam);
	CHECK_EQUAL(155, alg.numExecuteInvocations);
	CHECK_EQUAL(10, alg.lastN);
}

TEST(Algoritmo1A10IncrementandoPruebas) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(1, 10, 1, 11, 20);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado el algoritmo para tama�os
	// 1..10 ejecutandolo 20 veces, luego 19, etc., hasta 11.
	CHECK(!alg.error);
	CHECK_EQUAL(55, alg.setUpNParam);
	CHECK_EQUAL(155, alg.numExecuteInvocations);
	CHECK_EQUAL(10, alg.lastN);
}

TEST(Algoritmo1A10DandoloAlReves) {
	CMockAlgoritmo alg;
	CMideTiempos medicion(10, 1, 1, 20, 11);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	// Deber�a haber ejecutado el algoritmo para tama�os
	// 1..10 ejecutandolo 20 veces, luego 19, etc., hasta 11.
	CHECK(!alg.error);
	CHECK_EQUAL(55, alg.setUpNParam);
	CHECK_EQUAL(155, alg.numExecuteInvocations);
	CHECK_EQUAL(10, alg.lastN);
}
