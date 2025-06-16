#include "../include/GestorDatos.h"
#include "../include/Camion.h"
#include "../include/Automovil.h"
#include "../include/Motocicleta.h"
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;

void GestorDatos::guardarDatos(const vector<unique_ptr<Vehiculo>>& vehiculos, const string& filename) {
    filesystem::path ruta = filesystem::path(filename).parent_path();
    if (!filesystem::exists(ruta)) {
        filesystem::create_directories(ruta);
    }

    ofstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << " para escritura." << endl;
        return;
    }

    for (const auto& v : vehiculos) {
        file << v->getTipo() << " "
             << v->getPlaca() << " "
             << v->getHorasPlanificadas() << "\n";
    }

    file.close();
    cout << "Datos guardados en " << filename << endl;
}

vector<unique_ptr<Vehiculo>> GestorDatos::cargarDatos(const string& filename) {
    vector<unique_ptr<Vehiculo>> vehiculos;
    ifstream file(filename);
    int tipo;
    string placa;
    double horas;

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << filename << " para lectura." << endl;
        return vehiculos;
    }

    while (file >> tipo >> placa >> horas) {
        switch (tipo) {
            case 0: vehiculos.push_back(make_unique<Camion>(placa, horas)); break;
            case 1: vehiculos.push_back(make_unique<Automovil>(placa, horas)); break;
            case 2: vehiculos.push_back(make_unique<Motocicleta>(placa, horas)); break;
        }
    }

    file.close();
    cout << "Datos cargados desde " << filename << endl;
    return vehiculos;
}

