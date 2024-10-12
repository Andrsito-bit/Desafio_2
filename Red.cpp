// Red.cpp
#include "Red.h"
#include <fstream>
#include <iostream>
using namespace std;

Red::Red(const string& nombreArchivo) : nombreArchivo(nombreArchivo), numEstaciones(0) {}

void Red::cargarDesdeArchivo() {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    numEstaciones = 0; // Reiniciar el número de estaciones antes de cargar
    string nombreEstacion;

    while (getline(archivo, nombreEstacion) && numEstaciones < 100) {
        estaciones[numEstaciones] = Estacion(nombreEstacion);
        ++numEstaciones;
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
        archivo << estaciones[i].getNombre() << endl;
    }

    archivo.close();
}

void Red::agregarEstacion(const Estacion& estacion) {
    if (numEstaciones < 100) {
        estaciones[numEstaciones] = estacion;
        ++numEstaciones;
    } else {
        cerr << "No se pueden agregar más estaciones. Límite alcanzado." << endl;
    }
}

void Red::eliminarEstacion(int indice) {
    if (indice >= 0 && indice < numEstaciones) {
        for (int i = indice; i < numEstaciones - 1; ++i) {
            estaciones[i] = estaciones[i + 1];
        }
        --numEstaciones;
    } else {
        cerr << "Índice de estación inválido. No se puede eliminar." << endl;
    }
}

void Red::mostrarEstaciones() const {
    if (numEstaciones == 0) {
        cout << "No hay estaciones disponibles en esta red." << endl;
    } else {
        for (int i = 0; i < numEstaciones; ++i) {
            cout << "Estación " << (i + 1) << ": " << estaciones[i].getNombre() << endl;
        }
    }
}

void Red::registrarVentaEnEstacion(int indice, double cantidad, const string& tipoGasolina) {
    if (indice >= 0 && indice < numEstaciones) {
        estaciones[indice].registrarVenta(cantidad, tipoGasolina);
    } else {
        cerr << "Índice de estación inválido. No se puede registrar la venta." << endl;
    }
}

// Getters
int Red::getNumEstaciones() const {
    return numEstaciones;
}

string Red::getNombreArchivo() const {
    return nombreArchivo;
}
