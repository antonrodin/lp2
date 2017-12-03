#ifndef MedalleroTablaCerradaH
#define MedalleroTablaCerradaH

#include <iostream>

#include "MedalleroAbstracto.h"
#include "TablaCerrada.h"

typedef CTablaCerrada< CPais, CMedallas> TInfoMedallasC;
typedef CTablaCerrada< CDeporte, TInfoMedallasC* > PorDeportesC;

class CMedalleroTCerrada : public CMedalleroAbstracto {
public:
	CMedalleroTCerrada();
	~CMedalleroTCerrada();

	std::string getNombre() { return "Tabla Cerrada"; }
	
	void  clasificacion(const CPrueba &prueba, CSecuencia< CAtleta > &clasif);
	CSecuencia< CPareja < CPais, CMedallas > >  medallero ();
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroOrdenado ();
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep);
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep);

private:
	TInfoMedallasC* _medallero;
	PorDeportesC* _porDeporte;

	void ponMedalla(int tipo, CPais pais, TInfoMedallasC* tabla);
	TInfoMedallasC* buscaDeporte(bool& existe, CDeporte deporte);
};

#endif
