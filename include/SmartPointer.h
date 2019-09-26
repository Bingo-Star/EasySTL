#ifndef SMAERPOINTER_H
#define SMAERPOINTER_H

#include "Pointer.h"

namespace EasySTL
{

template <typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p = NULL);
    SmartPointer(const SmartPointer<T>& obj);
    SmartPointer<T>& operator= (const SmartPointer<T>& obj);
    ~SmartPointer();
};

template <typename T>
SmartPointer<T>::SmartPointer(T* p) : Pointer<T>(p)
{
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
{
    this->mPointer = obj.mPointer;
    const_cast<SmartPointer<T>&>(obj).mPointer = NULL;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator= (const SmartPointer<T>& obj)
{
    if (*this != obj)
    {
    	T* tmp = this->mPointer;
        this->mPointer = obj.mPointer;
        const_cast<SmartPointer<T>&>(obj).mPointer = NULL;
        delete tmp;
    }
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    delete this->mPointer;
}

}   // end namespace EasySTL

#endif