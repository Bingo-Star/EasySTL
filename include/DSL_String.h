#ifndef STRING_H
#define STRING_H

#include "Root.h"

namespace EasyDSL
{

class String : public RootClass
{
protected:
	char* mStr;
	int mLength;

	void init(const char* str);
public:
	String();
	String(char c);
	String(const char* str);
	String(const String& obj);
	String& operator = (const String& obj);
	String& operator = (const char* str);
	String& operator = (char c);
	~String();

	int length() const;
	char* str() const;

	bool operator == (const String& obj) const;	
	bool operator == (const char* str) const;
	bool operator != (const String& obj) const;	
	bool operator != (const char* str) const;

	String operator + (const String& obj) const;	
	String operator + (const char* str) const;
	String operator + (const char c) const;
	
	void operator += (const String& obj);	
	void operator += (const char* str);
	void operator += (const char c);

	char& operator [] (int index);	
	char operator [] (int index) const;

	String& insert(int index, const char c);
	String& insert(int index, const char* str);
	String& insert(int index, const String& obj);
};


}   // end namespace EasyDSL

#endif


