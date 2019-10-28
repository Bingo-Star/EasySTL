#ifndef DUALCIRCLELIST_H
#define DUALCIRCLELIST_H

#include "DualLinkList.h"

namespace EasyDSL
{

template <typename T>
class DualCircleList : public DualLinkList<T>
{
protected:	
	typedef typename DualLinkList<T>::Node Node;
    
public:   
	bool insert(int index, const T& element);
	bool push_back(const T& element);
	bool remove(int index);
	  
	bool set(int index, const T& element);
	bool get(int index, T& element) const;
	T get(int index);

	int find(T& element) const;

	virtual bool move(int index, int step = 1);
};

template <typename T>
bool DualCircleList<T>::insert(int index, const T& element)
{
	int len = DualLinkList<T>::length();
	int new_index = index;
	if (len > 0)
	{
		if (index % len == 0 && index > 0)
		{
			new_index = len;
		}
		else
		{
			new_index = index % len;
		}
	}
	
	if (DualLinkList<T>::insert(new_index, element) == true)
	{
		this->mHeader->pre = this->mTail;
		this->mTail->next = this->mHeader;
	}
	else
	{
		return false;
	}

	return true;
}


template <typename T>
bool DualCircleList<T>::push_back(const T& element)
{
	return insert(DualLinkList<T>::length(), element);
}


template <typename T>
bool DualCircleList<T>::remove(int index)
{
	if (DualLinkList<T>::remove(index % DualLinkList<T>::length()) == true)
	{
		if (DualLinkList<T>::length() > 0)
		{
			this->mHeader->pre = this->mTail;
			this->mTail->next = this->mHeader;
		}
	}
	else
	{
		return false;
	}

	return true;
}


template <typename T>
bool DualCircleList<T>::set(int index, const T& element)
{
	return DualLinkList<T>::set(index % DualLinkList<T>::length(), element);
}

template <typename T>
bool DualCircleList<T>::get(int index, T& element) const
{
	return DualLinkList<T>::get(index % DualLinkList<T>::length(), element);;
}

template <typename T>
T DualCircleList<T>::get(int index)
{
	return DualLinkList<T>::get(index % DualLinkList<T>::length());;
}


template <typename T>
int DualCircleList<T>::find(T& element) const
{
	if (this->mTail != NULL && element == this->mTail->value)
	{
		return DualLinkList<T>::length() - 1;
	}
	
	int count = 0;
    for (Node* current = this->mHeader; current != this->mTail; current = current->next, count++)
    {
    	if (current->value == element)
    	{
    		return count;
    	}
    }
    
    return -1;
}


template <typename T>
bool DualCircleList<T>::move(int index, int step)
{
	return DualLinkList<T>::move(index % DualLinkList<T>::length(), step);
}



}   // end namespace EasyDSL

#endif

