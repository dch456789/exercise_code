#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "dynamic.h"

void printInt(void* data) //Int输出函数
{
	if (data) {
		int* p = (int*)data;
		printf("%d\n", *p);
	}
}

void test001()
{
	dynamicArray* array = initDynamicArray();
	for (int i = 0; i < 109; i++)
	{
		int* p = (int*)malloc(sizeof(int));
		if (p) {
			*p = (i + 1) * 3;
			pushBackDynamicArray(array, (void*)p);
		}
	}
	printDynamicArray(array, printInt);
	for (int i = 1000; i < 2000; i++) {
		int* p = (int*)malloc(sizeof(int));
		if (p) {
			*p = i + 1;
			pushBackDynamicArray(array, (void*)p);
		}
	}
	printDynamicArray(array, printInt);
	freeDynamicArray(&array);
	printf("array:%p\n", array);
}


struct book
{
	char name[128];
	double price;
	double dis;
};
typedef struct book book;

void printBook(void* data)
{
	if (data) {
		book* p = (book*)data;
		printf("%s\t%.lf\t%.lf\n", p->name, p->price, p->dis);
	}
}

void test002()
{
	dynamicArray* array = initDynamicArray();
	for (int i = 0; i < 33; i++) {
		book* p = (book*)malloc(sizeof(book));
		if (p) {
			memset(p, '\0', sizeof(book));
			memset(p->name, rand() % 26 + 'a', 4);
			memset(p->name + 4, rand() % 26 + 'a', 4);
			memset(p->name + 8, rand() % 26 + 'a', 4);
			p->price = (rand() % 9000 + 5000) / 100;
			p->dis = (rand() % 10) / (double)10;

			pushBackDynamicArray(array, p);
		}
	}
	printDynamicArray(array, printBook);

	for (int i = 0; i < 33000; i++) {
		book* p = (book*)malloc(sizeof(book));
		if (p) {
			memset(p, '\0', sizeof(book));
			memset(p->name, rand() % 26 + 'a', 4);
			memset(p->name + 4, rand() % 26 + 'a', 4);
			memset(p->name + 8, rand() % 26 + 'a', 4);
			p->price = (rand() % 9000 + 5000) / 100;
			p->dis = (rand() % 10) / (double)10;

			pushBackDynamicArray(array, p);
		}
	}
	printDynamicArray(array, printBook);
	freeDynamicArray(&array);
	printf("array:%p\n", array);
}
int main(int argc,const char *argv[])
{
	//SetConsoleOutputCP(65001);
	test001();
	//test002();
	return 0;
}