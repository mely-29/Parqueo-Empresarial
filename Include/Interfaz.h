#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Parqueo.h"

using namespace std;

class Interfaz {
private:
    Parqueo parqueo;
    double ingresoExtra;
public:
    void mostrarMenu();
};

#endif