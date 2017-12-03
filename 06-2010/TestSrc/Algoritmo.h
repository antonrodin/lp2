#ifndef AlgoritmoH
#define AlgoritmoH

#include <iostream>

class CAlgoritmo {
public:
	virtual ~CAlgoritmo() {}
	virtual std::string getDescription ()=0; //El =0 es un virtual puto, estara implementado despues en las clases fijas
	virtual void SetUp (int N)=0;
	virtual void Execute ()=0;
	virtual void TearDown ()=0;

private:
};

#endif
