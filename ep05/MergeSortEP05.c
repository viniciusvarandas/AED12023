#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM_ARRAY 20000
#define MAX_RANDOM_VALUE (TAM_ARRAY*2)

void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
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
   
   /*
    printf("array baguncada\n");
    imprimeArray(array, n);
   */
    
    inicio = clock();
    Mergesort(0, n, array); //algo
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
