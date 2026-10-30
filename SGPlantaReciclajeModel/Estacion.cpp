#include "Estacion.h"

using namespace SGPlantaReciclajeModel;

Estacion::Estacion() {
    this->estacionId = 0;
    this->alias = "";
    this->ubicacion = "";
    this->estado = 1; // Por defecto Operativo
    this->capacidadKgH = 0.0;
    this->horasOperacion = 0.0;
}

Estacion::Estacion(String^ alias, String^ ubicacion, int estado, double capacidadKgH, double horasOperacion) {
    this->estacionId = 0;
    this->alias = alias;
    this->ubicacion = ubicacion;
    this->estado = estado;
    this->capacidadKgH = capacidadKgH;
    this->horasOperacion = horasOperacion;
}

Estacion::Estacion(int estacionId, String^ alias, String^ ubicacion, int estado, double capacidadKgH, double horasOperacion) {
    this->estacionId = estacionId;
    this->alias = alias;
    this->ubicacion = ubicacion;
    this->estado = estado;
    this->capacidadKgH = capacidadKgH;
    this->horasOperacion = horasOperacion;
}

int Estacion::getEstacionId() { return estacionId; }
void Estacion::setEstacionId(int id) { this->estacionId = id; }

String^ Estacion::getAlias() { return alias; }
void Estacion::setAlias(String^ alias) { this->alias = alias; }

String^ Estacion::getUbicacion() { return ubicacion; }
void Estacion::setUbicacion(String^ ubicacion) { this->ubicacion = ubicacion; }

int Estacion::getEstado() { return estado; }
void Estacion::setEstado(int estado) { this->estado = estado; }

double Estacion::getCapacidadKgH() { return capacidadKgH; }
void Estacion::setCapacidadKgH(double capacidad) { this->capacidadKgH = capacidad; }

double Estacion::getHorasOperacion() { return horasOperacion; }
void Estacion::setHorasOperacion(double horas) { this->horasOperacion = horas; }

String^ Estacion::ToString() {
    return String::Format("[{0}] {1} | Ubicación: {2} | Capacidad: {3} kg/h",
        estacionId, alias, ubicacion, capacidadKgH);
}