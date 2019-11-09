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

char& String::operator [] (unsigned int index)
{
	if (index >= mLength)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
	}
	
	return mStr[index];
}

char String::operator [] (unsigned int index) const
{
	if (index >= mLength)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
	}
	
	return mStr[index];
}

String& String::insert(unsigned int index, const char c)
{
	char tmp[] = {c, '\0'};
	return insert(index, tmp);
}

String& String::insert(unsigned int index, const char* str)
{
	if (index > mLength)
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

String& String::insert(unsigned int index, const String& obj)
{
	return insert(index, obj.mStr);
}

int* String::init_PMT(const char* str) const
{
	int len = strlen(str);
	
	int* PMT = (int*)malloc(len + 1);
	if (PMT != NULL)
	{
		int ll = 0;
		PMT[0] = 0;
		for (int i = 1; i < len; i++)
		{
			while (ll > 0 && str[ll] != str[i])
			{
				ll = PMT[ll - 1];
			}
			
			if (str[ll] == str[i])
			{
				ll++;
			}
			PMT[i] = ll;
		}
	}
	
	return PMT;
}

int String::StrSearch(const char* SrcStr, const char* SubStr) const
{
	int SrcLne = strlen(SrcStr);
	int SubLen = strlen(SubStr);
	
	if (SrcLne >= SubLen)
	{
		int* PMT = init_PMT(SubStr);
		if (PMT != NULL)
		{
			int j = 0;
			int i = 0;
			for (; i < SrcLne && j < SubLen; )
			{
				if (SrcStr[i] == SubStr[j])
				{
					i++;
					j++;
				}
				else
				{
					while (j > 0 && SrcStr[i] != SubStr[j])
					{
						j = PMT[j];
					}
					if (j == 0)
					{
						i++;
					}
				}
			}
			if (j == SubLen)
			{
				return i - SubLen;
			}
			free(PMT);
		}
	}
	
	return -1;
}

int String::find(const char c) const
{
	char tmp[] = {c, '\0'};
	return StrSearch(mStr, tmp);
}

int String::find(const char* str) const
{
	return StrSearch(mStr, str != NULL ? str : "");
}

int String::find(const String& obj) const
{
	return StrSearch(mStr, obj.mStr);
}

bool String::remove(unsigned int index, unsigned int len)
{
	if (index > mLength || index + len > mLength)
	{
		return false;
	}

	strcpy(mStr + index, mStr + index + len);
	mLength -= len;

	return true;
}

bool String::remove(const char c)
{
	char tmp[] = {c, '\0'};
	return remove(tmp);
}

bool String::remove(const char* str)
{
	int index = find(str);
	if (index < 0)
	{
		return false;
	}
	
	return remove(index, strlen(str));
}

bool String::remove(const String& obj)
{
	return remove(obj.mStr);
}

bool String::replace(const char src_c, const char dst_c)
{
	char tmp_src[] = {src_c, '\0'};
	char tmp_dst[] = {dst_c, '\0'};
	return replace(tmp_src, tmp_dst);
}

bool String::replace(const char src_c, const char* dst_str)
{
	char tmp_src[] = {src_c, '\0'};
	return replace(tmp_src, dst_str);	
}

bool String::replace(const char src_c, const String& dst_obj)
{
	char tmp_src[] = {src_c, '\0'};
	return replace(tmp_src, dst_obj.mStr);	
}

bool String::replace(const char* src_str, const char dst_c)
{
	char tmp_dst[] = {dst_c, '\0'};
	return replace(src_str, tmp_dst);	
}

bool String::replace(const char* src_str, const char* dst_str)
{
	int index = find(src_str);
	if (index < 0)
	{
		return false;
	}

	if (remove(src_str) == true)
	{
		insert(index, dst_str);
		return true;
	}
	else
	{
		return false;
	}
}

bool String::replace(const char* src_str, const String& dst_obj)
{
	return replace(src_str, dst_obj.mStr);
}

bool String::replace(const String& src_obj, const char dst_c)
{
	char tmp_dst[] = {dst_c, '\0'};
	return replace(src_obj.mStr, tmp_dst);	
}

bool String::replace(const String& src_obj, const char* dst_str)
{
	return replace(src_obj.mStr, dst_str);	
}

bool String::replace(const String& src_obj, const String& dst_obj)
{
	return replace(src_obj.mStr, dst_obj.mStr);	
}

String String::sub(unsigned int index, unsigned int len) const
{
	String ret;

	if (index < mLength && len != 0)
	{
		char* buf = reinterpret_cast<char*>(malloc(len + 1));
		if (buf == NULL)
		{	
			THROW_EXCEPTION(NoEnoughMemoryException, "no memory to creat the sub string !!");
		}

		memset(buf, '\0', len + 1);
		strncpy(buf, mStr + index, len);
		ret = buf;
		free(buf);
	}

	return ret;
}

