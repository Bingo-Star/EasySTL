#include <iostream>
#include "SmartPointer.h"

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
    SmartPointer<Test> p1 = new Test();
    SmartPointer<Test> p2 = p1;

    cout << p1.IsNULL() << endl;
    cout << p2.IsNULL() << endl;
}