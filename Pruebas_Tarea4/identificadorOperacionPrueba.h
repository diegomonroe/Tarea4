#ifndef IdentificadorOperacionPrueba_H
#define IdentificadorOperacionPrueba_H

#include "../Tarea4_B64531/identificadorOperacionesBase.h"
#include "../Tarea4_B64531/operacion.h"

class IdentificadorOperacionPrueba : public IdentificadorOperacionesBase {

    Operacion *operacionPrueba;

    public:
    IdentificadorOperacionPrueba(Operacion *operacionPrueba) {
        this->operacionPrueba = operacionPrueba;
    }

    virtual Operacion *Identifique(string operacion) {
        return this->operacionPrueba;
    }

};

#endif