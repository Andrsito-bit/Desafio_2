// Red.h
#ifndef RED_H
#define RED_H

#include "Estacion.h"
#include <string>
using namespace std;

class Red {
public:
    Red(const string& nombreArchivo);
    void cargarDesdeArchivo();
    void guardarEnArchivo() const;
    void agregarEstacion(const Estacion& estacion);
    void eliminarEstacion(int indice);
    void mostrarEstaciones() const;
    void mostrarEstacionesConId() const;
    void eliminarEstacionPorId(int id);
    bool registrarVentaEnEstacion(int indice, double cantidad, const string& tipoGasolina,const string& metodopago);

    // Getters
    int getNumEstaciones() const;       // Obtiene el número de estaciones
    string getNombreArchivo() const;    // Obtiene el nombre del archivo

private:
    string nombreArchivo;
    Estacion estaciones[100];  // Pongamos un límite de 100 estaciones
    int numEstaciones;
};

#endif
