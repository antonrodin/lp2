/*
 Tests de la práctica de LP2
 (c) Marco Antonio Gómez Martín
*/


CPais esp("España");
CPais jap("Japon");
CPais chi("China");
CPais uk("Reino Unido");

CAtleta aEsp1("Pepe", esp);
CAtleta aEsp2("Jose", esp);
CAtleta aJap("Chun-lin", jap);
CAtleta aChi("Lin-chu", chi);
CAtleta aUk("Mr. Smith", uk);

CDeporte squash("squash");
CDeporte natacion("natacion");
CDeporte tenis("tenis");

CPrueba pSquash1("Masculino", squash);
CPrueba pSquash2("Femenino", squash);
CPrueba pNatacion1("100 espalda", natacion);
CPrueba pNatacion2("50 libres", natacion);

bool less_pareja(const CPareja<CPais, CMedallas>& a,
				 const CPareja<CPais, CMedallas>& b) {
	return a.v2() < b.v2();
}


bool mismoContenido(CSecuencia< CPareja<CPais, CMedallas> > &s1, 
					CSecuencia< CPareja<CPais, CMedallas> > &s2) {

	if (s1.numElems() != s2.numElems())
		return false;
	s1.reinicia();
	s2.reinicia();
	std::set<CPareja<CPais, CMedallas>,
			bool (*)(const CPareja<CPais, CMedallas>&, 
			         const CPareja<CPais, CMedallas>&)> cjto(less_pareja),
					                                    cjto2(less_pareja);

	while (!s1.esFin()) {
		cjto.insert(s1.actual());
		s1.avanza();
	}

	while (!s2.esFin()) {
		cjto2.insert(s2.actual());
		s2.avanza();
	}

	return cjto == cjto2;
}

#define RET_FALSE_SI_NO(expr) if (!(expr)) return false;

bool compruebaMedallero(CMedalleroAbstracto *m) {
	// El test rellena con diversas pruebas

	CSecuencia<CPareja<CPais, CMedallas> > conOrden;
	CSecuencia<CPareja<CPais, CMedallas> > sinOrden;

	// MEDALLERO GENERAL:
	//   Esp: 3, 0, 0
	//   Chi: 2, 3, 2
	//   Jap: 2, 0, 3
	//   Uk:  0, 4, 2
	sinOrden = m->medallero();
	conOrden = m->medalleroOrdenado();

	RET_FALSE_SI_NO(mismoContenido(sinOrden, conOrden));

	conOrden.reinicia();
	RET_FALSE_SI_NO(conOrden.actual().v1() == esp);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(3, 0, 0));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == chi);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(2, 3, 2));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == jap);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(2, 0, 3));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == uk);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(0, 4, 2));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.esFin());

	// MEDALLERO SQUASH
	//   Chi: 2, 2, 2
	//   Esp: 2, 0, 0
	//   Uk:  0, 2, 0
	//   Jap: 0, 0, 2
	sinOrden = m->medalleroDeporte(squash);
	conOrden = m->medalleroDeporteOrdenado(squash);

	RET_FALSE_SI_NO(mismoContenido(sinOrden, conOrden));

	conOrden.reinicia();
	RET_FALSE_SI_NO(conOrden.actual().v1() == chi);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(2, 2, 2));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == esp);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(2, 0, 0));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == uk);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(0, 2, 0));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == jap);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(0, 0, 2));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.esFin());

	// MEDALLERO NATACION
	//   Jap: 2, 0, 1
	//   Esp: 1, 0, 0
	//   Uk:  0, 2, 2
	//   Chi: 0, 1, 0
	sinOrden = m->medalleroDeporte(natacion);
	conOrden = m->medalleroDeporteOrdenado(natacion);

	RET_FALSE_SI_NO(mismoContenido(sinOrden, conOrden));

	conOrden.reinicia();
	RET_FALSE_SI_NO(conOrden.actual().v1() == jap);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(2, 0, 1));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == esp);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(1, 0, 0));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == uk);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(0, 2, 2));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.actual().v1() == chi);
	RET_FALSE_SI_NO(conOrden.actual().v2() == CMedallas(0, 1, 0));

	conOrden.avanza();
	RET_FALSE_SI_NO(conOrden.esFin());

	return true;
}


