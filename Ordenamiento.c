//universidad de Cundinamarca
//Jeferson Grueso - Lyle Romero
//ingenieria Electronica
//circuitos digitales 3


#include <stdlib.h>
#include <stdio.h>


void intercambio(int* a, int* b) {
    int cambio = *a;
    *a = *b;
    *b = cambio;
}

void quicksort(int* izq, int* der) {
    if (der < izq)
        return;
    int pivote = *izq;
    int* ult = der;
    int* pri = izq;
    while (izq < der) {
        while (*izq <= pivote && izq < der+1)
            izq++;
        while (*der > pivote && der > izq-1)
            der--;
        if (izq < der)
            intercambio(izq, der);
    }
    intercambio(pri, der);
    quicksort(pri, der-1);
    quicksort(der+1, ult);
}

int main(void) {
    int i;
    int tam;

    printf("Ingrese el tamaño del arreglo:\n");
    scanf("%d", &tam);
    int arreglo[tam];

    printf("Ingrese valores para el arreglo:\n");
    for (i = 0; i < tam; i++)
        scanf("%d", &arreglo[i]);
    printf("n");

    printf("Arreglo Original\n");
    for (i = 0; i < tam; i++)
        printf("%d ", arreglo[i]);
    printf("nn");

   quicksort(&arreglo[0], &arreglo[tam-1]);

    printf("Arreglo Ordenado\n");
    for (i = 0; i < tam; i++)
        printf("%d ", arreglo[i]);
    printf("\n\n");
}
