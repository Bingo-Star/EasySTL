#ifndef GTREE_H
#define GTREE_H

#include "GTreeNode.h"
#include "Tree.h"
#include "Exception.h"
#include "LinkQueue.h"


namespace EasyDSL
{

template <typename T>
class GTree : public Tree<T>
{
protected:
	GTreeNode<T>* find(GTreeNode<T>* node, const T& value) const;
	GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* dst_node) const;
	void free(GTreeNode<T>* node);
	int dsp(GTreeNode<T>* node, int& degree, int& count) const;

	LinkQueue< GTreeNode<T>* > NodeQueue;

	GTree(const GTree<T>& obj);
	GTree<T>& operator = (const GTree<T>& obj);

public:
	GTree();
	~GTree();
    virtual bool insert(TreeNode<T>* node);
    virtual bool insert(const T& value, TreeNode<T>* parent);
    virtual SharedPointer< Tree<T> > remove(const T& value);
    virtual SharedPointer< Tree<T> > remove(TreeNode<T>* node);
    virtual GTreeNode<T>* find(const T& value) const;
    virtual GTreeNode<T>* find(TreeNode<T>* node) const;
    virtual GTreeNode<T>* root() const;
    virtual int degree() const;
    virtual int count() const;
    virtual int height() const;
    virtual void clear();

    void begin();
    void next();
    bool end();
    const GTreeNode<T>* Current();
};

template <typename T>
GTree<T>::GTree()
{
}

template <typename T>
GTree<T>::~GTree()
{
	clear();
}

template <typename T>
GTree<T>::GTree(const GTree<T>& obj)
{
}

template <typename T>
GTree<T>& GTree<T>::operator = (const GTree<T>& obj)
{
}

template <typename T>
bool GTree<T>::insert(TreeNode<T>* node)
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
		GTreeNode<T>* ret = find(node->parent);
		if (ret != NULL)
		{
			GTreeNode<T>* tmp = dynamic_cast< GTreeNode<T>* >(node);
			if (ret->child.find(tmp) < 0)
			{
				ret->child.push_back(tmp);			
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
bool GTree<T>::insert(const T& value, TreeNode<T>* parent)
{
	GTreeNode<T>* pNode = GTreeNode<T>::NewNode();

	if (pNode != NULL)
	{
		pNode->value = value;
		pNode->parent = parent;

		if (insert(pNode) == false)
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
SharedPointer< Tree<T> > GTree<T>::remove(const T& value)
{
	GTreeNode<T>* pNode = find(value);
	if (pNode != NULL)
	{
		if (pNode == root())
		{
			this->mRoot = NULL;
		}
		else
		{
			GTreeNode<T>* pParent = dynamic_cast<GTreeNode<T>*>(pNode->parent);
			pParent->child.remove(pParent->child.find(pNode));
		}
		NodeQueue.clear();
		
		GTree<T>* ret = new GTree;
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
SharedPointer< Tree<T> > GTree<T>::remove(TreeNode<T>* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	return remove(node->value);
}

template <typename T>
GTreeNode<T>* GTree<T>::find(GTreeNode<T>* node, const T& value) const
{
	if (node == NULL)
	{
		return NULL;
	}

	GTreeNode<T>* ret = NULL;

	if (node->value != value)
	{
		for (node->child.move(0); !node->child.end() && NULL == ret; node->child.next())
		{
			ret = find(node->child.current(), value);
		}
	}
	else
	{
		ret = node;
	}

	return ret;
}

template <typename T>
GTreeNode<T>* GTree<T>::find(GTreeNode<T>* node, GTreeNode<T>* dst_node) const
{
	if (node == NULL || dst_node == NULL)
	{
		return NULL;
	}

	GTreeNode<T>* ret = NULL;

	if (node != dst_node)
	{
		for (node->child.move(0); !node->child.end() && NULL == ret; node->child.next())
		{
			ret = find(node->child.current(), dst_node);
		}
	}
	else
	{
		ret = dst_node;
	}

	return ret;
}


template <typename T>
GTreeNode<T>* GTree<T>::find(const T& value) const
{
	return find(root(), value);
}

template <typename T>
GTreeNode<T>* GTree<T>::find(TreeNode<T>* node) const
{
	return find(root(), dynamic_cast<GTreeNode<T>*>(node));
}

template <typename T>
GTreeNode<T>* GTree<T>::root() const
{
	return dynamic_cast<GTreeNode<T>*>(this->mRoot);
}

template <typename T>
int GTree<T>::dsp(GTreeNode<T>* node, int& degree, int& count) const
{
	if (node != NULL)
	{
		degree = node->child.length() > degree ? node->child.length() : degree;
		count++;
		int height = 0;
		for (node->child.move(0); !node->child.end(); node->child.next())
		{
			int ret = dsp(node->child.current(), degree, count);
			height = height < ret ? ret : height;
		}
		height++;

		return height;
	}
	else
	{
		return 0;
	}
}

template <typename T>
int GTree<T>::degree() const
{
	int degree = 0;
	int count = 0;
	dsp(root(), degree, count);
	return degree;
}

template <typename T>
int GTree<T>::count() const
{
	int degree = 0;
	int count = 0;
	dsp(root(), degree, count);
	return count;
}

template <typename T>
int GTree<T>::height() const
{
	int degree = 0;
	int count = 0;
	int height = dsp(root(), degree, count);
	return height;
}

template <typename T>
void GTree<T>::free(GTreeNode<T>* node)
{
	if (node != NULL)
	{
		for (node->child.move(0); !node->child.end(); node->child.next())
		{
			free(node->child.current());
		}

		if (node->flg())
		{
			delete node;
		}	
	}
}

template <typename T>
void GTree<T>::clear()
{
	free(root());
	this->mRoot = NULL;
	NodeQueue.clear();
}

template <typename T>
void GTree<T>::begin()
{
	NodeQueue.clear();
	if (root() != NULL)
	{
		NodeQueue.add(root());
		for (NodeQueue.front()->child.move(0); !NodeQueue.front()->child.end(); NodeQueue.front()->child.next())
		{
			NodeQueue.add(NodeQueue.front()->child.current());
		}
	}

}

template <typename T>
void GTree<T>::next()
{
	NodeQueue.remove();
	if (NodeQueue.length() > 0)
	{
		for (NodeQueue.front()->child.move(0); !NodeQueue.front()->child.end(); NodeQueue.front()->child.next())
		{
			NodeQueue.add(NodeQueue.front()->child.current());
		}
	}
}

template <typename T>
bool GTree<T>::end()
{
	return NodeQueue.length() > 0 ? false : true;
}

template <typename T>
const GTreeNode<T>* GTree<T>::Current()
{
	return NodeQueue.length() > 0 ? NodeQueue.front() : NULL;
}


}   // end namespace EasyDSL

#endif

