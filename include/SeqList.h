#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"

namespace EasySTL
{

template <typename T>
class SeqList : public List<T>
{
protected:
    T* mArray;      // 线性表存储空间
    int mLength;    // 当前线性表长度

public:
    bool insert(int index, const T& element);
    bool push_back(const T& element);
    bool remove(int index);
    bool set(int index, const T& element);
    bool get(int index, T& element) const;
    int length() const;
    void clear();

    T& operator[] (int index);
    T operator[] (int index) const;     // const 对象使用

    virtual int capacity() const = 0;
};

template <typename T>
bool SeqList<T>::insert(int index, const T& element)
{
    if (index < 0 || index > mLength || mLength >= capacity())
    {
        return false;
    }

    for (int i = mLength; i > index; i--)
    {
        mArray[i] = mArray[i - 1];
    }
    mArray[index] = element;
    mLength++;
    
    return true;
}

template <typename T>
bool SeqList<T>::push_back(const T& element)
{
    return insert(mLength, element);
}

template <typename T>
bool SeqList<T>::remove(int index)
{
    if (index < 0 || index >= mLength)
    {
        return false;
    }

    for (int i = index; i < mLength; i++)
    {
        mArray[i] = mArray[i + 1];
    }
    mLength--;

    return true;
}

template <typename T>
bool SeqList<T>::set(int index, const T& element)
{
    if (index < 0 || index >= mLength)
    {
        return false;
    }    

    mArray[index] = element;

    return true;
}

template <typename T>
bool SeqList<T>::get(int index, T& element) const
{
    if (index < 0 || index >= mLength)
    {
        return false;
    }    

    element = mArray[index];

    return true;
}

template <typename T>
int SeqList<T>::length() const
{
    return mLength;
}

template <typename T>
void SeqList<T>::clear()
{
    mLength = 0;
}

template <typename T>
T& SeqList<T>::operator[] (int index)
{
    if (index < 0 || index >= mLength)
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "index is invalid !!");
    }  
    return mArray[index];
}

template <typename T>
T SeqList<T>::operator[] (int index) const
{
    return (const_cast<SeqList<T>&>(*this))[index];
}

}   // end namespace EasySTL

#endif


