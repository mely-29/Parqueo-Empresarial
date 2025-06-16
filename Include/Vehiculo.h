#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <memory>

using namespace std;

class Vehiculo {
protected:
    string placa;
    double horasPlanificadas;
    
public:
    Vehiculo(const string& placa, double horas);
    virtual ~Vehiculo() = default;
    
    string getPlaca() const;
    double getHorasPlanificadas() const;
    
    virtual double calcularTarifaBase() const = 0;
    virtual double calcularTarifaExtra() const = 0;
    virtual bool validarPlaca(const string& placa) const = 0;
    virtual int getTipo() const = 0;
    
    double calcularPrecioPlanificado() const {
        return calcularTarifaBase() * horasPlanificadas;
    }
};

#endif