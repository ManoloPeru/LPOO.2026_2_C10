#pragma once

#include "BaseDAO.h"   // ← NUEVO: incluir BaseDAO para heredar clase Base

namespace SGPlantaReciclajeDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SGPlantaReciclajeModel;

	// ============================================================
	// CLASE: EstadoOperativoDAO
	// ============================================================
	// Data Access Object (DAO) para la entidad EstadoOperativo.
	// HEREDA de BaseDAO para reutilizar la ruta centralizada de
	// la carpeta BD\TXT\ donde se almacenan los archivos de datos.
	//
	// Formato del archivo "EstadoOperativo.txt" (cada línea):
	//   idEstadoOperativo;descripcion
	//
	// Ejemplo:
	//   1;Operativo
	//   2;En Mantenimiento
	public ref class EstadoOperativoDAO : public BaseDAO {   // ← HERENCIA
	private:
		// Nombre del archivo de datos (ubicado en BD\TXT\)
		String^ nombreArchivo = "EstadoOperativo.txt";

	public:
		// Constructor por defecto
		EstadoOperativoDAO();

		// ============================================================
		// OPERACIONES CRUD - ARCHIVO PLANO (TXT)
		// ============================================================
		// 
		// ---------- OPERACIONES DE LECTURA ----------

		// buscarTodosArchivo: lee todas las líneas del archivo
		// "EstadoOperativo.txt" y devuelve una lista de EstadoOperativo^.
		List<EstadoOperativo^>^ buscarTodosArchivo();

		// buscarxIdArchivo: busca un estado por su ID.
		// Devuelve el estado encontrado o nullptr si no existe.
		EstadoOperativo^ buscarxIdArchivo(int idEstadoOperativo);

		// buscarxDescripcionArchivo: busca un estado por su descripción
		// (búsqueda exacta, ignorando mayúsculas/minúsculas).
		EstadoOperativo^ buscarxDescripcionArchivo(String^ descripcion);

		// ---------- OPERACIONES DE ESCRITURA ----------

		// registrarEstadoArchivo: agrega un nuevo estado al archivo.
		void registrarEstadoArchivo(EstadoOperativo^ estado);

		// modificarEstadoArchivo: actualiza los datos de un estado
		// existente en el archivo, buscándolo por su ID.
		void modificarEstadoArchivo(EstadoOperativo^ estado);

		// eliminarEstadoArchivo: elimina un estado del archivo por su ID.
		void eliminarEstadoArchivo(int idEstadoOperativo);

		// escribirArchivo: reescribe el archivo completo a partir de
		// una lista de estados (método auxiliar de la lógica).
		void escribirArchivo(List<EstadoOperativo^>^ listaEstados);


		// ============================================================
		// OPERACIONES CRUD - BASE DE DATOS (SQL SERVER)
		// ============================================================

		// buscarTodosSQL: Retorna todos los estados desde la BD
		List<EstadoOperativo^>^ buscarTodosSQL();

		// buscarxIdSQL: Busca un estado por su ID en la BD
		EstadoOperativo^ buscarxIdSQL(int idEstadoOperativo);

		// registrarEstadoSQL: Inserta un nuevo estado. Devuelve true si fue exitoso.
		int registrarEstadoSQL(EstadoOperativo^ estado);

		// modificarEstadoSQL: Actualiza un estado existente. Devuelve true si fue exitoso.
		bool modificarEstadoSQL(EstadoOperativo^ estado);

		// eliminarEstadoSQL: Elimina un estado por ID. Devuelve true si fue exitoso.
		bool eliminarEstadoSQL(int idEstadoOperativo);
	};

}