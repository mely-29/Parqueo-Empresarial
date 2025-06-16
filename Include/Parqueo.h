#ifndef PARQUEO_H
#define PARQUEO_H

#include <vector>
#include <memory>
#include "Vehiculo.h"

using namespace std;

class Parqueo {
private:
    vector<unique_ptr<Vehiculo>> vehiculos;
    double ingresos;
    const int totalVallas;
    double ingresoExtra;
    
public:
    Parqueo();
    void insertarVehiculo(unique_ptr<Vehiculo> vehiculo);
    pair<double, int> devolverVehiculo(const string& placa);
    void listarVehiculos() const;
    void mostrarIngresos() const;
    void mostrarVallasDisponibles() const;
    vector<unique_ptr<Vehiculo>> guardarVehiculos() const;
    void agregarIngresoExtra(double monto);
    
    double calcularIngresosTotales() const {
        return ingresos + ingresoExtra;
    }
};

#endif