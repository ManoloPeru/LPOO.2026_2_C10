#include "TipoCeldaController.h"

namespace SGPlantaReciclajeController {

    TipoCeldaController::TipoCeldaController() {
        repositorio = gcnew List<TipoCelda^>();
    }

    List<TipoCelda^>^ TipoCeldaController::ListarTipos() {
        TipoCeldaDAO^ dao = gcnew TipoCeldaDAO();
        return dao->buscarTodosArchivo();
    }

    String^ TipoCeldaController::RegistrarTipo(TipoCelda^ tipo) {
        TipoCeldaDAO^ dao = gcnew TipoCeldaDAO();
        if (tipo == nullptr) return "Tipo de celda nulo.";
        if (dao->buscarxIdArchivo(tipo->getIdTipoCelda()) != nullptr)
            return "Ya existe un tipo de celda con el ID especificado.";
        if (dao->buscarxDescripcionArchivo(tipo->getDescripcion()) != nullptr)
            return "Ya existe un tipo de celda con la misma descripción.";

        dao->registrarTipoArchivo(tipo);
        return "";
    }

    TipoCelda^ TipoCeldaController::ConsultarTipo(int idTipoCelda) {
        TipoCeldaDAO^ dao = gcnew TipoCeldaDAO();
        return dao->buscarxIdArchivo(idTipoCelda);
    }

    String^ TipoCeldaController::ModificarTipo(int idTipoCelda, String^ nuevaDescripcion) {
        TipoCeldaDAO^ dao = gcnew TipoCeldaDAO();
        TipoCelda^ tipo = dao->buscarxIdArchivo(idTipoCelda);
        if (tipo == nullptr) return "Tipo de celda no encontrado.";
        if (String::IsNullOrWhiteSpace(nuevaDescripcion)) return "La descripción no puede estar vacía.";

        tipo->setDescripcion(nuevaDescripcion);
        dao->modificarTipoArchivo(tipo);
        return "";
    }

    String^ TipoCeldaController::EliminarTipo(int idTipoCelda) {
        TipoCeldaDAO^ dao = gcnew TipoCeldaDAO();
        if (dao->buscarxIdArchivo(idTipoCelda) == nullptr) return "Tipo de celda no encontrado.";
        dao->eliminarTipoArchivo(idTipoCelda);
        return "";
    }
}