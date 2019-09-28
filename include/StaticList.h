#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.h"

namespace EasyDSL
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    T mSpace[N];

public:
    StaticList();
    StaticList(const StaticList<T, N>& obj);
    StaticList<T, N>& operator= (const StaticList<T, N>& obj); 
    int capacity() const;
};

template <typename T, int N>
StaticList<T, N>::StaticList()
{
    this->mArray = mSpace;
    this->mLength = 0;
}

template <typename T, int N>
StaticList<T, N>::StaticList(const StaticList<T, N>& obj)
{
    for (int i = 0; i < obj.mLength; i++)
    {
        this->mSpace[i] = obj.mSpace[i];
    }
    this->mArray = this->mSpace;
    this->mLength = obj.mLength;
}

template <typename T, int N>
StaticList<T, N>& StaticList<T, N>::operator= (const StaticList<T, N>& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    
    for (int i = 0; i < obj.mLength; i++)
    {
        this->mSpace[i] = obj.mSpace[i];
    }
    this->mArray = this->mSpace;
    this->mLength = obj.mLength;
    return *this;
}

template <typename T, int N>
int StaticList<T, N>::capacity() const
{
    return N;
}

}   // end namespace EasyDSL

#endif

