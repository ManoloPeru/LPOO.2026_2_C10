#include "TipoEstacionClasificadoraController.h"

namespace SGPlantaReciclajeController {

    // ============================================================
    // CONSTRUCTOR
    // ============================================================
    TipoEstacionClasificadoraController::TipoEstacionClasificadoraController() {
        repositorio = gcnew List<TipoEstacionClasificadora^>();
    }

    // ============================================================
    // OPERACIONES CRUD
    // ============================================================

    List<TipoEstacionClasificadora^>^ TipoEstacionClasificadoraController::ListarTipos() {
        TipoEstacionClasificadoraDAO^ dao = gcnew TipoEstacionClasificadoraDAO();
        return dao->buscarTodosArchivo();
    }

    String^ TipoEstacionClasificadoraController::RegistrarTipo(TipoEstacionClasificadora^ tipo) {
        TipoEstacionClasificadoraDAO^ dao = gcnew TipoEstacionClasificadoraDAO();

        if (tipo == nullptr)
            return "Tipo de estación nulo.";

        if (dao->buscarxIdArchivo(tipo->getIdTipoEstacion()) != nullptr)
            return "Ya existe un tipo de estación con el ID especificado.";

        if (dao->buscarxDescripcionArchivo(tipo->getDescripcion()) != nullptr)
            return "Ya existe un tipo de estación con la misma descripción.";

        dao->registrarTipoArchivo(tipo);
        return "";
    }

    TipoEstacionClasificadora^ TipoEstacionClasificadoraController::ConsultarTipo(int idTipoEstacion) {
        TipoEstacionClasificadoraDAO^ dao = gcnew TipoEstacionClasificadoraDAO();
        return dao->buscarxIdArchivo(idTipoEstacion);
    }

    String^ TipoEstacionClasificadoraController::ModificarTipo(int idTipoEstacion, String^ nuevaDescripcion) {
        TipoEstacionClasificadoraDAO^ dao = gcnew TipoEstacionClasificadoraDAO();

        TipoEstacionClasificadora^ tipo = dao->buscarxIdArchivo(idTipoEstacion);
        if (tipo == nullptr)
            return "Tipo de estación no encontrado.";

        if (String::IsNullOrWhiteSpace(nuevaDescripcion))
            return "La descripción no puede estar vacía.";

        tipo->setDescripcion(nuevaDescripcion);
        dao->modificarTipoArchivo(tipo);
        return "";
    }

    String^ TipoEstacionClasificadoraController::EliminarTipo(int idTipoEstacion) {
        TipoEstacionClasificadoraDAO^ dao = gcnew TipoEstacionClasificadoraDAO();

        if (dao->buscarxIdArchivo(idTipoEstacion) == nullptr)
            return "Tipo de estación no encontrado.";

        dao->eliminarTipoArchivo(idTipoEstacion);
        return "";
    }
}