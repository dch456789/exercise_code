#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#include "zho_util.h"

void swap_int(int *one, int *other) {
	int tmp;
	
	tmp = *one;
	*one = *other;
	*other = tmp;
}

int *create_array(int min_value, int max_value, int count) {
	int num;
	int index;
	int *address = NULL;
	
	address = (int *) malloc(sizeof(int) * count);
	
	srand(time(NULL));
	for (index = 0; index < count; index++) {
		num = rand() % (max_value - min_value + 1) + min_value;
		address[index] = num;
	}
	
	return address;
}

void show_array(int *array, int count) {
	int index;
	
	for (index = 0; index < count; index++) {
		printf("%d ", array[index]);
	}
	printf("\n");
}
