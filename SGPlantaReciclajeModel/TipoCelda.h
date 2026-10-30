#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class TipoCelda {
    private:
        int idTipoCelda;
        String^ descripcion;

    public:
        TipoCelda();
        TipoCelda(int idTipoCelda, String^ descripcion);

        int getIdTipoCelda();
        void setIdTipoCelda(int id);

        String^ getDescripcion();
        void setDescripcion(String^ descripcion);

        String^ ToString() override;
    };
}