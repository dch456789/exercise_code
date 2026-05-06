#define _CRT_SECURE_NO_WARNINGS
#if 0

#include <memory>
#include   <iostream>
using namespace   std;


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
	friend ostream& operator<<(ostream& os, const person p);
};

//
ostream& operator<<(ostream& os, const person p)
{
	return os << p.name << " ->" << p.age << endl;
}


//技术点1:
void test001()
{
	person* p1 = new person;
	delete p1;
	cout << "++++++" << endl;
	unique_ptr<person> p2(new person());

	p2->print();
	(*p2).print();

	person* peon = p2.get();
	//p2.release();
	//p2.reset();
	peon->print();
	(*peon).print();
}


class factoryData
{
private:
	unique_ptr <person> p;
public:
	factoryData(person* p) :p(p)
	{
		cout << "构造了数据工厂" << endl;
	}
	~factoryData()
	{
		if (p)
		{
			cout << "析构数据工厂" << endl;
		}
	}
	person* operator->()
	{
		if (p.get())
		{
			return p.get();
		}
		return nullptr;
	}
};



//技术点2:
void test002()
{
	factoryData f1(new person());

	f1->print();
}

//技术点3:
void test003()
{

}

int main(int argc, char const* argv[])
{
	puts("++++++++++++++++ 1 ++++++++++++++++");
	test001();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test002();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test003();
	return 0;
}

#endif