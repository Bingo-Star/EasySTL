#ifndef ROOT_H
#define ROOT_H

#include <cstdio>

namespace EasySTL
{

class RootClass
{
public:
    void* operator new (size_t  size) throw();
    void operator delete (void* p);

    void* operator new[] (size_t  size) throw();
    void operator delete[] (void* p);

    bool operator == (RootClass& obj);
	bool operator != (RootClass& obj);

    virtual ~RootClass() = 0;
};

}   // end namespace EasySTL

#endif
