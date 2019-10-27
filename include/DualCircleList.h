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
	bool push_back(const T& element);
	bool remove(int index);
	  
	bool set(int index, const T& element);
	bool get(int index, T& element) const;
	T get(int index);

	int find(T& element) const;

	virtual bool move(int index, int step = 1);
};

template <typename T>
DualCircleList<T>::DualCircleList()
{
    mTail = NULL;
}

template <typename T>
DualCircleList<T>::~DualCircleList()
{
}


template <typename T>
bool DualCircleList<T>::insert(int index, const T& element)
{
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
		if (index != 0)
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
			return false;
		}
		
		Node* node = DualLinkList<T>::create();
		if (node != NULL)
		{
			node->value = element;
			node->next = node;
			node->pre = node;
			this->mHeader = node;
			mTail = node;
			this->mLength++;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create a node !!");
			return false;
		}	
	}
	else
	{
		int new_index = index % len;
		Node* node = DualLinkList<T>::create();
		if (node != NULL)
		{		
			if (new_index == 0)
			{
				node->value = element;
				node->next = this->mHeader;
				node->pre = mTail;
				this->mHeader->pre = node;
				mTail->next = node;
				
				if (index == 0)
				{
					this->mHeader = node;
				}
				else if (index > 0)
				{
					mTail = node;
				}
				else
				{
					THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
					return false;
				}
			}
			else
			{
				Node* current = NULL;
				if (new_index <= len / 2)
				{
					current = this->mHeader;
					while (--new_index)
					{
						current = current->next;
					}
				}
				else
				{
					new_index = len - new_index;
					current = mTail;
					while (new_index--)
					{
						current = current->pre;
					}		
				}
				node->value = element;
				node->next = current->next;
				node->pre = current;
				current->next = node;
				if (node->next != NULL)
				{
					node->next->pre = node;
				}	
			}
			this->mLength++;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create a node !!");
			return false;
		}
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
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "the list is empty !!");
		return false;
	}
	
	index = index % len;
	if (index == 0)
    {
    	Node* current = this->mHeader;
    	if (len == 1)
    	{
    		this->mHeader = NULL;
    		mTail = NULL;
    	}
    	else 
    	{
    		this->mHeader = this->mHeader->next;
			this->mHeader->pre = mTail;
			mTail->next = this->mHeader;
    	}
    	    	
		this->mLength--;

		if (this->mCurrent == current)
		{
			this->mCurrent = current->next;
		}
    	
    	DualLinkList<T>::destroy(current);
    }
    else
    {
	    Node* current = NULL;
		if (index <= len / 2)
		{
			current = this->mHeader;
			while (--index)
			{
				current = current->next;
			}
		}
		else
		{
			index = len - index;
			current = mTail;
			while (index--)
			{
				current = current->pre;
			}		
		}

	    Node* tmp = current->next;
	    current->next = current->next->next;
	    if (current->next != NULL)
	   	{
	   		current->next->pre = current;
	   	}
	   	this->mLength--;

		if (this->mCurrent == tmp)
		{
			this->mCurrent = current->next;
		}
		
	    DualLinkList<T>::destroy(tmp);
	}
	return true;
}

template <typename T>
bool DualCircleList<T>::set(int index, const T& element)
{
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "the list is empty !!");
		return false;
	}	
	index = index % len;
	
	Node* current = NULL;
	if (index <= len / 2)
	{
		current = this->mHeader;
		while (index--)
		{
			current = current->next;
		}
	}
	else
	{
		index = len - index;
		current = mTail;
		while (--index)
		{
			current = current->pre;
		}		
	}
	current->value = element;
	
	return true;
}

template <typename T>
bool DualCircleList<T>::get(int index, T& element) const
{
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "the list is empty !!");
		return false;
	}	
	index = index % len;
	
	Node* current = NULL;
	if (index <= len / 2)
	{
		current = this->mHeader;
		while (index--)
		{
			current = current->next;
		}
	}
	else
	{
		index = len - index;
		current = mTail;
		while (--index)
		{
			current = current->pre;
		}		
	}
	element = current->value;
	
	return true;

}

template <typename T>
T DualCircleList<T>::get(int index)
{
	int len = DualLinkList<T>::length();
	if (len == 0)
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "the list is empty !!");
	}	
	index = index % len;
	
	Node* current = NULL;
	if (index <= len / 2)
	{
		current = this->mHeader;
		while (index--)
		{
			current = current->next;
		}
	}
	else
	{
		index = len - index;
		current = mTail;
		while (--index)
		{
			current = current->pre;
		}		
	}
	
	return current->value;
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



}   // end namespace EasyDSL

#endif

