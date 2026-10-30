#include "UsuarioController.h"

namespace SGPlantaReciclajeController {

    UsuarioController::UsuarioController() {
        dao = gcnew UsuarioDAO();
    }

    String^ UsuarioController::RegistrarUsuario(Usuario^ usuario) {
        // Validaciones básicas de negocio
        if (usuario == nullptr) return "El usuario es nulo.";
        if (String::IsNullOrWhiteSpace(usuario->getUsuario())) return "El nombre de usuario es obligatorio.";
        if (String::IsNullOrWhiteSpace(usuario->getContrasenia())) return "La contraseña es obligatoria.";

        // Verificar si el nombre de usuario ya existe (evitar duplicados)
        if (dao->buscarxNombreUsuario(usuario->getUsuario(), usuario->getContrasenia()) != nullptr) {
            return "El nombre de usuario ya se encuentra registrado.";
        }

        int idGenerado = dao->registrarUsuario(usuario);
        if (idGenerado > 0) {
            return ""; // Éxito
        }
        return "Ocurrió un error en la base de datos al registrar el usuario.";
    }

    List<Usuario^>^ UsuarioController::ListarUsuarios() {
        return dao->buscarTodos();
    }

    Usuario^ UsuarioController::ConsultarUsuario(int idUsuario) {
        return dao->buscarxId(idUsuario);
    }

    Usuario^ UsuarioController::ValidarLogin(String^ nombreUsuario, String^ contrasenia) {
        Usuario^ obj = dao->buscarxNombreUsuario(nombreUsuario, contrasenia);
        if (obj != nullptr && obj->getEstado() == "A") {
            return obj; // Login exitoso y cuenta activa
        }
        return nullptr; // Usuario no encontrado, contraseña incorrecta o inactivo
    }

    String^ UsuarioController::ModificarUsuario(Usuario^ usuario) {
        if (usuario == nullptr) return "El usuario es nulo.";
        if (usuario->getIdUsuario() <= 0) return "El ID del usuario no es válido.";

        bool exito = dao->modificarUsuario(usuario);
        if (exito) return "";
        return "Ocurrió un error al modificar el usuario.";
    }

    String^ UsuarioController::EliminarUsuario(int idUsuario) {
        if (idUsuario <= 0) return "El ID del usuario no es válido.";

        bool exito = dao->eliminarUsuario(idUsuario);
        if (exito) return "";
        return "Ocurrió un error al eliminar el usuario.";
    }
}