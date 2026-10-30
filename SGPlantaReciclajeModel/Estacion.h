#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class Estacion {
    private:
        int estacionId;         // PK (No es Identity en tu script, se ingresa manual)
        String^ alias;
        String^ ubicacion;
        int estado;             // FK lógica a catálogo de Estados
        double capacidadKgH;
        double horasOperacion;

    public:
        // ---------- CONSTRUCTORES ----------
        Estacion();

        // Constructor sin ID (por si se llegara a usar Identity en un futuro)
        Estacion(String^ alias, String^ ubicacion, int estado, double capacidadKgH, double horasOperacion);

        // Constructor completo
        Estacion(int estacionId, String^ alias, String^ ubicacion, int estado, double capacidadKgH, double horasOperacion);

        // ---------- GETTERS Y SETTERS ----------
        int getEstacionId();
        void setEstacionId(int id);

        String^ getAlias();
        void setAlias(String^ alias);

        String^ getUbicacion();
        void setUbicacion(String^ ubicacion);

        int getEstado();
        void setEstado(int estado);

        double getCapacidadKgH();
        void setCapacidadKgH(double capacidad);

        double getHorasOperacion();
        void setHorasOperacion(double horas);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override;
    };
}