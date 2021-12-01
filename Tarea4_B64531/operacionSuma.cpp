#include "operacionSuma.h"
#include <string>
#include <sstream>

OperacionSuma::OperacionSuma() {
}

string OperacionSuma::Ejecute(string entrada) {
 
    int primerValor = 0;
    int segundoValor = 0;
    char signo = ' ';
    
    istringstream streamNumeros(entrada);
    streamNumeros >> primerValor >> signo >> segundoValor;
    
    int resultadoOperacion = primerValor + segundoValor;
    string valor = to_string(resultadoOperacion);
    return valor;
}