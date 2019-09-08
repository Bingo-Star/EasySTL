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
    try
    {
        THROW_EXCEPTION(NullPointerException, "NullPointerException");
    }
    catch(const Exception& obj)
    {
        cout << obj.message() << endl;
        cout << obj.location() << endl;
    }
}