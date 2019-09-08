#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "Root.h"

using namespace EasySTL;
using namespace std;

void* RootClass::operator new (size_t size) throw()
{
    cout << "operator new" << endl;
    return malloc(size);
}

void RootClass::operator delete (void* p)
{
    cout << "operator delete" << endl;
    free(p);
}

void* RootClass::operator new[] (size_t size) throw()
{
    return malloc(size);
}

void RootClass::operator delete[] (void* p)
{
    free(p);
}

RootClass::~RootClass()
{
}



