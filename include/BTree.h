#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"
#include "Tree.h"
#include "Exception.h"

namespace EasyDSL
{

enum BTNodePos
{
	ANY,
	LEFT,
	RIGHT
};

template <typename T>
class BTree : public Tree<T>
{
protected:
	BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const;
	BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* dst_node) const;
	void free(BTreeNode<T>* node);
	int dsp(BTreeNode<T>* node, int& degree, int& count) const;

	BTree(const BTree<T>& obj);
	BTree<T>& operator = (const BTree<T>& obj);

public:
	BTree();
	~BTree();
	virtual bool insert(TreeNode<T>* node);
    bool insert(TreeNode<T>* node, BTNodePos pos);
    virtual bool insert(const T& value, TreeNode<T>* parent);
    bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos);    
    virtual SharedPointer< Tree<T> > remove(const T& value);
    virtual SharedPointer< Tree<T> > remove(TreeNode<T>* node);
    virtual BTreeNode<T>* find(const T& value) const;
    virtual BTreeNode<T>* find(TreeNode<T>* node) const;
    virtual BTreeNode<T>* root() const;
    virtual int degree() const;
    virtual int count() const;
    virtual int height() const;
    virtual void clear();

    virtual void begin();
    virtual void next();
    virtual bool end();
    virtual const TreeNode<T>* Current();
};

template <typename T>
BTree<T>::BTree()
{
}

template <typename T>
BTree<T>::~BTree()
{
	clear();
}

template <typename T>
BTree<T>::BTree(const BTree<T>& obj)
{
}

template <typename T>
BTree<T>& BTree<T>::operator = (const BTree<T>& obj)
{
}

template <typename T>
bool BTree<T>::insert(TreeNode<T>* node)
{
	return insert(node, ANY);
}

