#ifndef DYNAMIC_ARRAY_D260408_DCH
#define DYNAMIC_ARRAY_D260408_DCH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG

#define DEFAULT_CAPACITY 10
#define DEFAULT_INCREMENT 2

typedef struct DYNAMIC_ARRAY
{
    void** data;
    int capacity;
    int size;
}dynamicArray;

dynamicArray* initDynamicArray();

typedef void(*Print)(void*);
void printDynamicArray(dynamicArray*,Print);

void freeDynamicArray(dynamicArray**);

void pushBackDynamicArray(dynamicArray*,void*);

void sortDynamicArray(dynamicArray*, int(*compare)(void*, void*));
#endif