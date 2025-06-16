#include "../include/GestorDatos.h"
#include "../include/Camion.h"
#include "../include/Automovil.h"
#include "../include/Motocicleta.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

using namespace std;

void GestorDatos::guardarDatos(const vector<unique_ptr<Vehiculo>>& vehiculos, const string& filename) {
    filesystem::path ruta = filesystem::path(filename).parent_path();
    if(!filesystem::exists(ruta)) {
        filesystem::create_directories(ruta);
    }

    ofstream archivo(filename);
    if(!archivo) {
        cerr << "Error: No se pudo abrir el archivo " << filename << " para escritura." << endl;
        return;
    }
    
    for(const auto& veh : vehiculos) {
        archivo << veh->getPlaca() << "," 
                << veh->getTipo() << "," 
                << veh->getHorasPlanificadas() << "\n";
    }

    archivo.close();
    cout << "Datos guardados en " << filename << endl;
}

vector<unique_ptr<Vehiculo>> GestorDatos::cargarDatos(const string& filename) {
    vector<unique_ptr<Vehiculo>> vehiculos;
    ifstream archivo(filename);
    string linea;

    if(archivo.is_open()) {
        while(getline(archivo, linea)) {
            istringstream ss(linea);
            string placa;
            int tipoInt;
            double horas;

            getline(ss, placa, ',');
            ss >> tipoInt;
            ss.ignore();
            ss >> horas;

            switch(tipoInt) {
                case 0: vehiculos.push_back(make_unique<Camion>(placa, horas)); break;
                case 1: vehiculos.push_back(make_unique<Automovil>(placa, horas)); break;
                case 2: vehiculos.push_back(make_unique<Motocicleta>(placa, horas)); break;
            }
        }
        archivo.close();
        cout << "Datos cargados desde " << filename << endl;
    } else {
        cerr << "No se pudo cargar el fichero." << endl;
    }
    return vehiculos;
}