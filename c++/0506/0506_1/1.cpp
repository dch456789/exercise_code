#define _CRT_SECURE_NO_WARNINGS
#if 0
#include   <iostream>
using namespace   std;


void print(int a)
{
	cout << "a=" << a << endl;
}

class person;

struct printData
{
	void print(const int& a);
	void print(const double& a);
	void print(const person& p);
	void operator()(const int& a);
	void operator()(const double& a);
	void operator()(const person& a);
};

class person
{
private:
	string name;
	int age;
public:
	person()
	{
		name = string(3, rand() % 26 + 65) + string(8, 97);
		age = rand() % 96;
		cout << "\t\t\t+++构造person（）" << endl;
	}
	void print()
	{
		cout << "Name:" << name << "\tAge:" << age << endl;
	}
	~person()
	{
		cout << "\t\t\t+++析构person（）" << endl;
	}
	friend void printData::print(const person& p);
	friend ostream& operator<<(ostream& os, const person p);
};

//
ostream& operator<<(ostream& os, const person p)
{
	return os << p.name << " ->" <<p.age << endl;
}

//
void printData::print(const int& a)
{
	cout << "int=>" << a << endl;
}
void printData::print(const double& a)
{
	cout << "double=>" << a << endl;
}
void printData::print(const person& p)
{
	cout << "Name:" << p.name << ",Age:" << p.age << endl;
}
//
void printData::operator()(const int& a)
{
	cout << "Int\t=>\t" << a << endl;
}
void printData::operator()(const double& a)
{
	cout << "Double\t=>\t" << a << endl;
}
void printData::operator()(const person& a)
{
	cout << "Person\t=>\t" << a << endl;
}

//技术点1:
void test001()
{
	printData pd;
	pd(9088);
	pd(52.8);
	pd(person());
}


//技术点2:
void test002()
{

}

//技术点3:
void test003()
{

}

int main(int argc, char const* argv[])
{
	//void (*p)(int);
	//p = print;
	//p(128);
	puts("++++++++++++++++ 1 ++++++++++++++++");
	test001();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test002();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test003();
	return 0;
}

#endif