#include <stdio.h>
#include <stdlib.h>

#include "./src/struct.h"
#include "./src/arq.h"
#include "./src/heap.h"

#define NUM_BASES 18

static const int BASE_SIZES[NUM_BASES] = {
    500,
    1000,
    1500,
    2000,
    2500,
    3000,
    3500,
    4000,
    4500,
    5000,
    5500,
    6000,
    6500,
    7000,
    7500,
    8000,
    8500,
    9000
};

int main(){

    char *out_path = "dataset_result.csv";
    
    printf("\n                     ===================================");
    printf("\n                            Teste de Performance          ");
    printf("\n                     ===================================");

    printf("\n");

    Heap *p = createHeap();

    double *records = (double *)malloc(sizeof(double) * NUM_BASES);

    long double med = 0, sum = 0;

    FILE *out = fopen(out_path, "w");
   
    if(!out){
        printf("\n Falha ao Abrir o Arquivo '%s'\n", out_path);
        free(records);
        destroyHeap(p);
        return 1;
    }

    fprintf(out, "Tamanho da Base, Total de Iterações, Média de Iterações\n");
    
    for(int i = 0; i < NUM_BASES; i++){  

        int iterations = 0; 

        loadRegistrations(p, "dataset.csv", BASE_SIZES[i], &iterations);
        
        restartHeap(p);
        
        records[i] = (double)iterations / BASE_SIZES[i];  
        
        printf("\n Tamanho da Base: %-4d | Total de Iteracoes: %-6d | Media de Iteracoes: %.2f\n", BASE_SIZES[i], iterations, records[i]);
    
        fprintf(out, "%-4d, %-6d, %-2.2f\n", BASE_SIZES[i], iterations, records[i]);
    }

    for(int i = 0; i < NUM_BASES; i++){
        sum += records[i];
    }

    med = sum / NUM_BASES;

    printf("\n Media de Iteracoes: %.2Lf", med);

    free(records);
    destroyHeap(p);

    fclose(out);

    return 0;

}