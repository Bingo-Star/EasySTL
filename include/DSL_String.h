#ifndef STRING_H
#define STRING_H

#include "Root.h"
#include <cstring>
#include <cstdlib>

namespace EasyDSL
{

class String : public RootClass
{
protected:
	char* mStr;
	int mLength;

	void init(const char* str);
	int* init_PMT(const char* str) const; 
	int StrSearch(const char* SrcStr, const char* SubStr) const;
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

	char& operator [] (unsigned int index);	
	char operator [] (unsigned int index) const;

	String& insert(unsigned int index, const char c);
	String& insert(unsigned int index, const char* str);
	String& insert(unsigned int index, const String& obj);

	int find(const char c) const;
	int find(const char* str) const;
	int find(const String& obj) const;

	bool remove(unsigned int index, unsigned int len);
	bool remove(const char c);
	bool remove(const char* str);
	bool remove(const String& obj);

	bool replace(const char src_c, const char dst_c);
	bool replace(const char src_c, const char* dst_str);
	bool replace(const char src_c, const String& dst_obj);
	bool replace(const char* src_str, const char dst_c);
	bool replace(const char* src_str, const char* dst_str);
	bool replace(const char* src_str, const String& dst_obj);
	bool replace(const String& src_obj, const char dst_c);
	bool replace(const String& src_obj, const char* dst_str);
	bool replace(const String& src_obj, const String& dst_obj);

	String sub(unsigned int index, unsigned int len) const;
};


}   // end namespace EasyDSL

#endif


