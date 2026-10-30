#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class UsuarioController {
    private:
        UsuarioDAO^ dao;

    public:
        UsuarioController();

        // Retorna "" si fue exitoso, o un mensaje de error en caso contrario
        String^ RegistrarUsuario(Usuario^ usuario);
        List<Usuario^>^ ListarUsuarios();
        Usuario^ ConsultarUsuario(int idUsuario);

        // Validación básica de Login
        Usuario^ ValidarLogin(String^ nombreUsuario, String^ contrasenia);

        String^ ModificarUsuario(Usuario^ usuario);
        String^ EliminarUsuario(int idUsuario);
    };
}