#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    // ============================================================
    // CLASE: TipoEstacionClasificadoraController
    // ============================================================
    // Capa de control que gestiona las operaciones CRUD sobre los
    // tipos de estación, utilizando persistencia en archivo de texto.
    public ref class TipoEstacionClasificadoraController {
    private:
        // Repositorio en memoria para almacenar los tipos de estación
        List<TipoEstacionClasificadora^>^ repositorio;

    public:
        // Constructor: inicializa el repositorio vacío
        TipoEstacionClasificadoraController();

        // ---------- OPERACIONES CRUD ----------

        // ListarTipos: devuelve la lista completa de tipos de estación.
        List<TipoEstacionClasificadora^>^ ListarTipos();

        // RegistrarTipo: registra un nuevo tipo. Devuelve "" si
        // tuvo éxito o un mensaje de error en caso contrario.
        String^ RegistrarTipo(TipoEstacionClasificadora^ tipo);

        // ConsultarTipo: busca un tipo por su ID.
        TipoEstacionClasificadora^ ConsultarTipo(int idTipoEstacion);

        // ModificarTipo: actualiza la descripción de un tipo.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ ModificarTipo(int idTipoEstacion, String^ nuevaDescripcion);

        // EliminarTipo: elimina un tipo por su ID.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ EliminarTipo(int idTipoEstacion);
    };
}