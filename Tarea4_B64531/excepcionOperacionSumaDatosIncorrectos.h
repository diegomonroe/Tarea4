#ifndef ExcepcionOperacionSumaDatosIncorrectos_H
#define ExcepcionOperacionSumaDatosIncorrectos_H

#include <exception>

class ExcepcionOperacionSumaDatosIncorrectos : public std::exception
{
    public:
    ExcepcionOperacionSumaDatosIncorrectos() noexcept = default;
    ~ExcepcionOperacionSumaDatosIncorrectos() = default;

    virtual const char* what() const noexcept {
        return "OperaciónSuma no se puede realizar con los datos suminstrados";
    }

};

#endif