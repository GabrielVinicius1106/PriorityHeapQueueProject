#ifndef ARQ_H
#define ARQ_H

#include "struct.h"

// Métodos

void printItem(Item *item);

Item readCSVLine(char line[]);

int loadRegistrations(Heap *p, char csv_path[], int numRecords, int *iterations);

void read_string(const char *prompt, char *buf, int max);

void continuar();

#endif