#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace SGPlantaReciclajeModel;

    public ref class EstacionDAO : public BaseDAO {
    public:
        EstacionDAO();

        // CRUD
        int registrarEstacion(Estacion^ estacion);
        List<Estacion^>^ buscarTodos();
        Estacion^ buscarxId(int estacionId);
        List<Estacion^>^ buscarxIdxEstado(int estacionId, int idEstado);
        bool modificarEstacion(Estacion^ estacion);
        bool eliminarEstacion(int estacionId);
    };
}