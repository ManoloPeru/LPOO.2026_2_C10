#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class Usuario {
    private:
        int idUsuario;          // PK (Identity en SQL)
        String^ nombres;
        String^ apellidos;
        String^ correo;
        String^ usuario;        // Nombre de usuario para login
        String^ contrasenia;
        String^ estado;         // 'A' = Activo, 'I' = Inactivo (char 1)

    public:
        // ---------- CONSTRUCTORES ----------
        Usuario();

        // Constructor sin ID (útil para INSERT, ya que el ID lo genera SQL)
        Usuario(String^ nombres, String^ apellidos, String^ correo, String^ usuario, String^ contrasenia, String^ estado);

        // Constructor con ID (útil para SELECT/UPDATE)
        Usuario(int idUsuario, String^ nombres, String^ apellidos, String^ correo, String^ usuario, String^ contrasenia, String^ estado);

        // ---------- GETTERS Y SETTERS ----------
        int getIdUsuario();
        void setIdUsuario(int id);

        String^ getNombres();
        void setNombres(String^ nombres);

        String^ getApellidos();
        void setApellidos(String^ apellidos);

        String^ getCorreo();
        void setCorreo(String^ correo);

        String^ getUsuario();
        void setUsuario(String^ usuario);

        String^ getContrasenia();
        void setContrasenia(String^ contrasenia);

        String^ getEstado();
        void setEstado(String^ estado);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override;
    };
}