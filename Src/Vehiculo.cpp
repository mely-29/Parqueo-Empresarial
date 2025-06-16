#include "../include/Vehiculo.h"

using namespace std;

Vehiculo::Vehiculo(const string& placa, double horas) 
    : placa(placa), horasPlanificadas(horas) {}

string Vehiculo::getPlaca() const { return placa; }
double Vehiculo::getHorasPlanificadas() const { return horasPlanificadas; }