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
#include "StackBaseQueue.h"
#include "QueueBaseStack.h"

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
	QueueBaseStack<int> obj;
//	cout << obj.length() << endl;
	for (int i = 0; i < 5; i++)
	{
//		Test tmp(i);
		obj.add(i);
	}
	cout << "add success !" << endl;
	while (obj.length())
	{
		cout << obj.front() << endl;
		obj.remove();
	}

//	for (int i = 0; i < 10; i++)
//	{
//		cout << obj.get(i) << endl;
//	}
	
//	int j = 0;
//	for (j = 0, obj.move(0, 1); j < 10; obj.pre(), j++)
//	{
//		cout << obj.current() << endl;
//	}

//	obj.clear();
//	obj.push_back(1000);
//	obj.push_back(50);
//	obj.remove(obj.length());

//	obj.set(6, 5);

//	cout << "remove success !" << endl;

//	for (j = 0, obj.move(0, 1); j < 10; obj.pre(), j++)
//	{
//		cout << obj.current() << endl;
//	}
}