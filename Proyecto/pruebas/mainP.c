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
#define PARTIDAS  3

/* Prototipos */

int random(void);

void desplegarMatriz(char matriz[][LEN_ARRAY]);
void mostrarTitulo(void);

void gotoxy(int x, int y);
int menu(const char *titulo, const char *opciones[], int num_opciones, int x, int y);
void llenarArrglo(char matriz[][LEN_ARRAY]);

void jugar(int numJugadores, double score[]);
int tiro(char matriz[][LEN_ARRAY]);

int main(void)
{
    /* Variables del menu */
    const char *opciones[] = {
        "Seleccionar cantidad de jugadores",
        "Jugar",
        "Tablero",
        "Reiniciar",
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
    int numJugadores;

    /* Variables de la practica */

    double score[PARTIDAS][JUGADORES]= {0};

    do
    {
        system("cls");
        // Menú de opciones
        mostrarTitulo();
        seleccion = menu(titulo, opciones, num_opciones, 5, 18);


	seleccion = 3;

        system("cls");
        mostrarTitulo();

        switch (seleccion)
        {
        case 0:
            /* Se le suma 1 porque la funcion menu tiene como indice desde la opcion 0 */
            numJugadores = 1 + menu(titulo_SelecJugadores, opciones_SelecJugadores, num_opciones, 5, 18);
            break;
        case 1:
            if (numJugadores > 0 & numJugadores < 5)
            {
                gotoxy(5, 18);
                jugar(numJugadores, score);
            }
            else
            {
                gotoxy(5, 18);
                printf("\nAntes de jugar debes seleccionar la cantidad de jugadores");
            }
            /*printf("Cantidad de jugadores = %d", numJugadores); */
            break;
        case 2:
		

            break;
        case 3:
		char objetivo[LEN_ARRAY][LEN_ARRAY] = {'o'};
		llenarArrglo(objetivo);
		desplegarMatriz(objetivo);
		printf("Tiro siguiente\n");
    		tiro(objetivo);
    		desplegarMatriz(objetivo);



            break;
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no disponible =(.\n");
        }
        printf("\n\nPresione cualquier tecla para continua");
        fflush(stdin);
        getchar();
    } while (seleccion != 5);

    return 0;
}

int random(void)
{
    return rand() % (LEN_ARRAY + 2) + 1;
}

void mostrarTitulo(void)
{
    // Código ANSI para color morado
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

    // Restablecer color al final
    printf("\033[0m");
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
void jugar(int numJugadores, double score[])
{
    srand(time(NULL));
    char objetivo[LEN_ARRAY][LEN_ARRAY] = {'o'};
    printf("\n");
    llenarArrglo(objetivo);

    desplegarMatriz(objetivo);

    printf("Tiro siguiente\n");
    tiro(objetivo);
    desplegarMatriz(objetivo);

    printf("Tiro siguiente\n");
    tiro(objetivo);
    desplegarMatriz(objetivo);
    printf("Tiro siguiente\n");
    tiro(objetivo);
    desplegarMatriz(objetivo);
}

void llenarArrglo(char matriz[][LEN_ARRAY])
{
    for (int f = 0; f < LEN_ARRAY; f++)
    {
        for (int c = 0; c < LEN_ARRAY; c++)
        {
	            matriz[f][c] = 'o';
        }
    }
}

int tiro(char matriz[][LEN_ARRAY])
{
	int x = random(), y = random(), puntos = 0;

    	matriz[x][y] = 'x';

	if ( y == 0 || y == LEN_ARRAY - 1 || x == 0 || x == LEN_ARRAY - 1){puntos +=30;}
	else if (y == 1 || y == LEN_ARRAY - 2 || x == 1 || x == LEN_ARRAY - 2){puntos +=60;}
	else if (y == 2 && x == 2){puntos += 100;}
	printf("Puntaje: %d\n", puntos);
	retun puntos;
}

void desplegarMatriz(char matriz[][LEN_ARRAY])
{
	int puntos = 0; 
    for (int f = 0; f < LEN_ARRAY; f++)
    {
        for (int c = 0; c < LEN_ARRAY; c++)
        {
            if (matriz[f][c] == 'o')
            {
		if ( c == 0 || c == LEN_ARRAY - 1 || f == 0 || f == LEN_ARRAY - 1)
		{
			printf("\033[34m");
                	printf("%c  ", matriz[f][c]);
		
			// Restablecer color al final
   			printf("\033[0m");
		}
		else if (c == 1 || c == LEN_ARRAY - 2 || f == 1 || f == LEN_ARRAY - 2)
		{
			// colorear de amarillo.
			printf("\033[33m");
                	printf("%c  ", matriz[f][c]);
			// Restablecer color al final
   			printf("\033[0m");
		}
		else if (c == 2 && f == 2){
			// colorear de rojo .
			printf("\033[31m");
                	printf("%c  ", matriz[f][c]);
			// Restablecer color al final
   			printf("\033[0m");
		}
		else{printf("%c  ", matriz[f][c]);}
            }
            else if (matriz[f][c] == 'x')
            {
                printf("\033[35m");
                printf("%c  ", matriz[f][c]);
                printf("\033[0m");
            }
        }
        printf("\n");
    }


}
