#include "../include/Parqueo.h"
#include "../include/Camion.h"
#include "../include/Automovil.h"
#include "../include/Motocicleta.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

Parqueo::Parqueo() : ingresos(0), totalVallas(10), ingresoExtra(0) {}

void Parqueo::insertarVehiculo(unique_ptr<Vehiculo> vehiculo) {
    vehiculos.push_back(move(vehiculo));
}

pair<double, int> Parqueo::devolverVehiculo(const string& placa) {
    auto it = find_if(vehiculos.begin(), vehiculos.end(), [&placa](const unique_ptr<Vehiculo>& v) {
        return v->getPlaca() == placa;
    });

    if (it != vehiculos.end()) {
        double precio = (*it)->calcularPrecioPlanificado();
        int tipo = (*it)->getTipo();
        ingresos += precio;
        vehiculos.erase(it);
        return {precio, tipo};
    }
    return {-1, -1};
}

void Parqueo::agregarIngresoExtra(double monto) {
    ingresoExtra += monto;
}

void Parqueo::listarVehiculos() const {
    if (vehiculos.empty()) {
        cout << "No hay veh\xA1"<<"culos en el parqueo.\n";
        return;
    }
    
    for (const auto& veh : vehiculos) {
        cout << "Placa: " << veh->getPlaca()
             << ", Tipo: " << (veh->getTipo() == 0 ? "Cami\xA2n" :
                              veh->getTipo() == 1 ? "Autom\xA2vil" : "Motocicleta")
             << ", Horas: " << veh->getHorasPlanificadas() << endl;
    }
}

void Parqueo::mostrarIngresos() const {
    cout << fixed << setprecision(2);
    cout << "\nIngresos Principales: " << ingresos << " CUP\n";
    cout << "Ingresos Extra: " << ingresoExtra << " CUP\n";
    cout << "Ingresos Totales: " << calcularIngresosTotales() << " CUP\n";
}

void Parqueo::mostrarVallasDisponibles() const {
    int disponibles = totalVallas - vehiculos.size();
    cout << "\nVallas disponibles: " << disponibles << "/" << totalVallas << endl;
}

vector<unique_ptr<Vehiculo>> Parqueo::guardarVehiculos() const {
    vector<unique_ptr<Vehiculo>> copia;
    for (const auto& veh : vehiculos) {
        switch (veh->getTipo()) {
            case 0: copia.push_back(make_unique<Camion>(veh->getPlaca(), veh->getHorasPlanificadas())); break;
            case 1: copia.push_back(make_unique<Automovil>(veh->getPlaca(), veh->getHorasPlanificadas())); break;
            case 2: copia.push_back(make_unique<Motocicleta>(veh->getPlaca(), veh->getHorasPlanificadas())); break;
        }
    }
    return copia;
}