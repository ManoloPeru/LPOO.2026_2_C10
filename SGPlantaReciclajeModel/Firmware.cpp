#include "Firmware.h"

using namespace SGPlantaReciclajeModel;

Firmware::Firmware() {
    this->idFirmware = 0;
    this->version = "1.0.0";
    this->fechaUltimaCompilacion = DateTime::Now;
    this->memoriaInternaKB = 0.0;
}

Firmware::Firmware(int idFirmware, String^ version, DateTime fechaUltimaCompilacion, double memoriaInternaKB) {
    this->idFirmware = idFirmware;
    this->version = version;
    this->fechaUltimaCompilacion = fechaUltimaCompilacion;
    this->memoriaInternaKB = memoriaInternaKB;
}

int Firmware::getIdFirmware() {
    return idFirmware;
}

void Firmware::setIdFirmware(int id) {
    idFirmware = id;
}

String^ Firmware::getVersion() {
    return version;
}

void Firmware::setVersion(String^ version) {
    this->version = version;
}

DateTime Firmware::getFechaUltimaCompilacion() {
    return fechaUltimaCompilacion;
}

void Firmware::setFechaUltimaCompilacion(DateTime fecha) {
    this->fechaUltimaCompilacion = fecha;
}

double Firmware::getMemoriaInternaKB() {
    return memoriaInternaKB;
}

void Firmware::setMemoriaInternaKB(double memoria) {
    this->memoriaInternaKB = memoria;
}

void Firmware::actualizarFirmware(String^ nuevaVersion) {
    this->version = nuevaVersion;
    this->fechaUltimaCompilacion = DateTime::Now;
}

void Firmware::compilar() {
    this->fechaUltimaCompilacion = DateTime::Now;
}