//Anthony Hetzael, Usuario con atributos y métodos completos
#include "Usuario.h"

Usuario::Usuario(std::string nombre) {
    this->nombre = nombre;
    this->puntajeMaximo = 0;
    this->partidasJugadas = 0;
    this->partidasGanadas = 0;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

int Usuario::getPuntajeMaximo() {
    return this->puntajeMaximo;
}

int Usuario::getPartidasJugadas() {
    return this->partidasJugadas;
}

int Usuario::getPartidasGanadas() {
    return this->partidasGanadas;
}

void Usuario::setPuntajeMaximo(int puntaje) {
    if (puntaje > this->puntajeMaximo) {
        this->puntajeMaximo = puntaje;
    }
}

void Usuario::incrementarPartidasJugadas() {
    this->partidasJugadas++;
}

void Usuario::incrementarPartidasGanadas() {
    this->partidasGanadas++;
}
