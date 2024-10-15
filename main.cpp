#include <iostream>
#include <ctime>
#include "Red.h"
using namespace std;

void borr() {
    for (int i = 0; i < 10; i++) {
        cout << endl;
    }
}


string seleccion_metodo_pago() {
    string seleccion;
    cout << "Seleccione el metodo de pago:" << endl;
    cout << "1) Efectivo  2) T.Credito  3) T.Debito" << endl;
    cin >> seleccion;

    // Validar la selección del método de pago
    while (seleccion != "1" && seleccion != "2" && seleccion != "3") {
        cout << "Método de pago no válido. Por favor, seleccione uno de los disponibles." << endl;
        cout << "1) Efectivo  2) T.Credito  3) T.Debito" << endl;
        cin >> seleccion;
    }

    // Retornar el método de pago correspondiente
    if (seleccion == "1") return "Efectivo";
    if (seleccion == "2") return "T.Credito";
    return "T.Debito";
}

string seleccion_tipo_gasolina() {
    string seleccion;
    cout << "Seleccione el tipo de gasolina:" << endl;
    cout << "1) Regular  2) Premium  3) EcoExtra" << endl;
    cin >> seleccion;

    // Validar la selección del tipo de gasolina
    while (seleccion != "1" && seleccion != "2" && seleccion != "3") {
        cout << "Tipo de gasolina no válido. Por favor, seleccione uno de los disponibles." << endl;
        cout << "1) Regular  2) Premium  3) EcoExtra" << endl;
        cin >> seleccion;
    }

    // Retornar el tipo de gasolina correspondiente
    if (seleccion == "1") return "Regular";
    if (seleccion == "2") return "Premium";
    return "EcoExtra";
}



void mostrarMenu() {
    cout << "\n===== Gestion de Red de Estaciones de Gasolina =====" << endl;
    cout << "1. Mostrar estaciones de una red" << endl;
    cout << "2. Agregar una nueva estacion a una red" << endl;
    cout << "3. Eliminar una estacion de una red" << endl;
    cout << "4. Registrar una venta en una estacion" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
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
        cout << "Opcion invalida. Seleccionando red Norte por defecto." << endl;
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
            borr();
            cout << "\nEstaciones en la Red Norte:\n";
            redNorte.mostrarEstaciones();
            cout << "\nEstaciones en la Red Centro:\n";
            redCentro.mostrarEstaciones();
            cout << "\nEstaciones en la Red Sur:\n";
            redSur.mostrarEstaciones();
            break;
        }
        case 2: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            int numero;
            string nombreEstacion;
            double precioRegular, precioPremium, precioDiesel;

            cout << "Ingrese el identificador de la estacion: ";
            cin >> numero;
            cout << "Ingrese el nombre de la nueva estacion: ";
            cin.ignore();
            getline(cin, nombreEstacion);
            cout << "Ingrese el precio de la gasolina Regular: ";
            cin >> precioRegular;
            cout << "Ingrese el precio de la gasolina Premium: ";
            cin >> precioPremium;
            cout << "Ingrese el precio de la gasolina Diesel: ";
            cin >> precioDiesel;

            Estacion nuevaEstacion(numero, nombreEstacion, redSeleccionada->getNombreArchivo(), precioRegular, precioPremium, precioDiesel);
            redSeleccionada->agregarEstacion(nuevaEstacion);
            break;
        }

        case 3: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            redSeleccionada->mostrarEstacionesConId();
            int idEstacion;
            cout << "Ingrese el ID de la estacion a eliminar: ";
            cin >> idEstacion;

            redSeleccionada->eliminarEstacionPorId(idEstacion);
            break;
        }

        case 4: {
            seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
            int indiceEstacion;
            double cantidad;
            string tipoGasolina;
            string metodoPago;

            // Verificar que haya al menos una estación en la red seleccionada
            if (redSeleccionada->getNumEstaciones() == 0) {
                cout << "No hay estaciones registradas en esta red." << endl;
                break;
            }

            // Seleccionar la estación por índice
            cout << "Ingrese el indice de la estación (1 a "
                 << redSeleccionada->getNumEstaciones() << "): ";
            cin >> indiceEstacion;

            // Validar el índice de la estación
            if (indiceEstacion < 1 || indiceEstacion > redSeleccionada->getNumEstaciones()) {
                cout << "Índice de estación inválido. Por favor, ingrese un número entre 1 y "
                     << redSeleccionada->getNumEstaciones() << "." << endl;
                break;
            }

            // Ingresar la cantidad de gasolina
            cout << "Ingrese la cantidad de gasolina vendida: ";
            cin >> cantidad;

            // Validar la cantidad de gasolina
            if (cantidad <= 0) {
                cout << "Cantidad de gasolina no válida. Debe ser mayor a 0." << endl;
                break;
            }

            // Seleccionar el tipo de gasolina usando la función
            tipoGasolina = seleccion_tipo_gasolina();

            // Seleccionar el método de pago usando la función
            metodoPago = seleccion_metodo_pago();

            // Registrar la venta en la estación seleccionada
            redSeleccionada->registrarVentaEnEstacion(indiceEstacion - 1, cantidad, tipoGasolina, metodoPago);
            break;
        }

        case 5:
            cout << "Saliendo del programa. Gracias!" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

