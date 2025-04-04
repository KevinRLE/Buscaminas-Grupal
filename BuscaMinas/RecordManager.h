//Luis Valenzuela, creación de encabezado
#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <vector>
#include <string>
#include "Usuario.h"

class RecordManager {
private:
    std::vector<Usuario> usuarios;
    std::string archivoRecords;

public:
    RecordManager(std::string archivo);
    void cargarUsuarios();
    void guardarUsuarios();
    void agregarUsuario(std::string nombre);
    Usuario* buscarUsuario(std::string nombre); // importante
    void mostrarTop10();
};

#endif
