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
    LinkList<Test> list;
    Test obj_A(0);
    Test obj_B(1);
    Test obj_C(2);
    
    list.insert(0, obj_A);
    list.insert(0, obj_B);
    list.insert(0, obj_C);

    cout << list.find(obj_A) << endl;
}