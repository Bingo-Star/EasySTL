#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"

namespace EasySTL
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
    
public:
    LinkList();
    bool insert(int index, const T& element);
    bool remove(int index);
    bool set(int index, const T& element);
    bool get(int index, T& element) const;
    int length() const;
    void clear();
    ~LinkList();
};

template <typename T>
LinkList<T>::LinkList()
{
    mHeader = NULL;
    mLength = 0;
}

template <typename T>
bool LinkList<T>::insert(int index, const T& element)
{
    if (index < 0 || index > length())
    {
        return false;
    }    

    Node* node = new Node();
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
    	delete current;
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
	    delete tmp;
	}
    mLength--;

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
int LinkList<T>::length() const
{
   return mLength; 
}

template <typename T>
void LinkList<T>::clear()
{
    int count = length();
    while (count--)
    {
    	remove(0);
	} 
}

template <typename T>
LinkList<T>::~LinkList()
{
    clear();
}

}   // end namespace EasySTL

#endif

