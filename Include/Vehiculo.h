#endif
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <memory>
using namespace std;
class Vehiculo {
protected:
    string placa;
    double horas;

public:
    Vehiculo(const string& placa, double horas) : placa(placa), horas(horas) {}

    virtual double calcularTarifaBase() const = 0;
    virtual double calcularTarifaExtra() const = 0;
    virtual double getHorasPlanificadas() const = 0;
    virtual bool validarPlaca(const string& placa) const = 0;
    virtual int getTipo() const = 0;

    string getPlaca() const { return placa; }
    double getHoras() const { return horas; }

    virtual ~Vehiculo() {}
};

#endif




