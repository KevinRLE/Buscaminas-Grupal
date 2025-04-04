//Luis Valenzuela, clase para almacenar los registros de récords de los usuarios
#include "RecordManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>

RecordManager::RecordManager(std::string archivo) : archivoRecords(archivo) {
    cargarUsuarios();
}

void RecordManager::cargarUsuarios() {
    std::ifstream archivo(archivoRecords);
    if (archivo.is_open()) {
        std::string nombre;
        int puntaje, jugadas, ganadas;

        while (archivo >> nombre >> puntaje >> jugadas >> ganadas) {
            Usuario usuario(nombre);
            usuario.setPuntajeMaximo(puntaje);
            for (int i = 0; i < jugadas; i++) usuario.incrementarPartidasJugadas();
            for (int i = 0; i < ganadas; i++) usuario.incrementarPartidasGanadas();
            usuarios.push_back(usuario);
        }
        archivo.close();
    }
}

void RecordManager::guardarUsuarios() {
    std::ofstream archivo(archivoRecords);
    if (archivo.is_open()) {
        for (Usuario &usuario : usuarios) {
            archivo << usuario.getNombre() << " "
                    << usuario.getPuntajeMaximo() << " "
                    << usuario.getPartidasJugadas() << " "
                    << usuario.getPartidasGanadas() << "\n";
        }
        archivo.close();
    }
}

void RecordManager::agregarUsuario(std::string nombre) {
    usuarios.push_back(Usuario(nombre));
    guardarUsuarios();
}

Usuario* RecordManager::buscarUsuario(std::string nombre) {
    for (auto &usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            return &usuario;
        }
    }
    return nullptr;
}

void RecordManager::mostrarTop10() {
    // Ordenar usuarios por puntaje máximo (orden descendente)
    std::sort(usuarios.begin(), usuarios.end(), [](Usuario &a, Usuario &b) {
        return a.getPuntajeMaximo() > b.getPuntajeMaximo();
    });

    std::cout << "\n\t\tTOP 10 JUGADORES\n";
    std::cout << "\t\t----------------\n";
    int limite = std::min(10, (int)usuarios.size());
    for (int i = 0; i < limite; i++) {
        std::cout << "\t\t" << i+1 << ". " << usuarios[i].getNombre()
                  << " - Puntaje: " << usuarios[i].getPuntajeMaximo()
                  << " - Partidas: " << usuarios[i].getPartidasJugadas()
                  << " - Ganadas: " << usuarios[i].getPartidasGanadas() << "\n";
    }
    std::cout << "\n";
}
