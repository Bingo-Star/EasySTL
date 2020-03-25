#ifndef GTREENODE_H
#define GTREENODE_H

#include "TreeNode.h"
#include "LinkList.h"

namespace EasyDSL
{

template <typename T>
class GTreeNode : public TreeNode<T>
{
protected:
	bool mFlg;

	void* operator new (size_t size)  throw();
	GTreeNode();	// creat the new Node must to use NewNode()

public:
	LinkList< GTreeNode<T>* > child;
	
	static GTreeNode<T>* NewNode();
	bool flg();
};

template <typename T>
GTreeNode<T>::GTreeNode()
{
	this->mFlg = false;
}

template <typename T>
void* GTreeNode<T>::operator new (size_t size) throw()
{
	return RootClass::operator new(size);
}

template <typename T>
GTreeNode<T>* GTreeNode<T>::NewNode()
{
	GTreeNode<T>* ret = new GTreeNode<T>();
	if (ret != NULL)
	{
		ret->mFlg = true;
	}
}

template <typename T>
bool GTreeNode<T>::flg()
{
	return mFlg;
}

}   // end namespace EasyDSL

#endif
 
