#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../Tarea4_B64531/proveedorFormatoDesdeStream.h"
#include "../Tarea4_B64531/proveedorFormatoDesdeStream.cpp"

using namespace std;

namespace {
    TEST(ProveedorFormatoDesdeStream_Test, TestObtenerFormato) {
        /// AAA

        // Arrange - configurar el escenario
        string esperado = "Hola ";
        std::istringstream stream(esperado); 

        // Act - ejecute la operación
        ProveedorFormatoDesdeStream *proveedorFormatoArchivoStream = new ProveedorFormatoDesdeStream(&stream);
        string actual = proveedorFormatoArchivoStream->ObtenerFormato();
        delete proveedorFormatoArchivoStream;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }
}