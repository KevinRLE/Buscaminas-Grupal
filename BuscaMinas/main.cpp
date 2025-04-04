#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
#include "RecordManager.h"

using namespace std;

int main() {
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = false;
    const int VIDASTABLERO = 3;

    RecordManager records("records.txt");//records guardados, Luis Valenzuela y Anthony Hetzael
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);

    string nombreUsuario;
    cout << "\n\t\tIngrese su nombre de usuario: ";
    cin >> nombreUsuario;

    Usuario* usuarioActual = records.buscarUsuario(nombreUsuario);
    if (usuarioActual == nullptr) {
        records.agregarUsuario(nombreUsuario);
        usuarioActual = records.buscarUsuario(nombreUsuario);
        cout << "\n\t\tNuevo usuario creado. ¡Bienvenido, " << nombreUsuario << "!\n";
    } else {
        cout << "\n\t\tBienvenido de vuelta, " << nombreUsuario << "!\n";
        cout << "\t\tTu puntaje máximo: " << usuarioActual->getPuntajeMaximo() << "\n";
    }

    system("pause");

    int opciones;
    bool repetir = true;
    do {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Ver records" << endl; // Anthony Hetzael, opción para ver los récords
        cout << "\t\t4. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1: {
                configuracionJuego.menuConfiguracion();
                break;
            }
            case 2: {
                Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(),
                                          configuracionJuego.getcolumnasTablero(),
                                          configuracionJuego.getmodoDesarrolladorTablero()),
                                  configuracionJuego.getminasTablero(),
                                  configuracionJuego.getvidasTablero());
                juegoTemporal.iniciar();

                // Actualizar estadísticas del usuario
                usuarioActual->incrementarPartidasJugadas();
                int puntajeActual = juegoTemporal.getTablero().puntosTotal();
                usuarioActual->setPuntajeMaximo(puntajeActual);

                if (juegoTemporal.jugadorGana()) {
                    usuarioActual->incrementarPartidasGanadas();
                }

                records.guardarUsuarios();
                system("pause");
                break;
            }
            case 3: {
                records.mostrarTop10();
                system("pause");
                break;
            }
            case 4: {
                repetir = false;
                break;
            }
        }
    } while (repetir);

    system("cls");
    return 0;
}
