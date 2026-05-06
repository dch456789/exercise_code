#define _CRT_SECURE_NO_WARNINGS
#include   <iostream>

using namespace   std;
#include "_complex.h"
//技术点1:
void test001()
{
	__complex c1;
	__complex c2(1);
	__complex c3(1, 2);
	__complex c4(c1);
	c1.Print();
	c2.Print();
	c3.Print();
	c4.Print();
}


//技术点2:
void test002()
{

}

//技术点3:
void test003()
{

}

int main(int argc, char const *argv[])
{
	puts("++++++++++++++++ 1 ++++++++++++++++");
	test001();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test002();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test003();
	return 0;
}