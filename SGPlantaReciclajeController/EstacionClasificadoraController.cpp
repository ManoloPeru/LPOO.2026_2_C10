#include "EstacionClasificadoraController.h"

namespace SGPlantaReciclajeController {

    // ============================================================
    // CONSTRUCTOR
    // ============================================================
    EstacionClasificadoraController::EstacionClasificadoraController() {
        // Inicializar el repositorio en memoria
        repositorio = gcnew List<EstacionClasificadora^>();
    }

    // ============================================================
    // OPERACIONES CRUD
    // ============================================================

    List<EstacionClasificadora^>^ EstacionClasificadoraController::ListarEstaciones() {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();
        return daoEstacion->buscarTodosArchivo();          // ← Lee del archivo
    }

    String^ EstacionClasificadoraController::RegistrarEstacion(EstacionClasificadora^ estacion) {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();
        if (estacion == nullptr) {
            Console::WriteLine("Error: Estacion nula.");
            return "Estacion nula.";
        }
        if (daoEstacion->buscarxSerialIdArchivo(estacion->getSerialId()) != nullptr) {
            Console::WriteLine("Error: Estacion con Serial ID {0} ya existe.", estacion->getSerialId());
            return "Estacion con Serial ID {0} ya existe.";
        }
        daoEstacion->registrarEstacionArchivo(estacion);   // ← Persistencia en archivo
        return "";
    }

    EstacionClasificadora^ EstacionClasificadoraController::ConsultarEstacion(String^ serialId) {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();
        return daoEstacion->buscarxSerialIdArchivo(serialId);  
    }

    String^ EstacionClasificadoraController::ModificarEstacion(String^ serialId, String^ nuevoAlias, int nuevoTipo, int nuevoEstado, String^ nuevaUbicacion) {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();
        EstacionClasificadora^ estacion = daoEstacion->buscarxSerialIdArchivo(serialId);
        if (estacion == nullptr)
            return "Estación no encontrada.";
        estacion->setAlias(nuevoAlias);
        estacion->setEstado(nuevoEstado);
        estacion->setUbicacion(nuevaUbicacion);
        estacion->setTipo(nuevoTipo);
        daoEstacion->modificarEstacionArchivo(estacion);
        return "";
    }

    String^ EstacionClasificadoraController::EliminarEstacion(String^ serialId) {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();

        if (daoEstacion->buscarxSerialIdArchivo(serialId) == nullptr)
            return "Estación no encontrada.";
        daoEstacion->eliminarEstacionArchivo(serialId);
        return "";
    }
    
    List<EstacionClasificadora^>^ EstacionClasificadoraController::ConsultarEstacionByFiltros(String^ serialId, int idTipo, int idEstado) {
        EstacionClasificadoraDAO^ daoEstacion = gcnew EstacionClasificadoraDAO();
        return daoEstacion->buscarByFiltrosArchivo(serialId, idTipo, idEstado);
    }
    

    // ============================================================
    // MÉTODOS AUXILIARES
    // ============================================================

    // ContarEstaciones: devuelve el número total de estaciones registradas.
    int EstacionClasificadoraController::ContarEstaciones() {
        return repositorio->Count;
    }

    // ExisteEstacion: verifica si existe una estación con el Serial ID dado.
    bool EstacionClasificadoraController::ExisteEstacion(String^ serialId) {
        return ConsultarEstacion(serialId) != nullptr;
    }

    void EstacionClasificadoraController::LibreraMemoria() {
        this->repositorio = nullptr;
    }

    // InsertarEstacionesIniciales: inserta 3 estaciones de ejemplo.
    void EstacionClasificadoraController::InsertarEstacionesIniciales() {
        Console::WriteLine();
        Console::ForegroundColor = ConsoleColor::DarkBlue;
        Console::WriteLine("=== INSERTAR ESTACIONES CLASIFICADORAS DE EJEMPLO ===");

        // Estación 1: Neumática de Polímeros
        EstacionClasificadora^ estacionNeumatica = gcnew EstacionClasificadora(
            "EST-NEU-001",
            "Clasificadora-Neumatica-01",
            1,
            1,
            "Línea de Clasificación de Polímeros"
        );
        RegistrarEstacion(estacionNeumatica);
        Console::WriteLine("Estacion registrada: " + estacionNeumatica->ToString());

        // Estación 2: Separador Magnético
        EstacionClasificadora^ estacionMagnetica = gcnew EstacionClasificadora(
            "SEP-MAG-002",
            "Separadora-Mag-05",
            2,  
            2,
            "Zona de Extracción de Metales"
        );
        RegistrarEstacion(estacionMagnetica);
        Console::WriteLine("Estacion registrada: " + estacionMagnetica->ToString());

        // Estación 3: Clasificación Óptica
        EstacionClasificadora^ estacionOptica = gcnew EstacionClasificadora(
            "EST-OPT-003",
            "Clasificadora-Optica-01",
            3,
            3,
            "Línea de Clasificación de Polímeros"
        );
        RegistrarEstacion(estacionOptica);
        Console::WriteLine("Estacion registrada: " + estacionOptica->ToString());

        Console::WriteLine("\nSe han insertado 3 estaciones clasificadoras exitosamente.");
        Console::WriteLine("Total de estaciones en el sistema: {0}", ContarEstaciones());
    }

    // ============================================================
    // OPERACIONES CRUD PARA EL MANEJO DE ARCHIVOS
    // ============================================================
    
}