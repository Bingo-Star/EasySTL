#include <iostream>

#include "SmartPointer.h"
#include "Exception.h"

using namespace std;
using namespace EasySTL;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    {
    SmartPointer<int>* sp = new SmartPointer<int>();
    }
}