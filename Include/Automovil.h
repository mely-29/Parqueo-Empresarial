#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Vehiculo.h"

using namespace std;

class Automovil : public Vehiculo {
public:
    Automovil(const string& placa, double horas);
    double calcularTarifaBase() const override;
    double calcularTarifaExtra() const override;
    bool validarPlaca(const string& placa) const override;
    int getTipo() const override;
};

#endif