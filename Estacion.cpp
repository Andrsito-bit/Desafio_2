// Estacion.cpp
#include "Estacion.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

Estacion::Estacion(int numero, const string& nombre, const string& nombreRed,
                   double precioRegular, double precioPremium, double precioEcoExtra)
    : numero(numero), nombre(nombre), nombreRed(nombreRed),
    precioRegular(precioRegular), precioPremium(precioPremium), precioEcoExtra(precioEcoExtra) {}



void Estacion::mostrarInfo() const {
    cout << "ID: " << numero << ", Nombre: " << nombre << ", Red: " << nombreRed << endl;
    cout << "Precios - Regular: " << precioRegular << ", Premium: " << precioPremium
         << ", EcoExtra: " << precioEcoExtra << endl;
    cout << "Inventario - Regular: " << inventarioRegular << "L, Premium: " << inventarioPremium
         << "L, EcoExtra: " << inventarioEcoExtra << "L" << endl;
}


bool Estacion::venderGasolina(double cantidad, const string& tipoGasolina) {

    if (tipoGasolina == "Regular" && inventarioRegular >= cantidad) {
        inventarioRegular -= cantidad;
        return true;
    } else if (tipoGasolina == "Premium" && inventarioPremium >= cantidad) {
        inventarioPremium -= cantidad;
        return true;
    } else if (tipoGasolina == "EcoExtra" && inventarioEcoExtra >= cantidad) {
        inventarioEcoExtra -= cantidad;
        return true;
    }
    return false; // No hay suficiente inventario
}


void Estacion::registrarVenta(double cantidad, const string& tipoGasolina, const string& metodoPago) {
    double precio = 0.0;

    // Determinar el precio por tipo de gasolina
    if (tipoGasolina == "Regular") precio = precioRegular;
    else if (tipoGasolina == "Premium") precio = precioPremium;
    else if (tipoGasolina == "EcoExtra") precio = precioEcoExtra;

    // Calcular el total a pagar
    double total = cantidad * precio;

    // Registrar en el archivo de ventas
    ofstream archivoVentas("registro_ventas.txt", ios::app);
    if (!archivoVentas) {
        cerr << "Error al abrir el archivo de ventas para escribir." << endl;
        return;
    }

    // Obtener la hora actual
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    // Escribir la información de la venta en el archivo
    archivoVentas << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S") << " - "
                  << "Estacion ID: " << numero << " - Tipo: " << tipoGasolina
                  << " - Cantidad: " << cantidad << "L - Metodo: " << metodoPago
                  << " - Total: $" << fixed << setprecision(2) << total << endl;

    archivoVentas.close();

    // Mostrar confirmación en consola
    cout << "Venta registrada: " << cantidad << "L de " << tipoGasolina
         << " en la Estacion ID " << numero << " con metodo de pago: "
         << metodoPago << ". Total: $" << total << endl;

    inventarioRegularAnterior = inventarioRegular;
    inventarioPremiumAnterior = inventarioPremium;
    inventarioEcoExtraAnterior = inventarioEcoExtra;
}

string Estacion::toString() const {
    stringstream ss;
    ss << numero << "|" << nombre << "|" << nombreRed << "|"
       << precioRegular << "|" << precioPremium << "|" << precioEcoExtra;
    return ss.str();
}

int Estacion::getNumero() const {
    return numero;
}

string Estacion::getNombre() const {
    return nombre;
}

bool Estacion::verific_fuga() const {
    return (inventarioRegular <= inventarioRegularAnterior*0.95 ||
            inventarioPremium <= inventarioPremiumAnterior*0.95 ||
            inventarioEcoExtra <= inventarioEcoExtraAnterior*0.95);
}




