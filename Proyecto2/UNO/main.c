/*
 * File: main
 * Author: Joshua Osorio Osorio y Manuel Alejandro Cruz Lares
 * Materia:  LENGUAJE C (531)
 * Date: 12/May/2025
 * Comments:
 */

#include "UNO_FUNCIONES.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* Constantes para la interfaz */
#define MAX_JUGADORES 4
#define TITULO_UNO "\
+=================================+\n\
|                                 |\n\
|                                 |\n\
|                                 |\n\
|      _   _   _   _    ___       |\n\
|     | | | | | \\ | |  / _ \\      |\n\
|     | | | | |  \\| | | | | |     |\n\
|     | |_| | | |\\  | | |_| |     |\n\
|      \\___/  |_| \\_|  \\___/      |\n\
|                                 |\n\
|                                 |\n\
|                                 |\n\
+=================================+ "

/* Prototipos de funciones locales */
void mostrarTitulo();
void gotoxy(int x, int y);
int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y);
void configurarPartida(int *numJugadores);
void jugarUNO(int numJugadores);

int main()
{
    int numJugadores = 2; /* Valor por defecto */
    int opcion;

    /* Menú principal */
    const char *opciones[] = {"Configurar partida", "Jugar", "Salir"};
    const char *titulo = TITULO_UNO;

    do
    {
        system("cls");
        mostrarTitulo();
        opcion = menu(titulo, opciones, 3, 5, 15);
        switch (opcion)
        {
        case 0:
            configurarPartida(&numJugadores);
            break;
        case 1:
            jugarUNO(numJugadores);
            break;
        case 2:
            printf("\n¡Gracias por jugar!\n");
            exit(0);
        }
    } while (1);

    return 0;
}

/* *********************** FUNCIONES DE INTERFAZ *********************** */

void mostrarTitulo()
{
    system("cls");
    printf("\033[36m"); /* Color azul */
    puts(TITULO_UNO);
    printf("\033[0m"); /* Reset color */
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y)
{
    int seleccion = 0, tecla;
    do
    {
        /* system("cls"); */
        gotoxy(x, y);
        for (int i = 0; i < num_opciones; i++)
        {
            gotoxy(x, y + i);
            if (i == seleccion)
            {
                printf("\033[33m-> %s\033[0m\n", opciones[i]); // Amarillo para selección
            }
            else
            {
                printf("   %s\n", opciones[i]);
            }
        }
        tecla = _getch();
        switch (tecla)
        {
        case 72: // Flecha arriba
            seleccion = (seleccion - 1 + num_opciones) % num_opciones;
            break;
        case 80: // Flecha abajo
            seleccion = (seleccion + 1) % num_opciones;
            break;
        case 13: // Enter
            return seleccion;
        }
    } while (1);
}

/* --------------------------------------------------- LÓGICA DEL JUEGO --------------------------------------------------- */

void configurarPartida(int *numJugadores)
{
    system("cls");
    mostrarTitulo();

    const char *opciones[] = {"2 Jugadores", "3 Jugadores", "4 Jugadores"};
    int seleccion = menu("Seleccione el número de jugadores:", opciones, 3, 5, 15);

    *numJugadores = seleccion + 2; // Convierte opción (0-2) a 2-4 jugadores

    // Validar que no exceda el máximo
    if (*numJugadores > MAX_JUGADORES)
    {
        *numJugadores = MAX_JUGADORES;
    }

    printf("\nConfiguración guardada: %d jugadores.\n", *numJugadores);
    system("pause");
}

