// Red.cpp
#include "Red.h"
#include <iostream>
#include <fstream>
#include <sstream>
    using namespace std;

Red::Red(const string& nombreArchivo) : nombreArchivo(nombreArchivo), numEstaciones(0) {
    // Inicializar las estaciones con un estado "vacío"
    for (int i = 0; i < 100; ++i) {
        estaciones[i] = Estacion(); // Esto solo inicializa los objetos, pero no los considera como ocupados
    }
}


void Red::mostrarEstacionesConId() const {
    if (numEstaciones == 0) {
        cout << "No hay estaciones registradas." << endl;
        return;
    }

    for (int i = 0; i < numEstaciones; ++i) {
        cout << "ID: " << estaciones[i].getNumero() << " - " << estaciones[i].getNombre() << endl;
    }
}


void Red::eliminarEstacionPorId(int id) {
    bool encontrada = false;
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i].getNumero() == id) {
            encontrada = true;
            // Shift left para cubrir el espacio eliminado
            for (int j = i; j < numEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1];
            }
            --numEstaciones;
            guardarEnArchivo(); // Guardar inmediatamente después de eliminar
            cout << "Estacion con ID " << id << " eliminada." << endl;
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró una estación con el ID proporcionado." << endl;
    }
}



void Red::agregarEstacion(const Estacion& estacion) {
    if (numEstaciones < 100) {
        estaciones[numEstaciones] = estacion;
        ++numEstaciones;
        guardarEnArchivo(); // Guardar inmediatamente después de agregar
    } else {
        cerr << "No se pueden agregar más estaciones. Limite alcanzado." << endl;
    }
}

void Red::mostrarEstaciones() const {
    if (numEstaciones == 0) {
        cout << "No hay estaciones registradas en esta red." << endl;
        return;
    }

    for (int i = 0; i < numEstaciones; ++i) {
        cout << "Estacion " << (i + 1) << ":" << endl;
        estaciones[i].mostrarInfo();
        cout <<endl;
    }
}



bool Red::registrarVentaEnEstacion(int indice, double cantidad, const string& tipoGasolina, const string& metodoPago) {
    if (indice >= 0 && indice < numEstaciones) {
        // Verificar si la venta puede realizarse
        bool ventaExitosa = estaciones[indice].venderGasolina(cantidad, tipoGasolina);

        if (ventaExitosa) {
            // Registrar la venta solo si se pudo vender la cantidad solicitada
            estaciones[indice].registrarVenta(cantidad, tipoGasolina, metodoPago);
            guardarEnArchivo(); // Guardar los cambios en el archivo
            return true;
        }
    }
    return false;
}

int Red::getNumEstaciones() const {
    return numEstaciones;
}

string Red::getNombreArchivo() const {
    return nombreArchivo;
}

void Red::cargarDesdeArchivo() {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        try {
            stringstream ss(linea);
            string numeroStr, nombre, red, precioRegularStr, precioPremiumStr, precioEcoExtraStr;

            getline(ss, numeroStr, '|');
            getline(ss, nombre, '|');
            getline(ss, red, '|');
            getline(ss, precioRegularStr, '|');
            getline(ss, precioPremiumStr, '|');
            getline(ss, precioEcoExtraStr, '|');

            if (numeroStr.empty() || precioRegularStr.empty() || precioPremiumStr.empty() || precioEcoExtraStr.empty()) {
                cerr << "Error: una de las entradas esta vacia. Linea: " << linea << endl;
                continue;
            }

            int numero = stoi(numeroStr);
            double precioRegular = stod(precioRegularStr);
            double precioPremium = stod(precioPremiumStr);
            double precioEcoExtra = stod(precioEcoExtraStr);


            Estacion estacion(numero, nombre, red, precioRegular, precioPremium, precioEcoExtra);
            agregarEstacion(estacion);
        } catch (const invalid_argument& e)

        {
            cerr << "Error de conversión en la linea: " << linea << " - " << e.what() << endl;
        } catch (const out_of_range& e) {
            cerr << "Valor fuera de rango en la linea: " << linea << " - " << e.what() << endl;
        }
    }

    archivo.close();
}

void Red::guardarEnArchivo() const {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir: " << nombreArchivo << endl;
        return;
    }

    for (int i = 0; i < numEstaciones; ++i) {
        archivo << estaciones[i].toString() << endl;
    }

    archivo.close();
}


