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
                   "VALUES (@alias, @ubicacion, @estado, @capacidad, @horas)";
    // Creamos un arreglo de parámetros para pasar los valores
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(5);
    parametros[0] = gcnew SqlParameter("@alias", estacion->getAlias());
    parametros[1] = gcnew SqlParameter("@ubicacion", estacion->getUbicacion());
    parametros[2] = gcnew SqlParameter("@estado", estacion->getEstado());
    parametros[3] = gcnew SqlParameter("@capacidad", estacion->getCapacidadKgH());
    parametros[4] = gcnew SqlParameter("@horas", estacion->getHorasOperacion());
	// Llamamos a insertSql con el SQL y los parámetros
    return insertSql(sSql, parametros);
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
        "FROM Estacion WHERE EstacionId = @estacionId OR Estado = @idEstado";
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		// Usamos parámetros para evitar Inyección SQL
        comando->Parameters->AddWithValue("@estacionId", estacionId);
        comando->Parameters->AddWithValue("@idEstado", idEstado);
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
	// Usamos @parametros en la sentencia SQL
    String^ sSql = "UPDATE Estacion SET Alias=@Alias, " +
        "Ubicacion=@Ubicacion, " +
        "Estado=@Estado, " +
        "CapacidadKgH=@CapacidadKgH, " +
        "HorasOperacion=@HorasOperacion " +
        "WHERE EstacionId=@EstacionId";
	// Creamos un arreglo de parámetros para pasar los valores
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(6);
    parametros[0] = gcnew SqlParameter("@Alias", estacion->getAlias());
    parametros[1] = gcnew SqlParameter("@Ubicacion", estacion->getUbicacion());
    parametros[2] = gcnew SqlParameter("@Estado", estacion->getEstado());
    parametros[3] = gcnew SqlParameter("@CapacidadKgH", estacion->getCapacidadKgH());
    parametros[4] = gcnew SqlParameter("@HorasOperacion", estacion->getHorasOperacion());
    parametros[5] = gcnew SqlParameter("@EstacionId", estacion->getEstacionId());
	// Llamamos a executeSql con el SQL y los parámetros
    return executeSql(sSql, parametros);
}

// ============================================================
// DELETE: Eliminar Estación
// ============================================================
bool EstacionDAO::eliminarEstacion(int estacionId) {
    String^ sSql = "DELETE FROM Estacion WHERE EstacionId = @estacionId";
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(1);
    parametros[0] = gcnew SqlParameter("@estacionId", estacionId);
    return executeSql(sSql, parametros);
}