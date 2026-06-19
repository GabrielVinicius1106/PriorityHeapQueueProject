#ifndef STRUCT_H
#define STRUCT_H

#define MAX_SIZE 20000
#define MAX_STR    100

// Estrutura do Item
typedef struct {
    char      name[MAX_STR];
    long long registration;
    int       ranking;
    char      course[MAX_STR];
} Item;

// Estrutura da Heap
typedef struct heap {
    Item      *vet;
    int       size;
    long long totalIterations;
    long long numInsertions;
} Heap;

#endif