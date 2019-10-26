#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include "Queue.h"
#include "Exception.h"


namespace EasyDSL
{

template <typename T, int N>
class StaticQueue : public Queue<T>
{
protected:
	T mSpace[N];
	int mFront;
	int mRear;
	int mLength;

public:
	StaticQueue();
	~StaticQueue();
	
    virtual void add(const T& element);
    virtual void remove();
    virtual T front();
    virtual void clear();
    virtual int length() const;

	int capacity() const;
};

template <typename T, int N>
StaticQueue<T, N>::StaticQueue()
{
	mLength = 0;
	mFront = 0;
	mRear = 0;
}

template <typename T, int N>
StaticQueue<T, N>::~StaticQueue()
{
}

template <typename T, int N>
void StaticQueue<T, N>::add(const T& element)
{
	if (mLength == N)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is full !!");
	}
	else
	{
		mSpace[mRear] = element;
		mRear = (mRear + 1) % N;
		mLength++;
	}
}

template <typename T, int N>
void StaticQueue<T, N>::remove()
{
	if (mLength == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is empty !!");
	}
	else
	{
		mFront = (mFront + 1) % N;
		mLength--;
	}
}

template <typename T, int N>
T StaticQueue<T, N>::front()
{
	if (mFront == mRear && mLength == 0)
	{
		THROW_EXCEPTION(InvalidOperationException, "The queue is empty !!");
	}

	return mSpace[mFront];
}

template <typename T, int N>
void StaticQueue<T, N>::clear()
{
	mLength = 0;
	mFront = 0;
	mRear = 0;
}

template <typename T, int N>
int StaticQueue<T, N>::length() const
{
	return mLength;
}

template <typename T, int N>
int StaticQueue<T, N>::capacity() const
{
	return N;
}

}   // end namespace EasyDSL

#endif


