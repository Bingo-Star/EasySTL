#ifndef TREENODE_H
#define TREENODE_H

#include "Root.h"

namespace EasyDSL
{

template <typename T>
class TreeNode : public RootClass
{
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
    
}   // end namespace EasyDSL

#endif
