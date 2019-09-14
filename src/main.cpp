#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"
#include "DynamicList.h"
#include "StaticList.h"

using namespace std;
using namespace EasySTL;

int main()
{
    StaticList<int, 10> nums;
    for (int i = 0; i < nums.capacity(); i++)
    {
        nums.insert(i, i);
    }
    StaticList<int, 10> numsB = nums;
    numsB[0] = 99;
    for (int i = 0; i < nums.length(); i++)
    {
        cout << nums[i] << endl;
    }
}