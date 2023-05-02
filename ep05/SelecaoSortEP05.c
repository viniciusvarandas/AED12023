#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM_ARRAY 5000
//#define TAM_ARRAY 10000
//#define TAM_ARRAY 15000
//#define TAM_ARRAY 20000
#define MAX_RANDOM_VALUE (TAM_ARRAY*2)

void Selecao (int n, int v[]) {
    int i, j, min, x;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) 
            if (v[j] < v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}

void imprimeArray(int array[], int size) {
    for (int i = 0; i<size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}


int main()
{
    clock_t inicio, fim;
    double tempo_gasto;
     int array[TAM_ARRAY];
    //int array[] = {0, 10, 3, 76, 34, 23, 32};
    int n = sizeof(array) / sizeof(array[0]);
    int i;
    int num;
    bool hash_table[MAX_RANDOM_VALUE] = {false};

    srand(time(NULL));
        
    for (i = 0; i < TAM_ARRAY; i++){
        do {
            num = rand() % MAX_RANDOM_VALUE;
        } while (hash_table[num]);

        hash_table[num] = true;
        array[i] = num;
    }
   
    ///*
    printf("array baguncada\n");
    imprimeArray(array, n);
    //*/
    
    inicio = clock();
    Selecao(n, array); //algo
    fim = clock();
    
    ///*
    printf("array crescente: \n");
    imprimeArray(array, n);
    //*/
    
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("tempo de execução para %d números: %.18f milissegundos.\n", TAM_ARRAY, tempo_gasto*1000);
    printf("MAX_RANDOM: %d\n", MAX_RANDOM_VALUE);

    return 0;

}