#ifndef ARRAY_H
#define ARRAY_H

#include "Root.h"
#include "Exception.h"

namespace EasyDSL
{

template <typename T>
class Array : public RootClass
{
protected:
    T* mArray;

public:
    virtual bool set(int index, const T& element);
    virtual bool get(int index, T& element) const;
    T& operator[] (int index);
    T operator[] (int index) const;
    T* addr() const;
    virtual int length() const = 0;
};

template <typename T>
bool Array<T>::set(int index, const T& element)
{
    if (index < 0 || index >= length())
    {
        return false;
    }

    mArray[index] = element;
    
    return true;
}

template <typename T>
bool Array<T>::get(int index, T& element) const
{
    if (index < 0 || index >= length())
    {
        return false;
    }

    element = mArray[index];
    
    return true;
}

template <typename T>
T& Array<T>::operator[] (int index)
{
    if (index < 0 || index >= length())
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "index is invalid !!");
    }

    return mArray[index];
}

template <typename T>
T Array<T>::operator[] (int index) const
{
    return (const_cast<Array<T>&>(*this))[index];
}

template <typename T>
T* Array<T>::addr () const
{
    return mArray;
}


}   // end namespace EasyDSL

#endif


