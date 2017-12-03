/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "MideTiempos.h"
#include "Algoritmo.h"
#include <windows.h>

//#define _TESTS_LENTOS
#ifdef _TESTS_LENTOS

class CMockAlgoritmo5Secs : public CAlgoritmo {
public: 
	virtual std::string getDescription() { return "MockAlg"; }

	virtual void SetUp(int N) {
		setUpNParam += N;
		cincoSeg = true;
	}

	/**
	 Ejecución concreta del algoritmo. Se ejecuta tantas veces como CMideTiempos se
   lo indique. La particularidad es que la primera vez tarda en ejecutarse 5 segundos 
	 */
	virtual void Execute() { 
		if (cincoSeg) {
			Sleep(5100);
			cincoSeg = false;
		}
		numExecuteInvocations++;
	}

	/// Invocado tras la ejecución del algoritmo, para que
	/// se puedan liberar los datos, etc. El objeto puede volver
	/// a utilizarse para otra prueba, si después se llama al SetUp.
	virtual void TearDown() {
	}

	CMockAlgoritmo5Secs() : numExecuteInvocations(0),setUpNParam(0),cincoSeg(true){}

	// Atributos que registran las llamadas a los métodos


	int numExecuteInvocations;
	bool cincoSeg;
	int setUpNParam;
};

TEST(FactorReduccion) {
	// Test para comprobar si se divide por dos correctamente
	// cuando se superan los 5 segundos.
	// Se pide ejecutar para N = {1, 2, 3} repitiendo
	// R = {24, 20, 16}. Sin embargo, todas las pruebas tardan
	// más de cinco segundos, por lo que las repeticiones
	// efectivas deberían ser R = {24, 20/2, 16/4}, o lo que
	// es lo mismo, R = {24, 10, 4}.

	CMockAlgoritmo5Secs alg;
	CMideTiempos medicion(1, 3, 1, 24, 16);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	CHECK_EQUAL(38, alg.numExecuteInvocations);
	CHECK_EQUAL(6, alg.setUpNParam);
}

TEST(FactorConParacaidas) {
	// Test para comprobar si cuando se divide por dos
	// el número de repeticiones se tiene cuidado para que
	// si sale repetir 0 veces, al menos se repita una!

	// Se pide ejecutar para N = {10, 20, 30} repitiendo
	// R = {1, 1, 1}. Sin embargo, todas las pruebas tardan
	// más de cinco segundos, por lo que debería ser
	// R = {1, 1/2, 1/4}...

	CMockAlgoritmo5Secs alg;
	CMideTiempos medicion(10, 30, 10, 1, 1);
	medicion.LanzaPrueba(&alg, NULL, NULL);

	CHECK_EQUAL(3, alg.numExecuteInvocations);
	CHECK_EQUAL(60, alg.setUpNParam);
}
#endif // _TESTS_LENTOS
