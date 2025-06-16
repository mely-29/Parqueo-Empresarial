#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"


using namespace std;

class Camion : public Vehiculo {
public:
    Camion(const string& placa, double horas);
    double calcularTarifaBase() const override;
    double calcularTarifaExtra() const override;
    bool validarPlaca(const string& placa) const override;
    int getTipo() const override;
};

#endif