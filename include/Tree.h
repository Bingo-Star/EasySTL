#ifndef TREE_H
#define TREE_H

#include "Root.h"
#include "TreeNode.h"
#include "SharedPointer.h"
#include "LinkQueue.h"


namespace EasyDSL
{

template <typename T>
class Tree : public RootClass
{
protected:
	TreeNode<T>* mRoot;
	LinkQueue< TreeNode<T>* > NodeQueue;

public:
	Tree();
    virtual bool insert(TreeNode<T>* node) = 0;
    virtual bool insert(const T& value, TreeNode<T>* parent) = 0;
    virtual SharedPointer< Tree<T> > remove(const T& value) = 0;
    virtual SharedPointer< Tree<T> > remove(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* find(const T& value) const = 0;
    virtual TreeNode<T>* find(TreeNode<T>* node) const = 0;
    virtual TreeNode<T>* root() const = 0;
    virtual int degree() const = 0;
    virtual int count() const = 0;
    virtual int height() const = 0;
    virtual void clear() = 0;
    virtual void begin() = 0;
    virtual void next() = 0;
    virtual bool end() = 0;
    virtual const TreeNode<T>* Current() = 0;

};

template <typename T>
Tree<T>::Tree()
{
	mRoot = NULL;
}

}   // end namespace EasyDSL

#endif
