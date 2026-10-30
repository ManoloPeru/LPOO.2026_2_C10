#include "EstadoOperativoDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO; /* Tiene las clases para manejo de archivos de texto */
using namespace System::Data::SqlClient;

// ============================================================
// CONSTRUCTOR
// ============================================================
// Invoca al constructor de BaseDAO para calcular la ruta de la
// carpeta BD\TXT\ antes de cualquier operación.
EstadoOperativoDAO::EstadoOperativoDAO() : BaseDAO() {
	// El constructor de BaseDAO ya calculó rutaCarpetaTXT
	// y aseguró que la carpeta exista.
}

// ============================================================
// OPERACIONES CRUD - ARCHIVO PLANO (TXT) [SIN CAMBIOS]
// ============================================================

// OPERACIONES DE LECTURA
// ============================================================

// buscarTodosArchivo: lee todas las líneas del archivo "EstadoOperativo.txt"
// ubicado en BD\TXT\ y construye una lista de objetos EstadoOperativo^.
List<EstadoOperativo^>^ EstadoOperativoDAO::buscarTodosArchivo() {
	List<EstadoOperativo^>^ listaEstados = gcnew List<EstadoOperativo^>();

	// ← Usar ObtenerRutaArchivo() de BaseDAO en lugar de "EstadoOperativo.txt"
	String^ rutaArchivo = ObtenerRutaArchivo(this->nombreArchivo);

	// Si el archivo no existe, devolvemos una lista vacía
	if (!File::Exists(rutaArchivo)) {
		return listaEstados;
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
		int idEstadoOperativo = Convert::ToInt32(datos[0]);
		String^ descripcion = datos[1];

		// Crear el estado con los datos leídos
		EstadoOperativo^ estado = gcnew EstadoOperativo(idEstadoOperativo, descripcion);
		listaEstados->Add(estado);
	}

	return listaEstados;
}

// buscarxIdArchivo: busca un estado por su ID.
EstadoOperativo^ EstadoOperativoDAO::buscarxIdArchivo(int idEstadoOperativo) {
	List<EstadoOperativo^>^ listaEstadosTodos = buscarTodosArchivo();

	for (int i = 0; i < listaEstadosTodos->Count; i++) {
		if (listaEstadosTodos[i]->getIdEstadoOperativo() == idEstadoOperativo) {
			return listaEstadosTodos[i];
		}
	}
	return nullptr;
}

// buscarxDescripcionArchivo: busca un estado por su descripción.
EstadoOperativo^ EstadoOperativoDAO::buscarxDescripcionArchivo(String^ descripcion) {
	List<EstadoOperativo^>^ listaEstadosTodos = buscarTodosArchivo();

	for (int i = 0; i < listaEstadosTodos->Count; i++) {
		if (listaEstadosTodos[i]->getDescripcion()->Equals(descripcion, StringComparison::OrdinalIgnoreCase)) {
			return listaEstadosTodos[i];
		}
	}
	return nullptr;
}

// OPERACIONES DE ESCRITURA
// ============================================================

// registrarEstadoArchivo: agrega un nuevo estado al archivo.
void EstadoOperativoDAO::registrarEstadoArchivo(EstadoOperativo^ estado) {
	List<EstadoOperativo^>^ listaEstadosTodos = buscarTodosArchivo(); /* Recupero todos los estados del archivo */
	listaEstadosTodos->Add(estado); /* Agrego el nuevo a la lista */
	escribirArchivo(listaEstadosTodos);
}

// modificarEstadoArchivo: actualiza los datos de un estado existente.
void EstadoOperativoDAO::modificarEstadoArchivo(EstadoOperativo^ estado) {
	List<EstadoOperativo^>^ listaEstadosTodos = buscarTodosArchivo(); /* Recupero todos los estados del archivo */

	for (int i = 0; i < listaEstadosTodos->Count; i++) {
		// Buscar por ID (identificador lógico del estado)
		if (listaEstadosTodos[i]->getIdEstadoOperativo() == estado->getIdEstadoOperativo()) {
			listaEstadosTodos[i]->setDescripcion(estado->getDescripcion());
			break;
		}
	}
	escribirArchivo(listaEstadosTodos);
}

