#include "CeldaProcesoController.h"

namespace SGPlantaReciclajeController {

    CeldaProcesoController::CeldaProcesoController() {
        this->dao = gcnew CeldaProcesoDAO();

        // Paso 1: Cargar automáticamente las celdas del archivo a memoria
        this->repositorio = dao->buscarTodosArchivo();
    }

    String^ CeldaProcesoController::AgregarCelda(CeldaProceso^ celda) {
        if (celda == nullptr) return "La celda es nula.";
        if (String::IsNullOrWhiteSpace(celda->getId())) return "El ID es obligatorio.";

        // Validar ID único en memoria
        for each (CeldaProceso ^ c in this->repositorio) {
            if (c->getId()->Equals(celda->getId(), StringComparison::OrdinalIgnoreCase)) {
                return "Error: El ID de la celda ya se encuentra registrado.";
            }
        }
        this->repositorio->Add(celda);
        GuardarCambios(); // Sincronizar con archivo
        return ""; // Éxito
    }

    List<CeldaProceso^>^ CeldaProcesoController::ListarCeldas() {
        return this->dao->buscarTodosArchivo();
    }

    CeldaProceso^ CeldaProcesoController::ConsultarCelda(String^ id) {
		this->repositorio = this->dao->buscarTodosArchivo(); 
        for each (CeldaProceso ^ c in this->repositorio) {
            if (c->getId()->Equals(id, StringComparison::OrdinalIgnoreCase)) {
                return c;
            }
        }
        return nullptr;
    }

    List<CeldaProceso^>^ CeldaProcesoController::ConsultarCeldaByFiltros(String^ id, int idTipo, int idEstado) {
        CeldaProcesoDAO^ daoCelda = gcnew CeldaProcesoDAO();
        return daoCelda->buscarByFiltros(id, idTipo, idEstado);
    }

    String^ CeldaProcesoController::ModificarCelda(String^ id, String^ nuevoNombre, int nuevoTipo, int nuevoEstado, double nuevaCapacidad) {
        CeldaProceso^ celda = ConsultarCelda(id);
        if (celda == nullptr) return "Celda no encontrada.";

        celda->setNombre(nuevoNombre);
        celda->setTipo(nuevoTipo);
        celda->setEstado(nuevoEstado);
        celda->setCapacidad(nuevaCapacidad);

        GuardarCambios(); // Sincronizar con archivo
        return ""; // Éxito
    }

    String^ CeldaProcesoController::EliminarCelda(String^ id) {
        for (int i = 0; i < this->repositorio->Count; i++) {
            if (this->repositorio[i]->getId()->Equals(id, StringComparison::OrdinalIgnoreCase)) {
                this->repositorio->RemoveAt(i);
                GuardarCambios(); // Sincronizar con archivo
                return ""; // Éxito
            }
        }
        return "Celda no encontrada.";
    }

    void CeldaProcesoController::GuardarCambios() {
        dao->escribirArchivo(this->repositorio);
    }
}