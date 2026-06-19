#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "arq.h"
#include "heap.h"

#define MAX_RECORDS 10000
#define NUM_BASES      18

// MANIPULAÇÃO DE ARQUIVO

void printItem(Item *item){
   
    printf("\n");
    printf("  Nome     : %-20s\n", item->name);
    printf("  Matricula: %-10lld\n", item->registration);
    printf("  Ranking  : %-5d\n", item->ranking);
    printf("  Curso    : %s\n", item->course);

}   

Item readCSVLine(char line[]){
    
    Item item;
    memset(&item, 0, sizeof(item));

    char buffer[512];
    
    strncpy(buffer, line, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *p = buffer + strlen(buffer) - 1;
    while (p >= buffer && (*p == '\r' || *p == '\n')) * p-- = '\0';

    char *token = strtok(buffer, ",");
    if (!token) return item;
    strncpy(item.name, token, MAX_STR - 1);

    token = strtok(NULL, ",");
    if (!token) return item;
    item.registration = atoll(token);

    token = strtok(NULL, ",");
    if (!token) return item;
    item.ranking = atoi(token);

    token = strtok(NULL, ",");
    if (!token) return item;
    strncpy(item.course, token, MAX_STR - 1);

    return item;
}
 
int loadRegistrations(Heap *p, char csv_path[], int numRecords, int *iterations){

    srand((unsigned)time(NULL));

    FILE *f = fopen(csv_path, "r");
    
    if(!f){
        fprintf(stderr, "Erro ao Abrir '%s'\n", csv_path);
        return -1;
    }

    Item *records = (Item *)malloc(numRecords * sizeof(Item));
    
    if(!records){ 
        perror("malloc"); 
        fclose(f); 
        return -1; 
    }

    char line[512];

    if (!fgets(line, sizeof(line), f)){
        fprintf(stderr, "Arquivo Vazio.\n");
        free(records);
        fclose(f); 
        return -1;
    }

    
    int count = 0;
    
    
    while (count < numRecords && fgets(line, sizeof(line), f)) {
        
        Item item = readCSVLine(line);
        
        if (item.registration != 0){
            records[count] = item;
            count++;
        }
    }

    int *arr = (int *)malloc(sizeof(int) * count);

    if(!arr){
        perror("malloc");
        free(records);
        fclose(f);
        return -1;
    };
    
    for(int k = 0; k < count; k++) arr[k] = k;
    
    for(int i = count - 1; i > 0; i--){
        
        int j = rand() % (i + 1);
        
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int actualIterations = 0;

    for(int i = 0; i < numRecords; i++){

        actualIterations = insertHeap(p, records[arr[i]]);

        if(actualIterations < 0){
            break;
        }

        *iterations += actualIterations;
    }
    
    free(arr);
    free(records);
    fclose(f);

    return count;
}

// AUXILIARES

void read_string(const char *prompt, char *buf, int max) {
    printf("%s", prompt);
    fgets(buf, max, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

void continuar(){
    printf("  PRESSIONE ENTER PARA CONTINUAR...");
    while (getchar() != '\n');
}