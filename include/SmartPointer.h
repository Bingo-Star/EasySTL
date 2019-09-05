#ifndef SMAERPOINT_H
#define SMAERPOINT_H

namespace EasySTL
{

template <typename T>
class SmartPointer
{
protected:
    T* mPointer;

public:
    SmartPointer(T* p = NULL);
    SmartPointer(const SmartPointer<T>& obj);
    SmartPointer<T>& operator= (const SmartPointer<T>& obj);
    T* operator-> ();
    T& operator* ();
    bool IsNULL();
    ~SmartPointer();
};

template <typename T>
SmartPointer<T>::SmartPointer(T* p)
{
    this->mPointer = p;
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
        delete this->mPointer;
        this->mPointer = obj.mPointer;
        const_cast<SmartPointer<T>&>(obj).mPointer = NULL;
    }
}

template <typename T>
T* SmartPointer<T>::operator-> ()
{
    return this->mPointer;
}

template <typename T>
T& SmartPointer<T>::operator* ()
{
    return *(this->mPointer);
}

template <typename T>
bool SmartPointer<T>::IsNULL()
{
    return this->mPointer == NULL;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    delete this->mPointer;
}

}

#endif