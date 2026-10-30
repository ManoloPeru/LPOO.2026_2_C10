#include "CeldaProceso.h"

using namespace SGPlantaReciclajeModel;

CeldaProceso::CeldaProceso() {
    this->id = "SIN-ID";
    this->nombre = "Sin nombre";
    this->tipo = 0;
    this->estado = 0;
    this->capacidad = 0.0;
}

CeldaProceso::CeldaProceso(String^ id, String^ nombre, int tipo, int estado, double capacidad) {
    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->estado = estado;
    this->capacidad = capacidad;
}

String^ CeldaProceso::getId() {
    return id;
}

void CeldaProceso::setId(String^ id) {
    this->id = id;
}

String^ CeldaProceso::getNombre() {
    return nombre;
}

void CeldaProceso::setNombre(String^ nombre) {
    this->nombre = nombre;
}

int CeldaProceso::getTipo() {
    return tipo;
}

void CeldaProceso::setTipo(int tipo) {
    this->tipo = tipo;
}

int CeldaProceso::getEstado() {
    return estado;
}

void CeldaProceso::setEstado(int estado) {
    this->estado = estado;
}

double CeldaProceso::getCapacidad() {
    return capacidad;
}

void CeldaProceso::setCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

String^ CeldaProceso::ToString() {
    return String::Format("[{0}] {1} | Tipo: {2} | Estado: {3} | Capacidad: {4} kg/h",
        id, nombre, tipo, estado, capacidad);
}