#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class __complex
{
private:
	int a;
	int b;
public:
	__complex(const int& a = 0, const int& b = 0);
	__complex(const __complex& c);
	~__complex();
	void Print();
};