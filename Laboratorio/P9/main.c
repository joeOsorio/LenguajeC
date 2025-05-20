/*------------------------------------------------------------------------------------------
-LABORATORIO: 9.
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Marzo/12/2025

Objetivo:
Comprender y aplicar el uso de apuntadores en variables y arreglos a traves del uso de funciones o procedimientos que utilizan parametros.

Descripcion:
Elaborar un programa a traves del cual puedas asignar elementos a un arreglo de tamaño definido, ingresar elementos de manera aleatoria.
Contar los elementos que correspondan a ser el multiplo de un numero solicitado
Realizar recorridos en el arreglo y cambiar los elementos por numeros primo, no importa el orden.
Desplegar el arreglo en el momento que se desea visualizar
------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10 /* Tamaño del arreglo */

/* Prototipo de funciones */
void llenarArregloAleatorio(int *arreglo, int tam);
void mostrarArreglo(int *arreglo, int tam);
int esPrimo(int numero);
void reemplazarConPrimos(int *arreglo, int tam);
int contarMultiplos(int *arreglo, int tam, int multiplo);

int main()
{
    srand(time(NULL)); /* Semilla*/
    /* Declaración del arreglo */
    int arreglo[TAM]={0};
    int opcion, multiplo;

    do
    {
        // Menú de opciones
        printf("\n--- Menú de Manipulación de Arreglos ---");
        printf("\n\t1)Llenar arreglo con números aleatorios");
        printf("\n\t2)Mostrar arreglo");
        printf("\n\t3)Contar múltiplos de un número");
        printf("\n\t4)Reemplazar elementos con números primos");
        printf("\n\t5)Salir");
        /* Capturar Opción */
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            llenarArregloAleatorio(arreglo, TAM);
            mostrarArreglo(arreglo, TAM);
            break;
        case 2:
            mostrarArreglo(arreglo, TAM);
            break;
        case 3:
            printf("Ingrese el número para buscar múltiplos: ");
            scanf("%d", &multiplo);
            printf("Cantidad de múltiplos de %d: %d\n",
                   multiplo,
                   contarMultiplos(arreglo, TAM, multiplo));
            break;
        case 4:
            printf("Arreglo anterior ");
            mostrarArreglo(arreglo, TAM);
            reemplazarConPrimos(arreglo, TAM);
	    printf("Arreglo nuevo ");
            mostrarArreglo(arreglo, TAM);
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no disponible =(.\n");
        }
        printf("\n\nPresione cualquier tecla para continua");
        fflush(stdin);
        getchar();
    } while (opcion != 5);

    return 0;
}

// Función para llenar arreglo con números aleatorios
void llenarArregloAleatorio(int *arreglo, int tam)
{
    printf("Llenando arreglo con números aleatorios:\n");
    for (int i = 0; i < tam; i++)
    {
        arreglo[i] = rand() % 100 + 1; // Números entre 1 y 100
    }
    printf("Arreglo llenado exitosamente.\n");
}

// Función para mostrar el arreglo
void mostrarArreglo(int *arreglo, int tam)
{
    printf("Contenido del arreglo:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

// Función para verificar si un número es primo
int esPrimo(int numero)
{
    if (numero <= 1)
        return 0;
    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
            return 0;
    }
    return 1;
}

// Función para reemplazar elementos con números primos
void reemplazarConPrimos(int *arreglo, int tam)
{
    printf("Reemplazando elementos con números primos:\n");

    for (int i = 0; i < tam; i++)
    {
        int primo = arreglo[i];
        while (!esPrimo(primo))
        {
            do
            {
                printf("\n El elemento %d, No es primo\nIngrese Otro numero:\t", arreglo[i]);
                scanf("%d", &primo);

		if (!esPrimo(primo)) {
                printf("El número %d no es primo. Intente de nuevo.\n", primo);}
            } while (!esPrimo(primo));
        }
        arreglo[i] = primo;
    }

    printf("Elementos reemplazados con primos.\n");
}



// Función para contar múltiplos de un número
int contarMultiplos(int *arreglo, int tam, int multiplo)
{
    int contador = 0;
    for (int i = 0; i < tam; i++)
    {
        if (arreglo[i] % multiplo == 0)
        {
            contador++;
        }
    }
    return contador;
}