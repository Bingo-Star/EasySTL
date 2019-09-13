#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"
#include "DynamicList.h"

using namespace std;
using namespace EasySTL;

int main()
{
    DynamicList<int> nums(10);
    for (int i = 0; i < nums.capacity(); i++)
    {
        nums.insert(i, i);
        cout << nums[i] << endl;
    }
    nums.resize(5);
    for (int i = 0; i < nums.capacity(); i++)
    {
        cout << nums[i] << endl;
    }
}