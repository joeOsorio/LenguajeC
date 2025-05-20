/****************************************************
 * File: main.c
 * Author: Manuel alejandro y Joshua Osorio
 * Materia: Lenguaje C
 * Date: Abr/08/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <conio.h>
#include <windows.h>

#define LEN_ARRAY 5
#define JUGADORES 4
#define PARTIDAS 3

/* *************************************** Prototipos *************************************** */

int random(void);
void desplegarMatriz(char *matriz);
void mostrarTitulo(void);
void gotoxy(int x, int y);
int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y);
void llenarArrglo(char *matriz);

void jugar(int numJugadores, int *score);
int tiro(char matriz[][LEN_ARRAY]);

int main(void)
{
    /* Variables del menu */
    const char *opciones[] = {
        "Seleccionar cantidad de jugadores",
        "Jugar",
        "Salir"};
    const char *titulo = "\nMuenu\n";
    int num_opciones = sizeof(opciones) / sizeof(opciones[0]);
    int seleccion;

    /* Variables de menu de cantidada de jugadores*/
    const char *opciones_SelecJugadores[] = {
        "1 Jugador",
        "2 Jugadores",
        "3 Jugadores",
        "4 Jugadores",
        "Salir"};
    const char *titulo_SelecJugadores = "\nSeleccionar Cantidad de jugadores\n";
    int num_opciones_SelecJugadores = sizeof(opciones_SelecJugadores) / sizeof(opciones_SelecJugadores[0]);
    int numJugadores = -1;

    /* Variables de la practica */

    int score[JUGADORES][PARTIDAS] = {0};

    do
    {
        system("cls");
        /* Menú de opciones */
        mostrarTitulo();
        seleccion = menu(titulo, opciones, num_opciones, 5, 18);
        system("cls");
        /* Menú de opciones */
        mostrarTitulo();

        switch (seleccion)
        {
        case 0:
            /* Se le suma 1 porque la funcion menu tiene como indice desde la opcion 0 */
            numJugadores = 1 + menu(titulo_SelecJugadores, opciones_SelecJugadores, num_opciones_SelecJugadores, 5, 18);
            printf("\n%d jugadores", numJugadores);
            break;
        case 1:
            if ((numJugadores > 0) & (numJugadores < 5))
            {
                gotoxy(5, 18);
                jugar(numJugadores, *score);
            }
            else
            {
                gotoxy(5, 18);
                printf("\nAntes de jugar debes seleccionar la cantidad de jugadores");
            }
            break;
        case 2:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no disponible =(.\n");
        }
        printf("\n\nPresione cualquier tecla para continua");
        fflush(stdin);
        getchar();
    } while (seleccion != 4);

    return 0;
}

int random(void)
{
    return (rand() % (LEN_ARRAY + 1));
}

void mostrarTitulo(void)
{
    /* Código ANSI para color morado */
    printf("\033[35m");

    puts("         ______                              ___            ");
    puts("        /\\__  _\\__                          /\\_ \\          ");
    puts("        \\/_/\\ \\/\\_\\  _ __   ___         __  \\\\/\\ \\         ");
    puts("           \\ \\ \\/\\ \\\\`'__\\/ __ `\\     /'__`\\  \\ \\ \\        ");
    puts("            \\ \\ \\ \\ \\ \\  \\\\  \\L\\ \\   /\\ \\L\\.\\_ \\_\\ \\_      ");
    puts("             \\ \\_\\ \\_\\ \\_\\\\ \\____/   \\ \\__/.\\_\\/\\____\\     ");
    puts("              \\/_/\\/_/\\/_/ \\/___/     \\/__/\\/_/\\/____/     ");
    puts("\n\n");
    puts("         __       ___                                      ");
    puts("        /\\ \\     /\\_ \\                                     ");
    puts("        \\ \\ \\____\\//\\ \\      __      ___     ___    ___    ");
    puts("         \\ \\ '__`\\ \\ \\ \\   /'__`\\  /' _ `\\  /'___\\ / __`\\  ");
    puts("          \\ \\ \\L\\ \\ \\_\\ \\_/\\ \\L\\.\\_/\\ \\/\\ \\/\\ \\__//\\ \\L\\ \\ ");
    puts("           \\ \\_,__/ /\\____\\ \\__/.\\_\\ \\_\\ \\_\\ \\____\\ \\____/ ");
    puts("            \\/___/  \\/____/\\/__/\\/_/\\/_/\\/_/\\/____/\\/___/  ");

    /* Restablecer color al final */
    printf("\033[0m");
}

void desplegarMatriz(char *matriz)
{
    int f, c;
    for (f = 0; f < LEN_ARRAY; f++)
    {
        for (c = 0; c < LEN_ARRAY; c++)
        {
            if (*(matriz + f * LEN_ARRAY + c) == 'o')
            {
                if (c == 0 || c == LEN_ARRAY - 1 || f == 0 || f == LEN_ARRAY - 1)
                {
                    printf("\033[34m");
                    printf("%c  ", *(matriz + f * LEN_ARRAY + c));

                    /* Restablecer color al final */
                    printf("\033[0m");
                }
                else if (c == 1 || c == LEN_ARRAY - 2 || f == 1 || f == LEN_ARRAY - 2)
                {
                    /* colorear de amarillo. */
                    printf("\033[33m");
                    printf("%c  ", *(matriz + f * LEN_ARRAY + c));
                    /* Restablecer color al final */
                    printf("\033[0m");
                }
                else if (c == 2 && f == 2)
                {
                    /* colorear de rojo . */
                    printf("\033[31m");
                    printf("%c  ", *(matriz + f * LEN_ARRAY + c));
                    /* Restablecer color al final */
                    printf("\033[0m");
                }
                else
                {
                    printf("%c  ", *(matriz + f * LEN_ARRAY + c));
                }
            }
            else if (*(matriz + f * LEN_ARRAY + c) == 'x')
            {
                printf("\033[35m");
                printf("%c  ", *(matriz + f * LEN_ARRAY + c));
                printf("\033[0m");
            }
        }
        printf("\n");
    }
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
        /* system("cls"); */
        gotoxy(x, y);
        printf("%s\n", titulo);
        for (i = 0; i < num_opciones; i++)
        {
            gotoxy(x, (y + 2) + i);
            if (i == seleccion)
            {
                printf("-> %s\n", opciones[i]);
            }
            else
            {
                printf("   %s\n", opciones[i]);
            }
        }

        tecla = _getch();
        switch (tecla)
        {
        case 72:
            seleccion--;
            if (seleccion < 0)
            {
                seleccion = num_opciones - 1;
            }
            break;
        case 80:
            seleccion++;
            if (seleccion >= num_opciones)
            {
                seleccion = 0;
            }
            break;
        case 13:
            return seleccion;
        }

    } while (1);
}

