#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class CeldaProcesoController {
    private:
        List<CeldaProceso^>^ repositorio; // Repositorio en memoria
        CeldaProcesoDAO^ dao;

    public:
        CeldaProcesoController();

        // CRUD básico
        String^ AgregarCelda(CeldaProceso^ celda);
        List<CeldaProceso^>^ ListarCeldas();
        String^ ModificarCelda(String^ id, String^ nuevoNombre, int nuevoTipo, int nuevoEstado, double nuevaCapacidad);
        String^ EliminarCelda(String^ id);
        CeldaProceso^ ConsultarCelda(String^ id);
        List<CeldaProceso^>^ ConsultarCeldaByFiltros(String^ id, int idTipo, int idEstado);

        // Sincronización
        void GuardarCambios(); // Vuelca el repositorio en memoria al archivo binario
    };
}