#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include "../Tarea4_B64531/operacionSuma.h"
#include "../Tarea4_B64531/operacionSuma.cpp"
#include "proveedorFormatoPrueba.h"

using namespace std;

namespace {
    TEST(OperacionSuma_Test, Test_Resultado) {

        OperacionSuma* operacionSuma = new OperacionSuma();

        string actual = operacionSuma->Ejecute("5+2");
        string esperado = "7";

        EXPECT_EQ(esperado, actual);
    }

    TEST(OperacionSuma_Test, Test_Datos_Erroneos)
    {
        OperacionSuma* operacionSuma = new OperacionSuma();

        EXPECT_THROW({
            string actual = operacionSuma->Ejecute("5-2");
            }, ExcepcionOperacionSumaDatosIncorrectos);
    }
}