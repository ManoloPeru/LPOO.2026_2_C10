#include "SeparadorMagnetico.h"

using namespace SGPlantaReciclajeModel;

SeparadorMagnetico::SeparadorMagnetico() : UnidadClasificadora() {
    this->intensidadCampoMin = 0.0;
    this->intensidadCampoMax = 0.0;
    this->capacidadExtraccionMax = 0.0;
}

SeparadorMagnetico::SeparadorMagnetico(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras,
    double intensidadCampoMin, double intensidadCampoMax, double capacidadExtraccionMax)
    : UnidadClasificadora(idUnidadClasificadora, fabricante, tiempoOperacionHoras) {
    this->intensidadCampoMin = intensidadCampoMin;
    this->intensidadCampoMax = intensidadCampoMax;
    this->capacidadExtraccionMax = capacidadExtraccionMax;
}

double SeparadorMagnetico::getIntensidadCampoMin() {
    return intensidadCampoMin;
}

void SeparadorMagnetico::setIntensidadCampoMin(double intensidad) {
    this->intensidadCampoMin = intensidad;
}

double SeparadorMagnetico::getIntensidadCampoMax() {
    return intensidadCampoMax;
}

void SeparadorMagnetico::setIntensidadCampoMax(double intensidad) {
    this->intensidadCampoMax = intensidad;
}

double SeparadorMagnetico::getCapacidadExtraccionMax() {
    return capacidadExtraccionMax;
}

void SeparadorMagnetico::setCapacidadExtraccionMax(double capacidad) {
    this->capacidadExtraccionMax = capacidad;
}

void SeparadorMagnetico::ajustarIntensidadCampo(double intensidad) {
    if (intensidad >= intensidadCampoMin && intensidad <= intensidadCampoMax) {
        // Intensidad ajustada dentro del rango permitido
    }
}

void SeparadorMagnetico::extraerMetalFerroso() {
    // Ejecuta extracción de metales ferrosos
}

double SeparadorMagnetico::calcularCapacidadExtraccion() {
    return capacidadExtraccionMax;
}

String^ SeparadorMagnetico::leerTelemetria() {
    return "Telemetría Separador Magnético - Temp: 30°C, Vibración: 60 Hz";
}

List<String^>^ SeparadorMagnetico::verificarAlertas() {
    List<String^>^ alertas = gcnew List<String^>();
    return alertas;
}