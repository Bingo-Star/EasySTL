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
	Node* mTail;
    
public:
    DualCircleList();
    ~DualCircleList();
    
	bool insert(int index, const T& element);
	bool remove(int index);
	  
	bool set(int index, const T& element);
	bool get(int index, T& element) const;

	int find(T& element) const;

	virtual bool move(int index, int step = 1);
};

template <typename T>
DualCircleList<T>::DualCircleList()
{
    mTail = NULL;
}

template <typename T>
bool DualCircleList<T>::insert(int index, const T& element)
{
	int new_index = index;
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
	    new_index = 0; 		
	}
	else if (index != 0 && index % len == 0)
	{
	    new_index = len;
	}
	else
	{
	    new_index = index % len;
	}

	if (DualLinkList<T>::insert(new_index, element) == true)
    {
		if (len == 0)
		{
			mTail = this->mHeader;
			this->mHeader->next = this->mHeader;
			this->mHeader->pre = this->mHeader;
		}
		else if (index != 0 && index % len == 0)
		{
			mTail = mTail->next;
	    	mTail->next = this->mHeader;
	    	this->mHeader->pre = mTail;
		}
    	return true;
    }
    else
    {
    	return false;
    }  

}

template <typename T>
bool DualCircleList<T>::remove(int index)
{
	index = index % DualLinkList<T>::length();
	if (DualLinkList<T>::remove(index) == true)
	{
		if (DualLinkList<T>::length() != 0)
		{
			if (index == 0)
			{
				mTail->next = this->mHeader;
				this->mHeader->pre = this->mHeader;
			}
			else if (index == DualLinkList<T>::length())
			{
				Node* current = this->mHeader;
				while (current->next != this->mHeader)
				{
					current = current->next;
				}
				mTail = current;
				this->mHeader->pre = mTail;
			}
		}
		else
		{
			mTail = NULL;
		}
		return true;
	}
	else
	{
		return false;
	}

}

template <typename T>
bool DualCircleList<T>::set(int index, const T& element)
{
	return DualLinkList<T>::set(index % DualLinkList<T>::length(), element);
}

template <typename T>
bool DualCircleList<T>::get(int index, T& element) const
{
    return DualLinkList<T>::get(index % DualLinkList<T>::length(), element);
}


template <typename T>
int DualCircleList<T>::find(T& element) const
{
	if (mTail != NULL && element == mTail->value)
	{
		return DualLinkList<T>::length() - 1;
	}
	
	int count = 0;
    for (Node* current = this->mHeader; current != mTail; current = current->next, count++)
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

template <typename T>
DualCircleList<T>::~DualCircleList()
{
    DualLinkList<T>::clear();
}

}   // end namespace EasyDSL

#endif

