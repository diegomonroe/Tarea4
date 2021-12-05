#include "operacionSuma.h"
#include "ExcepcionOperacionSumaDatosIncorrectos.h"

#include <string>
#include <sstream>


OperacionSuma::OperacionSuma() {
}

string OperacionSuma::Ejecute(string entrada) {
    string valor{};
    int primerValor{};
    int segundoValor{};
    char signo{};

	istringstream streamNumeros(entrada);
    streamNumeros >> primerValor >> signo >> segundoValor;

    if (signo != '+') {
        throw ExcepcionOperacionSumaDatosIncorrectos();
    }

    int resultadoOperacion = primerValor + segundoValor;
    valor = to_string(resultadoOperacion);
	
    return valor;
}