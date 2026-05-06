#include "0429.2_1.h"
using namespace std;

void point::init(void)
{
	this->x = 0;
	this->y = 0;
}
void point::init(int x)
{
	this->x = x;
	this->y = x;
}
void point::init(int x, int y)
{
	this->x = x;
	this->y = y;
}
void point::init(const point& p)
{
	this->x = p.x;
	this->y = p.y;
}
void point::toprint(void)
{
	std::cout << "Point(" << x << "," << y << ")";
}
int& point::getX(void)
{
	return this->x;
}
int& point::getY(void)
{
	return this->y;
}

void circle::init(int x = 0, int y = 0, int r = 0)
{
	this->p.init(x, y);
	this->r = r;
}
void circle::toprint(void)
{
	std::cout << "Circle:([x=" << this->p.getX() << "][y=" << this->p.getY() << "][r=" << this->r << "])";

}
int& circle::getX(void)
{
	return this->p.getX();
}
int& circle::getY(void)
{
	return this->p.getY();
}
int& circle::getR(void)
{
	return this->r;
}


bool Point_In_Circle(point& p, circle& c)
{
	int dd = (p.getX() - c.getX()) * (p.getX() - c.getX()) + ((p.getY()) - (c.getY())) * ((p.getY()) - (c.getY())) - c.getR() * c.getR();
	if (dd > 0) {
		p.toprint();
		std::cout << " 在 ";
		c.toprint();
		std::cout << " 内" << endl;
		return true;
	}
	else {
		p.toprint();
		std::cout << " 在 ";
		c.toprint();
		std::cout << " 外" << endl;
		return false;
	}
}
bool Point_In_Circle(circle& c, point& p)
{
	cout << "开始判断";
	int dd = (p.getX() - c.getX()) * (p.getX() - c.getX()) + ((p.getY()) - (c.getY())) * ((p.getY()) - (c.getY())) - c.getR() * c.getR();
	if (dd > 0) {
		p.toprint();
		std::cout << " 在 ";
		c.toprint();
		std::cout << " 内";
		return true;
	}
	else{
		p.toprint();
		std::cout << " 在 ";
		c.toprint();
		cout << " 外" << endl;
		return false;
	}
}