#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include "Pointer.h"
#include "Exception.h"
#include <cstdlib>

namespace EasySTL
{

template <typename T>
class SharedPointer : public Pointer<T>
{
protected:
	int* mpCount;

public:
	SharedPointer(T* p = NULL);
    SharedPointer(const SharedPointer<T>& obj);
    SharedPointer<T>& operator= (const SharedPointer<T>& obj);
    bool operator == (const SharedPointer<T>& obj) const;
    bool operator != (const SharedPointer<T>& obj) const;
    ~SharedPointer();
};

template <typename T>
SharedPointer<T>::SharedPointer(T* p) : mpCount(NULL)
{
	if (p)
	{
		mpCount = static_cast<int*>(std::malloc(sizeof(int)));
		if (mpCount)
		{
			*mpCount = 1;
			this->mPointer = p;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create SharePointer !! ");
		}
	}
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& obj) : Pointer<T>(NULL)
{
    this->mPointer = obj.get();
    mpCount = obj.mpCount;
	if (mpCount)
	{
    	(*mpCount)++;
    }
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator= (const SharedPointer<T>& obj)
{
    if (this != &obj)
    {
		T* tmpPointer = this->mPointer;
		this->mPointer = NULL;
		int* tmpCount = mpCount;
		mpCount = NULL;
		if (tmpCount)
		{
			(*tmpCount)--;
			if (*tmpCount == 0)
			{
				free(tmpCount);
				delete tmpPointer;	
			}
		}
    	
        this->mPointer = obj.get();
        mpCount = obj.mpCount;
		if (mpCount)
		{
			(*mpCount)++;
		}
    }
    return *this;
}

template <typename T>
bool SharedPointer<T>::operator == (const SharedPointer<T>& obj) const
{
	return this->get() == obj.get();
}

template <typename T>
bool SharedPointer<T>::operator != (const SharedPointer<T>& obj) const
{
	return this->get() != obj.get();
}


template <typename T>
SharedPointer<T>::~SharedPointer()
{
	if (mpCount)
	{
		(*mpCount)--;
		if (*mpCount == 0)
		{
			free(mpCount);
			delete this->mPointer;			
		}
	}

}

}   // end namespace EasySTL

#endif


