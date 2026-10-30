#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    // ============================================================
    // CLASE: EstacionClasificadoraController
    // ============================================================
    // Capa de control que gestiona las operaciones CRUD sobre las
    // estaciones clasificadoras utilizando un repositorio en memoria
    // y persistencia en archivo de texto.
    public ref class EstacionClasificadoraController {
    private:
        // Repositorio en memoria para almacenar las estaciones clasificadoras
        List<EstacionClasificadora^>^ repositorio;

    public:
        // Constructor: inicializa el repositorio vacío
        EstacionClasificadoraController();

        List<EstacionClasificadora^>^ ListarEstaciones();

        String^ RegistrarEstacion(EstacionClasificadora^ estacion);

        EstacionClasificadora^ ConsultarEstacion(String^ serialId);

        List<EstacionClasificadora^>^ ConsultarEstacionByFiltros(String^ serialId, int idTipo, int idEstado);

        String^ ModificarEstacion(String^ serialId, String^ nuevoAlias, int nuevoTipo, int nuevoEstado, String^ nuevaUbicacion);

        String^ EliminarEstacion(String^ serialId);

        // ---------- PROXIMAMENTE MÉTODOS PARA EL MANEJO DE ARCHIVOS BIN ----------

        // ---------- PROXIMAMENTE MÉTODOS PARA EL MANEJO DE BASE DE DATOS ----------

        // ---------- MÉTODOS AUXILIARES ----------

        // ContarEstaciones: devuelve el número total de estaciones registradas.
        int ContarEstaciones();

        // ExisteEstacion: verifica si existe una estación con el Serial ID dado.
        bool ExisteEstacion(String^ serialId);

        void LibreraMemoria();

        // InsertarEstacionesIniciales: inserta 3 estaciones de ejemplo.
        void InsertarEstacionesIniciales();

        // ---------- MÉTODOS PARA EL MANEJO DE ARCHIVOS TXT ----------

        
    };
}