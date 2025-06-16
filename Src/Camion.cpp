#include "../include/Camion.h"
#include "../include/Vehiculo.h"
#include <algorithm>
#include <cctype>

using namespace std;

Camion::Camion(const string& placa, double horas) 
    : Vehiculo(placa, horas) {}

double Camion::calcularTarifaBase() const { return 20.0; }
double Camion::calcularTarifaExtra() const { return calcularTarifaBase() * 1.05; }

bool Camion::validarPlaca(const string& placa) const {
    return placa.length() == 6 && 
           all_of(placa.begin(), placa.end(), [](char c) { 
               return isalnum(c); 
           });
}

int Camion::getTipo() const { return 0; }