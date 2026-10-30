#include "UnidadClasificadora.h"

using namespace SGPlantaReciclajeModel;

UnidadClasificadora::UnidadClasificadora() {
    this->idUnidadClasificadora = 0;
    this->fabricante = "Desconocido";
    this->tiempoOperacionHoras = 0.0;
}

UnidadClasificadora::UnidadClasificadora(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras) {
    this->idUnidadClasificadora = idUnidadClasificadora;
    this->fabricante = fabricante;
    this->tiempoOperacionHoras = tiempoOperacionHoras;
}

int UnidadClasificadora::getIdUnidadClasificadora() {
    return idUnidadClasificadora;
}

void UnidadClasificadora::setIdUnidadClasificadora(int id) {
    idUnidadClasificadora = id;
}

String^ UnidadClasificadora::getFabricante() {
    return fabricante;
}

void UnidadClasificadora::setFabricante(String^ fabricante) {
    this->fabricante = fabricante;
}

double UnidadClasificadora::getTiempoOperacionHoras() {
    return tiempoOperacionHoras;
}

void UnidadClasificadora::setTiempoOperacionHoras(double horas) {
    this->tiempoOperacionHoras = horas;
}

UnidadControl^ UnidadClasificadora::getUnidadControl() {
    return unidadControl;
}

void UnidadClasificadora::setUnidadControl(UnidadControl^ unidadControl) {
    this->unidadControl = unidadControl;
}

void UnidadClasificadora::acumularTiempoOperacion(double horas) {
    this->tiempoOperacionHoras += horas;
}