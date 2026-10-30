#include "TipoEstacionClasificadora.h"

using namespace SGPlantaReciclajeModel;

// ============================================================
// CONSTRUCTOR VACÍO
// ============================================================
TipoEstacionClasificadora::TipoEstacionClasificadora() {
    this->idTipoEstacion = 0;
    this->descripcion = "Sin descripción";
}

// ============================================================
// CONSTRUCTOR CON PARÁMETROS
// ============================================================
TipoEstacionClasificadora::TipoEstacionClasificadora(int idTipoEstacion, String^ descripcion) {
    this->idTipoEstacion = idTipoEstacion;
    this->descripcion = descripcion;
}

// ============================================================
// GETTERS Y SETTERS
// ============================================================
int TipoEstacionClasificadora::getIdTipoEstacion() {
    return idTipoEstacion;
}

void TipoEstacionClasificadora::setIdTipoEstacion(int id) {
    this->idTipoEstacion = id;
}

String^ TipoEstacionClasificadora::getDescripcion() {
    return descripcion;
}

void TipoEstacionClasificadora::setDescripcion(String^ descripcion) {
    this->descripcion = descripcion;
}

// ============================================================
// MÉTODOS AUXILIARES
// ============================================================
String^ TipoEstacionClasificadora::ToString() {
    return descripcion;
}