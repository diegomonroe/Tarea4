#ifndef OPERACIONPRUEBA_H
#define OPERACIONPRUEBA_H

#include "../Tarea4_B64531/operacion.h"
#include <string>

using namespace std;

class OperacionPrueba : public Operacion {

    public:
    virtual string Ejecute(string valor) {
        return "Prueba " + valor;
    }

};

#endif