#include "EstadoOperativo.h"

using namespace SGPlantaReciclajeModel;

// ============================================================
// CONSTRUCTOR VACÍO
// ============================================================
EstadoOperativo::EstadoOperativo() {
    this->idEstadoOperativo = 0;
    this->descripcion = "Sin descripción";
}

// ============================================================
// CONSTRUCTOR CON PARÁMETROS
// ============================================================
EstadoOperativo::EstadoOperativo(int idEstadoOperativo, String^ descripcion) {
    this->idEstadoOperativo = idEstadoOperativo;
    this->descripcion = descripcion;
}

// ============================================================
// GETTERS Y SETTERS
// ============================================================
int EstadoOperativo::getIdEstadoOperativo() {
    return idEstadoOperativo;
}

void EstadoOperativo::setIdEstadoOperativo(int id) {
    this->idEstadoOperativo = id;
}

String^ EstadoOperativo::getDescripcion() {
    return descripcion;
}

void EstadoOperativo::setDescripcion(String^ descripcion) {
    this->descripcion = descripcion;
}

// ============================================================
// MÉTODOS AUXILIARES
// ============================================================
String^ EstadoOperativo::ToString() {
    return descripcion;
}