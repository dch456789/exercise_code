#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#include "zho_util.h"
#include "zho_sort.h"

#if 0
#define USING_SHOW_ARRAY_CONTEXT
#endif

int main(int argc, char **argv) {
	int *arr;
	int min_value;
	int max_value;
	int count;
	long first_time;
	long last_time;
	
	if (argc < 4) {
		return 1;
	}
	
	min_value = atoi(argv[1]);
	max_value = atoi(argv[2]);
	count = atoi(argv[3]);
	
	arr = create_array(min_value, max_value, count);
#if defined (USING_SHOW_ARRAY_CONTEXT)
	printf("ÅÅÐòÇ°:\n");
	show_array(arr, count);
#endif
	
	first_time = clock();
	//base_insert_sort(arr, count);
	//base_select_sort(arr, count);
	//base_swap_sort(arr, count);
	//Shell_sort(arr, count);
	heap_sort(arr, count);
	last_time = clock();
#if defined (USING_SHOW_ARRAY_CONTEXT)
	printf("ÅÅÐòºó:\n");
	show_array(arr, count);
#endif
	last_time -= first_time;
	printf("ºÄÊ±£º%ld.%03ldÃë\n", last_time / 1000, last_time % 1000);
	
	free(arr);
	
	return 0;
}