TEST(Existe) {
	CMedallero m;
}

TEST(Vacio) {
	CMedallero m;

	CHECK_EQUAL(0, m.medallero().numElems());
	CHECK_EQUAL(0, m.medalleroOrdenado().numElems());
	CHECK_EQUAL(0, m.medalleroDeporte(squash).numElems());
	CHECK_EQUAL(0, m.medalleroDeporteOrdenado(squash).numElems());

}

TEST(UnPaisDosDeportes) {

	CMedallero m;

	// Tres españoles ganando en squash y en las 
	// dos pruebas de natación.
	CSecuencia<CAtleta> ganadores;
	ganadores.inserta(aEsp1);
	ganadores.inserta(aEsp2);
	ganadores.inserta(aEsp2);

	m.clasificacion(pSquash1, ganadores);
	m.clasificacion(pNatacion1, ganadores);
	m.clasificacion(pNatacion2, ganadores);

	// España debería tener (3, 3, 3) medallas
	CSecuencia<CPareja<CPais, CMedallas> > ret;

	ret = m.medallero();
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(3, 3, 3) == ret.actual().v2());
	ret = m.medalleroOrdenado();
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(3, 3, 3) == ret.actual().v2());

	// Debería tener (1, 1, 1) medallas en squash
	ret = m.medalleroDeporte(squash);
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(1, 1, 1) == ret.actual().v2());
	ret = m.medalleroDeporteOrdenado(squash);
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(1, 1, 1) == ret.actual().v2());

	// Debería tener (2, 2, 2) medallas en natación
	ret = m.medalleroDeporte(natacion);
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(2, 2, 2) == ret.actual().v2());
	ret = m.medalleroDeporteOrdenado(natacion);
	ret.reinicia();
	CHECK_EQUAL(1, ret.numElems());
	CHECK(esp == ret.actual().v1());
	CHECK(CMedallas(2, 2, 2) == ret.actual().v2());

	// Y, obviamente, ¡ninguna en tenis!
	ret = m.medalleroDeporte(tenis);
	CHECK_EQUAL(0, ret.numElems());
	ret = m.medalleroDeporteOrdenado(tenis);
	CHECK_EQUAL(0, ret.numElems());

}

TEST(VariosPaisesUnDeporte) {

	// (Esp, China, Jap) Lo meteremos 3 veces
	CSecuencia<CAtleta> ganadores1;
	ganadores1.inserta(aEsp1);
	ganadores1.inserta(aChi);
	ganadores1.inserta(aJap);

	// (China, Uk, China) Lo meteremos 2 veces
	CSecuencia<CAtleta> ganadores2;
	ganadores2.inserta(aChi);
	ganadores2.inserta(aUk);
	ganadores2.inserta(aChi);

	// (Japon, Uk, Uk) Lo meteremos 2 veces
	CSecuencia<CAtleta> ganadores3;
	ganadores3.inserta(aJap);
	ganadores3.inserta(aUk);
	ganadores3.inserta(aUk);

	// Metemos las mismas pruebas en distinto orden
	// y comprobamos que siempre queda igual.
	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);

		CHECK(compruebaMedallero(m));
		delete m;
	}


	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pSquash2, ganadores2);

		CHECK(compruebaMedallero(m));
		delete m;
	}

	{
		CMedalleroAbstracto *m = new CMedallero;
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion1, ganadores1);
		m->clasificacion(pSquash2, ganadores2);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pNatacion2, ganadores3);
		m->clasificacion(pSquash1, ganadores1);
		m->clasificacion(pSquash1, ganadores1);

		CHECK(compruebaMedallero(m));
		delete m;
	}
}
