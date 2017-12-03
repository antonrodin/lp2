#ifndef CSalidaH
#define CSalidaH

#include <iostream>

class CSalida {
public:
	virtual ~CSalida () {}
	virtual void InitPrueba(const std::string &desc)=0;
	virtual void Muestra(int tam, float tiempo)=0;
	virtual void FinPrueba()=0;
private:
};

#endif