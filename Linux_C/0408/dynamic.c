#include "dynamic.h"
#include <stdlib.h>

dynamicArray* initDynamicArray() {
	dynamicArray* arr = (dynamicArray*)malloc(sizeof(dynamicArray));
	if (arr) {
		arr->data = (void**)malloc(sizeof(void*) * DEFAULT_CAPACITY);
		if (arr->data) {
			memset(arr->data, '\0', sizeof(void*) * DEFAULT_CAPACITY);
			arr->capacity = DEFAULT_INCREMENT;
			arr->size = 0;
		}
	}
	return arr;
}
void printDynamicArray(dynamicArray* array,Print print){
	if (NULL == array || NULL == print) {
		return;
	}
	if (array->data) {
		for (int i = 0; i < array->size; i++) {
			printf("[%d]:", i);
			print(array->data[i]);
		}
	}
}

void freeDynamicArray(dynamicArray** array) {
	if (NULL == array) {
		return;
	}
	if (*array) {
		if ((*array)->data) {
			free((*array)->data);
		}
		free(*array);
		*array = NULL;
	}
}
void pushBackDynamicArray(dynamicArray* array, void* data) {
	if (NULL == array || NULL == data) {
		return;
	}
	if (array->size == array->capacity) {
		void** newData = malloc((sizeof(void*)) * array->capacity * DEFAULT_INCREMENT);
		if (newData) {
			memcpy(newData, array->data, sizeof(void*) * array->capacity);
			free(array->data);
			array->data = newData;
#ifdef DEBUG
			printf("\t\t\t更新容量，从 %d 到 %d\n", array->capacity, array->capacity * DEFAULT_INCREMENT);
#endif
			array->capacity *= DEFAULT_INCREMENT;
		}
	}

	array->data[array->size] = data;
	array->size++;
}

void sortDynamicArray(dynamicArray* ary, int(*compare)(void* first, void* second)) {
	if (NULL == ary || NULL == ary->data) {
		return;
	}
	for (int i = 0; i < ary->size - 1; i++) {
		for (int j = 0; j < ary->size - i - 1; j++) {
			if (compare(ary->data[j], ary->data[j + 1]) > 0) {
				void* tmp = ary->data[j];
				ary->data[j] = ary->data[j + 1];
				ary->data[j + 1] = tmp;
			}
		}
	}
}