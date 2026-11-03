#include "UsuarioDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::Data::SqlClient;

UsuarioDAO::UsuarioDAO() : BaseDAO() {
}

// ============================================================
// CREATE: Registrar Usuario
// ============================================================
int UsuarioDAO::registrarUsuario(Usuario^ usuario) {
    // 1. Usamos @nombreParametro en el SQL
    String^ sSql = "INSERT INTO Usuario (nombres, apellidos, correo, usuario, contrasenia, estado) " +
                   "VALUES (@nombres, @apellidos, @correo, @usuario, @contrasenia, @estado) ";
	// 2. Creamos un arreglo de SqlParameter para pasar los valores
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(6);
    parametros[0] = gcnew SqlParameter("@nombres", usuario->getNombres());
    parametros[1] = gcnew SqlParameter("@apellidos", usuario->getApellidos());
    parametros[2] = gcnew SqlParameter("@correo", usuario->getCorreo());
    parametros[3] = gcnew SqlParameter("@usuario", usuario->getUsuario());
    parametros[4] = gcnew SqlParameter("@contrasenia", usuario->getContrasenia());
    parametros[5] = gcnew SqlParameter("@estado", usuario->getEstado());
	// 3. Llamamos a insertSql con el SQL y los parámetros
    return insertSql(sSql, parametros);
}

// ============================================================
// READ: Buscar Todos
// ============================================================
List<Usuario^>^ UsuarioDAO::buscarTodos() {
    List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
    String^ sSql = "SELECT idUsuario, nombres, apellidos, correo, usuario, contrasenia, estado FROM Usuario";
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        SqlDataReader^ reader = comando->ExecuteReader();

        while (reader->Read()) {
            Usuario^ u = gcnew Usuario(
                Convert::ToInt32(reader["idUsuario"]),
                reader["nombres"]->ToString(),
                reader["apellidos"]->ToString(),
                reader["correo"]->ToString(),
                reader["usuario"]->ToString(),
                reader["contrasenia"]->ToString(),
                reader["estado"]->ToString()
            );
            listaUsuarios->Add(u);
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al listar usuarios: " + ex->Message);
    }
    return listaUsuarios;
}

// ============================================================
// READ: Buscar por ID
// ============================================================
Usuario^ UsuarioDAO::buscarxId(int idUsuario) {
    String^ sSql = "SELECT idUsuario, nombres, apellidos, correo, usuario, contrasenia, estado " +
        "FROM Usuario WHERE idUsuario = @idUsuario";
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		// Usamos parámetros para evitar Inyección SQL
        comando->Parameters->AddWithValue("@idUsuario", idUsuario);
        SqlDataReader^ reader = comando->ExecuteReader();
        if (reader->Read()) {
            Usuario^ u = gcnew Usuario(
                Convert::ToInt32(reader["idUsuario"]),
                reader["nombres"]->ToString(),
                reader["apellidos"]->ToString(),
                reader["correo"]->ToString(),
                reader["usuario"]->ToString(),
                reader["contrasenia"]->ToString(),
                reader["estado"]->ToString()
            );
            reader->Close();
            cerrarConexion();
            return u;
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al buscar usuario por ID: " + ex->Message);
    }
    return nullptr;
}

// ============================================================
// READ: Buscar por Nombre de Usuario (Login)
// ============================================================
Usuario^ UsuarioDAO::buscarxNombreUsuario(String^ nombreUsuario, String^ contrasenia) {
    String^ sSql = "SELECT idUsuario, nombres, apellidos, correo, usuario, contrasenia, estado " +
                   "FROM Usuario WHERE usuario = @nombreUsuario AND contrasenia = @contrasenia";
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		// Usamos parámetros para evitar Inyección SQL
        comando->Parameters->AddWithValue("@nombreUsuario", nombreUsuario);
        comando->Parameters->AddWithValue("@contrasenia", contrasenia);
        SqlDataReader^ reader = comando->ExecuteReader();
        if (reader->Read()) {
            Usuario^ u = gcnew Usuario(
                Convert::ToInt32(reader["idUsuario"]),
                reader["nombres"]->ToString(),
                reader["apellidos"]->ToString(),
                reader["correo"]->ToString(),
                reader["usuario"]->ToString(),
                reader["contrasenia"]->ToString(),
                reader["estado"]->ToString()
            );
            reader->Close();
            cerrarConexion();
            return u;
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al buscar usuario: " + ex->Message);
    }
    return nullptr;
}

// ============================================================
// UPDATE: Modificar Usuario
// ============================================================
bool UsuarioDAO::modificarUsuario(Usuario^ usuario) {
    // 1. Usamos @parametros en la sentencia SQL
    String^ sSql = "UPDATE Usuario SET nombres=@nombres, " +
        "apellidos=@apellidos, " +
        "correo=@correo, " +
        "usuario=@usuario, " +
        "contrasenia=@contrasenia, " +
        "estado=@estado " +
        "WHERE idUsuario=@id";

	// 2. Creamos el arreglo de parámetros, OJO son 7 parámetros
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(7);

    parametros[0] = gcnew SqlParameter("@nombres", usuario->getNombres());          //1
	parametros[1] = gcnew SqlParameter("@apellidos", usuario->getApellidos());      //2
	parametros[2] = gcnew SqlParameter("@correo", usuario->getCorreo());            //3
	parametros[3] = gcnew SqlParameter("@usuario", usuario->getUsuario());          //4
	parametros[4] = gcnew SqlParameter("@contrasenia", usuario->getContrasenia());  //5
	parametros[5] = gcnew SqlParameter("@estado", usuario->getEstado());            //6
    parametros[6] = gcnew SqlParameter("@id", usuario->getIdUsuario());             //7, Importante el int aquí

    // 3. Llamamos al nuevo método seguro de BaseDAO
    return executeSql(sSql, parametros);
}

// ============================================================
// DELETE: Eliminar (Borrado lógico)
// ============================================================
bool UsuarioDAO::eliminarUsuario(int idUsuario) {
    // 1. Usamos @parametros en la sentencia SQL
    String^ sSql = "DELETE FROM Usuario WHERE idUsuario=@id";

    // 2. Creamos el arreglo de parámetros
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(1);
    parametros[0] = gcnew SqlParameter("@id", idUsuario);

    // 3. Llamamos al nuevo método seguro de BaseDAO
    return executeSql(sSql, parametros);
}