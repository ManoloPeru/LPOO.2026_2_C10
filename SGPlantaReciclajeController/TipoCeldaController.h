#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class TipoCeldaController {
    private:
        List<TipoCelda^>^ repositorio;

    public:
        TipoCeldaController();

        List<TipoCelda^>^ ListarTipos();
        String^ RegistrarTipo(TipoCelda^ tipo);
        TipoCelda^ ConsultarTipo(int idTipoCelda);
        String^ ModificarTipo(int idTipoCelda, String^ nuevaDescripcion);
        String^ EliminarTipo(int idTipoCelda);
    };
}