template <typename T>
bool BTree<T>::insert(TreeNode<T>* node, BTNodePos pos)
{
	if (node == NULL)
	{
		THROW_EXCEPTION(InvalidParameterException, "Parameter node is null ...");
		return false;
	}

	if (this->mRoot == NULL)
	{
		node->parent = NULL;
		this->mRoot = node;
	}
	else
	{
		BTreeNode<T>* ret = find(node->parent);
		if (ret != NULL)
		{
			BTreeNode<T>* tmp = dynamic_cast< BTreeNode<T>* >(node);
			if ((LEFT == pos || ANY == pos) && ret->left == NULL)
			{
				ret->left = tmp;
			}
			else if ((RIGHT == pos || ANY == pos) && ret->right == NULL)
			{
				ret->right = tmp;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

template <typename T>
bool BTree<T>::insert(const T& value, TreeNode<T>* parent)
{
	return insert(value, parent, ANY);
}

template <typename T>
bool BTree<T>::insert(const T& value, TreeNode<T>* parent, BTNodePos pos)
{
	BTreeNode<T>* pNode = BTreeNode<T>::NewNode();

	if (pNode != NULL)
	{
		pNode->value = value;
		pNode->parent = parent;

		if (insert(pNode, pos) == false)
		{
			delete pNode;
			return false;
		}
	}
	else
	{
		THROW_EXCEPTION(NoEnoughMemoryException, "Create new node faile ...");
		return false;
	}

	return true;
}

template <typename T>
SharedPointer< Tree<T> > BTree<T>::remove(const T& value)
{
	BTreeNode<T>* pNode = find(value);
	if (pNode != NULL)
	{
		if (pNode == root())
		{
			this->mRoot = NULL;
		}
		else
		{
			BTreeNode<T>* pParent = dynamic_cast<BTreeNode<T>*>(pNode->parent);
			if (pParent->left != NULL && pParent->left->value == value)
			{
				pParent->left = NULL;
			}
			else
			{
				pParent->right = NULL;
			}
		}
		this->NodeQueue.clear();
		
		BTree<T>* ret = new BTree;
		if (ret == NULL)
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "Create tree faile ...");
			return NULL;
		}
		else
		{
			(*ret).insert(pNode);			
			return ret;
		}
	}
	else
	{
		return NULL;
	}
}

template <typename T>
SharedPointer< Tree<T> > BTree<T>::remove(TreeNode<T>* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	return remove(node->value);
}

template <typename T>
BTreeNode<T>* BTree<T>::find(BTreeNode<T>* node, const T& value) const
{
	if (node == NULL)
	{
		return NULL;
	}

	BTreeNode<T>* ret = NULL;

	if (node->value != value)
	{
		ret = find(node->left, value);
		if (ret == NULL)
		{
			ret = find(node->right, value);
		}
	}
	else
	{
		ret = node;
	}

	return ret;
}

template <typename T>
BTreeNode<T>* BTree<T>::find(BTreeNode<T>* node, BTreeNode<T>* dst_node) const
{
	if (node == NULL || dst_node == NULL)
	{
		return NULL;
	}

	BTreeNode<T>* ret = NULL;

	if (node != dst_node)
	{
		ret = find(node->left, dst_node);
		if (ret == NULL)
		{
			ret = find(node->right, dst_node);
		}
	}
	else
	{
		ret = dst_node;
	}

	return ret;
}


template <typename T>
BTreeNode<T>* BTree<T>::find(const T& value) const
{
	return find(root(), value);
}

template <typename T>
BTreeNode<T>* BTree<T>::find(TreeNode<T>* node) const
{
	return find(root(), dynamic_cast<BTreeNode<T>*>(node));
}

template <typename T>
BTreeNode<T>* BTree<T>::root() const
{
	return dynamic_cast<BTreeNode<T>*>(this->mRoot);
}

template <typename T>
int BTree<T>::dsp(BTreeNode<T>* node, int& degree, int& count) const
{
	if (node != NULL)
	{
		if (degree < 2)
		{
			degree = degree < !!node->left + !!node->right ? !!node->left + !!node->right : degree;
		}
		
		count++;
		
		int left_hight = dsp(node->left, degree, count);
		int right_hight = dsp(node->right, degree, count);

		return (left_hight > right_hight ? left_hight : right_hight) + 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
int BTree<T>::degree() const
{
	int degree = 0;
	int count = 0;
	dsp(root(), degree, count);
	return degree;
}

template <typename T>
int BTree<T>::count() const
{
	int degree = 0;
	int count = 0;
	dsp(root(), degree, count);
	return count;
}

template <typename T>
int BTree<T>::height() const
{
	int degree = 0;
	int count = 0;
	int height = dsp(root(), degree, count);
	return height;
}

template <typename T>
void BTree<T>::free(BTreeNode<T>* node)
{
	if (node != NULL)
	{
		free(node->left);
		free(node->right);

		delete node;
	}
}

template <typename T>
void BTree<T>::clear()
{
	free(root());
	this->mRoot = NULL;
	this->NodeQueue.clear();
}

template <typename T>
void BTree<T>::begin()
{
	this->NodeQueue.clear();
	if (root() != NULL)
	{
		this->NodeQueue.add(root());
		BTreeNode<T>* pNode = dynamic_cast<BTreeNode<T>*>(this->NodeQueue.front());
		if (pNode->left != NULL)
		{
			this->NodeQueue.add(pNode->left);
		}
		if (pNode->right != NULL)
		{
			this->NodeQueue.add(pNode->right);
		}
	}

}

template <typename T>
void BTree<T>::next()
{
	this->NodeQueue.remove();
	if (this->NodeQueue.length() > 0)
	{
		BTreeNode<T>* pNode = dynamic_cast<BTreeNode<T>*>(this->NodeQueue.front());
		if (pNode->left != NULL)
		{
			this->NodeQueue.add(pNode->left);
		}
		if (pNode->right != NULL)
		{
			this->NodeQueue.add(pNode->right);
		}
	}
}

template <typename T>
bool BTree<T>::end()
{
	return this->NodeQueue.length() > 0 ? false : true;
}

template <typename T>
const TreeNode<T>* BTree<T>::Current()
{
	return this->NodeQueue.length() > 0 ? this->NodeQueue.front() : NULL;
}


}   // end namespace EasyDSL

#endif

