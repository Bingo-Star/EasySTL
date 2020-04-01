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

	GTreeNode();	// creat the new Node must to use NewNode()

public:

	LinkList< GTreeNode<T>* > child;
	static GTreeNode<T>* NewNode();
};

template <typename T>
GTreeNode<T>::GTreeNode()
{
}

template <typename T>
GTreeNode<T>* GTreeNode<T>::NewNode()
{
	return new GTreeNode<T>();
}

}   // end namespace EasyDSL

#endif
 
