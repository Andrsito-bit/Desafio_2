#include <iostream>
#include "mostrar_en_pantalla.h"
#include <string>
#include "Red.h" // Archivo donde estarán las clases Red y Estacion

using namespace std;



int main() {

    int opcionPrincipal;
    do {
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: {
            int opcionRed;
            do {
                cout << "\n--- Gestionando Red Norte ---" << endl;
                mostrarMenuRed();
                cin >> opcionRed;

                // Aquí irían las llamadas a los métodos de la clase Red para la Red Norte
                switch (opcionRed) {
                case 1:
                    // Lógica para agregar estación a redNorte
                    break;
                case 2:
                    // Lógica para eliminar estación de redNorte
                    break;
                case 3:
                    // Lógica para mostrar estaciones de redNorte
                    break;
                case 4:
                    // Lógica para ver ventas por tipo de combustible en redNorte
                    break;
                case 5:
                    cout << "Regresando al menú principal..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente nuevamente." << endl;
                }
            } while (opcionRed != 5);
            break;
        }

        case 2: {
            int opcionRed;
            do {
                cout << "\n--- Gestionando Red Centro ---" << endl;
                mostrarMenuRed();
                cin >> opcionRed;

                // Aquí irían las llamadas a los métodos de la clase Red para la Red Centro
                switch (opcionRed) {
                case 1:
                    // Lógica para agregar estación a redCentro
                    break;
                case 2:
                    // Lógica para eliminar estación de redCentro
                    break;
                case 3:
                    // Lógica para mostrar estaciones de redCentro
                    break;
                case 4:
                    // Lógica para ver ventas por tipo de combustible en redCentro
                    break;
                case 5:
                    cout << "Regresando al menú principal..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente nuevamente." << endl;
                }
            } while (opcionRed != 5);
            break;
        }

        case 3: {
            int opcionRed;
            do {
                cout << "\n--- Gestionando Red Sur ---" << endl;
                mostrarMenuRed();
                cin >> opcionRed;

                // Aquí irían las llamadas a los métodos de la clase Red para la Red Sur
                switch (opcionRed) {
                case 1:
                    // Lógica para agregar estación a redSur
                    break;
                case 2:
                    // Lógica para eliminar estación de redSur
                    break;
                case 3:
                    // Lógica para mostrar estaciones de redSur
                    break;
                case 4:
                    // Lógica para ver ventas por tipo de combustible en redSur
                    break;
                case 5:
                    cout << "Regresando al menú principal..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente nuevamente." << endl;
                }
            } while (opcionRed != 5);
            break;
        }

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción no válida, por favor intente de nuevo." << endl;
        }

    } while (opcionPrincipal != 4);

    return 0;
}
