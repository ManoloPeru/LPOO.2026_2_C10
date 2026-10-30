#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    // ============================================================
    // CLASE: CeldaProceso
    // ============================================================
    // Representa un módulo físico o zona de la línea de reciclaje.
    // Se marca como [Serializable] para permitir su persistencia
    // en formato binario.
    [Serializable]
    public ref class CeldaProceso {
    private:
        String^ id;         // Identificador único de la celda.
        String^ nombre;     // Nombre descriptivo (ej. "Módulo de Trituración Primaria").
        int tipo;           // Tipo (ej. "Trituración", "Lavado", "Compactación").
        int estado;         // Estado (ej. "Activa", "En Configuración").
        double capacidad;   // Capacidad máxima en kg/h.

    public:
        // ---------- CONSTRUCTORES ----------
        CeldaProceso();

        CeldaProceso(String^ id, String^ nombre, int tipo, int estado, double capacidad);

        // ---------- GETTERS Y SETTERS ----------
        String^ getId();
        void setId(String^ id);

        String^ getNombre();
        void setNombre(String^ nombre);

        int getTipo();
        void setTipo(int tipo);

        int getEstado();
        void setEstado(int estado);

        double getCapacidad();
        void setCapacidad(double capacidad);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override;
    };
}