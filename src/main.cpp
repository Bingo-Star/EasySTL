#include <iostream>

using namespace std;

#include "SmartPointer.h"
#include "SharedPointer.h"
#include "Exception.h"
#include "DynamicList.h"
#include "StaticList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "DualCircleList.h"
#include "StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"

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

int main()
{
	CircleList<Test> obj;
	cout << obj.length() << endl;
	for (int i = 0; i < 5; i++)
	{
		Test tmp(i);
		obj.insert(obj.length(), tmp);
	}
	cout << "add success !" << endl;
//	while (obj.length())
//	{
//		cout << obj.get(0).i << endl;
//		obj.remove(0);
//	}

//	for (int i = 0; i < 10; i++)
//	{
//		cout << obj.get(i).i << endl;
//	}
	
	int j = 0;
	for (obj.move(0, 1); j < 10; obj.next(), j++)
	{
		cout << obj.current().i << endl;
	}
}