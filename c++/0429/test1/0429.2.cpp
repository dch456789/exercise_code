#include <iostream>
#include "0429.2_1.h"
using namespace std;
//1.c++中struct和class 有什么区别?
//2.struct在C和C++中的应用区别?


void test1(void)
{

	point p;
	//Point(0,0)
	p.init();
	p.toprint();
	puts("");

	circle c;
	//Circle:( 0^2 +0^2 = 0^2 )
	c.init();
	c.toprint();
	puts("");

	//Point(3,3)
	p.init(3);
	p.toprint();
	puts("");
	//Point(3,2)
	p.init(3, 2);
	p.toprint();
	puts("");

	//Circle:( 1^2 +0^2 = 0^2 )
	c.init(1);
	c.toprint();
	puts("");
	//Circle:( 2^2 +20^2 = 0^2 )
	c.init(2, 20);
	c.toprint();
	puts("");
	//Circle:( 7^2 +8^2 = 5^2 )
	c.init(7, 8, 5);
	c.toprint();
	puts("");

	Point_In_Circle(p, c);

}

int main(void)
{
	test1();
	return 0;
}