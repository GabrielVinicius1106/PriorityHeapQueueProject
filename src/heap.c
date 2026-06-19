#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "heap.h"
#include "arq.h"

Heap * createHeap(){
    
    Item  *vet  = (Item *)malloc(sizeof(Item) * MAX_SIZE);

    if(!vet) return NULL;

    Heap *heap = (Heap *)malloc(sizeof(Heap)); 

    if(!heap) return NULL;

    heap->totalIterations = 0;
    heap->numInsertions   = 0;
    heap->size            = 0;

    heap->vet             = vet;

    return heap;
}

Heap * destroyHeap(Heap *p){

    if(p == NULL) return NULL;

    if(p->vet == NULL){
        free(p);
        return NULL;
    }

    free(p->vet);
    free(p);

    return NULL;
}

int insertHeap(Heap *p, Item item){

    if(p == NULL || p->vet == NULL) return -1;

    if(isFull(p)) return -1;
    
    int i = size(p);
    
    p->vet[i] = item;
    
    (p->size)++;
    
    int iterations = siftUp(p, i);

    p->totalIterations += iterations;

    (p->numInsertions)++; 

    return iterations;

}

Item * removeHeap(Heap *p){

    if(p == NULL || p->vet == NULL) return NULL;

    if(isEmpty(p)) return NULL;

    Item *max = &p->vet[0];
    
    p->vet[0] = p->vet[size(p) - 1];

    (p->size)--;

    if(size(p) > 0) siftDown(p, 0);

    return max;
}

Item * getLargest(Heap *p){

    if(p == NULL || p->vet == NULL) return NULL;

    if(isEmpty(p)) return NULL;

    Item *max = &p->vet[0];

    return max;
}

Heap * restartHeap(Heap *p){

    if(p == NULL) return NULL;

    free(p->vet);

    int size = p->size;

    p->vet = (Item *)malloc(sizeof(Item) * MAX_SIZE);

    p->size            = 0;
    p->numInsertions   = 0;
    p->totalIterations = 0;

    return p;
}

void traverseHeap(Heap *p){

    if(p == NULL || p->vet == NULL) return;

    int size = p->size;

    for(int i = 0; i < size; i++){

        printItem(&p->vet[i]);

    }
    
    printf("\n");

    return;
}

int size(Heap *p){
    return p->size;
}

int isEmpty(Heap *p){
    return size(p) == 0;
}

int isFull(Heap *p){
    return size(p) == MAX_SIZE;
}


int left(Heap *p, int N){

    if(p == NULL || p->vet == NULL) return -1;

    int i = N * 2 + 1;

    return i;
}

int right(Heap *p, int N){

    if(p == NULL || p->vet == NULL) return -1;

    int i = N * 2 + 2;

    return i;
}

int parent(Heap *p, int N){
   
    if(p == NULL || p->vet == NULL) return -1;

    int i = (N - 1) / 2;

    return i; 
}

void swap(Item *a, Item *b){

    Item temp = *a;
    *a = *b;
    *b = temp;
}

int siftUp(Heap *p, int index){

    int iterations = 0;
        
    while(index > 0){
    
        iterations++;

        int pt = parent(p, index);

        if(p->vet[pt].registration < p->vet[index].registration){
            swap(&p->vet[pt], &p->vet[index]);
            index = pt;
        } else {
            break;
        }
    }

    return iterations;
}  

int siftDown(Heap *p, int index){

    int iterations = 0;
    int i          = 0;
        
    while(1){
        
        int largest = i;

        iterations++;
        
        int l = left(p, i);
        int r = right(p, i);

        if(l < size(p) && p->vet[l].registration > p->vet[largest].registration) largest = l;     

        if(r < size(p) && p->vet[r].registration > p->vet[largest].registration) largest = r;

        if(largest == i) break;

        swap(&p->vet[i], &p->vet[largest]);

        i = largest;
    }

    return iterations;
}

// void heapSort(Heap *p){

//     if(p == NULL || p->vet == NULL) return;

//     int sizeVet = p->size;

    

//     return;
// }


