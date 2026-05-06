#include <iostream>
#include "control.h"

using namespace std;

#if _TEST2
enum num {
	one = 1,
	two = 2,
	four = 4,
	eight = 8
};

void try1(void)
{
	int a = 10;
	int* p = &a;
	cout << "a=" << a << "\t|\t*p=" << *p << endl;

	num k;
	k = num(6);
	cout << k << endl;

}

int main(void)
{

	return 0;
}


#endif