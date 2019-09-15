#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"
#include "Exception.h"

namespace EasySTL
{

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int mLength;      // 顺序存储空间大小

public:
    DynamicArray(int len);
    DynamicArray(const DynamicArray<T>& obj);
    DynamicArray<T>& operator= (const DynamicArray<T>& obj); 
    int length() const;
    void resize(int len);
    ~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray(int len)
{   
    this->mArray = new T[len];
    if (this->mArray != NULL)
    {
        mLength = len;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create the DynamicArray obj err !!");
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& obj)
{
    this->mArray = new T[obj.mLength];
    if (this->mArray != NULL)
    {
        for (int i = 0; i < obj.mLength; i++)
        {
            this->mArray[i] = obj.mArray[i];
        }
        mLength = obj.mLength;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create the DynamicArray obj err !!");
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& obj)
{
    if (this != &obj)
    { 
        T* lArray = new T[obj.mLength];
        if (lArray != NULL)
        {
            for (int i = 0; i < obj.mLength; i++)
            {
                lArray[i] = obj.mArray[i];
            }
            T* tmp = this->mArray;
            this->mArray = lArray;
            this->mLength = obj.mLength;
            if (tmp != NULL)
            {
                delete[] tmp;
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray obj !!");
        }
    }
    return *this;    
}

template <typename T>
int DynamicArray<T>::length() const
{
    return mLength;
}

template <typename T>
void DynamicArray<T>::resize(int len)
{
    if (len == mLength)
    {
        return;
    }  
    
    T* lArray = new T[len];
    if (lArray != NULL)
    {
        if (len > mLength)
        {
            for (int i = 0; i < mLength; i++)
            {
                lArray[i] = this->mArray[i];
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                lArray[i] = this->mArray[i];
            }         
        }
        T* tmp = this->mArray;     
        this->mArray = lArray; 
        this->mLength = len;
        delete[] tmp;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize !!");
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->mArray;
}

}   // end namespace EasySTL

#endif


