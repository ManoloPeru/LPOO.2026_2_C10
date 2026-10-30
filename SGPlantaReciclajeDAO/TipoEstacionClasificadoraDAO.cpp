#include "TipoEstacionClasificadoraDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO; /* Tiene las clases para manejo de archivos de texto */

// ============================================================
// CONSTRUCTOR
// ============================================================
// Invoca al constructor de BaseDAO para calcular la ruta de la
// carpeta BD\TXT\ antes de cualquier operación.
TipoEstacionClasificadoraDAO::TipoEstacionClasificadoraDAO() : BaseDAO() {
	// El constructor de BaseDAO ya calculó rutaCarpetaTXT
	// y aseguró que la carpeta exista.
}

// ============================================================
// OPERACIONES DE LECTURA
// ============================================================

// buscarTodosArchivo: lee todas las líneas del archivo "TipoEstaciones.txt" ubicado en BD\TXT\.
List<TipoEstacionClasificadora^>^ TipoEstacionClasificadoraDAO::buscarTodosArchivo() {
	List<TipoEstacionClasificadora^>^ listaTipos = gcnew List<TipoEstacionClasificadora^>();

	// ← Usar ObtenerRutaArchivo() de BaseDAO en lugar de "TipoEstaciones.txt"
	String^ rutaArchivo = ObtenerRutaArchivo(this->nombreArchivo);

	// Si el archivo no existe, devolvemos una lista vacía
	if (!File::Exists(rutaArchivo)) {
		return listaTipos;
	}

	array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
	String^ separadores = ";";

	for each (String ^ linea in lineas) {
		// Ignorar líneas vacías
		if (String::IsNullOrWhiteSpace(linea)) {
			continue;
		}

		array<String^>^ datos = linea->Split(separadores->ToCharArray());

		// Validar que la línea tenga al menos los 2 campos esperados
		if (datos->Length < 2) {
			continue;
		}

		// Parsear cada campo según su tipo
		int idTipoEstacion = Convert::ToInt32(datos[0]);
		String^ descripcion = datos[1];

		// Crear el tipo con los datos leídos
		TipoEstacionClasificadora^ tipo = gcnew TipoEstacionClasificadora(idTipoEstacion, descripcion);
		listaTipos->Add(tipo);
	}

	return listaTipos;
}

// buscarxIdArchivo: busca un tipo por su ID.
TipoEstacionClasificadora^ TipoEstacionClasificadoraDAO::buscarxIdArchivo(int idTipoEstacion) {
	List<TipoEstacionClasificadora^>^ listaTiposTodos = buscarTodosArchivo();

	for (int i = 0; i < listaTiposTodos->Count; i++) {
		if (listaTiposTodos[i]->getIdTipoEstacion() == idTipoEstacion) {
			return listaTiposTodos[i];
		}
	}
	return nullptr;
}

// buscarxDescripcionArchivo: busca un tipo por su descripción.
TipoEstacionClasificadora^ TipoEstacionClasificadoraDAO::buscarxDescripcionArchivo(String^ descripcion) {
	List<TipoEstacionClasificadora^>^ listaTiposTodos = buscarTodosArchivo();

	for (int i = 0; i < listaTiposTodos->Count; i++) {
		if (listaTiposTodos[i]->getDescripcion()->Equals(descripcion, StringComparison::OrdinalIgnoreCase)) {
			return listaTiposTodos[i];
		}
	}
	return nullptr;
}

// ============================================================
// OPERACIONES DE ESCRITURA
// ============================================================

// registrarTipoArchivo: agrega un nuevo tipo al archivo.
void TipoEstacionClasificadoraDAO::registrarTipoArchivo(TipoEstacionClasificadora^ tipo) {
	List<TipoEstacionClasificadora^>^ listaTiposTodos = buscarTodosArchivo();
	listaTiposTodos->Add(tipo);
	escribirArchivo(listaTiposTodos);
}

// modificarTipoArchivo: actualiza los datos de un tipo existente.
void TipoEstacionClasificadoraDAO::modificarTipoArchivo(TipoEstacionClasificadora^ tipo) {
	List<TipoEstacionClasificadora^>^ listaTiposTodos = buscarTodosArchivo();

	for (int i = 0; i < listaTiposTodos->Count; i++) {
		if (listaTiposTodos[i]->getIdTipoEstacion() == tipo->getIdTipoEstacion()) {
			listaTiposTodos[i]->setDescripcion(tipo->getDescripcion());
			break;
		}
	}
	escribirArchivo(listaTiposTodos);
}

// eliminarTipoArchivo: elimina un tipo del archivo por su ID.
void TipoEstacionClasificadoraDAO::eliminarTipoArchivo(int idTipoEstacion) {
	List<TipoEstacionClasificadora^>^ listaTiposTodos = buscarTodosArchivo();

	for (int i = 0; i < listaTiposTodos->Count; i++) {
		if (listaTiposTodos[i]->getIdTipoEstacion() == idTipoEstacion) {
			listaTiposTodos->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaTiposTodos);
}

// escribirArchivo: reescribe el archivo completo a partir de una lista.
void TipoEstacionClasificadoraDAO::escribirArchivo(List<TipoEstacionClasificadora^>^ listaTipos) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaTipos->Count);

	for (int i = 0; i < listaTipos->Count; i++) {
		TipoEstacionClasificadora^ tipo = listaTipos[i];

		lineasArchivo[i] =
			tipo->getIdTipoEstacion() + ";" +
			tipo->getDescripcion();
	}

	// ← Usar ObtenerRutaArchivo() de BaseDAO
	File::WriteAllLines(ObtenerRutaArchivo(this->nombreArchivo), lineasArchivo);
}