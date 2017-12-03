#ifndef _ACCESOINDEBIDO_H
#define _ACCESOINDEBIDO_H


#include <iostream>


class EAccesoIndebido{
public:
    EAccesoIndebido(std::string mensaje="");
	const std::string mensaje() const;
private:
    std::string _mensaje;
};

#endif
