#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "LinkList.h"

namespace EasySTL
{

template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
protected:
	typedef typename LinkList<T>::Node Node;

	struct SNode : Node
	{
		void* operator new(size_t size, void* p);
		void operator delete(void* p);
	};
	
	unsigned char mSpace[sizeof(SNode) * N];
	bool mUsed[N];

	Node* create();
	void destroy(Node *p);

public:
	StaticLinkList();
	int capacity();
};

template <typename T, int N>
void* StaticLinkList<T, N>::SNode::operator new(size_t size, void* p)
{
	(void)size;
	return p;
}

template <typename T, int N>
void StaticLinkList<T, N>::SNode::operator delete(void* p)
{
	return;
}

template <typename T, int N>
typename LinkList<T>::Node* StaticLinkList<T, N>::create()
{
	typename LinkList<T>::Node* ret = NULL;
	for (int i = 0; i < N; i++)
	{
		if (!mUsed[i])
		{
			ret = reinterpret_cast<typename LinkList<T>::Node*>(mSpace) + i;
			ret = new(ret)SNode();
			mUsed[i] = true;
			break;
		}
	}

	return ret;
}

template <typename T, int N>
void StaticLinkList<T, N>::destroy(Node *p)
{
	SNode* space = reinterpret_cast<SNode*>(mSpace);
	SNode* tmp = dynamic_cast<SNode*>(p);

	for (int i = 0; i < N; i++)
	{
		if (p == space + i)
		{
			mUsed[i] = false;
			tmp->~SNode();
		}
	}
}

template <typename T, int N>
StaticLinkList<T, N>::StaticLinkList()
{
	for (int i = 0; i < N; i++)
	{
		mUsed[i] = false;
	}
}


template <typename T, int N>
int StaticLinkList<T, N>::capacity()
{
	return N;
}

}   // end namespace EasySTL

#endif


