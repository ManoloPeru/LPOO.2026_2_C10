#pragma once

#include "BaseDAO.h"   // ← NUEVO: incluir BaseDAO para heredar clase Base

namespace SGPlantaReciclajeDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SGPlantaReciclajeModel;

	// ============================================================
	// CLASE: EstacionClasificadoraDAO
	// ============================================================
	// Data Access Object (DAO) para la entidad EstacionClasificadora.
	// HEREDA de BaseDAO para reutilizar la ruta centralizada de
	// la carpeta BD\TXT\ donde se almacenan los archivos de datos.
	//
	// Formato del archivo "Estaciones.txt" (cada línea):
	//   serialId;alias;tipo;estado;ubicacion
	//
	// Ejemplo:
	//   EST-NEU-001;Clasificadora-Neumatica-01;Neumatica;Operativo;Linea de Clasificacion de Polimeros
	public ref class EstacionClasificadoraDAO : public BaseDAO {   // ← HERENCIA
	private:
		// Nombre del archivo de datos (ubicado en BD\TXT\)
		String^ nombreArchivo = "Estaciones.txt";

	public:
		// Constructor por defecto
		EstacionClasificadoraDAO();

		// ---------- OPERACIONES DE LECTURA ----------

		// buscarTodosArchivo: lee todas las líneas del archivo
		// "Estaciones.txt" y devuelve una lista de EstacionClasificadora^.
		List<EstacionClasificadora^>^ buscarTodosArchivo();

		// buscarxSerialIdArchivo: busca una estación por su Serial ID.
		// Devuelve la estación encontrada o nullptr si no existe.
		EstacionClasificadora^ buscarxSerialIdArchivo(String^ serialId);

		List<EstacionClasificadora^>^ buscarByFiltrosArchivo(String^ serialId, int idTipo, int idEstado);

		// buscarxTipoArchivo: filtra las estaciones por tipo
		// (e.g., "Neumatica", "Magnetica", "Optica").
		// Devuelve una lista con las estaciones que coincidan.
		List<EstacionClasificadora^>^ buscarxTipoArchivo(int tipo);

		// ---------- OPERACIONES DE ESCRITURA ----------

		// registrarEstacionArchivo: agrega una nueva estación al archivo.
		void registrarEstacionArchivo(EstacionClasificadora^ estacion);

		// modificarEstacionArchivo: actualiza los datos de una estación
		// existente en el archivo, buscándola por su Serial ID.
		void modificarEstacionArchivo(EstacionClasificadora^ estacion);

		// eliminarEstacionArchivo: elimina una estación del archivo,
		// buscándola por su Serial ID.
		void eliminarEstacionArchivo(String^ serialId);

		// escribirArchivo: reescribe el archivo completo a partir de
		// una lista de estaciones (método auxiliar de la lógica).
		void escribirArchivo(List<EstacionClasificadora^>^ listaEstaciones);
	};

}