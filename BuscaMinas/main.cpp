#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"

using namespace std;
//para 31 de marzo o 2 de abril
int main()
{
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = false;
    const int VIDASTABLERO = 3;
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //Agregar vidasTablero
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero());
    srand(getpid());
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2:
            {
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero());
                juegoTemporal.iniciar();

                system("pause");    //funcion para que no corra nada en el programa en el momento que no se ejecuta nada incluso de parte del usuario
                break;
            }
        case 3: repetir = false;
                break;
        }
    } while (repetir);
    system("cls");
    return 0;
}
