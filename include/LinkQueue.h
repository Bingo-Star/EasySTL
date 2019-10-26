#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Queue.h"
#include "Exception.h"
#include "LinkList.h"

namespace EasyDSL
{

template <typename T>
class LinkQueue : public Queue<T>
{
protected:
	LinkList<T> mList;

public:
    virtual void add(const T& element);
    virtual void remove();
    virtual T front();
    virtual void clear();
    virtual int length() const;
};

template <typename T>
void LinkQueue<T>::add(const T& element)
{
	if (mList.push_back(element) == false)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is full !!");
	}
}

template <typename T>
void LinkQueue<T>::remove()
{
	if (mList.remove(0) == false)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is empty !!");
	}
}

template <typename T>
T LinkQueue<T>::front()
{
	if (mList.length() == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is empty !!");
	}
	
	return mList.get(0);
}

template <typename T>
void LinkQueue<T>::clear() 
{
	mList.clear();
}

template <typename T>
int LinkQueue<T>::length() const 
{
	return mList.length();
}


}   // end namespace EasyDSL

#endif


