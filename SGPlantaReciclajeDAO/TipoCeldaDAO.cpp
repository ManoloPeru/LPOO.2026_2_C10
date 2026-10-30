#include "TipoCeldaDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::IO;

TipoCeldaDAO::TipoCeldaDAO() : BaseDAO() {}

List<TipoCelda^>^ TipoCeldaDAO::buscarTodosArchivo() {
    List<TipoCelda^>^ listaTipos = gcnew List<TipoCelda^>();
    String^ rutaArchivo = ObtenerRutaArchivo(this->nombreArchivo);

    if (!File::Exists(rutaArchivo)) return listaTipos;

    array<String^>^ lineas = File::ReadAllLines(rutaArchivo);
    String^ separadores = ";";

    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        if (datos->Length < 2) continue;

        int idTipoCelda = Convert::ToInt32(datos[0]);
        String^ descripcion = datos[1];
        listaTipos->Add(gcnew TipoCelda(idTipoCelda, descripcion));
    }
    return listaTipos;
}

TipoCelda^ TipoCeldaDAO::buscarxIdArchivo(int idTipoCelda) {
    List<TipoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdTipoCelda() == idTipoCelda) return lista[i];
    }
    return nullptr;
}

TipoCelda^ TipoCeldaDAO::buscarxDescripcionArchivo(String^ descripcion) {
    List<TipoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getDescripcion()->Equals(descripcion, StringComparison::OrdinalIgnoreCase)) return lista[i];
    }
    return nullptr;
}

void TipoCeldaDAO::registrarTipoArchivo(TipoCelda^ tipo) {
    List<TipoCelda^>^ lista = buscarTodosArchivo();
    lista->Add(tipo);
    escribirArchivo(lista);
}

void TipoCeldaDAO::modificarTipoArchivo(TipoCelda^ tipo) {
    List<TipoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdTipoCelda() == tipo->getIdTipoCelda()) {
            lista[i]->setDescripcion(tipo->getDescripcion());
            break;
        }
    }
    escribirArchivo(lista);
}

void TipoCeldaDAO::eliminarTipoArchivo(int idTipoCelda) {
    List<TipoCelda^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdTipoCelda() == idTipoCelda) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

void TipoCeldaDAO::escribirArchivo(List<TipoCelda^>^ listaTipos) {
    array<String^>^ lineas = gcnew array<String^>(listaTipos->Count);
    for (int i = 0; i < listaTipos->Count; i++) {
        lineas[i] = listaTipos[i]->getIdTipoCelda() + ";" + listaTipos[i]->getDescripcion();
    }
    File::WriteAllLines(ObtenerRutaArchivo(this->nombreArchivo), lineas);
}