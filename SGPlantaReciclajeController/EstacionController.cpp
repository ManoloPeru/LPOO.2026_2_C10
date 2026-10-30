#include "EstacionController.h"

namespace SGPlantaReciclajeController {

    EstacionController::EstacionController() {
        dao = gcnew EstacionDAO();
    }

    String^ EstacionController::RegistrarEstacion(Estacion^ estacion) {
        // Validaciones básicas
        if (estacion == nullptr) return "La estación es nula.";
        if (String::IsNullOrWhiteSpace(estacion->getAlias())) return "El alias es obligatorio.";
        if (estacion->getCapacidadKgH() <= 0) return "La capacidad debe ser mayor a 0.";

        // Evitar IDs duplicados
        if (dao->buscarxId(estacion->getEstacionId()) != nullptr) {
            return "El ID de la estación ya se encuentra registrado.";
        }

        bool exito = dao->registrarEstacion(estacion);
        return exito ? "" : "Ocurrió un error al registrar la estación.";
    }

    List<Estacion^>^ EstacionController::ListarEstaciones() {
        return dao->buscarTodos();
    }

    Estacion^ EstacionController::ConsultarEstacion(int estacionId) {
        return dao->buscarxId(estacionId);
    }

    List<Estacion^>^ EstacionController::ConsultarEstacionByIdEstado(int estacionId, int idEstado) {
        return dao->buscarxIdxEstado(estacionId, idEstado);
    }

    String^ EstacionController::ModificarEstacion(Estacion^ estacion) {
        if (estacion == nullptr) return "La estación es nula.";
        if (estacion->getEstacionId() <= 0) return "El ID de la estación no es válido.";
        if (String::IsNullOrWhiteSpace(estacion->getAlias())) return "El alias es obligatorio.";

        // Verificar que exista antes de modificar
        if (dao->buscarxId(estacion->getEstacionId()) == nullptr) {
            return "Estación no encontrada.";
        }

        bool exito = dao->modificarEstacion(estacion);
        return exito ? "" : "Ocurrió un error al modificar la estación.";
    }

    String^ EstacionController::EliminarEstacion(int estacionId) {
        if (estacionId <= 0) return "El ID no es válido.";

        if (dao->buscarxId(estacionId) == nullptr) {
            return "Estación no encontrada.";
        }

        bool exito = dao->eliminarEstacion(estacionId);
        return exito ? "" : "Ocurrió un error al eliminar la estación.";
    }
}