#ifndef HEAP_H
#define HEAP_H

#include "struct.h"

// INTERFACE

Heap * createHeap();

Heap * destroyHeap(Heap *p);

int    insertHeap(Heap *p, Item item);

Item * removeHeap(Heap *p);

Item * getLargest(Heap *p);

Heap * restartHeap(Heap *p);

void   traverseHeap(Heap *p);


// FUNDAMENTAIS 

int  siftUp(Heap *p, int index);

int  siftDown(Heap *p, int index);

// AUXILIARES

int    isEmpty(Heap *p);

int    isFull(Heap *p);

int    size(Heap *p);

int    left(Heap *p, int N);

int    right(Heap *p, int N);

int    parent(Heap *p, int N);

void   swap(Item *a, Item *b);

// SORT

// [ ] Implementar

// void buildMaxHeap(Heap *p);

// void buildMinHeap(Heap *p);

// void heapSort(Heap *p);

#endif