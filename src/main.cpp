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
	LinkStack<int> obj;
	cout << obj.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		obj.push(i);
	}

	while (obj.size())
	{
		cout << obj.top() << endl;
		obj.pop();
	}
}