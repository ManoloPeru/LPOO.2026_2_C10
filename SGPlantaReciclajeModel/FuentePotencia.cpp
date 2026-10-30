#include "FuentePotencia.h"

using namespace SGPlantaReciclajeModel;

FuentePotencia::FuentePotencia() {
    this->idFuentePotencia = 0;
    this->voltajeSalida = 0.0;
    this->corrienteMaxima = 0.0;
    this->eficienciaEnergetica = 0.0;
}

FuentePotencia::FuentePotencia(int idFuentePotencia, double voltajeSalida, double corrienteMaxima, double eficienciaEnergetica) {
    this->idFuentePotencia = idFuentePotencia;
    this->voltajeSalida = voltajeSalida;
    this->corrienteMaxima = corrienteMaxima;
    this->eficienciaEnergetica = eficienciaEnergetica;
}

int FuentePotencia::getIdFuentePotencia() {
    return idFuentePotencia;
}

void FuentePotencia::setIdFuentePotencia(int id) {
    idFuentePotencia = id;
}

double FuentePotencia::getVoltajeSalida() {
    return voltajeSalida;
}

void FuentePotencia::setVoltajeSalida(double voltaje) {
    this->voltajeSalida = voltaje;
}

double FuentePotencia::getCorrienteMaxima() {
    return corrienteMaxima;
}

void FuentePotencia::setCorrienteMaxima(double corriente) {
    this->corrienteMaxima = corriente;
}

double FuentePotencia::getEficienciaEnergetica() {
    return eficienciaEnergetica;
}

void FuentePotencia::setEficienciaEnergetica(double eficiencia) {
    this->eficienciaEnergetica = eficiencia;
}

void FuentePotencia::suministrarEnergia() {
    // Suministra energía a las estaciones asociadas
}

bool FuentePotencia::estaOperativa() {
    return (voltajeSalida > 0.0 && corrienteMaxima > 0.0);
}