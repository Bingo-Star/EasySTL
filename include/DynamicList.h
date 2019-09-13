#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"

namespace EasySTL
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int mCapacity;      // 顺序存储空间大小

public:
    DynamicList(int capacity);
    int capacity() const;
    void resize(int capacity);
    ~DynamicList();
};

template <typename T>
DynamicList<T>::DynamicList(int capacity)
{
    this->mArray = new T[capacity];
    if (this->mArray != NULL)
    {
        mCapacity = capacity;
    }
    else
    {
        mCapacity = 0;
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList obj !!");
    }
    this->mLength = 0;
}

template <typename T>
int DynamicList<T>::capacity() const
{
    return mCapacity;
}

template <typename T>
void DynamicList<T>::resize(int capacity)
{
    if (capacity == mCapacity)
    {
        return;
    }  
    
    T* lArray = new T[capacity];
    if (lArray != NULL)
    {
        if (capacity > this->mLength)
        {
            for (int i = 0; i < this->mLength; i++)
            {
                lArray[i] = this->mArray[i];
            }
        }
        else
        {
            for (int i = 0; i < capacity; i++)
            {
                lArray[i] = this->mArray[i];
            }
            this->mLength = capacity;
        }

        T* tmp = this->mArray;
        
        this->mArray = lArray;
        mCapacity = capacity;

        delete[] tmp;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize !!");
    }
}

template <typename T>
DynamicList<T>::~DynamicList()
{
    delete[] this->mArray;
}

}   // end namespace EasySTL

#endif

