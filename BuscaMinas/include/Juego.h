#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
    Tablero tablero;
    int cantidadMinas;
    int vidas; //agregar vidas

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();

public:
    Juego(Tablero tablero, int cantidadMinas, int vidasTablero);
    void colocarMinasAleatoriamente();
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
    void dibujarPortada(string nombreArchivo);
    int puntosTotal(); //score

    // Función pública para acceder al tablero
    Tablero& getTablero() {
        return this->tablero;
    }
};

#endif // JUEGO_H
