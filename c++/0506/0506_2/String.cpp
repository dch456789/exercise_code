#include "String.h"


String::String()
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	text = new char[1];
	*text = '\0';
	size = 0;


}

String::String(const String& s)
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	text = new char[s.size + 1];
	memset(text, '\0', s.size + 1);
	memcpy(text, s.text, s.size);
	size = s.size;
}

String::String(const char* s)
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	if (nullptr == s) {
		text = new char[1];
		*text = '\0';
		size = 0;
		return;
	}
	int len = strlen(s);
	text = new char[len+1];
	memset(text, '\0', len+1);
	memcpy(text, s, len);
	size = len;
}

String::String(size_t size, const char& c):size(size)
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	text = new char[size + 1];
	memset(text, '\0', size + 1);
	memset(text, c, size);
}

String::String(const char* s, size_t size)
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	if (nullptr == s) {
		text = new char[1];
		*text = '\0';
		size = 0;
		return;
	}
	text = new char[size + 1];
	memset(text, '\0', size + 1);
	memcpy(text, s, size);
	this->size = size;
}

String::~String()
{

	if (this->text)
	{
#ifdef  DEBUG
		PUT_CALL_MESSAGE;
#endif //  DEBUG
		delete[] this->text;
	}
}

void String::print()
{
#ifdef  DEBUG
	PUT_CALL_MESSAGE;
#endif //  DEBUG
	cout << "[text:" << text << "]|[size:" << size <<"]"<< endl;
}

String String::operator=(const String& s)
{
	if (this->text)
	{
		delete[] this->text;
		this->size = 0;
	}
	this->text = new char[(s.size)+1];
	memset(this->text, '\0', (s.size)+1);
	memcpy(this->text, s.text, s.size);
	this->size = s.size;	
	return *this;
}

String String::operator+(const String& s)  const
{
	char* newChar = new char[this->size + s.size + 1];
	memcpy(newChar, this->text, this->size);
	memcpy(newChar+this->size,s.text,s.size);
	String temp(newChar, this->size + s.size);
	delete[] newChar;
	return temp;
}
#if ONE == 0
String String::operator+=(const String& s)
{
	char* newChar = new char[this->size + s.size + 1];
	memset(newChar, '\0', this->size + s.size + 1);
	memcpy(newChar, this->text, this->size);
	memcpy(newChar + this->size, s.text, s.size);
	delete[] this->text;
	this->text = newChar;
	this->size += s.size;
	return *this;
}
#endif
String  String::append(const String& s)
{
	*this += s;
	return *this;
}
#if ONE == 0
bool String::operator<(const String& s) const
{
	return (strcmp(this->text, s.text) < 0);
}
bool String::operator>(const String& s) const
{
	return (strcmp(this->text, s.text) > 0);
}
bool String::operator==(const String& s) const
{
	return (strcmp(this->text, s.text) == 0);
}
bool String::operator!=(const String& s) const
{
	return (strcmp(this->text, s.text) != 0);
}
#endif

//____________________________________________________

#if ONE == 1
String operator+=(String& a, const String& b)
{
	char* tmp = new char[a.size + b.size +1];
	memset(tmp, '\0', a.size + b.size + 1);
	memcpy(tmp, a.text, a.size);
	memcpy(tmp + a.size, b.text, b.size);
	delete a.text;
	a.text = tmp;
	a.size += b.size;
	return a;
}
bool operator<(const String& a, const String& b)
{
	return strcmp(a.text, b.text) < 0;
}
bool operator>(const String& a, const String& b)
{
	return strcmp(a.text, b.text) > 0;
}
bool operator==(const String& a, const String& b)
{
	return strcmp(a.text, b.text) == 0;
}
bool operator!=(const String& a, const String& b)
{
	return strcmp(a.text, b.text) != 0;
}
#endif // ONE == 1