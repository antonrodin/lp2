/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/
#include "UnitTest++.h"

#include "MideTiempos.h"
#include "Algoritmo.h"
#include "Salida.h"
#include "Salida.h"

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
	 Ejecución concreta del algoritmo. Sólo lo ejecuta una vez
	 (por ejemplo se invocará sólo una vez a ordenaInsercion).
	 Es trabajo del gestor de las pruebas el invocar el número de
	 veces que considere conveniente a este método.
	 Nosotros simplemente garantizaremos que en todas las
	 invocaciones _se ejecuta lo mismo_ es decir, se 
	 ordena el vector siempre con los mismos datos iniciales.
	 */
	virtual void Execute() { numExecuteInvocations++; }

	/// Invocado tras la ejecución del algoritmo, para que
	/// se puedan liberar los datos, etc. El objeto puede volver
	/// a utilizarse para otra prueba, si después se llama al SetUp.
	virtual void TearDown() {
		if (!inExecution) error = true;
		inExecution = false;
	}

	CMockAlgoritmo() : error(false), inExecution(false),
					setUpNParam(0),
					numExecuteInvocations(0), lastN(-1) {}

	// Atributos que registran las llamadas a los métodos

	bool error;	// De protocolo

	bool inExecution;

	int setUpNParam;
	int numExecuteInvocations;
	int lastN;
};

class CMockSalida : public CSalida {
public:

	CMockSalida() : inExecution(false), error(false), sumaN(0) {}

	virtual void InitPrueba(const std::string &desc) {
		this->desc = desc;
		if (inExecution) error = true;
		inExecution = true;
		if (sumaN != 0) error = true;
	}

	virtual void Muestra(int tam, float tiempo) {
		sumaN += tam;
	}

	virtual void FinPrueba() {
		if (!inExecution) error = true;
		inExecution = false;
	}

	bool inExecution;
	bool error;
	int sumaN;
	std::string desc;
};

TEST(Salida) {
	CMockAlgoritmo alg;
	CMockSalida s1, s2;
	CMideTiempos medicion(1, 10, 1, 20, 11);
	medicion.LanzaPrueba(&alg, &s1, &s2);

	// Debería haber ejecutado el algoritmo para tamaños
	// 1..10 ejecutandolo 20 veces, luego 19, etc., hasta 11.
	CHECK(!alg.error);
	CHECK_EQUAL(55, alg.setUpNParam);
	CHECK_EQUAL(155, alg.numExecuteInvocations);
	CHECK_EQUAL(10, alg.lastN);
	
	CHECK_EQUAL(alg.getDescription(), s1.desc);
	CHECK_EQUAL(alg.getDescription(), s2.desc);
	CHECK(!s1.error);
	CHECK(!s2.error);
	CHECK(!s1.inExecution);
	CHECK(!s2.inExecution);
	CHECK_EQUAL(alg.setUpNParam, s1.sumaN);
	CHECK_EQUAL(alg.setUpNParam, s2.sumaN);
}

