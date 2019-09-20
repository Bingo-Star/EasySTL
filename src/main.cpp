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

class Test
{
public:
	Test()
	{
		throw(0);
	}
};

int main()
{
    LinkList<int> list;
    
    for (int i = 0; i < 10; i++)
    {
        list.insert(0, i);
    }
    int num = 0;
    list.clear();
    for (int i = 0; i < list.length(); i++)
    {
    	list.get(i, num);
        cout << num << endl;
    }
    
}