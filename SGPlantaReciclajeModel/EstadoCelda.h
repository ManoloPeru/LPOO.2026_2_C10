#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class EstadoCelda {
    private:
        int idEstadoCelda;
        String^ descripcion;

    public:
        EstadoCelda();
        EstadoCelda(int idEstadoCelda, String^ descripcion);

        int getIdEstadoCelda();
        void setIdEstadoCelda(int id);

        String^ getDescripcion();
        void setDescripcion(String^ descripcion);

        String^ ToString() override;
    };
}