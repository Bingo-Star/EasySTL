#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Exception.h"
#include "DSL_String.h"

using namespace EasyDSL;
using namespace std;

void String::init(const char* str)
{
	mStr = strdup(str);
	if (mStr != NULL)
	{
		mLength = strlen(mStr);
	}
	else
	{
		THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create String obj !!");
	}
}

String::String()
{
	init("");
}

String::String(char c)
{
	char tmp[] = {c, '\0'};
	init(tmp);
}

String::String(const char* str)
{
	init(str != NULL ? str : "");
}

String::String(const String& obj)
{
	init(obj.mStr);
}

String& String::operator = (const String& obj)
{
	if (obj != *this)
	{
		free(mStr);
		init(obj.mStr);
	}
	return *this;
}

String& String::operator = (const char* str)
{
	if (mStr != str)
	{
		free(mStr);
		init(str != NULL ? str : "");
	}
	return *this;
}

String& String::operator = (char c)
{
	free(mStr);
	char tmp[] = {c, '\0'};
	init(tmp);
	return *this;
}

String::~String()
{
	free(mStr);
}

int String::length() const
{
	return mLength;
}

char* String::str() const
{
	return mStr;
}

bool String::operator == (const String& obj) const
{
	return strcmp(mStr, obj.mStr) == 0;
}

bool String::operator == (const char* str) const
{
	return strcmp(mStr, str != NULL ? str : "") == 0;
}

bool String::operator != (const String& obj) const
{
	return strcmp(mStr, obj.mStr) != 0;
}

bool String::operator != (const char* str) const
{
	return strcmp(mStr, str != NULL ? str : "") != 0;
}

String String::operator + (const String& obj) const
{
	return *this + obj.mStr;
}

String String::operator + (const char* str) const
{
	String ret;
	int len = mLength + strlen(str) + 1;
	char* p = reinterpret_cast<char*>(malloc(len));
	if (p != NULL)
	{
		free(ret.mStr);
		ret.mStr = p;
		strcpy(ret.mStr, mStr);
		strcat(ret.mStr, str);
		ret.mLength = len;
	}
	else
	{
		THROW_EXCEPTION(InvalidOperationException, "No memory now");
	}
	return ret;
}

String String::operator + (const char c) const
{
	char tmp[] = {c, '\0'};
	return *this + tmp;
}

void String::operator += (const String& obj)
{
	*this = *this + obj;
}

void String::operator += (const char* str)
{
	*this = *this + str;
}

void String::operator += (const char c)
{
	char tmp[] = {c, '\0'};
	*this = *this + tmp;
}

char& String::operator [] (int index)
{
	if (index < 0 || index >= mLength)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
	}
	
	return mStr[index];
}

char String::operator [] (int index) const
{
	if (index < 0 || index >= mLength)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
	}
	
	return mStr[index];
}

String& String::insert(int index, const char c)
{
	char tmp[] = {c, '\0'};
	return insert(index, tmp);
}

String& String::insert(int index, const char* str)
{
	if (index < 0 || index > mLength)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
	}
	else
	{
		int len = strlen(str);
		char* p = reinterpret_cast<char*>(malloc(len + mLength + 1));
		if (p != NULL)
		{
			strncpy(p, mStr, index);
			strncpy(p + index, str, len);
			strcpy(p + index + len, mStr + index);

			free(mStr);
			mStr = p;
			mLength += len;
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "No memory now");
		}
	}
	return *this;
}

String& String::insert(int index, const String& obj)
{
	return insert(index, obj.mStr);
}