/* void jugarUNO(int numJugadores)
{
    JuegoUno juego;
    inicializar_juego(&juego); // Necesitarás modificar esta función en UNO_FUNCIONES.h

    while (1)
    {
        system("cls");
        mostrarTitulo();

        // Mostrar estado del juego
        printf("\n--- Turno del Jugador %d ---\n", juego.turno + 1);
        printf("Carta en el pozo: ");
        imprimir_carta(juego.descarte);
        printf("\n\nTus cartas:\n");

        // Mostrar mano del jugador actual
        for (int i = 0; i < juego.jugadores[juego.turno].cantidad; i++)
        {
            printf("%d: ", i + 1);
            imprimir_carta(juego.jugadores[juego.turno].mano[i]);
            printf("\n");
        }

        // Menú de acciones
        const char *opciones[] = {"Jugar carta", "Robar carta", "Salir"};
        int accion = menu("¿Qué deseas hacer?", opciones, 3, 5, 10 + juego.jugadores[juego.turno].cantidad);

        switch (accion)
        {
        case 0:
        { // Jugar carta
            int carta_idx;
            printf("\nIngresa el número de la carta a jugar: ");
            scanf("%d", &carta_idx);
            carta_idx--;

            if (carta_idx >= 0 && carta_idx < juego.jugadores[juego.turno].cantidad)
            {
                Carta carta = juego.jugadores[juego.turno].mano[carta_idx];
                if (es_jugada_valida(juego.descarte, carta))
                {
                    // Lógica para jugar carta (similar a tu implementación anterior)
                    // ...
                    printf("\n¡Carta jugada!\n");
                }
                else
                {
                    printf("\n¡Jugada inválida!\n");
                }
            }
            break;
        }
        case 1: // Robar carta
            robar_carta(&juego.jugadores[juego.turno], &juego);
            printf("\n¡Has robado una carta!\n");
            break;
        case 2: // Salir
            return;
        }
        system("pause");
    }
}
 */

void jugarUNO(int numJugadores)
{
    JuegoUno juego;

    // Inicializar con el número correcto de jugadores
    juego.numJugadores = numJugadores;
    inicializar_juego(&juego);

    while (1)
    {
        system("cls");
        mostrarTitulo();

        // Verificar si hay un ganador
        if (juego.jugadores[juego.turno].cantidad == 0)
        {
            printf("\n¡Jugador %d ha ganado!\n", juego.turno + 1);
            system("pause");
            return;
        }

        // Mostrar estado del juego
        printf("\n--- Turno del Jugador %d ---\n", juego.turno + 1);
        printf("Cartas restantes en mazo: %d\n", juego.cartasRestantes);
        printf("Carta en el pozo: ");
        imprimir_carta(juego.descarte);

        // Mostrar mano del jugador actual
        printf("\n\nTus cartas:\n");
        for (int i = 0; i < juego.jugadores[juego.turno].cantidad; i++)
        {
            printf("%d: ", i + 1);
            imprimir_carta(juego.jugadores[juego.turno].mano[i]);
            printf("\n");
        }

        // Menú de acciones
        const char *opciones[] = {"Jugar carta", "Robar carta", "Gritar UNO!", "Salir"};
        int accion = menu("¿Qué deseas hacer?", opciones, 4, 5, 10 + juego.jugadores[juego.turno].cantidad);

        switch (accion)
        {
        case 0:
        { // Jugar carta
            int carta_idx;
            printf("\nIngresa el número de la carta a jugar: ");
            scanf("%d", &carta_idx);
            carta_idx--;

            if (carta_idx >= 0 && carta_idx < juego.jugadores[juego.turno].cantidad)
            {
                Carta carta = juego.jugadores[juego.turno].mano[carta_idx];
                if (es_jugada_valida(juego.descarte, carta))
                {
                    // Mover carta al descarte
                    juego.descarte = carta;

                    // Eliminar carta de la mano
                    for (int i = carta_idx; i < juego.jugadores[juego.turno].cantidad - 1; i++)
                    {
                        juego.jugadores[juego.turno].mano[i] = juego.jugadores[juego.turno].mano[i + 1];
                    }
                    juego.jugadores[juego.turno].cantidad--;

                    // Aplicar efecto de carta especial
                    if (carta.color == 'N')
                    {
                        aplicar_poder(&juego, carta);
                    }

                    siguiente_turno(&juego);
                }
                else
                {
                    printf("\n¡Jugada inválida! La carta debe coincidir en color o número.\n");
                    system("pause");
                }
            }
            else
            {
                printf("\n¡Número de carta inválido!\n");
                system("pause");
            }
            break;
        }
        case 1: // Robar carta
            robar_carta(&juego.jugadores[juego.turno], &juego);
            printf("\n¡Has robado una carta!\n");
            siguiente_turno(&juego);
            system("pause");
            break;
        case 2: // Gritar UNO
            if (juego.jugadores[juego.turno].cantidad == 1)
            {
                printf("\n¡UNO! ¡Última carta!\n");
            }
            else
            {
                printf("\n¡Aún tienes más de una carta!\n");
            }
            system("pause");
            break;
        case 3: // Salir
            return;
        }
    }
}
