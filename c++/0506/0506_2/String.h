#pragma once
#ifndef STRING_0506_V001
#define STRING_0506_V001
#define ONE 1
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


	///////////////////////////第二部分（下午） ///////////////////////////////
	String operator+(const String&)  const; 
#if ONE == 0
	String operator+=(const String&);
	bool operator<(const String&) const;

	bool operator>(const String&) const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
#endif
	String  append(const String&);



#if  ONE == 1
	friend String operator+=(String&,const String&); 
	friend bool operator<(const String&,const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
#endif //  ONE == 1

};

#if  ONE == 1
String operator+=(String&,const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
#endif //  ONE == 1

#endif