#ifndef TREENODE_H
#define TREENODE_H

#include "Root.h"

namespace EasyDSL
{

template <typename T>
class TreeNode : public RootClass
{
protected:
	
	void* operator new (size_t size)  throw();

public:

	T value;
	TreeNode<T>* parent;

	TreeNode();
	virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::TreeNode()
{
	parent = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
}

template <typename T>
void* TreeNode<T>::operator new (size_t size) throw()
{
	return RootClass::operator new(size);
}

    
}   // end namespace EasyDSL

#endif