// eliminarEstadoArchivo: elimina un estado del archivo por su ID.
void EstadoOperativoDAO::eliminarEstadoArchivo(int idEstadoOperativo) {
	List<EstadoOperativo^>^ listaEstadosTodos = buscarTodosArchivo(); /* Recupero todos los estados del archivo */

	for (int i = 0; i < listaEstadosTodos->Count; i++) {
		if (listaEstadosTodos[i]->getIdEstadoOperativo() == idEstadoOperativo) {
			listaEstadosTodos->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaEstadosTodos);
}

// escribirArchivo: reescribe el archivo completo a partir de una lista.
void EstadoOperativoDAO::escribirArchivo(List<EstadoOperativo^>^ listaEstados) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEstados->Count);

	for (int i = 0; i < listaEstados->Count; i++) {
		EstadoOperativo^ estado = listaEstados[i];

		// Construir la línea con todos los campos separados por ';'
		lineasArchivo[i] =
			estado->getIdEstadoOperativo() + ";" +
			estado->getDescripcion();
	}

	// ← Usar ObtenerRutaArchivo() de BaseDAO
	File::WriteAllLines(ObtenerRutaArchivo(this->nombreArchivo), lineasArchivo);
}

// ============================================================
// OPERACIONES CRUD - BASE DE DATOS (SQL SERVER)
// ============================================================

List<EstadoOperativo^>^ EstadoOperativoDAO::buscarTodosSQL() {
	List<EstadoOperativo^>^ listaEstados = gcnew List<EstadoOperativo^>();
	String^ sSql = "SELECT idEstadoOperativo, descripcion FROM EstadoOperativo";

	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		SqlDataReader^ reader = comando->ExecuteReader();

		while (reader->Read()) {
			EstadoOperativo^ estado = gcnew EstadoOperativo(
				Convert::ToInt32(reader["idEstadoOperativo"]),
				reader["descripcion"]->ToString()
			);
			listaEstados->Add(estado);
		}
		reader->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al listar estados operativos en SQL: " + ex->Message);
	}
	return listaEstados;
}

EstadoOperativo^ EstadoOperativoDAO::buscarxIdSQL(int idEstadoOperativo) {
	String^ sSql = "SELECT idEstadoOperativo, descripcion FROM EstadoOperativo WHERE idEstadoOperativo = " + idEstadoOperativo;
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		SqlDataReader^ reader = comando->ExecuteReader();
		if (reader->Read()) {
			EstadoOperativo^ estado = gcnew EstadoOperativo(
				Convert::ToInt32(reader["idEstadoOperativo"]),
				reader["descripcion"]->ToString()
			);
			reader->Close();
			cerrarConexion();
			return estado;
		}
		reader->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al buscar estado operativo en SQL: " + ex->Message);
	}
	return nullptr;
}

int EstadoOperativoDAO::registrarEstadoSQL(EstadoOperativo^ estado) {
	String^ sSql = "INSERT INTO EstadoOperativo (descripcion) " + 
		"VALUES('" + estado->getDescripcion() + "')";
	return insertSql(sSql);
}

bool EstadoOperativoDAO::modificarEstadoSQL(EstadoOperativo^ estado) {
	String^ sSql = "UPDATE EstadoOperativo SET descripcion = '" + estado->getDescripcion() + "' " + 
		"WHERE idEstadoOperativo = " + estado->getIdEstadoOperativo();
	return executeSql(sSql);
}

bool EstadoOperativoDAO::eliminarEstadoSQL(int idEstadoOperativo) {
	String^ sSql = "DELETE FROM EstadoOperativo WHERE idEstadoOperativo = " + idEstadoOperativo;
	return executeSql(sSql);
}