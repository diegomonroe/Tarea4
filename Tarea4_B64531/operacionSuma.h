#ifndef OPERACIONSUMA_H
#define OPERACIONSUMA_H

#include "operacion.h"

class OperacionSuma :public Operacion {

	public:
	OperacionSuma();

	virtual string Ejecute(string valor);


};



#endif
