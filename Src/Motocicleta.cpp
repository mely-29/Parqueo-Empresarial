#include "../include/Motocicleta.h"
#include <cctype>
#include <algorithm>

using namespace std;

Motocicleta::Motocicleta(const string& placa, double horas) 
    : Vehiculo(placa, horas) {}

double Motocicleta::calcularTarifaBase() const { return 5.0; }
double Motocicleta::calcularTarifaExtra() const { return calcularTarifaBase() * 1.05; }

bool Motocicleta::validarPlaca(const string& placa) const {
    return placa.length() == 4 && 
           all_of(placa.begin(), placa.end(), [](char c) { 
               return isalnum(c); 
           });
}

int Motocicleta::getTipo() const { return 2; }