#ifndef OPERACIONSUMA_H
#define OPERACIONSUMA_H

#include "operacion.h"
#include "proveedorFormato.h"

class OperacionSuma :public Operacion {

	ProveedorFormato* proveedorFormato;

	public:
	OperacionSuma();

	virtual string Ejecute(string valor);


};



#endif
