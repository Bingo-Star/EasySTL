#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"

namespace EasyDSL
{

template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public RootClass
    {
        T value;
        Node* next;
    };
    
    Node* mHeader;
    int mLength;

    Node* mCurrent;
    int mStep;

    virtual Node* create();
    virtual void destroy(Node* p); 
    
public:
    LinkList();
    ~LinkList();
    
    bool insert(int index, const T& element);
    bool remove(int index);
    virtual bool push_back(const T& element);
      
    bool set(int index, const T& element);
    bool get(int index, T& element) const;
    T get(int index);
    
    int length() const;
    void clear();
    int find(T& element) const;
    
	virtual bool move(int index, int step = 1);
    virtual bool end();
    virtual T& current();
    virtual bool next();
};

template <typename T>
typename LinkList<T>::Node* LinkList<T>::create()
{
	return new Node();
}

template <typename T>
void LinkList<T>::destroy(Node* p)
{
	delete p;
}

template <typename T>
LinkList<T>::LinkList()
{
    mHeader = NULL;
    mLength = 0;
    mCurrent = NULL;
    mStep = 1;
}

template <typename T>
bool LinkList<T>::insert(int index, const T& element)
{
    if (index < 0 || index > length())
    {
        return false;
    }    

    Node* node = create();
    if (node != NULL)
    {       
        if (index == 0)
        {
	        node->value = element;
	        node->next = mHeader;
	        mHeader = node;
	    }
	    else
	    {
		    Node* current = mHeader;
		    while (--index)
	        {
	            current = current->next;
	        }
	        node->value = element;
	        node->next = current->next;
	        current->next = node;
	    }
        mLength++;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create a node !!");
    }

    return true;
}

template <typename T>
bool LinkList<T>::remove(int index)
{
    if (index < 0 || index >= length())
    {
        return false;
    } 

    if (index == 0)
    {
    	Node* current = mHeader;
    	mHeader = mHeader->next;
    	mLength--;

		if (mCurrent == current)
		{
			mCurrent = current->next;
		}
    	
    	destroy(current);
    }
    else
    {
	    Node* current = mHeader;
	    while (--index)
	    {
	        current = current->next;
	    }  
	    Node* tmp = current->next;
	    current->next = current->next->next;
	    mLength--;

		if (mCurrent == tmp)
		{
			mCurrent = current->next;
		}
		
	    destroy(tmp);
	}

    return true;
}

template <typename T>
bool LinkList<T>::set(int index, const T& element)
{
    if (index < 0 || index >= length())
    {
        return false;
    } 
    
    Node* current = mHeader;
    while (index--)
    {
        current = current->next;
    }     
    current->value = element;

    return true;
}

template <typename T>
bool LinkList<T>::get(int index, T& element) const
{
    if (index < 0 || index >= length())
    {
        return false;
    } 
    
    Node* current = mHeader;
    while (index--)
    {
        current = current->next;
    }     
    element = current->value;

    return true;
}

template <typename T>
T LinkList<T>::get(int index) 
{
    if (index < 0 || index >= length())
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "err index !!");
    } 
    
    Node* current = mHeader;
    while (index--)
    {
        current = current->next;
    }     
    return current->value;
}


template <typename T>
int LinkList<T>::length() const
{
   return mLength; 
}

template <typename T>
void LinkList<T>::clear()
{
    while (length())
    {
    	remove(0);
	} 
}

template <typename T>
int LinkList<T>::find(T& element) const
{
	int count = 0;
    for (Node* current = mHeader; current != NULL; current = current->next, count++)
    {
    	if (current->value == element)
    	{
    		return count;
    	}
    }
    return -1;
}

template <typename T>
bool LinkList<T>::push_back(const T& element)
{
	return insert(length(), element);
}

template <typename T>
bool LinkList<T>::move(int index, int step)
{
	if (index < 0 || index >= mLength || step <= 0)
	{
		return false;
	}

	mCurrent = mHeader;
	while (index--)
	{
		mCurrent = mCurrent->next;
	}
	mStep = step;

	return true;
}

template <typename T>
bool LinkList<T>::end()
{
	return mCurrent == NULL;
}

template <typename T>
T& LinkList<T>::current()
{
	if (!end())
	{
		return mCurrent->value;
	}
	else
	{
		THROW_EXCEPTION(InvalidOperationException, "No value at mCurrent pointer !!");
	}
}

template <typename T>
bool LinkList<T>::next()
{
	int i = 0;
	for (; i < mStep && !end(); i++)
	{
		mCurrent = mCurrent->next;
	}

	return i == mStep;
}

template <typename T>
LinkList<T>::~LinkList()
{
    clear();
}

}   // end namespace EasyDSL

#endif

