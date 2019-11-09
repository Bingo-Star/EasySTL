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
#include "DSL_String.h"

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
	String obj = "abc";
//	obj += '5';
	obj.insert(3, "456");
	cout << obj.str() << endl;
	cout << obj.length() << endl;
	String obj_B = obj.sub(5, 0);
	cout << obj_B.str() << endl;
	cout << obj_B.length() << endl;
//	obj.remove("abd");
//	cout << obj.str() << endl;
//	cout << obj.length() << endl;
}
