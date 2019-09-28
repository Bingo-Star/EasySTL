#ifndef POINTER_H
#define POINTER_H

#include "Root.h"

namespace EasyDSL
{

template <typename T>
class Pointer : public RootClass
{
protected:
	T* mPointer;

public:
	Pointer(T* p = NULL);
    T* operator-> ();
    const T* operator-> () const;
    T& operator* ();
    const T& operator* () const;
    bool IsNULL() const;
    T* get() const;
};

template <typename T>
Pointer<T>::Pointer(T* p)
{
	mPointer = p;
}

template <typename T>
T* Pointer<T>::operator-> ()
{
    return this->mPointer;
}

template <typename T>
const T* Pointer<T>::operator-> () const
{
    return this->mPointer;
}

template <typename T>
T& Pointer<T>::operator* ()
{
    return *(this->mPointer);
}

template <typename T>
const T& Pointer<T>::operator* () const
{
    return *(this->mPointer);
}

template <typename T>
bool Pointer<T>::IsNULL() const
{
    return this->mPointer == NULL;
}

template <typename T>
T* Pointer<T>::get() const
{
	return mPointer;
}

}   // end namespace EasyDSL

#endif

