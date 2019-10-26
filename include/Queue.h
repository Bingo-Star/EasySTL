#ifndef QUEUE_H
#define QUEUE_H

#include "Root.h"

namespace EasyDSL
{

template <typename T>
class Queue : public RootClass
{
public:
    virtual void add(const T& element) = 0;
    virtual void remove() = 0;
    virtual T front() = 0;
    virtual void clear() = 0;
    virtual int length() const = 0;
};

}   // end namespace EasyDSL

#endif



