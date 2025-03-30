#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
#include "Tablero.h"

using namespace std;

int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas, int vidas)
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
		this->vidas = vidas;
	}

	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario()
    {
        int fila = 0;
        bool valido = false;
        while (!valido)
        {
            cout << "Ingresa la FILA en la que desea jugar (1 a " << tablero.getAlturaTablero() << "): ";
            cin >> fila;
            if (fila >= 1 && fila <= tablero.getAlturaTablero())
            {
                valido = true;
            }
            else
            {
                cout << "Fila invalida. Debe estar entre 1 y " << tablero.getAlturaTablero() << ".\n";
            }
        }
        return fila - 1;
    }

    int Juego::solicitarColumnaUsuario()
    {
        int columna = 0;
        bool valido = false;
        while (!valido)
        {
            cout << "Ingresa la COLUMNA en la que desea jugar (1 a " << tablero.getAnchoTablero() << "): ";
            cin >> columna;
            if (columna >= 1 && columna <= tablero.getAnchoTablero())
            {
                valido = true;
            }
            else
            {
                cout << "Columna invalida. Debe estar entre 1 y " << tablero.getAnchoTablero() << ".\n";
            }
        }
        return columna - 1;
    }

	bool Juego::jugadorGana() {
        int celdasSeguras = (tablero.getAlturaTablero() * tablero.getAnchoTablero()) - cantidadMinas;
        return (this->tablero.puntosTotal() == celdasSeguras);
    }

//Implementacion de vidas por kevin
void Juego::iniciar() {
    int fila, columna;

    while (true) {
        system("cls");
        cout << "Vidas restantes: " << this->vidas << endl;
        this->tablero.imprimir();
        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();

        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        if (!respuestaAUsuario) {
            this->vidas--;

            if (this->vidas == 0) {
                cout << "Te quedaste sin vidas. Perdiste el juego.\n";
                this->tablero.setModoDesarrollador(true);
                this->tablero.imprimir();
                cout << "Acumulaste estos puntos: " << this->tablero.puntosTotal() << endl;
                return;
            }

        }
        else {
            if (this->jugadorGana()) {
                cout << "¡Ganaste el juego!\n";
                this->tablero.setModoDesarrollador(true);
                this->tablero.imprimir();
                cout << "Ganaste estos puntos: " << this->tablero.puntosTotal() << endl;
                return;
            }
        }
    }
}
