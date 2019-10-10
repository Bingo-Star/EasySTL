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

	DualLinkList<Test> list;

	Test obj_A(5);
	Test obj_B(4);
	Test obj_C(3);

	list.insert(0, obj_A);
	list.push_back(obj_B);
	list.push_back(obj_C);

	for (list.move(list.length() - 1); !list.end(); list.pre())
	{
		
		cout << list.current().i << endl;
		list.remove(0);
	}

/*
    DynamicArray< DynamicArray<int> > nums;
    nums.resize(10);
    for (int i = 0; i < nums.length(); i++)
    {
    	nums[i].resize(i + 1);
    }
    for (int i = 0; i < nums.length(); i++)
    {
    	for (int j = 0; j < nums[i].length(); j++)
    	{
    		nums[i].set(j, j);
    	}
    }
    for (int i = 0; i < nums.length(); i++)
    {
    	for (int j = 0; j < nums[i].length(); j++)
    	{
    		cout << nums[i][j] << " ";
    	}
    	cout << endl;
    }
*/

//	const SharedPointer<Test> p = new Test(5);
//	SharedPointer<Test> q(p);
//	cout << (p == q) << endl;

//	CirleList<int> cl;

//	for (int i = 1; i <= 5; i++)
//	{
//		cl.push_back(i);
//	}

//	cl.move(0, 2);

//	while (cl.length() > 0)
//	{
//		cl.next();
//		cout << cl.current() << endl;
//		cl.remove(cl.find(cl.current()));
//	}

//	cl.clear();
}