void llenarArrglo(char *matriz)
{
    int f, c;
    for (f = 0; f < LEN_ARRAY; f++)
    {
        for (c = 0; c < LEN_ARRAY; c++)
        {
            *(matriz + f * LEN_ARRAY + c) = 'o';
        }
    }
}

void jugar(int numJugadores, int *score)
{
    char objetivo[LEN_ARRAY][LEN_ARRAY];
    int partida = 0, jugador;
    char seguir;
    srand(time(NULL));

    /* Inicializar scores si es la primera partida */

    /* for (jugador = 0; jugador < JUGADORES; jugador++)
    {
        for (partida = 0; partida < PARTIDAS; partida++)
        {
            *(score + jugador * JUGADORES + PARTIDAS) = 0;
        }
    } */

    do
    {
        system("cls");
        mostrarTitulo();
        gotoxy(1, 18);

        llenarArrglo(*objetivo);

        printf("\n---------------------------------------------------------------");
        for (jugador = 0; jugador < numJugadores; jugador++)
        {
            printf("\nJugador %d: %d", jugador + 1, *(score + jugador * JUGADORES + PARTIDAS));
        }

        printf("\n----------------------  Partida %d -----------------------------\n", partida + 1);

        for (jugador = 0; jugador < numJugadores; jugador++)
        {
            printf("\nTurno del Jugador %d\n", jugador + 1);
            *(score + jugador * PARTIDAS + partida) += tiro(objetivo);
            printf("Puntaje acumulado: %d\n", *(score + jugador * JUGADORES + PARTIDAS));
            Sleep(1000); /* Pausa para que no pasen cosas raras */

            /* (ptr + i * columnas + j) */
        }

        partida++;

        if (partida >= PARTIDAS)
        {
            printf("\n¡Se han completado todas las partidas!\n");
            break;
        }
        printf("\n¿Quieres continuar con la siguiente partida? (S/N)\n/>");
        scanf(" %c", &seguir);
        getchar();

    } while (seguir == 's' || seguir == 'S');

    // Mostrar resultados finales
    system("cls");
    mostrarTitulo();
    printf("\nRESULTADOS FINALES:\n");
    for (int p = 0; p < partida; p++)
    {
        printf("\nPartida %d:\n", p + 1);
        for (int jugador = 0; jugador < numJugadores; jugador++)
        {
            printf("Jugador %d: %d puntos\n", jugador + 1, *(score + jugador * PARTIDAS + p));
        }
    }
}

int tiro(char matriz[][LEN_ARRAY])
{
    int x = random(), y = random(), puntos = 0;

    /* Validar que las coordenadas estén dentro del rango */
    x = x % LEN_ARRAY;
    y = y % LEN_ARRAY;

    /* Mostrar el disparo */
    matriz[x][y] = 'x';
    desplegarMatriz(*matriz);

    if (x == 2 && y == 2)
    {
        puntos = 100; /* Centro exacto */
    }
    else if ((x >= 1 && x <= 3) && (y >= 1 && y <= 3))
    {
        puntos = 60; /*  Anillo amarillo */
    }
    else
    {
        puntos = 30; /* Anillo exterior */
    }

    /* Restaurar la matriz */
    matriz[x][y] = 'o';

    printf("Disparo en (%d,%d) - Puntos: %d\n", y, x, puntos);
    return puntos;
}