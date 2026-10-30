#pragma once

#include "UnidadClasificadora.h"
// ↑ Se incluye el encabezado de la clase PADRE porque BrazoNeumaticoClasificador
//   HEREDA de UnidadClasificadora. Sin este include, el compilador no sabría
//   qué atributos y métodos se heredan.

namespace SGPlantaReciclajeModel {
    // ↑ Espacio de nombres del proyecto MODELO (biblioteca DLL).
    //   Agrupa todas las clases del dominio de la planta de reciclaje.

    using namespace System;
    // ↑ Permite usar tipos básicos de .NET como String, Int32, DateTime, etc.

    using namespace System::Collections::Generic;
    // ↑ Permite usar colecciones genéricas como List<T>, necesaria para
    //   el método verificarAlertas() que devuelve List<String^>^.

    // ============================================================
    // CLASE CONCRETA: BrazoNeumaticoClasificador
    // ============================================================
    // Esta clase representa un brazo robótico con succión neumática,
    // diseñado específicamente para separar polímeros y cerámicos.
    // Es CONCRETA porque puede instanciarse directamente (no es abstracta).
    //
    // RELACIÓN DE HERENCIA: ' : public UnidadClasificadora' indica que
    // BrazoNeumaticoClasificador ES UNA UnidadClasificadora. Hereda:
    //   - idUnidadClasificadora (PK)
    //   - fabricante
    //   - tiempoOperacionHoras
    //   - unidadControl (composición)
    // Y debe implementar los métodos abstractos:
    //   - leerTelemetria()
    //   - verificarAlertas()
    public ref class BrazoNeumaticoClasificador : public UnidadClasificadora {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    private:
        // ↑ 'private' significa que estos atributos son EXCLUSIVOS de esta clase.
        //   Ni las subclases (si las hubiera) ni el exterior pueden acceder
        //   directamente a ellos; solo a través de getters y setters.

        double presionSuccionMin;
        // ↑ ATRIBUTO PROPIO: presión mínima de succión expresada en Bar.
        //   Define el límite inferior del rango operativo del brazo.

        double presionSuccionMax;
        // ↑ ATRIBUTO PROPIO: presión máxima de succión expresada en Bar.
        //   Define el límite superior del rango operativo del brazo.

        double velocidadDesplazamiento;
        // ↑ ATRIBUTO PROPIO: velocidad de desplazamiento del brazo en mm/s.
        //   Controla qué tan rápido se mueve el brazo durante la clasificación.

        double radioInicial;    // Equivale a 'a'
        double tasaExpansion;   // Equivale a 'b'

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        BrazoNeumaticoClasificador();
        // ↑ Constructor vacío (por defecto): inicializa los atributos propios
        //   con valores neutros y llama implícitamente al constructor vacío
        //   de UnidadClasificadora (el padre).

        BrazoNeumaticoClasificador(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras,
            double presionSuccionMin, double presionSuccionMax, double velocidadDesplazamiento);
        // ↑ Constructor con TODOS los parámetros:
        //   - Los primeros 3 (id, fabricante, tiempoOperacion) se pasan al
        //     constructor del PADRE mediante la lista de inicialización.
        //   - Los últimos 3 son propios de esta clase y se asignan aquí.
        //   Esto demuestra cómo una subclase construye primero la parte
        //   heredada y luego la parte propia.

		// Constructor con parámetros extendidos (incluye radio y tasa de expansión)
        BrazoNeumaticoClasificador(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras,
            double presionSuccionMin, double presionSuccionMax, double velocidadDesplazamiento,
            double radioInicial, double tasaExpansion);


        // ---------- GETTERS Y SETTERS DE ATRIBUTOS PROPIOS ----------
        // Encapsulan el acceso a los atributos específicos del brazo neumático.

        double getPresionSuccionMin();
        // ↑ Devuelve la presión mínima de succión en Bar.

        void setPresionSuccionMin(double presion);
        // ↑ Permite modificar la presión mínima de succión.

        double getPresionSuccionMax();
        // ↑ Devuelve la presión máxima de succión en Bar.

        void setPresionSuccionMax(double presion);
        // ↑ Permite modificar la presión máxima de succión.

        double getVelocidadDesplazamiento();
        // ↑ Devuelve la velocidad de desplazamiento en mm/s.

        void setVelocidadDesplazamiento(double velocidad);
        // ↑ Permite modificar la velocidad de desplazamiento del brazo.


        double getRadioInicial();
        void setRadioInicial(double valor);
        double getTasaExpansion();
        void setTasaExpansion(double valor);

        // ---------- MÉTODOS DE NEGOCIO PROPIOS ----------
        // Representan comportamientos específicos del brazo neumático.

        void ajustarPresionSuccion(double presion);
        // ↑ Ajusta la presión de succión dentro del rango permitido
        //   [presionSuccionMin, presionSuccionMax]. Si el valor está fuera
        //   del rango, no se aplica (o podría lanzar una alerta).

        void moverBrazo(double velocidad);
        // ↑ Desplaza el brazo a la velocidad indicada en mm/s.
        //   Simula la maniobra física del actuador.

        void succionarPolimero();
        // ↑ Ejecuta la maniobra de succión para separar polímeros y cerámicos.
        //   Es la operación característica de este tipo de unidad.

        // ---------- MÉTODOS SOBRESCRITOS (implementación del contrato) ----------
        // 'override' indica que estos métodos SOBRESCRIBEN los métodos
        // abstractos declarados en la clase padre UnidadClasificadora.
        // Sin ellos, la clase seguiría siendo abstracta y no podría instanciarse.

        virtual String^ leerTelemetria() override;
        // ↑ Implementación concreta de la lectura de telemetría para el brazo
        //   neumático. Devuelve temperatura (°C) y vibración (Hz) en formato
        //   de cadena. Cumple con el contrato de ISensorizable.

        virtual List<String^>^ verificarAlertas() override;
        // ↑ Implementación concreta de la verificación de alertas para el
        //   brazo neumático. Devuelve una lista de cadenas con las alertas
        //   activas (por ejemplo, presión fuera de rango, vibración excesiva).
    };
}