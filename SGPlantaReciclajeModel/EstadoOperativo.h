#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // ============================================================
    // CLASE: EstadoOperativo
    // ============================================================
    // Representa un estado operativo posible de una estación
    // clasificadora (e.g., "Operativo", "En Mantenimiento",
    // "Falla Crítica", "Apagado").
    //
    // Esta clase se usa como TABLA MAESTRA (o catálogo) para
    // poblar los ComboBox de la capa de presentación y para
    // validar que el estado asignado a una estación sea uno
    // de los permitidos.
    public ref class EstadoOperativo {

    private:
        int idEstadoOperativo;  // Identificador único del estado (PK)
        String^ descripcion;    // Descripción del estado (e.g., "Operativo")

    public:
        // ---------- CONSTRUCTORES ----------
        EstadoOperativo();

        EstadoOperativo(int idEstadoOperativo, String^ descripcion);

        // ---------- GETTERS Y SETTERS ----------
        int getIdEstadoOperativo();
        void setIdEstadoOperativo(int id);

        String^ getDescripcion();
        void setDescripcion(String^ descripcion);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override; // Devuelve la descripción del estado.
    };
}