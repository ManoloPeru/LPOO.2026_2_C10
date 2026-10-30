#include "EstadoCeldaDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO;

EstadoCeldaDAO::EstadoCeldaDAO() : BaseDAO() {}

List<EstadoCelda^>^ EstadoCeldaDAO::buscarTodosArchivo() {
    List<EstadoCelda^>^ listaEstados = gcnew List<EstadoCelda^>();
    String^ rutaArchivo = ObtenerRutaArchivo(this->nombreArchivo);

    if (!File::Exists(rutaArchivo)) return listaEstados;

    array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
    String^ separadores = ";";

    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        if (datos->Length < 2) continue;

        int idEstadoCelda = Convert::ToInt32(datos[0]);
        String^ descripcion = datos[1];
        listaEstados->Add(gcnew EstadoCelda(idEstadoCelda, descripcion));
    }
    return listaEstados;
}

EstadoCelda^ EstadoCeldaDAO::buscarxIdArchivo(int idEstadoCelda) {
    List<EstadoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdEstadoCelda() == idEstadoCelda) return lista[i];
    }
    return nullptr;
}

EstadoCelda^ EstadoCeldaDAO::buscarxDescripcionArchivo(String^ descripcion) {
    List<EstadoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getDescripcion()->Equals(descripcion, StringComparison::OrdinalIgnoreCase)) return lista[i];
    }
    return nullptr;
}

void EstadoCeldaDAO::registrarEstadoArchivo(EstadoCelda^ estado) {
    List<EstadoCelda^>^ lista = buscarTodosArchivo();
    lista->Add(estado);
    escribirArchivo(lista);
}

void EstadoCeldaDAO::modificarEstadoArchivo(EstadoCelda^ estado) {
    List<EstadoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdEstadoCelda() == estado->getIdEstadoCelda()) {
            lista[i]->setDescripcion(estado->getDescripcion());
            break;
        }
    }
    escribirArchivo(lista);
}

void EstadoCeldaDAO::eliminarEstadoArchivo(int idEstadoCelda) {
    List<EstadoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdEstadoCelda() == idEstadoCelda) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

void EstadoCeldaDAO::escribirArchivo(List<EstadoCelda^>^ listaEstados) {
    array<String^>^ lineas = gcnew array<String^>(listaEstados->Count);
    for (int i = 0; i < listaEstados->Count; i++) {
        lineas[i] = listaEstados[i]->getIdEstadoCelda() + ";" + listaEstados[i]->getDescripcion();
    }
    File::WriteAllLines(ObtenerRutaArchivo(this->nombreArchivo), lineas);
}