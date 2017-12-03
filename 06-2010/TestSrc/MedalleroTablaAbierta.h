#ifndef MedalleroTablaAbiertaH
#define MedalleroTablaAbiertaH

#include <iostream>

#include "MedalleroAbstracto.h"
#include "TablaAbierta.h"

typedef CTablaAbierta< CPais, CMedallas> TInfoMedallas;
typedef CTablaAbierta< CDeporte, TInfoMedallas* > PorDeportes;

class CMedalleroTAbierta : public CMedalleroAbstracto {
public:
	CMedalleroTAbierta();
	~CMedalleroTAbierta();

	std::string getNombre() { return "Tabla Abierta"; };
	
	void  clasificacion(const CPrueba &prueba, CSecuencia< CAtleta > &clasif);
	CSecuencia< CPareja < CPais, CMedallas > >  medallero ();
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroOrdenado ();
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporte (const CDeporte &dep);
	CSecuencia< CPareja < CPais, CMedallas > >  medalleroDeporteOrdenado (const CDeporte &dep);

private:
	TInfoMedallas* _medallero;
	PorDeportes* _porDeporte;

	void ponMedalla(int tipo, CPais pais, TInfoMedallas* tabla);
	TInfoMedallas* buscaDeporte(bool& existe, CDeporte deporte);
};

#endif
