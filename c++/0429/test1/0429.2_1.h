#ifndef _TAG_0429_2_1
#define _TAG_0429_2_1

#include <iostream>

class point
{
private:
	int x;
	int y;
public:
	void init(void);
	void init(int x);
	void init(int x, int y);
	void init(const point& p);
	void toprint(void);
	int& getX(void);
	int& getY(void);
};
class circle
{
private:
	point p;
	int r;
public:
	void init(int x = 0, int y = 0, int r = 0);
	void toprint(void);
	int& getX(void);
	int& getY(void);
	int& getR(void);
};

bool Point_In_Circle(point& p, circle& c);
bool Point_In_Circle(circle& c, point& p);


#endif