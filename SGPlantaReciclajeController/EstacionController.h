#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class EstacionController {
    private:
        EstacionDAO^ dao;

    public:
        EstacionController();

        // Retorna "" si fue exitoso, o un mensaje de error en caso contrario
        String^ RegistrarEstacion(Estacion^ estacion);
        List<Estacion^>^ ListarEstaciones();
        Estacion^ ConsultarEstacion(int estacionId);
        List<Estacion^>^ ConsultarEstacionByIdEstado(int estacionId, int idEstado);
        String^ ModificarEstacion(Estacion^ estacion);
        String^ EliminarEstacion(int estacionId);
    };
}