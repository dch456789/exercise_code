#include <iostream>
#include <string>

using namespace std;
static string normal_name = "None";

struct Man
{
private:
	int age;
	string name;
public:
	void init(int age = 0, string name = normal_name)
	{
		this->age = age;
		this->name = name;
	}
	void pri(void)
	{
		cout << this->age<<" | ";
		cout << this->name << endl;
	}
};

void test1(void)
{
	int a = 5;
	int&& b = 5;
	cout << "a=" << a;
	cout << "|b=" << b << endl;
	b = 100;
	cout << "a=" << a;
	cout << "|b=" << b << endl;
	cout << 5 << endl;

}

int main(void)
{
	Man people[2];
	(people[0]).init(3);
	(people[1]).init(7,"superman");
	for (int i = 0; i < 2; i++)
	{
		people[i].pri();
	}
	return 0;
}