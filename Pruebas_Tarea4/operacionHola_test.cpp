#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include "../Tarea4_B64531/operacionHola.h"
#include "../Tarea4_B64531/operacionHola.cpp"
#include "proveedorFormatoPrueba.h"

using namespace std;

namespace {
    TEST(OperacionHola_Test, Test_Formato_Aplicado) {

        ProveedorFormatoPrueba *proveedorFormato = new ProveedorFormatoPrueba("Hola a ");
        OperacionHola *operacionHola = new OperacionHola(proveedorFormato);

        string actual = operacionHola->Ejecute("todos!!!");
        string esperado = "Hola a todos!!!";

        EXPECT_EQ(esperado, actual);
    }
}