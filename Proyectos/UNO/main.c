/*
 * File: main
 * Author: Joshua Osorio Osorio y Manuel Alejandro Cruz Lares
 * Materia:  LENGUAJE C (531)
 * Date: 12/May/2025
 * Comments:
 */

#include "UNO_FUNCIONES.h"


/* Constantes para la interfaz */
int main(void)
{
    int opcion;
    const char *opciones[] = {"Jugar", "Salir"};
    const char *titulo = "menu principal";

    /* setlocale(LC_ALL, "Spanish"); */
    SetConsoleOutputCP(CP_UTF8); /* Cambiar a UTF-8 */
    system("cls");

    /* Menú principal */

    do
    {
        system("cls");
        mostrarTitulo();
        opcion = menu(titulo, opciones, 2, 70, 10);
        switch (opcion)
        {
        case 0:
            jugarUNO();
            break;
        case 1:
            printf("\nGracias por jugar!\n");
            exit(0);
        }
    } while (opcion != 1);

    return 0;
}
