#include <iostream>
#include <fstream>
#include <ctime>
#include "Red.h"
using namespace std;

void mostrarMenu() {
    cout << "\n===== Gestión de Red de Estaciones de Gasolina =====" << endl;
    cout << "1. Mostrar estaciones de una red" << endl;
    cout << "2. Agregar una nueva estación a una red" << endl;
    cout << "3. Eliminar una estación de una red" << endl;
    cout << "4. Registrar una venta en una estación" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void seleccionarRed(Red*& red, Red& norte, Red& centro, Red& sur) {
    int opcionRed;
    cout << "Seleccione la red (1: Norte, 2: Centro, 3: Sur): ";
    cin >> opcionRed;

    switch (opcionRed) {
    case 1:
        red = &norte;
        break;
    case 2:
        red = &centro;
        break;
    case 3:
        red = &sur;
        break;
    default:
        cout << "Opción inválida. Seleccionando red Norte por defecto." << endl;
        red = &norte;
        break;
    }
}

int main() {
    Red redNorte("norte.txt");
    Red redCentro("centro.txt");
    Red redSur("sur.txt");

    redNorte.cargarDesdeArchivo();
    redCentro.cargarDesdeArchivo();
    redSur.cargarDesdeArchivo();

    Red* redSeleccionada = nullptr;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            redSeleccionada->mostrarEstaciones();
            break;
        }
        case 2: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            string nombreEstacion;
            cout << "Ingrese el nombre de la nueva estación: ";
            cin.ignore();
            getline(cin, nombreEstacion);
            Estacion nuevaEstacion(nombreEstacion);
            redSeleccionada->agregarEstacion(nuevaEstacion);
            break;
        }
        case 3: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            int indiceEstacion;
            cout << "Ingrese el índice de la estación a eliminar (1 a "
                 << redSeleccionada->getNumEstaciones() << "): ";
            cin >> indiceEstacion;
            redSeleccionada->eliminarEstacion(indiceEstacion - 1);
            break;
        }
        case 4: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            int indiceEstacion;
            double cantidad;
            string tipoGasolina;
            cout << "Ingrese el índice de la estación (1 a "
                 << redSeleccionada->getNumEstaciones() << "): ";
            cin >> indiceEstacion;
            cout << "Ingrese la cantidad de gasolina vendida: ";
            cin >> cantidad;
            cout << "Ingrese el tipo de gasolina (Regular, Premium, Diesel): ";
            cin >> tipoGasolina;
            redSeleccionada->registrarVentaEnEstacion(indiceEstacion - 1, cantidad, tipoGasolina);
            break;
        }
        case 5:
            cout << "Saliendo del programa. ¡Gracias!" << endl;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
