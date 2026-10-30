#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace SGPlantaReciclajeModel;

    public ref class TipoCeldaDAO : public BaseDAO {
    private:
        String^ nombreArchivo = "TipoCeldas.txt";

    public:
        TipoCeldaDAO();

        List<TipoCelda^>^ buscarTodosArchivo();
        TipoCelda^ buscarxIdArchivo(int idTipoCelda);
        TipoCelda^ buscarxDescripcionArchivo(String^ descripcion);

        void registrarTipoArchivo(TipoCelda^ tipo);
        void modificarTipoArchivo(TipoCelda^ tipo);
        void eliminarTipoArchivo(int idTipoCelda);
        void escribirArchivo(List<TipoCelda^>^ listaTipos);
    };
}