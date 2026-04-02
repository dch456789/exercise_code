#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "dch_util.h"
#include "dch_short.h"

int main(int argc,char **argv)
//int main(void)
{
    SetConsoleOutputCP(65001);
    int *arr;
    int min_value;
    int max_value;
    int count;
    long first_time;
    long last_time;

    if(argc <4){
        return 1;
    }
    min_value = atoi(argv[1]);
    max_value = atoi(argv[2]);
    count = atoi(argv[3]);
    arr = create_array(min_value,max_value,count);

    show_array(arr,count);
    first_time = time(NULL);

    base_insert(arr,count);

    last_time = time(NULL);
    show_array(arr,count);

    printf("\n耗时：%ld 秒",last_time-first_time);

    free(arr);

    return 0;
}