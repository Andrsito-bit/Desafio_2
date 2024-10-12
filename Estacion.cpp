#include "Estacion.h"
#include <iomanip>

// Constructor
Estacion::Estacion(const string& nombre) : nombre(nombre) {
    // Inicializar los nombres de los tipos de gasolina y sus ventas a cero
    tiposGasolina[0] = "Regular";
    tiposGasolina[1] = "Premium";
    tiposGasolina[2] = "Diesel";

    for (int i = 0; i < MAX_TIPOS; ++i) {
        preciosGasolina[i] = 0.0;
        ventasGasolina[i] = 0.0;
    }
}

// Establecer el precio de un tipo de gasolina
void Estacion::setPrecioGasolina(const string& tipoGasolina, double precio) {
    int indice = buscarIndiceGasolina(tipoGasolina);
    if (indice != -1) {
        preciosGasolina[indice] = precio;
    } else {
        cerr << "Error: El tipo de gasolina " << tipoGasolina << " no existe." << endl;
    }
}

// Obtener el precio de un tipo de gasolina
double Estacion::getPrecioGasolina(const string& tipoGasolina) const {
    int indice = buscarIndiceGasolina(tipoGasolina);
    if (indice != -1) {
        return preciosGasolina[indice];
    } else {
        cerr << "Error: El tipo de gasolina " << tipoGasolina << " no existe." << endl;
        return -1.0; // Devuelve un valor inválido si el tipo no existe
    }
}

// Registrar una venta de gasolina
void Estacion::registrarVenta(double cantidad, const string& tipoGasolina) {
    int indice = buscarIndiceGasolina(tipoGasolina);
    if (indice != -1) {
        ventasGasolina[indice] += cantidad;
    } else {
        cerr << "Error: El tipo de gasolina " << tipoGasolina << " no existe." << endl;
    }
}

// Mostrar la información de la estación
void Estacion::mostrar() const {
    cout << "Estación: " << nombre << endl;
    cout << "Precios de gasolina:" << endl;
    for (int i = 0; i < MAX_TIPOS; ++i) {
        cout << "- " << tiposGasolina[i] << ": $" << fixed << setprecision(2) << preciosGasolina[i] << " por litro" << endl;
    }

    cout << "Ventas acumuladas:" << endl;
    for (int i = 0; i < MAX_TIPOS; ++i) {
        cout << "- " << tiposGasolina[i] << ": " << fixed << setprecision(2) << ventasGasolina[i] << " litros" << endl;
    }
}

// Guardar la información de la estación en un archivo
void Estacion::guardarEnArchivo(ofstream& archivo) const {
    archivo << nombre << endl;
    for (int i = 0; i < MAX_TIPOS; ++i) {
        archivo << tiposGasolina[i] << " " << preciosGasolina[i] << " " << ventasGasolina[i] << endl;
    }
}

// Cargar la información de la estación desde un archivo
void Estacion::cargarDesdeArchivo(ifstream& archivo) {
    getline(archivo, nombre);

    for (int i = 0; i < MAX_TIPOS; ++i) {
        archivo >> tiposGasolina[i] >> preciosGasolina[i] >> ventasGasolina[i];
    }
}

// Busca el índice de un tipo de gasolina
int Estacion::buscarIndiceGasolina(const string& tipoGasolina) const {
    for (int i = 0; i < MAX_TIPOS; ++i) {
        if (tiposGasolina[i] == tipoGasolina) {
            return i;
        }
    }
    return -1;
}

// Obtener el nombre de la estación
string Estacion::getNombre() const {
    return nombre;
}


