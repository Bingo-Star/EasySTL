#ifndef STACKBASEQUEUE_H
#define STACKBASEQUEUE_H

#include "LinkQueue.h"
#include "Stack.h"
#include "Exception.h"

namespace EasyDSL
{

template <typename T>
class StackBaseQueue : public Stack<T>
{
protected:
	LinkQueue<T> mQueue_1;
	LinkQueue<T> mQueue_2;

	LinkQueue<T>* mpQueueMain;
	LinkQueue<T>* mpQueueBak;

public:
	StackBaseQueue();
	~StackBaseQueue();
    virtual void push(const T& element);
    virtual void pop();
    virtual T top();
    virtual void clear();
    virtual int size() const;
};

template <typename T>
StackBaseQueue<T>::StackBaseQueue()
{
	mpQueueMain = &mQueue_1;
	mpQueueBak = &mQueue_2;
}

template <typename T>
StackBaseQueue<T>::~StackBaseQueue()
{
	clear();
}

template <typename T>
void StackBaseQueue<T>::push(const T& element)
{
	mpQueueMain->add(element);
}

template <typename T>
void StackBaseQueue<T>::pop()
{
	if (size() == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "the stack is empty !!");
	}
	
	int len = mpQueueMain->length();
	while (len > 1)
	{
		mpQueueBak->add(mpQueueMain->front());
		mpQueueMain->remove();
		len--;
	}

	mpQueueMain->remove();

	LinkQueue<T>* tmp = mpQueueMain;
	mpQueueMain = mpQueueBak;
	mpQueueBak = tmp;
}

template <typename T>
T StackBaseQueue<T>::top()
{
	if (size() == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "the stack is empty !!");
	}

	int len = mpQueueMain->length();
	while (len > 1)
	{
		mpQueueBak->add(mpQueueMain->front());
		mpQueueMain->remove();
		len--;
	}

	return mpQueueMain->front();
}

template <typename T>
void StackBaseQueue<T>::clear()
{
	mQueue_1.clear();
	mQueue_2.clear();
}

template <typename T>
int StackBaseQueue<T>::size() const
{
	return mQueue_1.length() + mQueue_2.length();
}

}   // end namespace EasyDSL

#endif



