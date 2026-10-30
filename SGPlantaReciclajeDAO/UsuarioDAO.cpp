#include "UsuarioDAO.h"

using namespace SGPlantaReciclajeDAO;
using namespace System::Data::SqlClient;

UsuarioDAO::UsuarioDAO() : BaseDAO() {
}

// ============================================================
// CREATE: Registrar Usuario
// ============================================================
int UsuarioDAO::registrarUsuario(Usuario^ usuario) {
    // Usamos parámetros para evitar Inyección SQL
    String^ sSql = "INSERT INTO Usuario (nombres, apellidos, correo, usuario, contrasenia, estado) " +
        "VALUES ('" + usuario->getNombres() + "', " +
        "'" + usuario->getApellidos() + "', " +
        "'" + usuario->getCorreo() + "', " +
        "'" + usuario->getUsuario() + "', " +
        "'" + usuario->getContrasenia() + "', " +
        "'" + usuario->getEstado() + "'); SELECT SCOPE_IDENTITY(); ";
    return insertSql(sSql);
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
        "FROM Usuario WHERE idUsuario = " + idUsuario;

    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
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
        "FROM Usuario WHERE usuario = '" + nombreUsuario + "' AND contrasenia = '" + contrasenia + "'";

    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
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
	String^ sSql = "UPDATE Usuario SET nombres='" + usuario->getNombres() + "', " +
		"apellidos = '" + usuario->getApellidos() + "', " +
        "correo = '" + usuario->getCorreo() + "', " +
        "usuario='" + usuario->getUsuario() + "', " +
        "contrasenia='" + usuario->getContrasenia() + "', " +
        "estado='" + usuario->getEstado() + "' " +
        "WHERE idUsuario=" + usuario->getIdUsuario();
	return executeSql(sSql);
}

// ============================================================
// DELETE: Eliminar (Borrado lógico)
// ============================================================
bool UsuarioDAO::eliminarUsuario(int idUsuario) {
    String^ sSql = "DELETE FROM Usuario WHERE idUsuario=" + idUsuario.ToString();
	return executeSql(sSql);
}