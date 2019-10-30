#ifndef QUEUEBASESTACK_H
#define QUEUEBASESTACK_H

#include "Queue.h"
#include "LinkStack.h"
#include "Exception.h"

namespace EasyDSL
{

template <typename T>
class QueueBaseStack : public Queue<T>
{
protected:
	LinkStack<T> mStackIn;
	LinkStack<T> mStackOut;

public:
	QueueBaseStack();
	~QueueBaseStack();
    virtual void add(const T& element);
    virtual void remove();
    virtual T front();
    virtual void clear();
    virtual int length() const;
};

template <typename T>
QueueBaseStack<T>::QueueBaseStack()
{
}

template <typename T>
QueueBaseStack<T>::~QueueBaseStack()
{
	clear();
}

template <typename T>
void QueueBaseStack<T>::add(const T& element)
{
	mStackIn.push(element);
}

template <typename T>
void QueueBaseStack<T>::remove()
{
	if (length() == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "the queue is empty !!");
	}

	if (mStackOut.size() == 0)
	{
		int size = mStackIn.size();
		while (size-- > 0)
		{
			mStackOut.push(mStackIn.top());
			mStackIn.pop();
		}
	}

	mStackOut.pop();
}

template <typename T>
T QueueBaseStack<T>::front()
{
	if (length() == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "the queue is empty !!");
	}

	if (mStackOut.size() == 0)
	{
		int size = mStackIn.size();
		while (size-- > 0)
		{
			mStackOut.push(mStackIn.top());
			mStackIn.pop();
		}
	}

	return mStackOut.top();
}

template <typename T>
void QueueBaseStack<T>::clear() 
{
	mStackIn.clear();
	mStackOut.clear();
}

template <typename T>
int QueueBaseStack<T>::length() const
{
	return mStackIn.size() + mStackOut.size();
}

}   // end namespace EasyDSL

#endif

