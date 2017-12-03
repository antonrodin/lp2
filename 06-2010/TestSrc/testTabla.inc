/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/

class CMockClass {
public:
	CMockClass() {}
	int num() const { _numNums++; return 0; }
	bool operator==(const CMockClass &rhs) const { return this == &rhs;}
	static int _numNums;
};

int CMockClass::_numNums = 0;

TEST(Existe) {
	CTabla<int, int> t;
}

TEST(Constructor) {
	CTabla<int, int> t;
	CHECK(t.esVacio());
}

TEST(InsercionYVacio) {

	CTabla<int, char> t;
	CHECK(t.esVacio());
	t.inserta(3, 'a');
	CHECK(!t.esVacio());
}

TEST(InsercionYConsulta) {

	CTabla<int, char> t;
	t.inserta(3, 'a');
	CHECK_EQUAL('a', t.consulta(3));
	t.inserta(5, 'b');
	CHECK_EQUAL('a', t.consulta(3));
	CHECK_EQUAL('b', t.consulta(5));
}

TEST(InsercionDoble) {
	CTabla<int, char> t;
	t.inserta(3, 'a');
	t.inserta(3, 'b');
	CHECK_EQUAL('b', t.consulta(3));
}

TEST(Esta) {
	CTabla<int, char> t;
	
	CHECK(!t.esta(6));
	t.inserta(6, 'k');
	CHECK(t.esta(6));
}

TEST(Enumera) {

	CTabla<int, char> t;
	CSecuencia<CPareja<int, char> > sec;
	
	sec = t.enumera();
	CHECK_EQUAL(0, sec.numElems());
	
	t.inserta(3, '3');
	sec = t.enumera();
	CHECK_EQUAL(1, sec.numElems());
	
	CPareja<int, char> p;
	sec.reinicia();
	CHECK_EQUAL(3, sec.actual().v1());
	CHECK_EQUAL('3', sec.actual().v2());
	
	t.inserta(5, '5');

	sec = t.enumera();
	sec.reinicia();
	while (!sec.esFin()) {
		CHECK_EQUAL(sec.actual().v1(), sec.actual().v2() - '0');
		sec.avanza();
	}
}

TEST(Meter1000Elems) {

	CTabla<int, int> t;
	
	for (int i = 0; i < 10000; ++i)
		t.inserta(i, i);
}

TEST(LlamaANumBien) {
	CTabla<CMockClass, int> t;
	
	CMockClass::_numNums = 0;
	
	t.inserta(CMockClass(), 3);
	CHECK(0 != CMockClass::_numNums);
}

TEST(MetodosConst) {
	const CTabla<int, int> t;
	
	t.esVacio();
	CHECK_THROW(t.consulta(3), EClaveErronea);
	t.esta(3);
	t.enumera();
}
