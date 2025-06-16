#endif
#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

using namespace std;

#include "Vehiculo.h"

class Automovil : public Vehiculo {
public:
    Automovil(const string& placa, double horas);

    double calcularTarifaBase() const override;
    double calcularTarifaExtra() const override;
    double getHorasPlanificadas() const override { return horas; }
    bool validarPlaca(const string& placa) const override;
    int getTipo() const override;
};

#endif


