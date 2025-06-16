#include <iostream>
#include <vector>
#include <memory>
#include "include/Automovil.h"
#include "include/Camion.h"
#include "include/Motocicleta.h"
#include "include/GestorDatos.h"

using namespace std;

int main() {
    vector<unique_ptr<Vehiculo>> parqueo;

    // Agregamos vehículos usando herencia
    parqueo.push_back(make_unique<Automovil>("ABC123", 3.5));
    parqueo.push_back(make_unique<Camion>("TRK9000", 6.5));
    parqueo.push_back(make_unique<Motocicleta>("M1234", 4.5));

    cout << "--- VEHÍCULOS REGISTRADOS ---\n";
    for (const auto& vehiculo : parqueo) {
        cout << "Tipo: " << vehiculo->getTipo()
             << " | Placa: " << vehiculo->getPlaca();

        if (vehiculo->validarPlaca(vehiculo->getPlaca())) {
            double total = vehiculo->calcularTarifaBase() + vehiculo->calcularTarifaExtra();
            cout << " | Tarifa total: $" << total << endl;
        } else {
            cout << " | Placa inválida\n";
        }
    }

    // Guardar datos
    GestorDatos::guardarDatos(parqueo, "datos/vehiculos.txt");

    // Cargar datos
    auto cargados = GestorDatos::cargarDatos("datos/vehiculos.txt");

    cout << "\n--- VEHÍCULOS CARGADOS DESDE ARCHIVO ---\n";
    for (const auto& v : cargados) {
        cout << "Tipo: " << v->getTipo()
             << " | Placa: " << v->getPlaca();

        if (v->validarPlaca(v->getPlaca())) {
            double total = v->calcularTarifaBase() + v->calcularTarifaExtra();
            cout << " | Tarifa total: $" << total << endl;
        } else {
            cout << " | Placa inválida\n";
        }
    }

    return 0;
}

