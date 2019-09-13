#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.h"

namespace EasySTL
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    T mSpace[N];

public:
    StaticList();
    int capacity() const;
};

template <typename T, int N>
StaticList<T, N>::StaticList()
{
    this->mArray = mSpace;
    this->mLength = 0;
}

template <typename T, int N>
int StaticList<T, N>::capacity() const
{
    return N;
}

}   // end namespace EasySTL

#endif

