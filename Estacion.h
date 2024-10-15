// Estacion.h
#ifndef ESTACION_H
#define ESTACION_H

#include <string>
#include <ctime>
using namespace std;

class Estacion {
public:
    Estacion(int numero = 0, const string& nombre = "", const string& nombreRed = "",
             double precioRegular = 0.0, double precioPremium = 0.0, double precioEcoExtra = 0.0);

    void mostrarInfo() const;
    void registrarVenta(double cantidad, const string& tipoGasolina,const string& metodoPago);
    bool venderGasolina(double cantidad, const string& tipoGasolina);
    string toString() const;

    // Getters
    int getNumero()const;
    string getNombre() const;
    double getPrecioRegular() const;
    double getPrecioPremium() const;
    double getPrecioEcoExtra() const;
    double getInventarioRegular() const;
    double getInventarioPremium() const;
    double getInventarioEcoExtra() const;

    // Setters
    void setPrecioRegular(double nuevoPrecio);
    void setPrecioPremium(double nuevoPrecio);
    void setPrecioEcoExtra(double nuevoPrecio);

private:
    int numero;
    string nombre;
    string nombreRed;
    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

    double inventarioRegular = 200; // Inventario inicial de gasolina
    double inventarioPremium = 200;
    double inventarioEcoExtra = 200;
};

#endif


