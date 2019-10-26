#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "Stack.h"
#include "Exception.h"
#include "LinkList.h"

namespace EasyDSL
{

template <typename T>
class LinkStack : public Stack<T>
{
protected:
	LinkList<T> mList;

public:
    virtual void push(const T& element);
    virtual void pop();
    virtual T top();
    virtual void clear();
    virtual int size() const;
};

template <typename T>
void LinkStack<T>::push(const T& element)
{
	if (mList.insert(0, element) == false)
	{
		THROW_EXCEPTION(InvalidOperationException, "The satck is full !!");
	}
}

template <typename T>
void LinkStack<T>::pop()
{
	if (mList.remove(0) == false)
	{
        THROW_EXCEPTION(InvalidOperationException, "The satck is empty !!");
	}
}

template <typename T>
int LinkStack<T>::size() const
{
	return mList.length();
}

template <typename T>
void LinkStack<T>::clear()
{
	mList.clear();
}

template <typename T>
T LinkStack<T>::top()
{
	if (mList.length() == 0)
	{
        THROW_EXCEPTION(InvalidOperationException, "The satck is empty !!");
	}
	
	return mList.get(0);
}


}   // end namespace EasyDSL

#endif


