#pragma once

namespace SGPlantaReciclajeView {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace SGPlantaReciclajeController;
    using namespace SGPlantaReciclajeModel;

    // ============================================================
    // CLASE: ComboHelper
    // ============================================================
    // Clase auxiliar (Helper) que centraliza el llenado de los
    // ComboBox de Tipo y Estado (tanto para Estaciones como para Celdas).
    //
    // Evita duplicar la lógica en múltiples formularios y permite
    // que, si mañana se agrega un nuevo formulario con los mismos
    // ComboBox, solo se invoque a este Helper.
    public ref class ComboHelper {

    public:
        // ------------------------------------------------------------
        // LlenarComboTipoEstacion: puebla un ComboBox con los tipos de estación
        // obtenidos desde el TipoEstacionClasificadoraController.
        // ------------------------------------------------------------
        static void LlenarComboTipoEstacion(ComboBox^ cmbTipo, int idSeleccionado);

        // ------------------------------------------------------------
        // LlenarComboEstadoEstacion: puebla un ComboBox con los estados
        // operativos obtenidos desde el EstadoOperativoController.
        // ------------------------------------------------------------
        static void LlenarComboEstadoEstacion(ComboBox^ cmbEstado, int idSeleccionado);

        // ------------------------------------------------------------
        // LlenarComboTipoCelda: puebla un ComboBox con los tipos de celda
        // obtenidos desde el TipoCeldaController.
        // ------------------------------------------------------------
        static void LlenarComboTipoCelda(ComboBox^ cmbTipo, int idSeleccionado);

        // ------------------------------------------------------------
        // LlenarComboEstadoCelda: puebla un ComboBox con los estados de celda
        // obtenidos desde el EstadoCeldaController.
        // ------------------------------------------------------------
        static void LlenarComboEstadoCelda(ComboBox^ cmbEstado, int idSeleccionado);

        // ------------------------------------------------------------
        // ObtenerIdSeleccionado: devuelve el ID (Key) seleccionado
        // en un ComboBox poblado con KeyValuePair<String^, String^>.
        // Devuelve -1 si no hay selección.
        // ------------------------------------------------------------
        static int ObtenerIdSeleccionado(ComboBox^ cmb);

        // ------------------------------------------------------------
        // SeleccionarPorId: recorre los ítems del ComboBox y selecciona aquel cuyo Key
        // coincida con el idSeleccionado. Si idSeleccionado <= 0, no
        // selecciona nada (SelectedIndex = -1).
        // ------------------------------------------------------------
        static void SeleccionarPorId(ComboBox^ cmb, int idSeleccionado);
    
        //LlenarComboEstadoEstacion pero desde la BD
        static void LlenarComboEstadoEstacionBD(ComboBox^ cmbEstado, int idSeleccionado);
    };

}