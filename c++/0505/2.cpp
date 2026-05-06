#if 0
#include <iostream>
using namespace std;
class point;
class circle;

bool circletopoint(const circle& c, const point& p);

class point
{
private:
	int a;
	int b;
public:
	point(int x = rand() % 100, int y = rand() % 100) :a(x), b(y)
	{
		cout << "构造了point" << endl;
	}
	point(const point& p) :a(p.a), b(p.b)
	{
		cout << "拷贝构造了point" << endl;
	}
	void print()
	{
		cout << "point(" << a << "," << b << ")" << endl;
	}
	friend class circle;
	friend bool circletopoint(const circle& c, const point& p);
};


class circle
{
private:
	point p;
	int r;
public:
	circle(int a, int b, int c) :p(a, b), r(c)
	{
		cout << "圆构造3成功" << endl;
	}
	circle(const point& p, int c) :p(p), r(c)
	{
		cout << "圆构造2成功" << endl;
	}
	void print()
	{
		cout << "circle:(" << p.a << "," << p.b << ";" << r << ")" << endl;
	}
	friend bool circletopoint(const circle& c, const point& p);
};

bool circletopoint(const circle& c, const point& p)
{
	int length = (p.a - c.p.a) * (p.a - c.p.a) + (p.b - c.p.b) * (p.b - c.p.b);
	int r2 = c.r * c.r;
	if (r2 >= length)
	{
		cout << "点在圆内" << endl;
		return true;
	}
		cout << "点在圆外" << endl;
		return false;
}

int main(void)
{
	point p(1, 4);
	circle c(3, 5, 7);
	p.print();
	c.print();
	circletopoint(c, p);

	return 0;
}

#endif