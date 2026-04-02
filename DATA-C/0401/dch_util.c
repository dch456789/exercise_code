#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#include "dch_util.h"

int *create_array(int min_value,int max_value,int count)
{
    int num;
    int index;
    int *addreee = NULL;

    addreee = (int*)malloc(sizeof(int)*count);

    srand(time(NULL));
    for(index = 0;index < count;index++){
        num = rand()%(max_value - min_value +1) + min_value;
        addreee[index] = num;
    }
    //puts("");
    return addreee;
}

void show_array(int *array,int count)
{
    int index;
    for(index = 0;index < count;index++){
        printf("%d ",array[index]);
    }
    printf("\n");
    return;
}
