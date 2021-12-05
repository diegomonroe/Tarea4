#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include "../Tarea4_B64531/procesador.h"
#include "../Tarea4_B64531/procesadorInstrucciones.h"
#include "../Tarea4_B64531/procesadorInstrucciones.cpp"
#include "identificadorOperacionPrueba.h"
#include "operacionPrueba.h"

using namespace std;

namespace {
    TEST(ProcesadorInstrucciones_Test, TestInicial) {
        /// AAA

        // Arrange - configurar el escenario
        string instruccion { "instruccionPrueba" };
        string valor { "valorPrueba" };
        Operacion *operacion = new OperacionPrueba();

        IdentificadorOperacionesBase *identificador = new IdentificadorOperacionPrueba(operacion);

        // Act - ejecute la operación
        ProcesadorInstrucciones *procesadorPrueba = new ProcesadorInstrucciones(identificador);
        string actual = procesadorPrueba->Procese(instruccion, valor);
        delete procesadorPrueba;

        // Assert - valide los resultados
        EXPECT_NE("", actual);
    }
}