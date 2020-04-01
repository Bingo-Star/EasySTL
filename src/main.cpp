#include <iostream>

using namespace std;

//#include "SmartPointer.h"
//#include "SharedPointer.h"
//#include "Exception.h"
//#include "DynamicList.h"
//#include "StaticList.h"
//#include "StaticArray.h"
//#include "DynamicArray.h"
//#include "LinkList.h"
//#include "StaticLinkList.h"
//#include "CircleList.h"
//#include "DualLinkList.h"
//#include "DualCircleList.h"
//#include "StaticStack.h"
//#include "LinkStack.h"
//#include "StaticQueue.h"
//#include "LinkQueue.h"
//#include "StackBaseQueue.h"
//#include "QueueBaseStack.h"
//#include "DSL_String.h"
//#include "Sort.h"
#include "GTreeNode.h"
#include "GTree.h"
#include "BTree.h"



#include <list>

using namespace EasyDSL;

class Test : public RootClass
{
	
public:
	int i;
	Test(int element = 0)
	{
		cout << "Test() : " << element << endl;
		i = element;
	}
	bool operator == (Test& obj)
	{
		return this->i == obj.i;
	}
	~Test()
	{
		cout << "~Test() : " << i << endl;
	}
};

template <typename T>
T add(T num_A, T num_B)
{
	return num_A + num_B;
}

int main()
{
	GTree<int> Tree;
	
	GTreeNode<int>* pNode1 = GTreeNode<int>::NewNode();
	pNode1->value = 0;
	Tree.insert(pNode1);
	
	GTreeNode<int>* pNode2 = GTreeNode<int>::NewNode();
	pNode2->value = 1;
	pNode2->parent = pNode1;
	Tree.insert(pNode2);
	
	Tree.insert(2, pNode1);
	Tree.insert(3, pNode2);
	Tree.insert(4, pNode2);

	Tree.insert(5, Tree.find(2));
	Tree.insert(6, Tree.find(2));
//	
//	Tree.remove(Tree.find(1));

//	cout << Tree.height() << endl;

	for (Tree.begin(); !Tree.end(); Tree.next())
	{
		cout << Tree.Current()->value << endl;
	}

}
