#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"
#include "DynamicList.h"
#include "StaticList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"

using namespace std;
using namespace EasySTL;

class Test : public RootClass
{
	int i;
public:
	Test(int element = 0)
	{
		i = element;
	}
	bool operator == (Test& obj)
	{
		return this->i == obj.i;
	}
};

int main()
{
    LinkList<int>list;
    Test obj_A(0);
    Test obj_B(1);
    Test obj_C(2);
    
    list.push_back(0);
    list.push_back(1);
    list.push_back(3);

    // cout << list.find(obj_A) << endl;

    for (int i = 0; i < list.length(); i++)
    {
    	int num = 0;
    	list.get(i, num);
    	cout << num << endl;
    }
}