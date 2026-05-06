#include "_complex.h"
__complex::__complex(const int& a, const int& b):a(a),b(b)
{
	cout << "\t\t\t默认构造（" << a <<","<< b <<")" << endl;
}
__complex::__complex(const __complex& c)
{
	cout << "\t\t\t拷贝构造(" << c.a << "," << c.b << ")" << endl;
}
__complex::~__complex()
{
	cout<<"\t\t\t析构了（" << a << "," << b << ")" << endl;
}
void __complex::Print()
{
	cout << "Complex(" << a << "," << b << ")" << endl;
}