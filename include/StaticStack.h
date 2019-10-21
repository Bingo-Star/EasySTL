#ifndef STATICSTACK_H
#define STATICSTACK_H

#include "Stack.h"
#include "Exception.h"


namespace EasyDSL
{

template <typename T, int N>
class StaticStack : public Stack<T>
{
protected:
	T mSpace[N];
	int mTop;
	int mSize;

public:
	StaticStack();
	~StaticStack();
    virtual void push(const T& element);
    virtual void pop();
    virtual T top();
    virtual void clear();
    virtual int size() const;

	int capacity() const;
};

template <typename T, int N>
StaticStack<T, N>::StaticStack()
{
	mTop = -1;
	mSize = 0;
}

template <typename T, int N>
StaticStack<T, N>::~StaticStack()
{
}


template <typename T, int N>
int StaticStack<T, N>::capacity() const
{
	return N;
}

template <typename T, int N>
void StaticStack<T, N>::push(const T& element)
{
	if (size() == capacity())
	{
        THROW_EXCEPTION(InvalidOperationException, "The satck is full !!");
	}

	mSpace[mTop + 1] = element;
	mTop++;
	mSize++;
}

template <typename T, int N>
void StaticStack<T, N>::pop()
{
	if (size() == 0)
	{
        THROW_EXCEPTION(InvalidOperationException, "The satck is empty !!");
	}
	else
	{
		mTop--;
		mSize--;
	}
}

template <typename T, int N>
int StaticStack<T, N>::size() const
{
	return mSize;
}

template <typename T, int N>
void StaticStack<T, N>::clear()
{
	mTop = -1;
	mSize = 0;
}

template <typename T, int N>
T StaticStack<T, N>::top()
{
	if (size() == 0)
	{
        THROW_EXCEPTION(InvalidOperationException, "The satck is empty !!");
	}
	
	return mSpace[mTop];
}

}   // end namespace EasyDSL

#endif


