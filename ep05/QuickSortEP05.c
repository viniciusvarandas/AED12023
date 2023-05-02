#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM_ARRAY 5000
#define MAX_RANDOM_VALUE (TAM_ARRAY*2)

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k<r; k++)
        if (v[k] <=c){
            t= v[j], v[j] =v[k], v[k] =t;
            j++;
        }
        v[r] = v[j], v[j] = c;
        return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p <r ) {
        j = Separa (p, r, v);
        Quicksort(p, j-1, v);
        Quicksort(j+1, r, v);
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
   
    /*
    printf("array baguncada\n");
    imprimeArray(array, n);
    */
    
    inicio = clock();
    Quicksort(0, n-1, array); //algo
    fim = clock();
    
    /*
    printf("array crescente: \n");
    imprimeArray(array, n);
    */
    
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("tempo de execução para %d números: %.18f milissegundos.\n", TAM_ARRAY, tempo_gasto*1000);
    printf("MAX_RANDOM: %d\n", MAX_RANDOM_VALUE);

    return 0;

}