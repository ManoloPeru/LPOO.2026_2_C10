#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    // ============================================================
    // CLASE: EstadoOperativoController
    // ============================================================
    // Capa de control que gestiona las operaciones CRUD sobre los
    // estados operativos, utilizando persistencia en archivo de texto.
    public ref class EstadoOperativoController {
    private:
        // Repositorio en memoria para almacenar los estados operativos
        List<EstadoOperativo^>^ repositorio;
        EstadoOperativoDAO^ dao;

    public:
        // Constructor: inicializa el repositorio vacío
        EstadoOperativoController();

        // ---------- OPERACIONES CRUD ----------

        // ListarEstados: devuelve la lista completa de estados operativos.
        List<EstadoOperativo^>^ ListarEstados();

        // RegistrarEstado: registra un nuevo estado. Devuelve "" si
        // tuvo éxito o un mensaje de error en caso contrario.
        String^ RegistrarEstado(EstadoOperativo^ estado);

        // ConsultarEstado: busca un estado por su ID.
        EstadoOperativo^ ConsultarEstado(int idEstadoOperativo);

        // ModificarEstado: actualiza la descripción de un estado.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ ModificarEstado(int idEstadoOperativo, String^ nuevaDescripcion);

        // EliminarEstado: elimina un estado por su ID.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ EliminarEstado(int idEstadoOperativo);

        // ---------- MÉTODOS PARA BASE DE DATOS SQL ----------
        List<EstadoOperativo^>^ ListarEstadosSQL();
        EstadoOperativo^ ConsultarEstadoSQL(int idEstadoOperativo);
        String^ RegistrarEstadoSQL(EstadoOperativo^ estado);
        String^ ModificarEstadoSQL(int idEstadoOperativo, String^ nuevaDescripcion);
        String^ EliminarEstadoSQL(int idEstadoOperativo);
    };
}