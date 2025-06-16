#include "../include/Interfaz.h"
#include "../include/GestorDatos.h"
#include "../include/Camion.h"
#include "../include/Automovil.h"
#include "../include/Motocicleta.h"
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interfaz::mostrarMenu() {
    int opcion = 0;

    // Cargar datos al inicio
    auto vehiculosCargados = GestorDatos::cargarDatos("./data/registro.txt");
    for (auto& vehiculo : vehiculosCargados) {
        parqueo.insertarVehiculo(move(vehiculo));
    }

    do {
        system("cls || clear");
        cout << "========================================\n";
        cout << "      PARQUEO EMPRESARIAL - MEN\xE9 \n";
        cout << "========================================\n";
        cout << "1. Insertar Veh\xA1"<<"culo\n";
        cout << "2. Devolver  Veh\xA1"<<"culo\n";
        cout << "3. Mostrar vallas disponibles\n";
        cout << "4. Listar  Veh\xA1"<<"culos\n";
        cout << "5. Mostrar ingresos\n";
        cout << "6. Salir\n";
        cout << "========================================\n";
        cout << "Seleccione una opci\xA2n: ";
        
        if (!(cin >> opcion)) {
            limpiarBuffer();
            cout << "Entrada inv\xA0lida. Intente de nuevo.\n";
            system("pause");
            continue;
        }

        switch (opcion) {
            case 1: {
                string placa;
                int tipoInt;
                double horas;

                cout << "\nTipo de veh\xA1"<<"culo (0-Cami\xA2n, 1-Autom\xA2vil, 2-Motocicleta): ";
                if (!(cin >> tipoInt) || tipoInt < 0 || tipoInt > 2) {
                    cout << "Tipo inv\xA0lido.\n";
                    limpiarBuffer();
                    break;
                }

                cout << "Placa: ";
                cin >> placa;
                cout << "Horas: ";
                if (!(cin >> horas) || horas < 0) {
                    cout << "Horas inv\xA0lidas.\n";
                    limpiarBuffer();
                    break;
                }

                unique_ptr<Vehiculo> vehiculo;
                switch (tipoInt) {
                    case 0: vehiculo = make_unique<Camion>(placa, horas); break;
                    case 1: vehiculo = make_unique<Automovil>(placa, horas); break;
                    case 2: vehiculo = make_unique<Motocicleta>(placa, horas); break;
                }

                if (vehiculo->validarPlaca(placa)) {
                    parqueo.insertarVehiculo(move(vehiculo));
                    cout << "Veh\xA1"<<"culo registrado.\n";
                } else {
                    cout << "Placa inv\xA0lida para este tipo.\n";
                }
                break;
            }

            case 2: {
                string placa;
                cout << "Placa del veh\xA1"<<"culo a devolver: ";
                cin >> placa;

                auto resultado = parqueo.devolverVehiculo(placa);
                if (resultado.first == -1) {
                    cout << "Veh\xA1"<<"culo no encontrado.\n";
                    break;
                }

                double tarifaExtra = 0.0;
                switch (resultado.second) {
                    case 0: tarifaExtra = Camion("", 0).calcularTarifaExtra(); break;
                    case 1: tarifaExtra = Automovil("", 0).calcularTarifaExtra(); break;
                    case 2: tarifaExtra = Motocicleta("", 0).calcularTarifaExtra(); break;
                }

                cout << "Horas excedidas: ";
                double horasExcedidas;
                if (!(cin >> horasExcedidas)) {
                    cout << "Valor inv\xA0lido. Se asumen 0 horas.\n";
                    limpiarBuffer();
                    horasExcedidas = 0;
                }

                double costoExtra = horasExcedidas * tarifaExtra;
                parqueo.agregarIngresoExtra(costoExtra);
                double total = resultado.first + costoExtra;
                cout << "Total a pagar: " << total << " CUP\n";
                break;
            }

            case 3:
                parqueo.mostrarVallasDisponibles();
                break;

            case 4:
                parqueo.listarVehiculos();
                break;

            case 5:
                parqueo.mostrarIngresos();
                break;

            case 6:
                GestorDatos::guardarDatos(parqueo.guardarVehiculos(), "./data/registro.txt");
                cout << "Datos guardados. Saliendo...\n";
                break;

            default:
                cout << "Opción inv\xA0lida.\n";
                break;
        }

        system("pause");
    } while (opcion != 6);
}