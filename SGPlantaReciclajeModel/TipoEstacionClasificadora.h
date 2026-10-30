#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // ============================================================
    // CLASE: TipoEstacion
    // ============================================================
    // Representa un tipo posible de estación clasificadora
    // (e.g., "Neumática", "Magnética", "Óptica", "Otros").
    //
    // Esta clase se usa como TABLA MAESTRA (o catálogo) para
    // poblar los ComboBox de la capa de presentación y para
    // validar que el tipo asignado a una estación sea uno
    // de los permitidos.
    public ref class TipoEstacionClasificadora {

    private:
        int idTipoEstacion;     // Identificador único del tipo (PK)
        String^ descripcion;    // Descripción del tipo (e.g., "Neumática")

    public:
        // ---------- CONSTRUCTORES ----------
        TipoEstacionClasificadora();

        TipoEstacionClasificadora(int idTipoEstacion, String^ descripcion);

        // ---------- GETTERS Y SETTERS ----------
        int getIdTipoEstacion();
        void setIdTipoEstacion(int id);

        String^ getDescripcion();
        void setDescripcion(String^ descripcion);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override; // Devuelve la descripción del tipo.
    };
}