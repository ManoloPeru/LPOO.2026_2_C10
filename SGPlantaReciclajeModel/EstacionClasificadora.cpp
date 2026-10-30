#include "EstacionClasificadora.h"

using namespace SGPlantaReciclajeModel;

// ============================================================
// CONSTRUCTOR VACÍO
// ============================================================
// Inicializa los atributos con valores neutros/predeterminados
// para evitar referencias nulas.
EstacionClasificadora::EstacionClasificadora() {
    this->serialId = "SIN-ID";
    this->alias = "Sin alias";
    this->tipo = 0;
    this->estado = 0;
    this->ubicacion = "Sin ubicación";
}

// ============================================================
// CONSTRUCTOR CON TODOS LOS PARÁMETROS
// ============================================================
// Crea una estación completamente configurada desde su
// instanciación.
EstacionClasificadora::EstacionClasificadora(String^ serialId, String^ alias,
    int tipo, int estado, String^ ubicacion) {
    this->serialId = serialId;
    this->alias = alias;
    this->tipo = tipo;
    this->estado = estado;
    this->ubicacion = ubicacion;
}

// ============================================================
// GETTERS Y SETTERS
// ============================================================

String^ EstacionClasificadora::getSerialId() {
    return serialId;
}

void EstacionClasificadora::setSerialId(String^ serialId) {
    this->serialId = serialId;
}

String^ EstacionClasificadora::getAlias() {
    return alias;
}

void EstacionClasificadora::setAlias(String^ alias) {
    this->alias = alias;
}

int EstacionClasificadora::getTipo() {
    return tipo;
}

void EstacionClasificadora::setTipo(int tipo) {
    this->tipo = tipo;
}

int EstacionClasificadora::getEstado() {
    return estado;
}

void EstacionClasificadora::setEstado(int estado) {
    this->estado = estado;
}

String^ EstacionClasificadora::getUbicacion() {
    return ubicacion;
}

void EstacionClasificadora::setUbicacion(String^ ubicacion) {
    this->ubicacion = ubicacion;
}

// ============================================================
// MÉTODOS AUXILIARES
// ============================================================

// ToString: devuelve una representación en texto de la estación
// con formato legible para el usuario.
String^ EstacionClasificadora::ToString() {
    return String::Format("[{0}] {1} | Tipo: {2} | Estado: {3} | Ubicacion: {4}",
        serialId, alias, getTipo(), getEstado(), ubicacion);
}