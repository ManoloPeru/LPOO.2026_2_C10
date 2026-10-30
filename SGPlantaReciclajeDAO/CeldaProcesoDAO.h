#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SGPlantaReciclajeModel;

	public ref class CeldaProcesoDAO : public BaseDAO {
	private:
		String^ pathArchivo; // Ruta completa del archivo binario

	public:
		CeldaProcesoDAO();

		// Operaciones de persistencia
		List<CeldaProceso^>^ buscarTodosArchivo();
		List<CeldaProceso^>^ buscarByFiltros(String^ id, int idTipo, int idEstado);

		void registrarCeldaArchivo(List<CeldaProceso^>^ listaCeldas);

		// Método auxiliar
		void escribirArchivo(List<CeldaProceso^>^ listaCeldas);
	};
}