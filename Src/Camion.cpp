#include "../include/Camion.h"
#include "../include/Vehiculo.h"
#include <algorithm>
#include <cctype>

using namespace std;
Camion::Camion(const string& placa, double horas)
    : Vehiculo(placa, horas) {}

double Camion::calcularTarifaBase() const { return 20.0; }// Supón tarifa base más alta
}

double Camion::calcularTarifaExtra() const { return horas > 5 ? (horas - 5) * 3.0 : 0.0; }

bool Camion::validarPlaca(const string& placa) const {
     // Ejemplo: validación de 7 caracteres alfanuméricos
    return placa.length() == 7 && all_of(placa.begin(), placa.end(), [](char c) {
        return isalnum(c);
    });
}

int Camion::getTipo() const { return 2; }// Por ejemplo: tipo 2 representa camiones
}
