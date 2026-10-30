#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace SGPlantaReciclajeModel;

    public ref class UsuarioDAO : public BaseDAO {
    public:
        UsuarioDAO();

        // CRUD
        int registrarUsuario(Usuario^ usuario); // Devuelve el ID generado o 0 si falla
        List<Usuario^>^ buscarTodos();
        Usuario^ buscarxId(int idUsuario);
        Usuario^ buscarxNombreUsuario(String^ nombreUsuario, String^ contrasenia);
        bool modificarUsuario(Usuario^ usuario);
        bool eliminarUsuario(int idUsuario); // Borrado lógico (cambiar estado a 'I')
    };
}