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
#include "Sort.h"

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
//	int nums[10] = {5, 1, 8, 1, 7, 21, 4, 4, 9, 3};
	StaticArray <int, 10> nums;
	for (int i = 0; i < nums.length(); i++)
	{
		nums[i] = 10 - i;
	}

	Sort::Quick(nums, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << nums[i] << endl;
	}

}
