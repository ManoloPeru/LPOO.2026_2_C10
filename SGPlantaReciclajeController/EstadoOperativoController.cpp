#include "EstadoOperativoController.h"

namespace SGPlantaReciclajeController {

    // ============================================================
    // CONSTRUCTOR
    // ============================================================
    EstadoOperativoController::EstadoOperativoController() {
        repositorio = gcnew List<EstadoOperativo^>();
        dao = gcnew EstadoOperativoDAO();
    }

    // ============================================================
    // OPERACIONES CRUD
    // ============================================================

    List<EstadoOperativo^>^ EstadoOperativoController::ListarEstados() {
        return dao->buscarTodosArchivo();
    }

    String^ EstadoOperativoController::RegistrarEstado(EstadoOperativo^ estado) {
        if (estado == nullptr)
            return "Estado operativo nulo.";

        if (dao->buscarxIdArchivo(estado->getIdEstadoOperativo()) != nullptr)
            return "Ya existe un estado operativo con el ID especificado.";

        if (dao->buscarxDescripcionArchivo(estado->getDescripcion()) != nullptr)
            return "Ya existe un estado operativo con la misma descripción.";

        dao->registrarEstadoArchivo(estado);
        return "";
    }

    EstadoOperativo^ EstadoOperativoController::ConsultarEstado(int idEstadoOperativo) {
        return dao->buscarxIdArchivo(idEstadoOperativo);
    }

    String^ EstadoOperativoController::ModificarEstado(int idEstadoOperativo, String^ nuevaDescripcion) {
        EstadoOperativo^ estado = dao->buscarxIdArchivo(idEstadoOperativo);
        if (estado == nullptr)
            return "Estado operativo no encontrado.";

        if (String::IsNullOrWhiteSpace(nuevaDescripcion))
            return "La descripción no puede estar vacía.";

        estado->setDescripcion(nuevaDescripcion);
        dao->modificarEstadoArchivo(estado);
        return "";
    }

    String^ EstadoOperativoController::EliminarEstado(int idEstadoOperativo) {
        if (dao->buscarxIdArchivo(idEstadoOperativo) == nullptr)
            return "Estado operativo no encontrado.";

        dao->eliminarEstadoArchivo(idEstadoOperativo);
        return "";
    }

    // ============================================================
    // MÉTODOS PARA BASE DE DATOS SQL
    // ============================================================
    List<EstadoOperativo^>^ EstadoOperativoController::ListarEstadosSQL() {
        return dao->buscarTodosSQL();
    }

    EstadoOperativo^ EstadoOperativoController::ConsultarEstadoSQL(int idEstadoOperativo) {
        return dao->buscarxIdSQL(idEstadoOperativo);
    }

    String^ EstadoOperativoController::RegistrarEstadoSQL(EstadoOperativo^ estado) {
        if (estado == nullptr) return "Estado operativo nulo.";

        // Validar que no exista en la BD
        if (dao->buscarxIdSQL(estado->getIdEstadoOperativo()) != nullptr)
            return "Ya existe un estado operativo con el ID especificado en la BD.";

        bool exito = dao->registrarEstadoSQL(estado);
        return exito ? "" : "Ocurrió un error al registrar en la BD.";
    }

    String^ EstadoOperativoController::ModificarEstadoSQL(int idEstadoOperativo, String^ nuevaDescripcion) {
        EstadoOperativo^ estado = dao->buscarxIdSQL(idEstadoOperativo);
        if (estado == nullptr) return "Estado operativo no encontrado en la BD.";
        if (String::IsNullOrWhiteSpace(nuevaDescripcion)) return "La descripción no puede estar vacía.";

        estado->setDescripcion(nuevaDescripcion);
        bool exito = dao->modificarEstadoSQL(estado);
        return exito ? "" : "Ocurrió un error al modificar en la BD.";
    }

    String^ EstadoOperativoController::EliminarEstadoSQL(int idEstadoOperativo) {
        if (dao->buscarxIdSQL(idEstadoOperativo) == nullptr)
            return "Estado operativo no encontrado en la BD.";

        bool exito = dao->eliminarEstadoSQL(idEstadoOperativo);
        return exito ? "" : "Ocurrió un error al eliminar en la BD.";
    }
}