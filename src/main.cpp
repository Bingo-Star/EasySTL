#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"
#include "DynamicList.h"
#include "StaticList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"

using namespace std;
using namespace EasySTL;

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
    LinkList<Test>list;
    Test obj_A(5);
    Test obj_B(4);
    Test obj_C(3);
    
    list.push_back(obj_A);
    list.push_back(obj_B);
    list.push_back(obj_C);

    // cout << list.find(obj_A) << endl;

    for (list.move(0); !list.end(); list.next())
    {
    	
    	cout << list.current().i << endl;
    }
}