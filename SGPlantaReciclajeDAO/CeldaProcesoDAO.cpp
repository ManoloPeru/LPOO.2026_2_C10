#include "CeldaProcesoDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary; // Requerido para BinaryFormatter

CeldaProcesoDAO::CeldaProcesoDAO() : BaseDAO() {
	// Paso 1: Construir la ruta completa del archivo usando la ruta BIN de BaseDAO
	String^ rutaBIN = ObtenerRutaCarpetaBIN();
	this->pathArchivo = Path::Combine(rutaBIN, "celdasProceso.bin");

	// Paso 2: Si el archivo no existe, lo crea vacío con una lista serializable
	if (!File::Exists(this->pathArchivo)) {
		List<CeldaProceso^>^ listaVacia = gcnew List<CeldaProceso^>();
		Stream^ stream = File::Open(this->pathArchivo, FileMode::Create);
		BinaryFormatter^ formateador = gcnew BinaryFormatter();
		formateador->Serialize(stream, listaVacia);
		stream->Close();
	}
}

List<CeldaProceso^>^ CeldaProcesoDAO::buscarTodosArchivo() {
	// Verificar si el archivo está vacío
	FileInfo^ infoArchivo = gcnew FileInfo(this->pathArchivo);
	if (infoArchivo->Length == 0) {
		return gcnew List<CeldaProceso^>(); // Archivo vacío, inicializar lista vacía
	}

	// Intentar deserializar el archivo
	Stream^ stream = File::Open(this->pathArchivo, FileMode::Open);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();

	List<CeldaProceso^>^ listaCeldas = dynamic_cast<List<CeldaProceso^>^>(formateador->Deserialize(stream));
	stream->Close();

	if (listaCeldas == nullptr) {
		return gcnew List<CeldaProceso^>();
	}
	return listaCeldas;
}

List<CeldaProceso^>^ CeldaProcesoDAO::buscarByFiltros(String^ id, int idTipo, int idEstado) {
	List<CeldaProceso^>^ listaCeldas = buscarTodosArchivo();
	List<CeldaProceso^>^ listaFiltrada = gcnew List<CeldaProceso^>();

	for (int i = 0; i < listaCeldas->Count; i++) {
		if (listaCeldas[i]->getId()->Equals(id)
			|| listaCeldas[i]->getTipo() == idTipo
			|| listaCeldas[i]->getEstado() == idEstado) {
			listaFiltrada->Add(listaCeldas[i]);
		}
	}
	return listaFiltrada;
}

void CeldaProcesoDAO::registrarCeldaArchivo(List<CeldaProceso^>^ listaCeldas) {
	// Almacena la lista completa de vuelta en el archivo (sobreescribir)
	escribirArchivo(listaCeldas);
}

void CeldaProcesoDAO::escribirArchivo(List<CeldaProceso^>^ listaCeldas) {
	Stream^ stream = File::Open(this->pathArchivo, FileMode::Create);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();
	formateador->Serialize(stream, listaCeldas);
	stream->Close();
}