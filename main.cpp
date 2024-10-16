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
        cout << "Metodo de pago no valido. Por favor, seleccione uno de los disponibles." << endl;
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
        cout << "Tipo de gasolina no valido. Por favor, seleccione uno de los disponibles." << endl;
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
    cout << "5. Salir "<<endl;
    cout << "Seleccione una opcion: ";
}

void seleccionarRed(Red*& red, Red& norte, Red& centro, Red& sur) {
    string seleccion;
    int opcionRed;

    cout << "Seleccione la red (1: Norte, 2: Centro, 3: Sur): ";
    cin >> seleccion;
    while (seleccion != "1" && seleccion != "2"&& seleccion != "3"){

        cout << " Debes seleccionar una opcion valida "<<endl;
        cout << "Seleccione la red (1: Norte, 2: Centro, 3: Sur): ";
        cin >> seleccion;
    }

    if(seleccion == "1"){
        opcionRed = 1;
    }
    if(seleccion == "2"){
        opcionRed = 2;
    }
    if(seleccion == "3"){
        opcionRed = 3;
    }
    // Asignar la red seleccionada
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

        while (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n'); // Limpiar la entrada no válida
            cout << "Opción invalida. Ingrese un numero: ";
            cin >> opcion;
        }

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
            try {
                seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
                int numero;
                string nombreEstacion;
                double precioRegular, precioPremium, precioEcoExtra;

                cout << "Ingrese el identificador de la estacion: ";
                cin >> numero;
                while (cin.fail()) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Entrada invalida. Debe ingresar un numero para el identificador." << endl;
                    cout << "Ingrese el identificador de la estacion: ";
                    cin >> numero;
                }

                cout << "Ingrese el nombre de la estacion: ";
                cin.ignore();
                getline(cin, nombreEstacion);

                cout << "Ingrese el precio de la gasolina Regular: ";
                cin >> precioRegular;
                while (cin.fail() || precioRegular <= 0) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Entrada invalida. Debe ingresar un numero positivo para el precio de la gasolina Regular." << endl;
                    cout << "Ingrese el precio de la gasolina Regular: ";
                    cin >> precioRegular;
                }

                cout << "Ingrese el precio de la gasolina Premium: ";
                cin >> precioPremium;
                while (cin.fail() || precioPremium <= 0) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Entrada invalida. Debe ingresar un numero positivo para el precio de la gasolina Premium." << endl;
                    cout << "Ingrese el precio de la gasolina Premium: ";
                    cin >> precioPremium;
                }

                cout << "Ingrese el precio de la gasolina EcoExtra: ";
                cin >> precioEcoExtra;
                while (cin.fail() || precioEcoExtra <= 0) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Entrada invalida. Debe ingresar un numero positivo para el precio de la gasolina EcoExtra." << endl;
                    cout << "Ingrese el precio de la gasolina EcoExtra: ";
                    cin >> precioEcoExtra;
                }

                Estacion nuevaEstacion(numero, nombreEstacion, redSeleccionada->getNombreArchivo(), precioRegular, precioPremium, precioEcoExtra);
                redSeleccionada->agregarEstacion(nuevaEstacion);

                cout << "Estacion agregada exitosamente a la red." << endl;
            } catch (const exception& e) {
                cerr << "Ocurrio un error durante la operacion: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
                redSeleccionada->mostrarEstacionesConId();
                int idEstacion;
                cout << "Ingrese el ID de la estacion a eliminar: ";
                cin >> idEstacion;

                while (cin.fail() || idEstacion <= 0) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Entrada invalida. Debe ingresar un numero positivo para el ID de la estacion." << endl;
                    cout << "Ingrese el ID de la estacion a eliminar: ";
                    cin >> idEstacion;
                }

                redSeleccionada->eliminarEstacionPorId(idEstacion);
            } catch (const exception& e) {
                cerr << "Ocurrio un error durante la operacion: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            try {
                seleccionarRed(redSeleccionada, redNorte, redCentro, redSur);
                int indiceEstacion;
                double cantidad;
                string tipoGasolina;
                string metodoPago;

                if (redSeleccionada->getNumEstaciones() == 0) {
                    cout << "No hay estaciones registradas en esta red." << endl;
                    break;
                }

                redSeleccionada->mostrarEstaciones();
                cout <<endl;
                cout << "Ingrese el indice de la estacion (No su ID): ";
                cin >> indiceEstacion;

                while (cin.fail() || indiceEstacion < 1 || indiceEstacion > redSeleccionada->getNumEstaciones()) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Indice de estacion invalido. Por favor, ingrese un numero entre 1 y "
                         << redSeleccionada->getNumEstaciones() << "." << endl;
                    cout << "Ingrese el indice de la estacion (No su ID): ";
                    cin >> indiceEstacion;
                }

                cout << "Ingrese la cantidad de gasolina vendida: ";
                cin >> cantidad;

                while (cin.fail() || cantidad <= 0) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Cantidad de gasolina no valida. Debe ser un numero mayor a 0." << endl;
                    cout << "Ingrese la cantidad de gasolina vendida: ";
                    cin >> cantidad;
                }

                tipoGasolina = seleccion_tipo_gasolina();
                metodoPago = seleccion_metodo_pago();

                bool ventaExitosa = redSeleccionada->registrarVentaEnEstacion(indiceEstacion - 1, cantidad, tipoGasolina, metodoPago);

                if (ventaExitosa) {
                    cout << "Venta registrada exitosamente." << endl;
                } else {
                    cout << "La venta no pudo completarse. No hay suficiente inventario de "
                         << tipoGasolina << " en la estacion seleccionada." << endl;
                }
            } catch (const exception& e) {
                cerr << "Ocurrio un error durante la operación: " << e.what() << endl;
            }
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
tostring
