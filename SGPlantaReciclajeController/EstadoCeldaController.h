#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class EstadoCeldaController {
    private:
        List<EstadoCelda^>^ repositorio;

    public:
        EstadoCeldaController();

        List<EstadoCelda^>^ ListarEstados();
        String^ RegistrarEstado(EstadoCelda^ estado);
        EstadoCelda^ ConsultarEstado(int idEstadoCelda);
        String^ ModificarEstado(int idEstadoCelda, String^ nuevaDescripcion);
        String^ EliminarEstado(int idEstadoCelda);
    };
}