#ifndef UNIT_TEST

#include "procesadorInstrucciones.h"
#include "identificadorOperaciones.h"
#include "operacionHola.h"
#include "operacionSuma.h"

#include <iostream>
#include <string>
#include <fstream>

#include "proveedorFormato.h"
#include "proveedorFormatoDesdeStream.h"
#include "excepcionOperacionSumaDatosIncorrectos.h"

using namespace std;

int main() {

    try {
        // Inicialización
        // Configuración de la inyección de dependencias
        map<string, Operacion *> operaciones {};

        std::ifstream proveedorFormatoEspanol("formatoHola.ini", std::ifstream::in);

        if (!proveedorFormatoEspanol.is_open())
        {
            std::cerr << "Error leyendo archivo formatoHola.ini" << std::endl;
            return -1;
        }
        
        std::ifstream proveedorFormatoIngles("formatoHello.ini", std::ifstream::in);

        if (!proveedorFormatoIngles.is_open())
        {
            std::cerr << "Error leyendo archivo formatoHello.ini" << std::endl;
            return -1;
        }
        
        ProveedorFormato *proveedorFormatoHola = new ProveedorFormatoDesdeStream(&proveedorFormatoEspanol);
        ProveedorFormato *proveedorFormatoHello = new ProveedorFormatoDesdeStream(&proveedorFormatoIngles);

        OperacionHola *operacionHola = new OperacionHola(proveedorFormatoHola);
        operaciones.insert(std::pair<string, Operacion *>("hola", operacionHola));
        
        OperacionHola *operacionHello = new OperacionHola(proveedorFormatoHello);
        operaciones.insert(std::pair<string, Operacion *>("hello", operacionHello));
        
        OperacionSuma *operacionSuma = new OperacionSuma();
        operaciones.insert(std::pair<string, Operacion*>("suma", operacionSuma));

        IdentificadorOperacionesBase *identificadorOperaciones = new IdentificadorOperaciones(operaciones);
        // Fin de inicialización 
        
        ProcesadorInstrucciones *procesador = new ProcesadorInstrucciones(identificadorOperaciones);
        
        string resultadoHola = procesador->Procese("hola", "todos");
        cout << "Resultado saludo en español: " << resultadoHola << endl;


        string resultadoSuma = procesador->Procese("suma", " 0+ 5");
        cout << "Resultado suma: " << resultadoSuma << endl;

        string resultadoHello = procesador->Procese("hello", "everyone");
        cout << "Resultado saludo en ingles: " << resultadoHello << endl;

        //Destruir punteros
        delete procesador;
        delete identificadorOperaciones;
        delete operacionSuma;
        delete operacionHello;
        delete operacionHola;
        delete proveedorFormatoHello;
        delete proveedorFormatoHola;

        // Cerrar archivo de entrada
        proveedorFormatoEspanol.close();
        proveedorFormatoIngles.close();

    } catch (char const* exception)
    {
        cerr << "Error: " << exception << endl;
    }catch (const ExcepcionOperacionSumaDatosIncorrectos& exception)
    {
        cerr << exception.what() << endl;
    }
    
    return 0;
}

#endif