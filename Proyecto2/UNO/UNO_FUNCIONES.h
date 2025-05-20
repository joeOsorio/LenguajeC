#ifndef UNO_FUNCIONES_H
#define UNO_FUNCIONES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ***************************** Constantes ***************************** */
#define MAX_CARTAS_MAZO 30
#define MAX_CARTAS_MANO 20
#define MAX_JUGADORES 4

/* **************************** Estructuras **************************** */
typedef struct
{
    char color; /* 'R':Rojo, 'A':Amarillo, 'V': Verde, 'Y': Amarillo, 'N': Negro */
    int valor;  /* 0-8 (6=+2, 7=cambio color, 8=salto) */
    /*
        R = 0-5
        A = 0-5
        V = 0-5
        Y = 0-5
        N = 2: +2 ; 2: cambio color; 2: saltos
        total de cartas = (4*6) + 6 = 30;
    */
} Carta;

typedef struct
{
    Carta mano[MAX_CARTAS_MANO];
    int cantidad;
} Jugador;

typedef struct
{
    Carta mazo[MAX_CARTAS_MAZO];
    int cartasRestantes;
    Carta descarte;
    Jugador jugadores[MAX_JUGADORES];
    int turno;
    int numJugadores; // Se agrego esto.
} JuegoUno;

/* ************************* Fin de estructuras ************************* */

/* ***************************** Prototipos ***************************** */
void crear_mazo(Carta mazo[]);
void inicializar_juego(JuegoUno *juego);
void barajar_mazo(Carta mazo[], int tamanio);
void repartir_cartas(JuegoUno *juego);
bool es_jugada_valida(Carta descarte, Carta carta_jugada);
void aplicar_poder(JuegoUno *juego, Carta carta);
void siguiente_turno(JuegoUno *juego);
void imprimir_carta(Carta carta);
void robar_carta(Jugador *jugador, JuegoUno *juego);
int jugar_partida(JuegoUno *juego);

/* ************************* Fin de prototipos ************************* */

void inicializar_juego(JuegoUno *juego)
{
    srand(time(NULL));
    crear_mazo(juego->mazo);
    barajar_mazo(juego->mazo, MAX_CARTAS_MAZO);
    juego->cartasRestantes = MAX_CARTAS_MAZO;
    juego->descarte = juego->mazo[0];
    juego->cartasRestantes--; // Quitamos la carta del mazo

    // Inicializar jugadores
    for (int i = 0; i < juego->numJugadores; i++)
    {
        juego->jugadores[i].cantidad = 0;
    }

    repartir_cartas(juego);
    juego->turno = 0;
}

/* void inicializar_juego(JuegoUno *juego)
{
    srand(time(NULL));
    crear_mazo(juego->mazo);
    barajar_mazo(juego->mazo, MAX_CARTAS_MAZO);
    juego->descarte = juego->mazo[0]; // Primera carta del mazo
    for (int i = 0; i < MAX_JUGADORES; i++)
    {
        juego->jugadores[i].cantidad = 0;
    }
    repartir_cartas(juego);
    juego->turno = 0;
}
 */
