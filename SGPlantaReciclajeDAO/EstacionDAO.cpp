#include "EstacionDAO.h"
using namespace SGPlantaReciclajeDAO;
using namespace System::Data::SqlClient;


EstacionDAO::EstacionDAO() : BaseDAO() {}

// ============================================================
// CREATE: Registrar Estación
// ============================================================
int EstacionDAO::registrarEstacion(Estacion^ estacion) {
    // Como el ID no es IDENTITY en tu tabla, debes enviarlo explícitamente.
    String^ sSql = "INSERT INTO Estacion (Alias, Ubicacion, Estado, CapacidadKgH, HorasOperacion) " +
        "VALUES ('" + estacion->getAlias() + "', " +
        "'" + estacion->getUbicacion() + "', " +
        estacion->getEstado() + ", " +
        estacion->getCapacidadKgH() + ", " +
        estacion->getHorasOperacion() + ")";
    return insertSql(sSql);
}

// ============================================================
// READ: Buscar Todos
// ============================================================
List<Estacion^>^ EstacionDAO::buscarTodos() {
    List<Estacion^>^ lista = gcnew List<Estacion^>();
    String^ sSql = "SELECT EstacionId, Alias, Ubicacion, Estado, CapacidadKgH, HorasOperacion FROM Estacion";
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        SqlDataReader^ reader = comando->ExecuteReader();

        while (reader->Read()) {
            Estacion^ e = gcnew Estacion(
                Convert::ToInt32(reader["EstacionId"]),
                reader["Alias"]->ToString(),
                reader["Ubicacion"]->ToString(),
                Convert::ToInt32(reader["Estado"]),
                Convert::ToDouble(reader["CapacidadKgH"]),
                Convert::ToDouble(reader["HorasOperacion"])
            );
            lista->Add(e);
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al listar estaciones: " + ex->Message);
    }
    return lista;
}

// ============================================================
// READ: Buscar por ID
// ============================================================
Estacion^ EstacionDAO::buscarxId(int estacionId) {
    String^ sSql = "SELECT EstacionId, Alias, Ubicacion, Estado, CapacidadKgH, HorasOperacion " +
        "FROM Estacion WHERE EstacionId = " + estacionId;
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        SqlDataReader^ reader = comando->ExecuteReader();
        if (reader->Read()) {
            Estacion^ e = gcnew Estacion(
                Convert::ToInt32(reader["EstacionId"]),
                reader["Alias"]->ToString(),
                reader["Ubicacion"]->ToString(),
                Convert::ToInt32(reader["Estado"]),
                Convert::ToDouble(reader["CapacidadKgH"]),
                Convert::ToDouble(reader["HorasOperacion"])
            );
            reader->Close();
            cerrarConexion();
            return e;
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al buscar estación: " + ex->Message);
    }
    return nullptr;
}

List<Estacion^>^ EstacionDAO::buscarxIdxEstado(int estacionId, int idEstado) {
    List<Estacion^>^ lista = gcnew List<Estacion^>();
    String^ sSql = "SELECT EstacionId, Alias, Ubicacion, Estado, CapacidadKgH, HorasOperacion " +
        "FROM Estacion WHERE EstacionId = " + estacionId + " OR Estado = " + idEstado;
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        SqlDataReader^ reader = comando->ExecuteReader();
        while (reader->Read()) {
            Estacion^ e = gcnew Estacion(
                Convert::ToInt32(reader["EstacionId"]),
                reader["Alias"]->ToString(),
                reader["Ubicacion"]->ToString(),
                Convert::ToInt32(reader["Estado"]),
                Convert::ToDouble(reader["CapacidadKgH"]),
                Convert::ToDouble(reader["HorasOperacion"])
            );
            lista->Add(e);
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al buscar estación: " + ex->Message);
    }
    return lista;
}

// ============================================================
// UPDATE: Modificar Estación
// ============================================================
bool EstacionDAO::modificarEstacion(Estacion^ estacion) {
    String^ sSql = "UPDATE Estacion SET Alias='" + estacion->getAlias() + "', " +
        "Ubicacion='" + estacion->getUbicacion() + "', " +
        "Estado="+ estacion->getEstado() +", " +
        "CapacidadKgH="+ estacion->getCapacidadKgH() +", " +
        "HorasOperacion="+ estacion->getHorasOperacion() + " " +
        "WHERE EstacionId=" + estacion->getEstacionId();
    return executeSql(sSql);
}

// ============================================================
// DELETE: Eliminar Estación
// ============================================================
bool EstacionDAO::eliminarEstacion(int estacionId) {
    String^ sSql = "DELETE FROM Estacion WHERE EstacionId = " + estacionId;
    return executeSql(sSql);
}