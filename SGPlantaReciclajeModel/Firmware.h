#pragma once

// NOTA: No se incluye ningún otro encabezado del modelo porque Firmware
//       es una clase HOJA en la jerarquía: no hereda de nadie y no compone
//       ni agrega otras clases del dominio. Es la PARTE dentro de la
//       composición UnidadControl ◆── Firmware, pero esa relación se
//       modela desde el lado de UnidadControl, no desde aquí.

namespace SGPlantaReciclajeModel {
    // ↑ Espacio de nombres del proyecto MODELO (biblioteca DLL).
    //   Agrupa todas las clases del dominio de la planta de reciclaje.

    using namespace System;
    // ↑ Permite usar tipos básicos de .NET como String, Int32, DateTime, etc.
    //   En particular, aquí se necesita DateTime para la fecha de compilación
    //   y String para la versión del firmware.
    //   NOTA: No se incluye System::Collections::Generic porque esta clase
    //   no utiliza colecciones genéricas (List<T>, etc.).

    // ============================================================
    // CLASE CONCRETA: Firmware
    // ============================================================
    // Esta clase representa el código de bajo nivel específico para el
    // hardware de una UnidadControl. Contiene la información de versión,
    // fecha de compilación y memoria interna ocupada.
    //
    // RELACIÓN PRINCIPAL:
    //   - COMPOSICIÓN con UnidadControl: el Firmware es la PARTE dentro
    //     de la composición UnidadControl ◆── Firmware (1:1).
    //     NO puede existir ni operar fuera de su controladora: si esta
    //     se destruye o queda inoperativa, el firmware se considera
    //     destruido o inaccesible.
    //
    // Es una clase HOJA: no hereda, no compone, no agrega. Solo existe
    // como parte de una UnidadControl.
    public ref class Firmware {
        // ↑ 'public ref class' declara una clase administrada por el CLR
        //   (garbage collector), accesible desde otros ensamblados.

    private:
        // ↑ 'private' significa que estos atributos son EXCLUSIVOS de esta clase.
        //   Solo se accede a ellos a través de getters y setters.

        int idFirmware;
        // ↑ ATRIBUTO PK (Primary Key): identificador único del firmware.
        //   Aunque el firmware depende de su UnidadControl, se le asigna
        //   una PK propia para poder modelarlo como entidad en el dominio.

        String^ version;
        // ↑ ATRIBUTO PROPIO: versión del sistema (por ejemplo, "v2.4.1").
        //   Permite identificar qué versión de firmware está instalada.
        //   El '^' indica que es un objeto administrado de tipo String.

        DateTime fechaUltimaCompilacion;
        // ↑ ATRIBUTO PROPIO: fecha de la última compilación del firmware.
        //   DateTime es un tipo valor de .NET (struct) que almacena fecha
        //   y hora. NO lleva '^' porque no es una referencia administrada.

        double memoriaInternaKB;
        // ↑ ATRIBUTO PROPIO: espacio de memoria interna medido en Kilobytes (KB).
        //   Indica cuánta memoria ocupa el firmware en el hardware.

    public:
        // ↑ 'public' expone los constructores y métodos al exterior.

        // ---------- CONSTRUCTORES ----------
        Firmware();
        // ↑ Constructor vacío (por defecto): inicializa los atributos con
        //   valores neutros. Por ejemplo, versión "1.0.0" y fecha actual.
        //   Útil para crear un firmware "en blanco" antes de compilarlo.

        Firmware(int idFirmware, String^ version, DateTime fechaUltimaCompilacion, double memoriaInternaKB);
        // ↑ Constructor con TODOS los parámetros:
        //   - idFirmware: PK del firmware.
        //   - version: versión del sistema.
        //   - fechaUltimaCompilacion: fecha de la última compilación.
        //   - memoriaInternaKB: memoria interna ocupada (KB).
        //   Permite crear un firmware completamente configurado desde su
        //   instanciación.

        // ---------- GETTERS Y SETTERS ----------
        // Encapsulan el acceso a los atributos (principio de encapsulamiento).

        int getIdFirmware();
        // ↑ Devuelve el ID único (PK) del firmware.

        void setIdFirmware(int id);
        // ↑ Permite modificar el ID (por ejemplo, en una reasignación).

        String^ getVersion();
        // ↑ Devuelve la versión del sistema (por ejemplo, "v2.4.1").

        void setVersion(String^ version);
        // ↑ Permite modificar la versión del firmware (por ejemplo, tras
        //   una actualización manual).

        DateTime getFechaUltimaCompilacion();
        // ↑ Devuelve la fecha de la última compilación del firmware.

        void setFechaUltimaCompilacion(DateTime fecha);
        // ↑ Permite modificar la fecha de la última compilación (por ejemplo,
        //   tras recompilar el firmware).

        double getMemoriaInternaKB();
        // ↑ Devuelve el espacio de memoria interna ocupado en Kilobytes (KB).

        void setMemoriaInternaKB(double memoria);
        // ↑ Permite modificar la memoria interna (por ejemplo, tras
        //   optimizar el firmware).

        // ---------- MÉTODOS DE NEGOCIO PROPIOS ----------
        // Representan comportamientos específicos del firmware.

        void actualizarFirmware(String^ nuevaVersion);
        // ↑ Actualiza la versión del firmware y, como consecuencia,
        //   también actualiza la fecha de última compilación a la fecha
        //   actual del sistema. Simula una actualización de firmware.

        void compilar();
        // ↑ Ejecuta la compilación del firmware. Como resultado,
        //   actualiza la fecha de última compilación a la fecha actual.
        //   Simula el proceso de compilación del código de bajo nivel.
    };
}