#pragma once

#include "UnidadControl.h"
// ↑ Se incluye el encabezado de UnidadControl porque esta clase mantiene una
//   relación de COMPOSICIÓN con ella: cada UnidadClasificadora TIENE una
//   UnidadControl como parte integral de su estructura.

namespace SGPlantaReciclajeModel {
    // ↑ Espacio de nombres del proyecto MODELO (biblioteca DLL).
    //   Agrupa todas las clases del dominio de la planta de reciclaje.

    using namespace System;
    // ↑ Permite usar tipos básicos de .NET como String, Int32, DateTime, etc.

    using namespace System::Collections::Generic;
    // ↑ Permite usar colecciones genéricas como List<T>, necesaria para
    //   el método verificarAlertas() que devuelve List<String^>^.

    // ============================================================
    // CLASE ABSTRACTA: UnidadClasificadora
    // ============================================================
    // Esta clase representa cualquier pieza móvil clasificadora de la planta.
    // Es ABSTRACTA porque no se instancia directamente: solo sirve como base
    // para las especializaciones BrazoNeumaticoClasificador y SeparadorMagnetico.
    public ref class UnidadClasificadora abstract {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    protected:
        // ↑ 'protected' permite que las subclases (Brazo, Separador) accedan
        //   directamente a estos atributos, pero no desde fuera de la jerarquía.

        int idUnidadClasificadora;
        // ↑ ATRIBUTO PK (Primary Key): identificador único de hardware.
        //   Es heredado por las subclases, por lo que NO se redefine en ellas.

        String^ fabricante;
        // ↑ Nombre del fabricante de la unidad. El '^' indica que es un
        //   objeto administrado (referencia CLR) de tipo String.

        double tiempoOperacionHoras;
        // ↑ Tiempo de operación acumulado medido en horas (h).
        //   Se usa double para permitir fracciones de hora.

        UnidadControl^ unidadControl;
        // ↑ ATRIBUTO DE COMPOSICIÓN: cada unidad clasificadora TIENE una
        //   UnidadControl obligatoria. Si la unidad se destruye, la
        //   controladora también (relación de ciclo de vida dependiente).

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        UnidadClasificadora();
        // ↑ Constructor vacío (por defecto): inicializa los atributos con
        //   valores neutros. Útil para crear objetos sin datos iniciales.

        UnidadClasificadora(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras);
        // ↑ Constructor con parámetros: permite crear una unidad con datos
        //   específicos desde el momento de su instanciación.

        // ---------- GETTERS Y SETTERS ----------
        // Encapsulan el acceso a los atributos (principio de encapsulamiento).

        int getIdUnidadClasificadora();
        // ↑ Devuelve el ID único (PK heredada por las subclases).

        void setIdUnidadClasificadora(int id);
        // ↑ Permite modificar el ID (por ejemplo, al reasignar hardware).

        String^ getFabricante();
        // ↑ Devuelve el nombre del fabricante.

        void setFabricante(String^ fabricante);
        // ↑ Permite cambiar el fabricante (por ejemplo, en un reemplazo).

        double getTiempoOperacionHoras();
        // ↑ Devuelve el tiempo acumulado de operación en horas.

        void setTiempoOperacionHoras(double horas);
        // ↑ Permite asignar directamente el tiempo de operación
        //   (útil para reinicios o calibraciones).

        void acumularTiempoOperacion(double horas);
        // ↑ MÉTODO DE NEGOCIO: incrementa el tiempo acumulado sumando las
        //   horas transcurridas. Se usa durante el monitoreo continuo.

        // ---------- MÉTODOS DE LA COMPOSICIÓN ----------
        UnidadControl^ getUnidadControl();
        // ↑ Devuelve la UnidadControl asociada (parte de la composición).

        void setUnidadControl(UnidadControl^ unidadControl);
        // ↑ Asigna o reemplaza la UnidadControl de esta unidad clasificadora.
        //   Si la controladora anterior se reemplaza, su firmware asociado
        //   queda inaccesible (composición estricta).

        // ---------- MÉTODOS ABSTRACTOS (contrato ISensorizable) ----------
        virtual String^ leerTelemetria() abstract;
        // ↑ Método ABSTRACTO: obliga a cada subclase a implementar su propia
        //   versión de lectura de telemetría (temperatura en °C y vibración
        //   en Hz). Refleja el contrato de la interfaz ISensorizable.

        virtual List<String^>^ verificarAlertas() abstract;
        // ↑ Método ABSTRACTO: obliga a cada subclase a implementar su propia
        //   verificación de alertas. Devuelve una lista genérica de cadenas
        //   con las alertas activas.
    };
}