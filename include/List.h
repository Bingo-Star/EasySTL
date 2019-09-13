#ifndef LIST_H
#define LIST_H

#include "Root.h"

namespace EasySTL
{

template <typename T>
class List : public RootClass
{
public:
    virtual bool insert(int index, const T& element) = 0;
    virtual bool remove(int index) = 0;
    virtual bool set(int index, const T& element) = 0;
    virtual bool get(int index, T& element) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;
};

}   // end namespace EasySTL

#endif

