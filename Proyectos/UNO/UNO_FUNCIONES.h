#ifndef UNO_FUNCIONES_H
#define UNO_FUNCIONES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>   /* funciones de entrada/salida `printf` y `scanf`.*/
#include <stdlib.h>  /* funciones como `system` y `exit` */
#include <conio.h>   /* funciones como `_getch()` no estandar */
#include <windows.h> /* funciones específicas de Windows como `SetConsoleOutputCP` y `COORD` */

/* ***************************** Constantes ***************************** */
#define MAX_CARTAS_MAZO 44
#define MAX_CARTAS_MANO 20
#define MAX_JUGADORES 4
/* **************************** Estructuras **************************** */
typedef struct
{
    char color; /* R:Rojo, A:Azul, V:Verde, Y:Amarillo */
    int valor;  /* 0-5 normales, 6 = +2, 7 = Salto, 8 = Cambio de color */
} CARTA;

typedef struct
{
    CARTA mano[MAX_CARTAS_MANO]; /* Mano del jugador */
    int cantidad;                /* Cantidad de cartas en la mano */
} JUGADOR;

typedef struct
{
    CARTA mazo[MAX_CARTAS_MAZO];      /* Mazo de cartas */
    CARTA descartes[MAX_CARTAS_MAZO]; /* Cartas descartadas (historial) */
    int num_descartes;                /* Contador de descartes */
    int cartasRestantes;              /* Cartas restantes en el mazo */
    CARTA descarte;                   /* Última carta jugada */
    JUGADOR jugadores[MAX_JUGADORES]; /* Jugadores */
    int turno;                        /* Índice del jugador actual */
    int numJugadores;                 /* Número de jugadores */
    bool saltarTurno;                 /* Indica si el turno debe ser saltado */

} JUEGO_UNO;

/* ************************* Prototipos ************************* */
void inicializar_juego(JUEGO_UNO *juego);
void crear_mazo(CARTA mazo[]);
void barajar_mazo(CARTA mazo[], int tamanio);
void repartir_cartas(JUEGO_UNO *juego);
bool es_jugada_valida(CARTA descarte, CARTA carta_jugada);
void aplicar_poder(JUEGO_UNO *juego, CARTA carta);
void siguiente_turno(JUEGO_UNO *juego);
void imprimir_carta(CARTA carta);
void robar_carta(JUGADOR *jugador, JUEGO_UNO *juego);
int jugar_partida(JUEGO_UNO *juego);
void mostrarTitulo(void);
void gotoxy(int x, int y);
int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y);
void jugarUNO(void);

/* ************************* Implementaciones ************************* */

void inicializar_juego(JUEGO_UNO *juego)
{
    int i;
    srand(time(NULL));
    crear_mazo(juego->mazo);
    barajar_mazo(juego->mazo, MAX_CARTAS_MAZO);
    juego->cartasRestantes = MAX_CARTAS_MAZO;
    juego->descarte = juego->mazo[0];
    juego->cartasRestantes--;

    for (i = 0; i < juego->numJugadores; i++)
    {
        juego->jugadores[i].cantidad = 0;
    }

    repartir_cartas(juego);
    juego->turno = 0;
    juego->saltarTurno = false;
}

