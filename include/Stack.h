#ifndef STACK_H
#define STACK_H

#include "Root.h"

namespace EasyDSL
{

template <typename T>
class Stack : public RootClass
{
public:
    virtual void push(const T& element) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual void clear() = 0;
    virtual int size() const = 0;
};

}   // end namespace EasyDSL

#endif


