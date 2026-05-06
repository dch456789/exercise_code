#pragma once
#ifndef STRING_0506_V001
#define STRING_0506_V001
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#define PUT_CALL_MESSAGE printf("\t\t\t调用：%s在%d行\n",__FUNCTION__,__LINE__)

#define DEBUG 1

class String
{
private:
	char* text;
	int size;
public:
	String();
	String(const String&);
	String(const char*);
	String(size_t size, const char&);
	String(const char*, size_t size);
	~String();
	void print();
	String operator=(const String& s);
	friend ostream& operator<<(ostream& os, const String& s);
};


#endif