void crear_mazo(CARTA mazo[])
{
    int index = 0, v, c, i;
    char colores[] = {'R', 'A', 'V', 'Y'};

    for (c = 0; c < 4; c++)
    {
        /* Números 0-5 */
        for (v = 0; v <= 5; v++)
        {
            mazo[index].color = colores[c];
            mazo[index].valor = v;
            index++;
        }
        /* Cartas +2 y Salto (dos de cada por color) */
        for (i = 0; i < 2; i++)
        {
            mazo[index].color = colores[c];
            mazo[index].valor = 6; /* +2 */
            index++;

            mazo[index].color = colores[c];
            mazo[index].valor = 7; /* Salto */
            index++;
        }
    }

    /* Cartas negras (Cambio de color, 4 en total) */
    for (i = 0; i < 4; i++)
    {
        mazo[index].color = 'N';
        mazo[index].valor = 8; /* Cambio color */
        index++;
    }
}
void barajar_mazo(CARTA mazo[], int tamanio)
{
    int i;
    for (i = 0; i < tamanio; i++)
    {
        int j = rand() % tamanio;
        CARTA temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void repartir_cartas(JUEGO_UNO *juego)
{
    int i, j;
    for (j = 0; j < juego->numJugadores; j++)
    {
        for (i = 0; i < 7 && juego->cartasRestantes > 0; i++)
        {
            juego->jugadores[j].mano[i] = juego->mazo[--juego->cartasRestantes];
            juego->jugadores[j].cantidad++;
        }
    }
}

bool es_jugada_valida(CARTA descarte, CARTA carta_jugada)
{
    return (
        descarte.color == carta_jugada.color ||
        descarte.valor == carta_jugada.valor ||
        carta_jugada.color == 'N');
}

void siguiente_turno(JUEGO_UNO *juego)
{
    int incremento = juego->saltarTurno ? 2 : 1;
    juego->turno = (juego->turno + incremento) % juego->numJugadores;
    juego->saltarTurno = false;
    printf("\n--- Turno del JUGADOR %d ---\n", juego->turno + 1);
}

void imprimir_carta(CARTA carta)
{
    const char *color_ansi;
    switch (carta.color)
    {
    case 'R':
        color_ansi = "\x1b[31m";
        break;
    case 'A':
        color_ansi = "\x1b[34m";
        break;
    case 'V':
        color_ansi = "\x1b[32m";
        break;
    case 'Y':
        color_ansi = "\x1b[33m";
        break;
    case 'N':
        color_ansi = "\x1b[1;36m";
        break;
    default:
        color_ansi = "\x1b[0m";
        break;
    }

    printf("%s", color_ansi);
    if (carta.valor >= 6)
    {
        switch (carta.valor)
        {
        case 6:
            printf("+2");
            break;
        case 7:
            printf("Salto");
            break;
        case 8:
            printf("Cambio Color");
            break;
        default:
            printf("?");
            break;
        }
    }
    else
    {
        printf("%d", carta.valor);
    }
    printf("\x1b[0m");
}

void robar_carta(JUGADOR *jugador, JUEGO_UNO *juego)
{
    if (juego->cartasRestantes == 0)
    {
        /* Reiniciar mazo con el descarte (excepto la última carta) */
        CARTA ultima = juego->descarte;
        int i, num_descarte = MAX_CARTAS_MAZO - juego->cartasRestantes - 1;
        for (i = 0; i < num_descarte; i++)
        {
            juego->mazo[i] = juego->mazo[MAX_CARTAS_MAZO - num_descarte + i];
        }
        juego->cartasRestantes = num_descarte;
        barajar_mazo(juego->mazo, juego->cartasRestantes);
        juego->descarte = ultima; /* Restaurar la última carta al pozo */
    }

    if (juego->cartasRestantes > 0)
    {
        jugador->mano[jugador->cantidad++] = juego->mazo[--juego->cartasRestantes];
    }
    else
    {
        printf("¡Mazo vacío!\n");
    }
}

void aplicar_poder(JUEGO_UNO *juego, CARTA carta)
{
    int i, siguiente = (juego->turno + 1) % juego->numJugadores;

    switch (carta.valor)
    {
    case 6: /* +2 */
        printf("¡+2 cartas para el siguiente jugador (Jugador %d)!\n", siguiente + 1);
        for (i = 0; i < 2; i++)
        {
            robar_carta(&juego->jugadores[siguiente], juego);
        }
        juego->saltarTurno = true; /* Activar el salto */
        siguiente_turno(juego);    /* Forzar el avance de turno */
        break;

    case 7: /* Salto */
        printf("¡Turno del siguiente jugador será saltado!\n");
        juego->saltarTurno = true;
        break;

    case 8: /* Cambio de color */
    {
        char nuevo_color;
        do
        {
            printf("Elige nuevo color (R:Rojo, A:Azul, V:Verde, Y:Amarillo): ");
            scanf(" %c", &nuevo_color);
            nuevo_color = toupper(nuevo_color);
        } while (nuevo_color != 'R' && nuevo_color != 'A' &&
                 nuevo_color != 'V' && nuevo_color != 'Y');
        juego->descarte.color = nuevo_color;
        break;
    }

    default:
        break;
    }
}

int jugar_partida(JUEGO_UNO *juego)
{
    int opcion, i;
    while (1)
    {
        if (juego->jugadores[juego->turno].cantidad == 0)
            return juego->turno;
        gotoxy(60, 15);
        printf("\n--- Turno del JUGADOR %d ---\n", juego->turno + 1);
        printf("CARTA en pozo: ");
        imprimir_carta(juego->descarte);
        printf("\nTu mano: ");
        for (i = 0; i < juego->jugadores[juego->turno].cantidad; i++)
        {
            printf(" %d:", i);
            imprimir_carta(juego->jugadores[juego->turno].mano[i]);
        }

        printf("\nAcción (0 robar, 1-9 jugar carta): ");
        scanf("%d", &opcion);

        if (opcion == 0)
        {
            robar_carta(&juego->jugadores[juego->turno], juego);
            siguiente_turno(juego);
        }
        else if (opcion >= 1 && opcion <= 9)
        {
            int idx_carta = opcion - 1;
            if (idx_carta < juego->jugadores[juego->turno].cantidad)
            {
                CARTA carta = juego->jugadores[juego->turno].mano[idx_carta];
                if (es_jugada_valida(juego->descarte, carta))
                {
                    juego->descarte = carta;

                    for (i = idx_carta; i < juego->jugadores[juego->turno].cantidad - 1; i++)
                        juego->jugadores[juego->turno].mano[i] = juego->jugadores[juego->turno].mano[i + 1];

                    juego->jugadores[juego->turno].cantidad--;

                    aplicar_poder(juego, carta);
                    siguiente_turno(juego);
                }
                else
                {
                    printf("¡Jugada inválida!\n");
                }
            }
        }
    }
}

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
                        aplicar_poder(&juego, carta);

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

#endif