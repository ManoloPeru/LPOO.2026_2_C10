#pragma once

#include "BaseDAO.h"   // ← NUEVO: incluir BaseDAO para heredar clase Base

namespace SGPlantaReciclajeDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SGPlantaReciclajeModel;

	// ============================================================
	// CLASE: TipoEstacionClasificadoraDAO
	// ============================================================
	// Data Access Object (DAO) para la entidad TipoEstacion.
	// HEREDA de BaseDAO para reutilizar la ruta centralizada de
	// la carpeta BD\TXT\ donde se almacenan los archivos de datos.
	//
	// Formato del archivo "TipoEstaciones.txt" (cada línea):
	//   idTipoEstacion;descripcion
	//
	// Ejemplo:
	//   1;Neumática
	//   2;Magnética
	public ref class TipoEstacionClasificadoraDAO : public BaseDAO {   // ← HERENCIA
		private:
			// Métodos auxiliares privados (si es necesario) pueden ir aquí.
			String^ nombreArchivo = "TipoEstaciones.txt"; // Nombre del archivo de datos

		public:
			// Constructor por defecto
			TipoEstacionClasificadoraDAO();

			// ---------- OPERACIONES DE LECTURA ----------

			List<TipoEstacionClasificadora^>^ buscarTodosArchivo();

			TipoEstacionClasificadora^ buscarxIdArchivo(int idTipoEstacion);

			TipoEstacionClasificadora^ buscarxDescripcionArchivo(String^ descripcion);

			// ---------- OPERACIONES DE ESCRITURA ----------

			void registrarTipoArchivo(TipoEstacionClasificadora^ tipo);

			void modificarTipoArchivo(TipoEstacionClasificadora^ tipo);

			void eliminarTipoArchivo(int idTipoEstacion);

			void escribirArchivo(List<TipoEstacionClasificadora^>^ listaTipos);
	};

}