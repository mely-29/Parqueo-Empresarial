#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <vector>
#include <memory>
#include <string>
#include "Vehiculo.h"

using namespace std;

class GestorDatos {
public:
    static void guardarDatos(const vector<unique_ptr<Vehiculo>>& vehiculos, const string& filename);
    static vector<unique_ptr<Vehiculo>> cargarDatos(const string& filename);
};

#endif

