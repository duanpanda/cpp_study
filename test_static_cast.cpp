#include <iostream>

class MyClass
{
    int a;
    int b;
};

class SmartMyClass
{
public:
    SmartMyClass(int a, int b);
    operator int() const;
private:
    int _a;
    int _b;
};

SmartMyClass::SmartMyClass(int a, int b)
    : _a(a), _b(b)
{
}

SmartMyClass::operator int() const
{
    return _a | _b;
}

int main(int argc, char* argv[])
{
    MyClass myclass;
    MyClass* pmc = &myclass;
    SmartMyClass smartmyclass(1, 2);

    int pointer_impl(-1);

    // pointer_impl = static_cast<int>(pmc);
    // error C2440: 'static_cast' : cannot convert from 'MyClass *' to 'int'
    // There is no context in which this conversion is possible

    pointer_impl = reinterpret_cast<int>(pmc);

    int* pi(0);
    // pi = static_cast<int*>(pmc);
    // error C2440: 'static_cast' : cannot convert from 'MyClass *' to 'int *'
    // Types pointed to are unrelated; conversion requires reinterpret_cast,
    // C-style cast or function-style cast
    pi = (int*)(pmc);

    float fv(0);
    fv = static_cast<float>(pointer_impl);

    int iv(0);
    // iv = static_cast<int>(myclass);
    // error C2440: 'static_cast' : cannot convert from 'MyClass' to 'int'
    // No user-defined-conversion operator available that can perform this
    // conversion, or the operator cannot be called
    iv = static_cast<int>(smartmyclass);

    std::cout << std::hex << pointer_impl
              << ' ' << pmc
              << ' ' << pi
              << ' ' << fv
              << ' ' << iv
              << std::endl;
    return 0;
}
