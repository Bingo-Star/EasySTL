#ifndef BTREENODE_H
#define BTREENODE_H

#include "TreeNode.h"

namespace EasyDSL
{

template <typename T>
class BTreeNode : public TreeNode<T>
{
protected:

	BTreeNode();	// creat the new Node must to use NewNode()

public:

	BTreeNode<T>* left;
	BTreeNode<T>* right;
	static BTreeNode<T>* NewNode();
};

template <typename T>
BTreeNode<T>::BTreeNode()
{
	left = NULL;
	right = NULL;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::NewNode()
{
	return new BTreeNode<T>();
}

}   // end namespace EasyDSL

#endif
 

