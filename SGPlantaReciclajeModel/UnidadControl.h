#pragma once

#include "Firmware.h"
// ↑ Se incluye el encabezado de Firmware porque esta clase mantiene una
//   relación de COMPOSICIÓN con él: cada UnidadControl POSEE un Firmware
//   como parte integral e inseparable de su estructura.
//   Sin este include, el compilador no conocería el tipo Firmware^.

namespace SGPlantaReciclajeModel {
    // ↑ Espacio de nombres del proyecto MODELO (biblioteca DLL).
    //   Agrupa todas las clases del dominio de la planta de reciclaje.

    using namespace System;
    // ↑ Permite usar tipos básicos de .NET como String, Int32, DateTime, etc.
    //   NOTA: No se incluye System::Collections::Generic porque esta clase
    //   no utiliza colecciones genéricas (List<T>, etc.).

    // ============================================================
    // CLASE CONCRETA: UnidadControl
    // ============================================================
    // Esta clase representa el centro de procesamiento de señales de una
    // unidad clasificadora. Es el "cerebro" que gestiona el flujo de datos
    // y ejecuta comandos sobre el hardware.
    //
    // RELACIONES:
    //   - COMPOSICIÓN con Firmware: cada UnidadControl TIENE un Firmware.
    //     Si la controladora se destruye o queda inoperativa, el firmware
    //     asociado se considera destruido o inaccesible.
    //   - COMPOSICIÓN inversa: cada UnidadClasificadora TIENE una UnidadControl
    //     (relación 1:1 obligatoria).
    public ref class UnidadControl {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    private:
        // ↑ 'private' significa que estos atributos son EXCLUSIVOS de esta clase.
        //   Solo se accede a ellos a través de getters y setters.

        int idUnidadControl;
        // ↑ ATRIBUTO PK (Primary Key): identificador único de la controladora.
        //   Permite distinguir una UnidadControl de otra en el sistema.

        double voltajeOperacion;
        // ↑ ATRIBUTO PROPIO: voltaje de operación nominal en Voltios DC (VDC).
        //   El valor típico en este dominio es 24 VDC.

        double frecuenciaReloj;
        // ↑ ATRIBUTO PROPIO: frecuencia de reloj medida en Megahercios (MHz).
        //   Determina la velocidad de procesamiento de señales de la controladora.

        Firmware^ firmware;
        // ↑ ATRIBUTO DE COMPOSICIÓN: referencia al Firmware que pertenece
        //   a esta controladora. El firmware es específico para el hardware
        //   y NO puede existir ni operar fuera de esta UnidadControl.
        //   Si la controladora se destruye, el firmware también.

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        UnidadControl();
        // ↑ Constructor vacío (por defecto): inicializa los atributos con
        //   valores neutros. Internamente crea un Firmware vacío para
        //   garantizar la composición 1:1 (nunca queda en nullptr).

        UnidadControl(int idUnidadControl, double voltajeOperacion, double frecuenciaReloj, Firmware^ firmware);
        // ↑ Constructor con TODOS los parámetros:
        //   - idUnidadControl: PK de la controladora.
        //   - voltajeOperacion: voltaje nominal (VDC).
        //   - frecuenciaReloj: frecuencia de reloj (MHz).
        //   - firmware: objeto Firmware que se compone con esta controladora.
        //   Este constructor materializa la composición al recibir el
        //   firmware como parámetro obligatorio.

        // ---------- GETTERS Y SETTERS ----------
        // Encapsulan el acceso a los atributos (principio de encapsulamiento).

        int getIdUnidadControl();
        // ↑ Devuelve el ID único (PK) de la controladora.

        void setIdUnidadControl(int id);
        // ↑ Permite modificar el ID (por ejemplo, en una reasignación).

        double getVoltajeOperacion();
        // ↑ Devuelve el voltaje de operación nominal en VDC.

        void setVoltajeOperacion(double voltaje);
        // ↑ Permite modificar el voltaje de operación (calibración).

        double getFrecuenciaReloj();
        // ↑ Devuelve la frecuencia de reloj en MHz.

        void setFrecuenciaReloj(double frecuencia);
        // ↑ Permite modificar la frecuencia de reloj (overclock/underclock).

        // ---------- MÉTODOS DE LA COMPOSICIÓN ----------
        Firmware^ getFirmware();
        // ↑ Devuelve el Firmware asociado (parte de la composición).
        //   Es la única vía de acceso al firmware desde el exterior.

        void setFirmware(Firmware^ firmware);
        // ↑ Asigna o reemplaza el Firmware de esta controladora.
        //   Si se reemplaza el firmware anterior, este queda inaccesible
        //   (composición estricta: el firmware viejo se destruye).

        // ---------- MÉTODOS DE NEGOCIO PROPIOS ----------
        // Representan comportamientos específicos de la controladora.

        void procesarSenales();
        // ↑ Procesa las señales de entrada provenientes de los sensores
        //   de telemetría de la unidad clasificadora asociada.
        //   Es la función principal de la controladora como centro de
        //   procesamiento de señales.

        void enviarComando(String^ comando);
        // ↑ Envía un comando de texto al hardware (actuadores de la unidad
        //   clasificadora). El comando se interpreta según el firmware.

        bool estaOperativa();
        // ↑ Verifica si la controladora está operativa. En la práctica,
        //   depende de que el firmware asociado no sea nullptr y esté
        //   correctamente cargado. Si el firmware se destruye, la
        //   controladora deja de estar operativa.
    };
}