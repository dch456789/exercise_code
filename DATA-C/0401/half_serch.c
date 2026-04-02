#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND 0
int binary_search(const int *ar,const int count,const int val)
{
    int head = 0;
    int tail = count - 1;
    int midle;
    while(head < tail)
    {
        midle = (head + tail)/2;
        if(ar[midle] > val)
        {
            tail = midle + 1;
        }
        else if(ar[midle] < val)
        {
            head = midle - 1;
        }
        else
            return midle;
    }
    return NOT_FOUND;
}