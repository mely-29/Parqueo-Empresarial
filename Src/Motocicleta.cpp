#include "../include/Motocicleta.h"
#include <cctype>
#include <algorithm>

using namespace std;
Motocicleta::Motocicleta(const string& placa, double horas)
    : Vehiculo(placa, horas) {}

double Motocicleta::calcularTarifaBase() const {
    return 5.0;  // Tarifa base más baja para motos
}

double Motocicleta::calcularTarifaExtra() const {
    return (horas > 3) ? (horas - 3) * 1.0 : 0.0;
}

double Motocicleta::getHorasPlanificadas() const {
    return horas;
}

bool Motocicleta::validarPlaca(const string& placa) const {
    return placa.length() == 5 && all_of(placa.begin(), placa.end(), [](char c) {
        return isalnum(c);  // letras y números
    });
}

int Motocicleta::getTipo() const {
    return 2;  // Tipo 2 para motocicletas
}

