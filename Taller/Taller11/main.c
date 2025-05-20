/****************************************************
 * File: main
 * Author: Joshua Osorio Osorio *
 * Materia:  LENGUAJE C (531)
 * Date: 07/May/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
/* #include <string.h> */
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int dado1;
    int dado2;
    int suma;
} Lanzamiento;

typedef struct Jugador
{
    char nombre[50];
    int lanzamientos[20];
    int cantidad_lanzamientos;
    int exito;
} Jugador;

void lanzarDados(Lanzamiento *lanzamiento);
int jugarRondas(Jugador *j);
void determinarGanador(Jugador jugadores[], int numJugadores);
void registrarJugadores(Jugador jugadores[], int jmax);
void jugarConJugadores(Jugador jugadores[], int *numJugadores);

int main()
{
    srand(time(NULL));
    int jmax = 0;
    printf("Ingresa la cantidad de jugadores: ");
    scanf("%d", &jmax);
    Jugador jugadores[jmax];
    registrarJugadores(jugadores, jmax);
    jugarConJugadores(jugadores, &jmax);
    determinarGanador(jugadores, jmax);x
    return 0;
}
void lanzarDados(Lanzamiento *lanzamiento)
{
    lanzamiento->dado1 = rand() % 6 + 1;
    lanzamiento->dado2 = rand() % 6 + 1;
    lanzamiento->suma = lanzamiento->dado1 + lanzamiento->dado2;
}

void registrarJugadores(Jugador jugadores[], int jmax)
{
    for (int i = 0; i < jmax; i++)
    {

        printf("Ingrese el nombre del jugador[%d]:", i + 1);
        scanf("%s", jugadores[i].nombre);

        jugadores[i].cantidad_lanzamientos = 0;
        jugadores[i].exito = 0;
    }
}

void jugarConJugadores(Jugador jugadores[], int *numJugadores)
{

    for (int i = 0; i < *numJugadores; i++)
    {

        int lanzamientos_realizados = jugarRondas(&jugadores[i]);

        printf("Jugador %s realizo %d lanzamientos. ", jugadores[i].nombre, lanzamientos_realizados);

        if (jugadores[i].exito)

        {

            printf("Obtuvo una suma de 12\n");
        }
        else
        {
        }

        printf("No logro una suma de 12 en 20 lanzamientos.\n");

        printf("\n");
    }
}

void determinarGanador(Jugador jugadores[], int numJugadores)
{

    int indiceGanador = -1;
    int minLanzamientos = 21;

    for (int i = 0; i < numJugadores; i++)
    {

        if (jugadores[i].exito && jugadores[i].cantidad_lanzamientos < minLanzamientos)
        {
            minLanzamientos = jugadores[i].cantidad_lanzamientos;
            indiceGanador = i;
        }

        if (indiceGanador != -1)
        {

            printf("\nEl ganador es %s con %d lanzamientos\n", jugadores[indiceGanador].nombre, jugadores[indiceGanador].cantidad_lanzamientos);
        }
        else
        {

            printf("\nNo hubo ningun ganador; ningun jugador logro una suma de 12.\n");
        }
    }
}

int jugarRondas(struct Jugador *j)
{
    Lanzamiento lanzamiento;
    j->cantidad_lanzamientos = 0;
    for (int i = 0; i < 20; i++)
    {
        lanzarDados(&lanzamiento);

        j->lanzamientos[i] = lanzamiento.suma;
        j->cantidad_lanzamientos++;

        printf("Jugador %-10s Lanzamiento %-10d Dado 1= %-10d Dado 2 = %-10d Suma= %-10d \n", j->nombre, i + 1, lanzamiento.dado1, lanzamiento.dado2, lanzamiento.suma);
        if (lanzamiento.suma == 12)
        {
            j->exito = 1;
            break;
        }
    }
    return j->cantidad_lanzamientos;
}
