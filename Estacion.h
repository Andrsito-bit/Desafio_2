#ifndef ESTACION_H
#define ESTACION_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Estacion {
private:
    string nombre;  // Nombre de la estación
    static const int MAX_TIPOS = 3;  // Número máximo de tipos de gasolina (por ejemplo, 3: Magna, Premium, Diesel)
    string tiposGasolina[MAX_TIPOS]; // Nombres de los tipos de gasolina
    double preciosGasolina[MAX_TIPOS]; // Precios de cada tipo de gasolina
    double ventasGasolina[MAX_TIPOS];  // Registro de las ventas acumuladas por cada tipo de gasolina

    // Busca el índice de un tipo de gasolina por nombre, retorna -1 si no se encuentra
    int buscarIndiceGasolina(const string& tipoGasolina) const;

public:
    // Constructor
    Estacion(const string& nombre = "");


    // Establecer el precio de un tipo de gasolina
    void setPrecioGasolina(const string& tipoGasolina, double precio);

    // Obtener el precio de un tipo de gasolina
    double getPrecioGasolina(const string& tipoGasolina) const;

    // Registrar una venta de gasolina
    void registrarVenta(double cantidad, const string& tipoGasolina);

    // Mostrar la información de la estación
    void mostrar() const;

    // Guardar la información de la estación en un archivo
    void guardarEnArchivo(ofstream& archivo) const;

    // Cargar la información de la estación desde un archivo
    void cargarDesdeArchivo(ifstream& archivo);

    // Obtener el nombre de la estación
    string getNombre() const;
};

#endif // ESTACION_H
