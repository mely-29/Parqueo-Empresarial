#include "../include/Automovil.h"
#include <cctype>
#include <cctype>
#include <algorithm>
Automovil::Automovil(const string& placa, double horas)
    : Vehiculo(placa, horas) {}

double Automovil::calcularTarifaBase() const { return 10.0; }

double Automovil::calcularTarifaExtra() const { return horas > 2 ? (horas - 2) * 1.5 : 0.0; }

bool Automovil::validarPlaca(const string& placa) const {
    return placa.length() == 6 && all_of(placa.begin(), placa.end(), [](char c) {
        return isalnum(c);
    });
}

int Automovil::getTipo() const { return 1; }

