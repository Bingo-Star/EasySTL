#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstdio>

namespace EasySTL
{

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception
{
protected:
    char* mMessage;
    char* mLocation;

    void init(const char* message, const char* file, int line);

public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& obj);
    Exception& operator= (const Exception& obj);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception();
};

class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(NULL){}
    ArithmeticException(const char* message) : Exception(message){}
    ArithmeticException(const char* file, int line) : Exception(file, line){}
    ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line){}

    ArithmeticException(const ArithmeticException& obj) : Exception(obj){}
    ArithmeticException& operator= (const ArithmeticException& obj);
};

class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(NULL){}
    IndexOutOfBoundsException(const char* message) : Exception(message){}
    IndexOutOfBoundsException(const char* file, int line) : Exception(file, line){}
    IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& obj) : Exception(obj){}
    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException& obj);
};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(NULL){}
    NoEnoughMemoryException(const char* message) : Exception(message){}
    NoEnoughMemoryException(const char* file, int line) : Exception(file, line){}
    NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& obj) : Exception(obj){}
    NoEnoughMemoryException& operator= (const NoEnoughMemoryException& obj);
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(NULL){}
    InvalidParameterException(const char* message) : Exception(message){}
    InvalidParameterException(const char* file, int line) : Exception(file, line){}
    InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line){}

    InvalidParameterException(const InvalidParameterException& obj) : Exception(obj){}
    InvalidParameterException& operator= (const InvalidParameterException& obj);
};

class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(NULL){}
    NullPointerException(const char* message) : Exception(message){}
    NullPointerException(const char* file, int line) : Exception(file, line){}
    NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line){}

    NullPointerException(const NullPointerException& obj) : Exception(obj){}
    NullPointerException& operator= (const NullPointerException& obj);
};

}

#endif

