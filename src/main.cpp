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
    for (int i = 0; i < 5; i++)
    {
        nums.insert(i, i);
    }
    nums.push_back(55);
    for (int i = 0; i < nums.length(); i++)
    {
        cout << nums[i] << endl;
    }
}