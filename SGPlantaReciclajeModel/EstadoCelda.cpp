#include "EstadoCelda.h"

using namespace SGPlantaReciclajeModel;

EstadoCelda::EstadoCelda() {
    this->idEstadoCelda = 0;
    this->descripcion = "Sin descripción";
}

EstadoCelda::EstadoCelda(int idEstadoCelda, String^ descripcion) {
    this->idEstadoCelda = idEstadoCelda;
    this->descripcion = descripcion;
}

int EstadoCelda::getIdEstadoCelda() {
    return idEstadoCelda;
}

void EstadoCelda::setIdEstadoCelda(int id) {
    this->idEstadoCelda = id;
}

String^ EstadoCelda::getDescripcion() {
    return descripcion;
}

void EstadoCelda::setDescripcion(String^ descripcion) {
    this->descripcion = descripcion;
}

String^ EstadoCelda::ToString() {
    return descripcion;
}