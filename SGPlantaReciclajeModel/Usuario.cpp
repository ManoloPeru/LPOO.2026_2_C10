#include "Usuario.h"

using namespace SGPlantaReciclajeModel;

Usuario::Usuario() {
    this->idUsuario = 0;
    this->nombres = "";
    this->apellidos = "";
    this->correo = "";
    this->usuario = "";
    this->contrasenia = "";
    this->estado = "A";
}

Usuario::Usuario(String^ nombres, String^ apellidos, String^ correo, String^ usuario, String^ contrasenia, String^ estado) {
    this->idUsuario = 0;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->correo = correo;
    this->usuario = usuario;
    this->contrasenia = contrasenia;
    this->estado = estado;
}

Usuario::Usuario(int idUsuario, String^ nombres, String^ apellidos, String^ correo, String^ usuario, String^ contrasenia, String^ estado) {
    this->idUsuario = idUsuario;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->correo = correo;
    this->usuario = usuario;
    this->contrasenia = contrasenia;
    this->estado = estado;
}

int Usuario::getIdUsuario() { return idUsuario; }
void Usuario::setIdUsuario(int id) { this->idUsuario = id; }

String^ Usuario::getNombres() { return nombres; }
void Usuario::setNombres(String^ nombres) { this->nombres = nombres; }

String^ Usuario::getApellidos() { return apellidos; }
void Usuario::setApellidos(String^ apellidos) { this->apellidos = apellidos; }

String^ Usuario::getCorreo() { return correo; }
void Usuario::setCorreo(String^ correo) { this->correo = correo; }

String^ Usuario::getUsuario() { return usuario; }
void Usuario::setUsuario(String^ usuario) { this->usuario = usuario; }

String^ Usuario::getContrasenia() { return contrasenia; }
void Usuario::setContrasenia(String^ contrasenia) { this->contrasenia = contrasenia; }

String^ Usuario::getEstado() { return estado; }
void Usuario::setEstado(String^ estado) { this->estado = estado; }

String^ Usuario::ToString() {
    return String::Format("[{0}] {1} {2} | User: {3} | Estado: {4}",
        idUsuario, nombres, apellidos, usuario, estado);
}