void barajar_mazo(Carta mazo[], int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        int j = rand() % tamanio;
        Carta temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

/* void imprimir_carta(Carta carta)
{
    const char *colores[] = {"\x1b[31mR", "\x1b[34mA", "\x1b[32mV", "\x1b[33mY", "\x1b[37mN"};
    int color_idx = (carta.color == 'R') ? 0 : (carta.color == 'A') ? 1
                                           : (carta.color == 'V')   ? 2
                                           : (carta.color == 'Y')   ? 3
                                                                    : 4;
    printf("[%s%d\x1b[0m]", colores[color_idx], carta.valor);
} */

void repartir_cartas(JuegoUno *juego)
{
    for (int j = 0; j < juego->numJugadores; j++)
    {
        for (int i = 0; i < 7 && juego->cartasRestantes > 0; i++)
        {
            juego->jugadores[j].mano[i] = juego->mazo[juego->cartasRestantes - 1];
            juego->jugadores[j].cantidad++;
            juego->cartasRestantes--;
        }
    }
}

/* void repartir_cartas(JuegoUno *juego)
{
    for (int j = 0; j < MAX_JUGADORES; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            juego->jugadores[j].mano[i] = juego->mazo[juego->cartasRestantes - 1];
            juego->jugadores[j].cantidad++;
            juego->cartasRestantes--;
        }
    }
}
 */
bool es_jugada_valida(Carta descarte, Carta carta_jugada)
{
    if (descarte.color == carta_jugada.color || descarte.valor == carta_jugada.valor)
    {
        return true;
    }
    return false;
}

void siguiente_turno(JuegoUno *juego)
{
    // Si la carta en el pozo es "Salto" (valor 8), se salta un turno adicional
    int saltos = 1;
    if (juego->descarte.valor == 8)
    {
        saltos++;                   // Efecto de la carta "Salto"
        juego->descarte.valor = -1; // Resetear para no aplicar el efecto repetidamente
    }

    // Avanzar el turno (módulo MAX_JUGADORES  para ciclar entre jugadores)
    juego->turno = (juego->turno + saltos) % MAX_JUGADORES;

    // Mensaje informativo
    printf("\n--- Turno del Jugador %d ---\n", juego->turno + 1);
}
void imprimir_carta(Carta carta)
{
    // Asignar colores ANSI y símbolos
    const char *color_ansi;
    const char *simbolo;

    switch (carta.color)
    {
    case 'R':
        color_ansi = "\x1b[31m";
        simbolo = "♥";
        break; // Rojo
    case 'A':
        color_ansi = "\x1b[34m";
        simbolo = "♦";
        break; // Azul
    case 'V':
        color_ansi = "\x1b[32m";
        simbolo = "♣";
        break; // Verde
    case 'Y':
        color_ansi = "\x1b[33m";
        simbolo = "♠";
        break; // Amarillo
    case 'N':
        color_ansi = "\x1b[37m";
        simbolo = "★";
        break; // Negro (especial)
    default:
        color_ansi = "\x1b[0m";
        simbolo = "?";
        break; // Por defecto
    }

    // Imprimir carta con formato: [Color Símbolo Valor]
    printf("%s[%s ", color_ansi, simbolo);

    // Mostrar valor o poder especial
    if (carta.color == 'N')
    {
        switch (carta.valor)
        {
        case 6:
            printf("+2");
            break;
        case 7:
            printf("Cambio Color");
            break;
        case 8:
            printf("Salto");
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

    printf("]\x1b[0m"); /* Resetear color */
}

void crear_mazo(Carta mazo[])
{
    int index = 0;
    char colores[] = {'R', 'A', 'V', 'Y'};

    /* Cartas normales (0-5 por color) */
    for (int c = 0; c < 4; c++)
    {
        for (int v = 0; v <= 5; v++)
        {
            mazo[index].color = colores[c];
            mazo[index].valor = v;
            index++;
        }
    }

    /* Cartas especiales (negras: +2, cambio color, salto) */
    for (int i = 0; i < 6; i++)
    {
        mazo[index++] = (Carta){'N', 6}; // +2
        mazo[index++] = (Carta){'N', 7}; // Cambio color
        mazo[index++] = (Carta){'N', 8}; // Salto
    }
}

void robar_carta(Jugador *jugador, JuegoUno *juego)
{
    if (juego->cartasRestantes > 0)
    {
        jugador->mano[jugador->cantidad++] = juego->mazo[--juego->cartasRestantes];
    }
    else
    {
        printf("¡Mazo vacío! Se reinicia con la carta de descarte.\n");
        // Opcional: Reiniciar mazo con la carta de descarte (excepto la última)
    }
}

void aplicar_poder(JuegoUno *juego, Carta carta)
{
    switch (carta.valor)
    {
    case 6: // +2
        printf("¡+2 cartas para el siguiente jugador!\n");
        robar_carta(&juego->jugadores[(juego->turno + 1) % juego->numJugadores], juego);
        robar_carta(&juego->jugadores[(juego->turno + 1) % juego->numJugadores], juego);
        break;
    case 7:
    { // Cambio color
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
    case 8: // Salto
        printf("¡Turno saltado!\n");
        siguiente_turno(juego);
        break;
    }
}

/* void aplicar_poder(JuegoUno *juego, Carta carta)
{
    switch (carta.valor)
    {
    case 6: // +2
        printf("¡+2 cartas para el siguiente jugador!\n");
        robar_carta(&juego->jugadores[(juego->turno + 1) % MAX_JUGADORES], juego);
        robar_carta(&juego->jugadores[(juego->turno + 1) % MAX_JUGADORES], juego);
        break;
    case 7: // Cambio color
        printf("Elige nuevo color (R, A, V, Y): ");
        char nuevo_color;
        scanf(" %c", &nuevo_color);
        juego->descarte.color = nuevo_color;
        break;
    case 8: // Salto
        printf("¡Turno saltado!\n");
        siguiente_turno(juego);
        break;
    }
}
 */
int jugar_partida(JuegoUno *juego)
{
    while (1)
    {
        // Verificar si un jugador ganó
        if (juego->jugadores[juego->turno].cantidad == 0)
        {
            return juego->turno; // Índice del ganador
        }

        // Mostrar estado
        printf("\n--- Turno del Jugador %d ---\n", juego->turno + 1);
        printf("Carta en pozo: ");
        imprimir_carta(juego->descarte);
        printf("\nTu mano: ");
        for (int i = 0; i < juego->jugadores[juego->turno].cantidad; i++)
        {
            printf("%d:", i);
            imprimir_carta(juego->jugadores[juego->turno].mano[i]);
        }

        // Solicitar acción
        int opcion;
        printf("\nAcción (0 robar, 1-9 jugar carta): ");
        scanf("%d", &opcion);

        if (opcion == 0)
        {
            robar_carta(&juego->jugadores[juego->turno], juego);
        }
        else if (opcion >= 1 && opcion <= 9)
        {
            int idx_carta = opcion - 1;
            if (idx_carta < juego->jugadores[juego->turno].cantidad)
            {
                Carta carta = juego->jugadores[juego->turno].mano[idx_carta];
                if (es_jugada_valida(juego->descarte, carta))
                {
                    juego->descarte = carta;
                    // Eliminar carta de la mano
                    for (int i = idx_carta; i < juego->jugadores[juego->turno].cantidad - 1; i++)
                    {
                        juego->jugadores[juego->turno].mano[i] = juego->jugadores[juego->turno].mano[i + 1];
                    }
                    juego->jugadores[juego->turno].cantidad--;
                    // Aplicar poderes
                    if (carta.color == 'N')
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

#endif