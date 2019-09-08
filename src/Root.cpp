#include "Root.h"
#include <cstdlib>
#include <cstdio>

using namespace EasySTL;

void* RootClass::operator new (size_t size) throw()
{
    return malloc(size);
}

void RootClass::operator delete (void* p)
{
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


