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