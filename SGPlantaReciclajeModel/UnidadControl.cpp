#include "UnidadControl.h"

using namespace SGPlantaReciclajeModel;

UnidadControl::UnidadControl() {
    this->idUnidadControl = 0;
    this->voltajeOperacion = 24.0;
    this->frecuenciaReloj = 0.0;
    this->firmware = gcnew Firmware();
}

UnidadControl::UnidadControl(int idUnidadControl, double voltajeOperacion, double frecuenciaReloj, Firmware^ firmware) {
    this->idUnidadControl = idUnidadControl;
    this->voltajeOperacion = voltajeOperacion;
    this->frecuenciaReloj = frecuenciaReloj;
    this->firmware = firmware;
}

int UnidadControl::getIdUnidadControl() {
    return idUnidadControl;
}

void UnidadControl::setIdUnidadControl(int id) {
    idUnidadControl = id;
}

double UnidadControl::getVoltajeOperacion() {
    return voltajeOperacion;
}

void UnidadControl::setVoltajeOperacion(double voltaje) {
    this->voltajeOperacion = voltaje;
}

double UnidadControl::getFrecuenciaReloj() {
    return frecuenciaReloj;
}

void UnidadControl::setFrecuenciaReloj(double frecuencia) {
    this->frecuenciaReloj = frecuencia;
}

Firmware^ UnidadControl::getFirmware() {
    return firmware;
}

void UnidadControl::setFirmware(Firmware^ firmware) {
    this->firmware = firmware;
}

void UnidadControl::procesarSenales() {
    // Procesa señales de entrada
}

void UnidadControl::enviarComando(String^ comando) {
    // Envía comando al hardware
}

bool UnidadControl::estaOperativa() {
    return (firmware != nullptr);
}