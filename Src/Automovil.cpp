#include "../include/Automovil.h"
#include <cctype>
#include <algorithm>

using namespace std;

Automovil::Automovil(const string& placa, double horas) 
    : Vehiculo(placa, horas) {}

double Automovil::calcularTarifaBase() const { return 10.0; }
double Automovil::calcularTarifaExtra() const { return calcularTarifaBase() * 1.05; }

bool Automovil::validarPlaca(const string& placa) const {
    return placa.length() == 6 && 
           all_of(placa.begin(), placa.end(), [](char c) { 
               return isalnum(c); 
           });
}

int Automovil::getTipo() const { return 1; }