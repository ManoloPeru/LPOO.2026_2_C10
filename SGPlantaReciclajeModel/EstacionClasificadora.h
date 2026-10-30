#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class EstacionClasificadora {

    private:
        String^ serialId; // Serial ID único de la estación (e.g., "EST-NEU-001", "SEP-MAG-002"). Es el identificador visible para el usuario.
        String^ alias; // Alias o nombre descriptivo de la estación (e.g., "Clasificadora-01", "Separadora-Mag-05").
        int tipo; // Tipo de estación clasificadora (e.g., 1, 2, 3).
        int estado; // Estado operativo actual de la estación (1, 2, 3).
        String^ ubicacion; // Ubicación específica en la planta (e.g., "Zona de Extracción de Metales").

    public:
        // ---------- CONSTRUCTORES ----------
        EstacionClasificadora();

        EstacionClasificadora(String^ serialId, String^ alias, int tipo, int estado, String^ ubicacion);

        // ---------- GETTERS Y SETTERS ----------
        String^ getSerialId();
        void setSerialId(String^ serialId);

        String^ getAlias();
        void setAlias(String^ alias);

        int getTipo();
        void setTipo(int tipo);

        int getEstado();
        void setEstado(int estado);

        String^ getUbicacion();
        void setUbicacion(String^ ubicacion);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override; // Devuelve una representación en texto de la estación.
    };
}