#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "LinkList.h"

namespace EasyDSL
{

template <typename T>
class CircleList : public LinkList<T>
{
protected:
	typedef typename LinkList<T>::Node Node;
	Node* mTail;

public:
	CircleList();
	~CircleList();
	
	bool insert(int index, const T& element);
	bool remove(int index);
	virtual bool push_back(const T& element);
	  
	bool set(int index, const T& element);
	bool get(int index, T& element) const;
	T get(int index);

	int find(T& element) const;

	virtual bool move(int index, int step = 1);
};

template <typename T>
CircleList<T>::CircleList()
{
	mTail = NULL;
}

template <typename T>
CircleList<T>::~CircleList()
{
}

template <typename T>
bool CircleList<T>::insert(int index, const T& element)
{
	int len = LinkList<T>::length();
	if (len != 0 && index % len == 0)
	{
		return push_back(element);
	}
	else
	{
		if (len != 0 && index >= len)
		{
			index = index % len;
		}
		if (LinkList<T>::insert(index, element) == true)
    	{
			if (len == 0)
			{		
				mTail = this->mHeader;
				this->mHeader->next = this->mHeader;
			}
			else if (index == 0)
			{
				mTail->next = this->mHeader;
			}
	    	return true;
	    }
	    else
	    {
	    	return false;
  		} 
	}
}

template <typename T>
bool CircleList<T>::push_back(const T& element)
{
	Node* node = LinkList<T>::create();
	if (node != NULL)
	{		
		node->value = element;
		
		if (mTail != NULL)
		{
			mTail->next = node;
			mTail = mTail->next;		
		}
		else
		{
			mTail = node;
			this->mHeader = node;
		}
		
		mTail->next = this->mHeader;
		this->mLength++;
		
		return true;
	}
	else
	{
		THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create a node !!");
		return false;
	}
}


template <typename T>
bool CircleList<T>::remove(int index)
{
	index = index % LinkList<T>::length();
	if (LinkList<T>::remove(index) == true)
	{
		if (LinkList<T>::length() != 0)
		{
			if (index == 0)
			{
				mTail->next = this->mHeader;
			}
			else if (index == LinkList<T>::length())
			{
				Node* current = this->mHeader;
				while (current->next != this->mHeader)
				{
					current = current->next;
				}
				mTail = current;
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
bool CircleList<T>::set(int index, const T& element)
{
    return LinkList<T>::set(index % LinkList<T>::length(), element);
}

template <typename T>
bool CircleList<T>::get(int index, T& element) const
{
    return LinkList<T>::get(index % LinkList<T>::length(), element);
}

template <typename T>
T CircleList<T>::get(int index)
{
    return LinkList<T>::get(index % LinkList<T>::length());
}


template <typename T>
int CircleList<T>::find(T& element) const
{
	if (mTail != NULL && element == mTail->value)
	{
		return LinkList<T>::length() - 1;
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
bool CircleList<T>::move(int index, int step)
{
	return LinkList<T>::move(index % LinkList<T>::length(), step);
}

}   // end namespace EasyDSL

#endif


