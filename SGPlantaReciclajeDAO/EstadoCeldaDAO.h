#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace SGPlantaReciclajeModel;

    public ref class EstadoCeldaDAO : public BaseDAO {
    private:
        String^ nombreArchivo = "EstadoCeldas.txt";

    public:
        EstadoCeldaDAO();

        List<EstadoCelda^>^ buscarTodosArchivo();
        EstadoCelda^ buscarxIdArchivo(int idEstadoCelda);
        EstadoCelda^ buscarxDescripcionArchivo(String^ descripcion);

        void registrarEstadoArchivo(EstadoCelda^ estado);
        void modificarEstadoArchivo(EstadoCelda^ estado);
        void eliminarEstadoArchivo(int idEstadoCelda);
        void escribirArchivo(List<EstadoCelda^>^ listaEstados);
    };
}