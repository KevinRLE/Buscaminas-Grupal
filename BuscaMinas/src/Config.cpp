#include "Config.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}

int Config::getfilasTablero() { return this->filasTablero; }
int Config::setfilasTablero(int filasTablero) { return this->filasTablero = filasTablero; }
int Config::getcolumnasTablero() { return this->columnasTablero; }
int Config::setcolumnasTablero(int columnasTablero) { return this->columnasTablero = columnasTablero; }
int Config::getminasTablero() { return this->minasTablero; }
int Config::setminasTablero(int minasTablero) { return this->minasTablero = minasTablero; }
bool Config::getmodoDesarrolladorTablero() { return this->modoDesarrolladorTablero; }
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero) { return this->modoDesarrolladorTablero = modoDesarrolladorTablero; }
int Config::getvidasTablero() { return this->vidasTablero; }
int Config::setvidasTablero(int vidasTablero) { return this->vidasTablero = vidasTablero; }

void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t[0 = modo jugador][1 = modo desarrollador]" << endl; // aqui se puso el nuevo texto para el menu "Ferdynand"
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones != 6)
        {
            cout << "\n\t\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }

        switch (opciones)
        {
        case 1:
            {

                if (valorIngresado < 2) {
                    cout << "El tamaño minimo de filas permitido es 2. Se ajustara automaticamente a 2." << endl;
                    this->setfilasTablero(2);
                } else if (valorIngresado > 10) {
                    cout << "El tamaño maximo de filas permitido es 10. Se ajustara automaticamente a 10." << endl;
                    this->setfilasTablero(10);
                } else {
                    this->setfilasTablero(valorIngresado);
                }
                cout << "\t\tFilas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {

                if (valorIngresado < 2) {
                    cout << "El tamaño minimo de columnas permitido es 2. Se ajustara automaticamente a 2." << endl;
                    this->setcolumnasTablero(2);
                } else if (valorIngresado > 10) {
                    cout << "El tamaño maximo de columnas permitido es 10. Se ajustara automaticamente a 10." << endl;
                    this->setcolumnasTablero(10);
                } else {
                    this->setcolumnasTablero(valorIngresado);
                }
                cout << "\t\tColumnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {

                int maxMinas = max(1, (this ->getcolumnasTablero() * this->getfilasTablero()) / 10);

                if (valorIngresado > maxMinas)
                {
                    cout <<"\t\tEl maximo de minas que puedes colocar es el 10% del total de celdas y el minimo de 1 mina: " << maxMinas << endl;
                    this->setminasTablero(maxMinas);
                }else if (valorIngresado <= 0){
                    this ->setminasTablero (1);
                } else
                {
                    this->setminasTablero(valorIngresado);
                    cout << "\t\tMinas del Tablero actualizadas" << endl;
                }
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "\t\tModo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "\t\tVidas del Juego actualizadas" << endl;
                break;
            }
        case 6:
            repetir = false;
            break;
        }
        system("pause");
    } while (repetir);
}
