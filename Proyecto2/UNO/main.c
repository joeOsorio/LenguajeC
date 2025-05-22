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
#include <locale.h>

/* Constantes para la interfaz */
#define MAX_JUGADORES 4
#define TITULO_UNO "\
\033[31m+=================================+\033[0m\n\
\033[31m|                                 |\033[0m\033[31m\033[0m\n\
\033[31m|      \033[0;33m_   _   _   _    ___\033[0m       \033[31m|\033[0m\n\
\033[31m|     \033[0;33m| | | | | \\ | |  / _ \\\033[0m      \033[31m|\033[0m\n\
\033[31m|     \033[0;33m| | | | |  \\| | | | | |\033[0m     \033[31m|\033[0m\n\
\033[31m|     \033[0;33m| |_| | | |\\  | | |_| |\033[0m     \033[31m|\033[0m\n\
\033[31m|      \033[0;33m\\___/  |_| \\_|  \\___/\033[0m      \033[31m|\033[0m\n\
\033[31m|                                 \033[31m|\033[0m\n\
\033[31m+=================================+\033[0m"

/* Prototipos de funciones locales */
void mostrarTitulo(void);
void gotoxy(int x, int y);
int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y);
void jugarUNO(void);

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

/* *********************** FUNCIONES DE INTERFAZ *********************** */

void mostrarTitulo(void)
{
    puts("\n");
    gotoxy(60, 1);
    puts("\033[31m+=================================+\033[0m\n");
    gotoxy(60, 2);
    puts("\033[31m|                                 |\033[0m\033[31m\033[0m\n");
    gotoxy(60, 3);
    puts("\033[31m|      \033[0;33m_   _   _   _    ___\033[0m       \033[31m|\033[0m\n");
    gotoxy(60, 4);
    puts("\033[31m|     \033[0;33m| | | | | \\ | |  / _ \\\033[0m      \033[31m|\033[0m\n");
    gotoxy(60, 5);
    puts("\033[31m|     \033[0;33m| | | | |  \\| | | | | |\033[0m     \033[31m|\033[0m\n");
    gotoxy(60, 6);
    puts("\033[31m|     \033[0;33m| |_| | | |\\  | | |_| |\033[0m     \033[31m|\033[0m\n");
    gotoxy(60, 7);
    puts("\033[31m|      \033[0;33m\\___/  |_| \\_|  \\___/\033[0m      \033[31m|\033[0m\n");
    gotoxy(60, 8);
    puts("\033[31m|                                 \033[31m|\033[0m\n");
    gotoxy(60, 9);
    puts("\033[31m+=================================+\033[0m");
    gotoxy(60, 10);
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
    int seleccion = 0, tecla, i;
    do
    {
        gotoxy(x, y);
        printf("%s\n", titulo);
        for (i = 0; i < num_opciones; i++)
        {
            gotoxy(x, y + 2 + i);
            if (i == seleccion)
            {
                printf("\033[33m-> %s\033[0m\n", opciones[i]); /* Amarillo para selección */
            }
            else
            {
                printf("   %s\n", opciones[i]);
            }
        }
        tecla = _getch();
        switch (tecla)
        {
        case 72: /* Flecha arriba */
            seleccion = (seleccion - 1 + num_opciones) % num_opciones;
            break;
        case 80: /* Flecha abajo */
            seleccion = (seleccion + 1) % num_opciones;
            break;
        case 13: /* Enter */
            return seleccion;
        }
    } while (1);
}

/* --------------------------------------------------- LÓGICA DEL JUEGO --------------------------------------------------- */

void jugarUNO(void)
{
    JUEGO_UNO juego;
    CARTA carta;
    int numJugadores, carta_idx, i, accion;
    const char *opciones[] = {"Jugar carta", "Robar carta", "Gritar UNO!", "Salir"};
    bool turno_activo;

    /* Solicitar número de jugadores (2-4) */
    do
    {
        system("cls");
        mostrarTitulo();
        printf("\nIngrese el número de jugadores (2-4): ");
        scanf("%d", &numJugadores);
    } while (numJugadores < 2 || numJugadores > MAX_JUGADORES);

    /* Inicializar juego */
    juego.numJugadores = numJugadores;
    inicializar_juego(&juego);

    while (1)
    {
        turno_activo = true;
        while (turno_activo)
        {
            system("cls");
            mostrarTitulo();

            /* Mostrar estado del juego */
            gotoxy(60, 15);
            printf("\n--- Turno del Jugador %d ---\n", juego.turno + 1);
            gotoxy(60, 16);
            printf("Cartas restantes en mazo: %d\n", juego.cartasRestantes);
            gotoxy(60, 17);
            printf("Carta en el pozo: ");
            imprimir_carta(juego.descarte);

            /* Mostrar mano del jugador */
            printf("\n\nTus cartas:\n");
            for (i = 0; i < juego.jugadores[juego.turno].cantidad; i++)
            {
                printf("%d: ", i + 1);
                imprimir_carta(juego.jugadores[juego.turno].mano[i]);
                printf("\t");
            }

            /* Menú de acciones */
            accion = menu("¿Qué deseas hacer?", opciones, 4, 70, 25);

            switch (accion)
            {
            case 0: /* Jugar carta */
                gotoxy(70, 32);
                printf("\nIngresa el número de la carta a jugar: ");
                scanf("%d", &carta_idx);
                carta_idx--;

                if (carta_idx >= 0 && carta_idx < juego.jugadores[juego.turno].cantidad)
                {
                    carta = juego.jugadores[juego.turno].mano[carta_idx];
                    if (es_jugada_valida(juego.descarte, carta))
                    {
                        /* Mover carta al descarte */
                        juego.descarte = carta;
                        for (i = carta_idx; i < juego.jugadores[juego.turno].cantidad - 1; i++)
                        {
                            juego.jugadores[juego.turno].mano[i] = juego.jugadores[juego.turno].mano[i + 1];
                        }
                        juego.jugadores[juego.turno].cantidad--;

                        /* Verificar victoria */
                        if (juego.jugadores[juego.turno].cantidad == 0)
                        {
                            printf("\n¡Jugador %d ha ganado!\n", juego.turno + 1);
                            system("pause");
                            return;
                        }

                        /* Aplicar poder especial */
                        if (carta.color == 'N')
                        {
                            aplicar_poder(&juego, carta);
                        }

                        siguiente_turno(&juego);
                        turno_activo = false;
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

            case 1: /* Robar carta */
                robar_carta(&juego.jugadores[juego.turno], &juego);
                printf("\n¡Has robado una carta!\n");
                system("pause");
                break;

            case 2: /* Gritar UNO */
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

            case 3: /* Salir */
                return;
            }
        }
    }
}