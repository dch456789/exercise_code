#include <stdio.h>

#include "dch_short.h"

void base_insert(int *array,int count){
    int s_index = 0;
    int index;
    int tmp;
    int i;
    int t;

    for(index = 1;index < count;index++)
    {
        tmp = array[index];
        for(i = 0;i <= s_index;i++)
        {
            if(array[i]>tmp)
            {
                break;
            }

        }

        for(t = s_index + 1;t >= i;t--){
            array[t] = array[t-1];
        }
        array[i] = tmp;
        ++s_index;
    }
}
