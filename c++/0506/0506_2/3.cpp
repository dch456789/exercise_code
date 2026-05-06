#define _CRT_SECURE_NO_WARNINGS
#include   <iostream>
#include "String.h"
using namespace   std;
ostream& operator<<(ostream& os, const String& s)
{
	if (0 <= s.size)
	{
		return os << s.text;
	}
	return os;
}

 
//技术点1:
void test001()
{
	using str = std::string;
	str s1;
	str s2(s1);
	str s3("你好");
	const char* text = "xiix";
	str s4(text);
	s1 = text;
	str s5(10, 'A');
	str s6(text, 4);

	str s7 = s5 + s6;
	s7.append(s6);

	s5 += s6;

	if (s1 < s2)
	{

	}
	else {
		if (s1 > s2) {

		}
	}
	if (s1 != s2) {

	}
	if (s1 == s2) {

	}
	if (s1.compare(s2)) {

	}
	char t[128] = "abcdefg12315";
	s1.copy(t, 3, 4);
}


//技术点2:
void test002()
{
	String s1;
	String s2(109, 'a');
	char name[] = "dadandmom12315";
	String s3(name, 10);
	String s4(name);
	String s5("你好");
	String s6 = s4;
	s1.print();
	s2.print();  
	s3.print();
	s4.print();
	s5.print();
	s6.print();
	s1 = s6;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
}

//技术点3:
void test003()
{
	String s1(3, 'a');
	String s2(6, 'A');
	String s3 = s1 + s2;
	cout << "s3:" << s3 << endl;
	s3.print();
	s1 += s2;
	cout << "s1+=s2:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	s1.print();
	s2.print();


	s1 = "abcd";
	s2 = "1234";
	s1.append(s2);
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	if (s1 > s2)
		cout << "s1>s2!" << endl;
	else if (s1 < s2)
		cout << "s1 < s2!" << endl;
	else
		cout << "s1 == s2!" << endl;
}

int main(int argc, char const *argv[])
{
	puts("++++++++++++++++ 1 ++++++++++++++++");
	test001();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	test002();

	puts("++++++++++++++++ 3 ++++++++++++++++");
	test003();
	return 0;
}