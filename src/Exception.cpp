#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "Exception.h"

using namespace EasySTL;
using namespace std;

void Exception::init(const char* message, const char* file, int line)
{
    this->mMessage = message ? strdup(message) : NULL;

    if (file != NULL)
    {
        this->mLocation = static_cast<char*>(malloc(64));
        if (this->mLocation != NULL)
        {
            memset(this->mLocation, 0, 64);
            sprintf(this->mLocation, "%s:%d", file, line);
        }
    }
    else
    {
        this->mLocation = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message, NULL, 0);
}

Exception::Exception(const char* file, int line)
{
    init(NULL, file, line);
}

Exception::Exception(const char* message, const char* file, int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception& obj)
{
    mMessage = strdup(obj.mMessage);
    mLocation = strdup(obj.mLocation);
}

Exception& Exception::operator= (const Exception& obj)
{
    if (this != &obj)
    {
        free(mMessage);
        free(mLocation);

        mMessage = strdup(obj.mMessage);
        mLocation = strdup(obj.mLocation);
    }
    return *this;
}

const char* Exception::message() const
{
    return mMessage;
}

const char* Exception::location() const
{
    return mLocation;
}

Exception::~Exception()
{
    free(mMessage);
    free(mLocation);
}

/* ArithmeticException */

ArithmeticException& ArithmeticException::operator= (const ArithmeticException& obj)
{
    Exception::operator=(obj);
    return *this;
}

/* IndexOutOfBoundsException */

IndexOutOfBoundsException& IndexOutOfBoundsException::operator= (const IndexOutOfBoundsException& obj)
{
    Exception::operator=(obj);
    return *this;
}

/* NoEnoughMemoryException */

NoEnoughMemoryException& NoEnoughMemoryException::operator= (const NoEnoughMemoryException& obj)
{
    Exception::operator=(obj);
    return *this;
}

/* InvalidParameterException */

InvalidParameterException& InvalidParameterException::operator= (const InvalidParameterException& obj)
{
    Exception::operator=(obj);
    return *this;
}

/* NullPointerException */

NullPointerException& NullPointerException::operator= (const NullPointerException& obj)
{
    Exception::operator=(obj);
    return *this;
}

/* IndexOperationException */

InvalidOperationException& InvalidOperationException::operator= (const InvalidOperationException& obj)
{
    Exception::operator=(obj);
    return *this;
}








