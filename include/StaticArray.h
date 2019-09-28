#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.h"

namespace EasyDSL
{

template <typename T, int N>
class StaticArray : public Array<T>
{
protected:
    T mSpace[N];

public:
    StaticArray();
    StaticArray(StaticArray<T, N>& obj);
    StaticArray<T, N>& operator= (StaticArray<T, N>& obj);
    int length() const;
};

template <typename T, int N>
StaticArray<T, N>::StaticArray()
{
    this->mArray = mSpace;
}

template <typename T, int N>
StaticArray<T, N>::StaticArray(StaticArray<T, N>& obj)
{
    this->mArray = mSpace;
    for (int i = 0; i < obj.length(); i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

template <typename T, int N>
StaticArray<T, N>& StaticArray<T, N>::operator= (StaticArray<T, N>& obj)
{
    if (this != &obj)
    {
        this->mArray = mSpace;
        for (int i = 0; i < obj.length(); i++)
        {
            mSpace[i] = obj.mSpace[i];
        }
    }
    return *this;
}

template <typename T, int N>
int StaticArray<T, N>::length() const
{
    return N;
}

}   // end namespace EasyDSL

#endif

