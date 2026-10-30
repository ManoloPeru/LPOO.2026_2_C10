#pragma once

// NOTA: No se incluye ningún otro encabezado del modelo porque FuentePotencia
//       NO participa en relaciones de composición ni agregación con otras clases.
//       Solo mantiene una ASOCIACIÓN externa con EstacionClasificadora, la cual
//       se modela desde el lado de la estación (no desde aquí).

namespace SGPlantaReciclajeModel {
    // ↑ Espacio de nombres del proyecto MODELO (biblioteca DLL).
    //   Agrupa todas las clases del dominio de la planta de reciclaje.

    using namespace System;
    // ↑ Permite usar tipos básicos de .NET como String, Int32, DateTime, etc.
    //   NOTA: No se incluye System::Collections::Generic porque esta clase
    //   no utiliza colecciones genéricas (List<T>, etc.).

    // ============================================================
    // CLASE CONCRETA: FuentePotencia
    // ============================================================
    // Esta clase representa una fuente de alimentación externa que suministra
    // la energía necesaria para el movimiento de las unidades clasificadoras
    // de una o varias estaciones.
    //
    // RELACIÓN PRINCIPAL:
    //   - ASOCIACIÓN con EstacionClasificadora: una misma fuente puede
    //     alimentar a varias estaciones simultáneamente (relación 1..*:1).
    //     Es una dependencia EXTERNA, no una composición ni agregación:
    //     la fuente existe independientemente de las estaciones y puede
    //     compartirse entre ellas.
    public ref class FuentePotencia {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    private:
        // ↑ 'private' significa que estos atributos son EXCLUSIVOS de esta clase.
        //   Solo se accede a ellos a través de getters y setters.

        int idFuentePotencia;
        // ↑ ATRIBUTO PK (Primary Key): identificador único de la fuente.
        //   Permite distinguir una fuente de otra en el sistema.

        double voltajeSalida;
        // ↑ ATRIBUTO PROPIO: voltaje de salida expresado en Voltios (V).
        //   Determina la tensión que la fuente entrega a las estaciones.

        double corrienteMaxima;
        // ↑ ATRIBUTO PROPIO: corriente máxima expresada en Amperios (A).
        //   Define el límite superior de corriente que la fuente puede
        //   suministrar sin sobrecargarse.

        double eficienciaEnergetica;
        // ↑ ATRIBUTO PROPIO: eficiencia energética expresada en porcentaje (%).
        //   Indica qué tan eficiente es la fuente al convertir la energía
        //   de entrada en energía de salida útil.

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        FuentePotencia();
        // ↑ Constructor vacío (por defecto): inicializa los atributos con
        //   valores neutros. Útil para crear objetos sin datos iniciales.

        FuentePotencia(int idFuentePotencia, double voltajeSalida, double corrienteMaxima, double eficienciaEnergetica);
        // ↑ Constructor con TODOS los parámetros:
        //   - idFuentePotencia: PK de la fuente.
        //   - voltajeSalida: voltaje de salida (V).
        //   - corrienteMaxima: corriente máxima (A).
        //   - eficienciaEnergetica: eficiencia (%).
        //   Permite crear una fuente completamente configurada desde su
        //   instanciación.

        // ---------- GETTERS Y SETTERS ----------
        // Encapsulan el acceso a los atributos (principio de encapsulamiento).

        int getIdFuentePotencia();
        // ↑ Devuelve el ID único (PK) de la fuente.

        void setIdFuentePotencia(int id);
        // ↑ Permite modificar el ID (por ejemplo, en una reasignación).

        double getVoltajeSalida();
        // ↑ Devuelve el voltaje de salida en Voltios (V).

        void setVoltajeSalida(double voltaje);
        // ↑ Permite modificar el voltaje de salida (calibración).

        double getCorrienteMaxima();
        // ↑ Devuelve la corriente máxima en Amperios (A).

        void setCorrienteMaxima(double corriente);
        // ↑ Permite modificar la corriente máxima (por ejemplo, al cambiar
        //   de configuración del sistema).

        double getEficienciaEnergetica();
        // ↑ Devuelve la eficiencia energética en porcentaje (%).

        void setEficienciaEnergetica(double eficiencia);
        // ↑ Permite modificar la eficiencia energética (por ejemplo, tras
        //   un mantenimiento o recalibración).

        // ---------- MÉTODOS DE NEGOCIO PROPIOS ----------
        // Representan comportamientos específicos de la fuente de potencia.

        void suministrarEnergia();
        // ↑ Suministra energía a las estaciones asociadas. Es la función
        //   principal de la fuente: proveer la potencia necesaria para
        //   que las unidades clasificadoras se muevan y operen.
        //   Al ser una asociación externa, una misma fuente puede
        //   suministrar energía a varias estaciones simultáneamente.

        bool estaOperativa();
        // ↑ Verifica si la fuente está operativa. En la práctica, depende
        //   de que el voltaje de salida y la corriente máxima sean mayores
        //   que cero. Si alguno es cero, la fuente no puede suministrar
        //   energía y se considera inoperativa.
    };
}