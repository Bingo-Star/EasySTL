#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"
#include "DynamicList.h"
#include "StaticList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

using namespace std;
using namespace EasySTL;

int main()
{
    DynamicArray<int> nums(10);
    for (int i = 0; i < nums.length(); i++)
    {
        nums[i] = 10 - i;
    }
    DynamicArray<int> nums2(6);
    nums2 = nums;
    nums2.resize(5);
    for (int i = 0; i < nums.length(); i++)
    {
        cout << nums[i] << endl;
    }
}