#include "EstacionClasificadoraDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO; /* Tiene las clases para manejo de archivos de texto */

// ============================================================
// CONSTRUCTOR
// ============================================================
// Invoca al constructor de BaseDAO para calcular la ruta de la
// carpeta BD\TXT\ antes de cualquier operación.
EstacionClasificadoraDAO::EstacionClasificadoraDAO() : BaseDAO() {
	// El constructor de BaseDAO ya calculó rutaCarpetaTXT
	// y aseguró que la carpeta exista.
}

// ============================================================
// OPERACIONES DE LECTURA
// ============================================================

// buscarTodosArchivo: lee todas las líneas del archivo "Estaciones.txt"
// ubicado en BD\TXT\ y construye una lista de objetos EstacionClasificadora^.
List<EstacionClasificadora^>^ EstacionClasificadoraDAO::buscarTodosArchivo() {
	List<EstacionClasificadora^>^ listaEstaciones = gcnew List<EstacionClasificadora^>();

	// ← Usar ObtenerRutaArchivo() de BaseDAO en lugar de "Estaciones.txt"
	String^ rutaArchivo = ObtenerRutaArchivo(this->nombreArchivo);

	// Si el archivo no existe, devolvemos una lista vacía
	if (!File::Exists(rutaArchivo)) {
		return listaEstaciones;
	}

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	String^ separadores = ";";

	for each (String ^ linea in lineas) {
		// Ignorar líneas vacías
		if (String::IsNullOrWhiteSpace(linea)) {
			continue;
		}

		array<String^>^ datos = linea->Split(separadores->ToCharArray());

		// Validar que la línea tenga al menos los 5 campos esperados
		if (datos->Length < 5) {
			continue;
		}

		// Parsear cada campo según su tipo
		String^ serialId = datos[0];
		String^ alias = datos[1];
		int tipo = Convert::ToInt32(datos[2]);
		int estado = Convert::ToInt32(datos[3]);
		String^ ubicacion = datos[4];

		// Crear la estación con los datos leídos
		EstacionClasificadora^ estacion = gcnew EstacionClasificadora(
			serialId,
			alias,
			tipo,
			estado,
			ubicacion
		);

		listaEstaciones->Add(estacion);
	}

	return listaEstaciones;
}

// buscarxSerialIdArchivo: busca una estación por su Serial ID.
EstacionClasificadora^ EstacionClasificadoraDAO::buscarxSerialIdArchivo(String^ serialId) {
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo();

	for (int i = 0; i < listaEstacionesTodos->Count; i++) {
		if (listaEstacionesTodos[i]->getSerialId()->Contains(serialId)) {
			return listaEstacionesTodos[i];
		}
	}
	return nullptr;
}

List<EstacionClasificadora^>^ EstacionClasificadoraDAO::buscarByFiltrosArchivo(String^ serialId, int idTipo, int idEstado) {
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo();
	List<EstacionClasificadora^>^ listaEncontrados = gcnew List<EstacionClasificadora^>();
	for (int i = 0; i < listaEstacionesTodos->Count; i++) {
		if (listaEstacionesTodos[i]->getSerialId()->Equals(serialId)
			|| listaEstacionesTodos[i]->getTipo() == idTipo
			|| listaEstacionesTodos[i]->getEstado() == idEstado) {
			listaEncontrados->Add(listaEstacionesTodos[i]);
		}
	}
	return listaEncontrados;
}

// buscarxTipoArchivo: filtra las estaciones por tipo.
List<EstacionClasificadora^>^ EstacionClasificadoraDAO::buscarxTipoArchivo(int tipo) {
	List<EstacionClasificadora^>^ listaEstacionesFiltradas = gcnew List<EstacionClasificadora^>();
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo();

	for (int i = 0; i < listaEstacionesTodos->Count; i++) {
		if (listaEstacionesTodos[i]->getTipo() == tipo) {
			listaEstacionesFiltradas->Add(listaEstacionesTodos[i]);
		}
	}
	return listaEstacionesFiltradas;
}

// ============================================================
// OPERACIONES DE ESCRITURA
// ============================================================

// registrarEstacionArchivo: agrega una nueva estación al archivo.
void EstacionClasificadoraDAO::registrarEstacionArchivo(EstacionClasificadora^ estacion) {
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo(); /* Recupero todas las estaciones del archivo */
	listaEstacionesTodos->Add(estacion); /* Agrego la nueva a la lista */
	escribirArchivo(listaEstacionesTodos);
}

// modificarEstacionArchivo: actualiza los datos de una estación existente.
void EstacionClasificadoraDAO::modificarEstacionArchivo(EstacionClasificadora^ estacion) {
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo(); /* Recupero todas las estaciones del archivo */

	for (int i = 0; i < listaEstacionesTodos->Count; i++) {
		// Buscar por Serial ID (identificador lógico de la estación)
		if (listaEstacionesTodos[i]->getSerialId()->Equals(estacion->getSerialId(), StringComparison::OrdinalIgnoreCase)) {
			listaEstacionesTodos[i]->setAlias(estacion->getAlias());
			listaEstacionesTodos[i]->setTipo(estacion->getTipo());
			listaEstacionesTodos[i]->setEstado(estacion->getEstado());
			listaEstacionesTodos[i]->setUbicacion(estacion->getUbicacion());
			break;
		}
	}
	escribirArchivo(listaEstacionesTodos);
}

// eliminarEstacionArchivo: elimina una estación del archivo por Serial ID.
void EstacionClasificadoraDAO::eliminarEstacionArchivo(String^ serialId) {
	List<EstacionClasificadora^>^ listaEstacionesTodos = buscarTodosArchivo(); /* Recupero todas las estaciones del archivo */

	for (int i = 0; i < listaEstacionesTodos->Count; i++) {
		if (listaEstacionesTodos[i]->getSerialId()->Equals(serialId, StringComparison::OrdinalIgnoreCase)) {
			listaEstacionesTodos->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaEstacionesTodos);
}

// escribirArchivo: reescribe el archivo completo a partir de una lista.
void EstacionClasificadoraDAO::escribirArchivo(List<EstacionClasificadora^>^ listaEstaciones) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEstaciones->Count);

	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionClasificadora^ estacion = listaEstaciones[i];

		// Construir la línea con todos los campos separados por ';'
		lineasArchivo[i] =
			estacion->getSerialId() + ";" +
			estacion->getAlias() + ";" +
			estacion->getTipo() + ";" +
			estacion->getEstado() + ";" +
			estacion->getUbicacion();
	}

	// ← Usar ObtenerRutaArchivo() de BaseDAO
	File::WriteAllLines(ObtenerRutaArchivo(this->nombreArchivo), lineasArchivo);
}