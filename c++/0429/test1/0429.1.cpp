#include <iostream>
#include "head.h"
#if _0429_1



using namespace std;
#define NAME_SIZE 128
#define SCORE_SIZE 3
int safe = 0;
int* safity = &safe;
struct  person
{
	char name[NAME_SIZE];
	int score[SCORE_SIZE];
	double  avg;

	void init()
	{
		memset(name, '\0', NAME_SIZE);
		memset(score, '\0', sizeof(int) * SCORE_SIZE);
		memset(name, rand() % 26 + 'A', 3);
		memset(name + 3, rand() % 26 + 'a', 4);
		memset(name + 7, rand() % 26 + 'a', 4);
		for (int i = 0; i < SCORE_SIZE; i++)
		{
			score[i] = rand() % 50 + 50;
		}
		avg = 0.0;
	}
	double getAvg()
	{
		int sum = 0;
		for (int i = 0; i < SCORE_SIZE; i++)
		{
			sum += score[i];
		}
		return (double)sum / SCORE_SIZE;
	}
	void print()
	{
		cout << name << "\t";
		for (int i = 0; i < SCORE_SIZE; i++)
		{
			cout << score[i] << " ";
		}
		cout << avg << endl;
	}
};

//int& getMax(int* data, int size);
//double& getMax(double* data, int size);
//person& getMax(person* data, int size);
//要求函数测试完毕必须直接使用函数表达式赋值后，再次输出原数组的值

//作业2:
//定义获取数组最大值的引用，要求返回类型为引用，且所有参数也为引用

int& getMax(int* data, int size);
double& getMax(double* data, int size);
person& getMax(person* data, int size);
void p_int(int* a, int b);
int& g_max(int* const& argc = nullptr, const int& length = 0);
int& swap(int& x, int& y);

void test1(void)
{
	int arp[5] = { 12,66,834,463,45 };
	double beta[5] = { 777.7,888.8,999.9,222.2,555.5 };


	cout << "int:" << getMax(arp, 5) << endl;
	getMax(arp, 5) = 11;
	cout << getMax(arp, 5) << endl;
	p_int(arp, sizeof(arp) / sizeof(int));

	int a = 10;
	int b = 1000;
	cout << "swap:" << swap(a, b) << "\ta:" << a << "\tb:" << b << endl;
	swap(a, b) = 2;
	cout << "a:" << a << "\tb:" << b << endl;

	cout << "此时的int数组为:";
	p_int(arp, sizeof(arp) / sizeof(int));

}

int main(void)
{


	return 0;
}





int& getMax(int* data, int size)
{
	if (NULL == data){
		return *data;
	}
	int* max = data;
	for (int i = 1; i < size; i++) {
		if (*max < (*(data + i))) {
			max = (data + i);
		}
	}
	return *max;
}
double& getMax(double* data, int size)
{
	if (NULL == data) {
		return *data;
	}
	double max = *data;
	int con = 0;
	for (int i = 1; i < size; i++) {
		if (max < (*(data + i))) {
			max = (*(data + i));
			con = i;
		}
	}
	return data[con];
}
person& getMax(person* data, int size)
{
	// person a = *data;

	return *data;
}

int& swap(int& x, int& y)
{
	int i;
	i = x;
	x = y;
	y = i;
	return x;
}

void p_int(int* a, int b)
{
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";

	}
	cout << endl;
}

int& g_max(int* const& argc, const int& length)
{
	if (nullptr == argc || length <= 0) {
		return safe;
	}
	int max = *argc;
	int con = 0;
	for (int i = 0; i < length; i++) {
		if (max < *(argc + i)) {
			max = *(argc + i);
			con = i;
		}
	}
	return argc[con];
}

#endif // DEBUG