#include "EstadoCeldaController.h"

namespace SGPlantaReciclajeController {

    EstadoCeldaController::EstadoCeldaController() {
        repositorio = gcnew List<EstadoCelda^>();
    }

    List<EstadoCelda^>^ EstadoCeldaController::ListarEstados() {
        EstadoCeldaDAO^ dao = gcnew EstadoCeldaDAO();
        return dao->buscarTodosArchivo();
    }

    String^ EstadoCeldaController::RegistrarEstado(EstadoCelda^ estado) {
        EstadoCeldaDAO^ dao = gcnew EstadoCeldaDAO();
        if (estado == nullptr) return "Estado de celda nulo.";
        if (dao->buscarxIdArchivo(estado->getIdEstadoCelda()) != nullptr)
            return "Ya existe un estado de celda con el ID especificado.";
        if (dao->buscarxDescripcionArchivo(estado->getDescripcion()) != nullptr)
            return "Ya existe un estado de celda con la misma descripción.";

        dao->registrarEstadoArchivo(estado);
        return "";
    }

    EstadoCelda^ EstadoCeldaController::ConsultarEstado(int idEstadoCelda) {
        EstadoCeldaDAO^ dao = gcnew EstadoCeldaDAO();
        return dao->buscarxIdArchivo(idEstadoCelda);
    }

    String^ EstadoCeldaController::ModificarEstado(int idEstadoCelda, String^ nuevaDescripcion) {
        EstadoCeldaDAO^ dao = gcnew EstadoCeldaDAO();
        EstadoCelda^ estado = dao->buscarxIdArchivo(idEstadoCelda);
        if (estado == nullptr) return "Estado de celda no encontrado.";
        if (String::IsNullOrWhiteSpace(nuevaDescripcion)) return "La descripción no puede estar vacía.";

        estado->setDescripcion(nuevaDescripcion);
        dao->modificarEstadoArchivo(estado);
        return "";
    }

    String^ EstadoCeldaController::EliminarEstado(int idEstadoCelda) {
        EstadoCeldaDAO^ dao = gcnew EstadoCeldaDAO();
        if (dao->buscarxIdArchivo(idEstadoCelda) == nullptr) return "Estado de celda no encontrado.";
        dao->eliminarEstadoArchivo(idEstadoCelda);
        return "";
    }
}