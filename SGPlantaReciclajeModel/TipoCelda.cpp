#include "TipoCelda.h"

using namespace SGPlantaReciclajeModel;

TipoCelda::TipoCelda() {
    this->idTipoCelda = 0;
    this->descripcion = "Sin descripción";
}

TipoCelda::TipoCelda(int idTipoCelda, String^ descripcion) {
    this->idTipoCelda = idTipoCelda;
    this->descripcion = descripcion;
}

int TipoCelda::getIdTipoCelda() {
    return idTipoCelda;
}

void TipoCelda::setIdTipoCelda(int id) {
    this->idTipoCelda = id;
}

String^ TipoCelda::getDescripcion() {
    return descripcion;
}

void TipoCelda::setDescripcion(String^ descripcion) {
    this->descripcion = descripcion;
}

String^ TipoCelda::ToString() {
    return descripcion;
}