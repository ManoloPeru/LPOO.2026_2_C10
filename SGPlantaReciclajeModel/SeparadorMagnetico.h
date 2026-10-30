#pragma once

#include "UnidadClasificadora.h"
// ↑ Se incluye el encabezado de la clase PADRE porque SeparadorMagnetico
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
    // CLASE CONCRETA: SeparadorMagnetico
    // ============================================================
    // Esta clase representa un separador electromagnético instalado sobre
    // la faja transportadora, optimizado para extraer metales ferrosos.
    // Es CONCRETA porque puede instanciarse directamente (no es abstracta).
    //
    // RELACIÓN DE HERENCIA: ' : public UnidadClasificadora' indica que
    // SeparadorMagnetico ES UNA UnidadClasificadora. Hereda:
    //   - idUnidadClasificadora (PK)
    //   - fabricante
    //   - tiempoOperacionHoras
    //   - unidadControl (composición)
    // Y debe implementar los métodos abstractos:
    //   - leerTelemetria()
    //   - verificarAlertas()
    public ref class SeparadorMagnetico : public UnidadClasificadora {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    private:
        // ↑ 'private' significa que estos atributos son EXCLUSIVOS de esta clase.
        //   Ni las subclases (si las hubiera) ni el exterior pueden acceder
        //   directamente a ellos; solo a través de getters y setters.

        double intensidadCampoMin;
        // ↑ ATRIBUTO PROPIO: intensidad mínima del campo magnético en militeslas (mT).
        //   Define el límite inferior del rango operativo del separador.

        double intensidadCampoMax;
        // ↑ ATRIBUTO PROPIO: intensidad máxima del campo magnético en militeslas (mT).
        //   Define el límite superior del rango operativo del separador.

        double capacidadExtraccionMax;
        // ↑ ATRIBUTO PROPIO: capacidad máxima de extracción en kilogramos por hora (kg/h).
        //   Representa el Throughput máximo de metales ferrosos que puede procesar.

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        SeparadorMagnetico();
        // ↑ Constructor vacío (por defecto): inicializa los atributos propios
        //   con valores neutros y llama implícitamente al constructor vacío
        //   de UnidadClasificadora (el padre).

        SeparadorMagnetico(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras,
            double intensidadCampoMin, double intensidadCampoMax, double capacidadExtraccionMax);
        // ↑ Constructor con TODOS los parámetros:
        //   - Los primeros 3 (id, fabricante, tiempoOperacion) se pasan al
        //     constructor del PADRE mediante la lista de inicialización.
        //   - Los últimos 3 son propios de esta clase y se asignan aquí.
        //   Esto demuestra cómo una subclase construye primero la parte
        //   heredada y luego la parte propia.

        // ---------- GETTERS Y SETTERS DE ATRIBUTOS PROPIOS ----------
        // Encapsulan el acceso a los atributos específicos del separador magnético.

        double getIntensidadCampoMin();
        // ↑ Devuelve la intensidad mínima del campo magnético en mT.

        void setIntensidadCampoMin(double intensidad);
        // ↑ Permite modificar la intensidad mínima del campo magnético.

        double getIntensidadCampoMax();
        // ↑ Devuelve la intensidad máxima del campo magnético en mT.

        void setIntensidadCampoMax(double intensidad);
        // ↑ Permite modificar la intensidad máxima del campo magnético.

        double getCapacidadExtraccionMax();
        // ↑ Devuelve la capacidad máxima de extracción en kg/h.

        void setCapacidadExtraccionMax(double capacidad);
        // ↑ Permite modificar la capacidad máxima de extracción del separador.

        // ---------- MÉTODOS DE NEGOCIO PROPIOS ----------
        // Representan comportamientos específicos del separador magnético.

        void ajustarIntensidadCampo(double intensidad);
        // ↑ Ajusta la intensidad del campo magnético dentro del rango permitido
        //   [intensidadCampoMin, intensidadCampoMax]. Si el valor está fuera
        //   del rango, no se aplica (o podría lanzar una alerta).

        void extraerMetalFerroso();
        // ↑ Ejecuta la extracción de metales ferrosos de la faja transportadora.
        //   Es la operación característica de este tipo de unidad.

        double calcularCapacidadExtraccion();
        // ↑ Calcula y devuelve la capacidad de extracción actual en kg/h.
        //   Puede depender de la intensidad del campo y de otros factores.

        // ---------- MÉTODOS SOBRESCRITOS (implementación del contrato) ----------
        // 'override' indica que estos métodos SOBRESCRIBEN los métodos
        // abstractos declarados en la clase padre UnidadClasificadora.
        // Sin ellos, la clase seguiría siendo abstracta y no podría instanciarse.

        virtual String^ leerTelemetria() override;
        // ↑ Implementación concreta de la lectura de telemetría para el separador
        //   magnético. Devuelve temperatura (°C) y vibración (Hz) en formato
        //   de cadena. Cumple con el contrato de ISensorizable.

        virtual List<String^>^ verificarAlertas() override;
        // ↑ Implementación concreta de la verificación de alertas para el
        //   separador magnético. Devuelve una lista de cadenas con las alertas
        //   activas (por ejemplo, intensidad fuera de rango, capacidad excedida).
    };
}