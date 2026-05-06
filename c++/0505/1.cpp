#if 0
#include <iostream>
using namespace std;

class person
{
private:
	string name;
	double age;
	string number;
public:
	static int count;

	static int height;
	static int length;
	static int width;
	static int weight;

	person()
	{
		name = string(4, rand() % 26 + 65) + string(8, rand() % 26 + 97);
		age = 0;
		cout << "\t\t\t无参构造:" << name << endl;
		count++;
	}
	person(string name, int age = 0)
	{
		this->name = name;
		this->age = age;
		cout << "\t\t\t有参(string name,int age = 0)构造:" << name << endl;
		count++;
	}
	person(const person& a)
	{
		this->name = a.name;
		this->age = a.age;
		cout << "\t\t\t拷贝构造：" << name << endl;
		count++;
	}
	~person()
	{
		cout << "\t\t\t析构函数启动:" << name << endl;
	}
	person operator= (const person& a)
	{
		this->name = a.name;
		this->age = a.age;
	}
	void print()
	{
		cout << "Name：" << (this->name) << "|Age:" << this->age << endl;
	}
	static void ddCount()
	{
		cout << "调用了:" << __FUNCTION__ << endl;
		height = 100;
		length = 90;
		width = 70;
		weight = 245;
	}

	static void printPersonGlobal()
	{
		cout << "height:" << height << "|length：" << length << "|width:" << width << "|weigth:" << weight << endl;
	}
};

int person::count = 0;

int person::height = 0;
int person::length = 0;
int person::width = 0;
int person::weight = 0;

int main(void)
{
	person  p1;
	person  p2("张无忌");
	person  p3("张三丰", 120);

	p1.print();
	p2.print();
	p3.print();

	person* q = new person("刘德华", 66);
	q->print();

	person  w[] = { person("aaaa",11),person("bbbb",21) ,person("cccc",21) };


	cout << "size(person):" << sizeof(person) << endl;
	cout << "size(string):" << sizeof(string) << endl;

	cout << "count=>" << p1.count << endl;
	cout << "count=>" << person::count << endl;

	p1.ddCount();
	person::ddCount();

	p1.ddCount();
	p1.printPersonGlobal();
	person::printPersonGlobal();

	return 0;
}
#endif