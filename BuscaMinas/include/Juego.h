#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;

	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();
	int vidas; //agregar vidas
public:
    Juego(Tablero tablero, int cantidadMinas, int vidasTablero);
	void colocarMinasAleatoriamente();
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana();
	void iniciar();
	void dibujarPortada(string nombreArchivo);
	int puntosTotal(); //score
};

#endif // JUEGO_H
